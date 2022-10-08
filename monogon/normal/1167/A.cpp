
#include <iostream>

using namespace std;

int T, n;
string str;

int main() {
	cin >> T;
	for(int t = 0; t < T; t++) {
		cin >> n >> str;
		bool b = false;
		for(int i = 0; i <= n - 11; i++) {
			if(str[i] == '8') {
				b = true;
			}
		}
		cout << (b ? "YES" : "NO") << endl;
	}
}