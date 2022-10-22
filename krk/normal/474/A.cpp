#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const string s[] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};

char ch;
string str;

int main()
{
	cin >> ch;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
		for (int j = 0; j < 3; j++) {
			int p = s[j].find(str[i]);
			if (p != string::npos) {
				if (ch == 'L') p++;
				else p--;
				cout << s[j][p]; break;
			}
		}
	cout << endl;
	return 0;
}