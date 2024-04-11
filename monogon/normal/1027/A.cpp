#include <iostream>
#include <string>

using namespace std;

int T, l;
string s;

int main() {
	cin >> T;
	for(int i = 0; i < T; i++) {
		cin >> l >> s;
		unsigned int j = 0;
		for(j = 0; j < s.length() / 2; j++) {
			if(s[j] != s[s.length() - j - 1] && abs(s[j] - s[s.length() - j - 1]) != 2) {
				break;
			}
		}
		cout << (j < s.length() / 2 ? "NO" : "YES") << endl;
	}
}