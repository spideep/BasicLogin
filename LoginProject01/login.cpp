

#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;
void login();
void registr();
void forgot();

int main()
{
	int choice;
	cout << "****************** LOGIN *********************\n";
	cout << "1.Login";
	cout << "\n2.Register";
	cout << "\n3.Forgot credentials";
	cout << "\nEnter your choice :";
	cin >> choice;
	switch (choice) {
	case 1:
		login();
		break;
	case 2:
		registr();
		break;
	case 3:
		forgot();
		break;
	case 4:
		cout << "Thanks for using the login page\n";
		break;
	default:
		system("cls");
		cout << "This a bad choice";
		main();
	}
}

void registr() {
	string reguser, regpass;
	system("cls");
	cout << "Enter the username :";
	cin >> reguser;
	cout << "Enter the password :";
	cin >> regpass;

	ofstream reg("database.txt", ios::app);
	reg << reguser << ' ' << regpass << endl;
	system("cls");
	cout << "Registration was successfull\n";
	main();
}

void login() {
	static int count;
	string user, pass, u, p;
	system("cls");
	cout << "Enter the username :";
	cin >> user;
	cout << "Enter the password :";
	cin >> pass;

	ifstream input("database.txt");
	while (input >> u >> p) {
		if (u == user && p == pass) {
			count = 1;
			system("cls");
		}
	}
	input.close();
	if (count == 1) {
		cout << "Welcome " << user << "\nWe are glad you are here.\n";
		main();
	}
	else {
		cout << "Login error.\n";
		main();
	}
}

void forgot() {
	int ch;
	system("cls");
	cout << "1.Search your account by username ";
	cout << "\n2.Search your account by password ";
	cout << "\n3.Mainmenu ";
	cout << "\nEnter your choice : ";
	cin >> ch;

	switch (ch)
	{
	case 1: {
		int ex = 0;
		string searchuser, su, sp;
		cout << "Enter your remembered username :";
		cin >> searchuser;

		ifstream searchu("database.txt");
		while (searchu >> su >> sp)
		{
			if (su == searchuser) {
				ex = 1;
				break;
			}
		}
		searchu.close();
		if (ex == 1) {
			cout << "Account found!\n";
			cout << "Your password is " << sp;
			main();
		}
		else {
			cout << "Account not found\n";
			main();
		}
		break;
	}
	case 2: {
		int exi = 0;
		string searchpass, su2, sp2;
		cout << "Enter the remembered password :";
		cin >> searchpass;

		ifstream searchp("database.txt");
		while (searchp >> su2 >> sp2) {
			if (sp2 == searchpass) {
				exi = 1;
				break;
			}
		}
		searchp.close();
		if (exi == 1) {
			cout << "The account was found \n";
			cout << "Your username is: " << su2;
			cout << "Your password is: " << sp2;
			cin.get();
			cin.get();
			main();
		}
		break;
	}
	case 3: {
		main();
		break;
	}
	default: {
		cout << "You have given a wrong choice, press any key to try again";
		forgot();
		break;
	}
	}

}