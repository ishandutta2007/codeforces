#include <iostream>

using namespace std;

int n;
string s;

bool palindrome() {
	for(unsigned int i = 0; i < s.length() / 2; i++) {
		if(s[i] != s[s.length() - 1 - i]) {
			return false;
		}
	}
	return true;
}
string correct() {
	for(unsigned int i = 0; i < s.length(); i++) {
		if(s[i] != s[0]) {
			if(palindrome()) {
				swap(s[0], s[i]);
			}
			return s;
		}
	}
	return "-1";
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s;
		cout << correct() << endl;
	}
}