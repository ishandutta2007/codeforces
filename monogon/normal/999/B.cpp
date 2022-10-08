#include <iostream>

using namespace std;

int n;
string s;

int main() {
	cin >> n >> s;
	for(int i = 1; i <= n; i++) {
		if(n % i == 0) {
			for(int j = 0; j < i / 2; j++) {
				char temp = s[j];
				s[j] = s[i - j - 1];
				s[i - j - 1] = temp;
			}
		}
	}
	cout << s << endl;
}