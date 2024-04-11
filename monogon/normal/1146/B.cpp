
#include <iostream>
#include <sstream>

using namespace std;

string str;

int main() {
	cin >> str;
	stringstream ss;
	for(unsigned int i = 0; i < str.length(); i++) {
		if(str[i] != 'a') {
			ss << str[i];
		}
	}
	string str2 = ss.str();
	string str3 = str2.substr(0, str2.length() / 2);
	if(str2 != (str3 + str3) || str.substr(str.length() - str3.length(), str.length()) != str3) {
		cout << ":(" << endl;
		return 0;
	}
	cout << str.substr(0, str.length() - str3.length()) << endl;
}