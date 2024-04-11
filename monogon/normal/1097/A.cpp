#include <iostream>

using namespace std;

string s1, s2;

int main() {
	cin >> s1;
	for(int i = 0; i < 5; i++) {
		cin >> s2;
		if(s1[0] == s2[0] || s1[1] == s2[1]) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}