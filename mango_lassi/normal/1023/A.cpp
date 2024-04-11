#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string s;
	string t;
	cin >> s >> t;

	int w = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '*') {
			w = i;
		}
	}
	bool match = true;
	if (w == -1) {
		if (n != m) match = false;
		else {
			for (int i = 0; i < n; ++i) {
				if (s[i] != t[i]) match = false;
			}
		}
	} else {
		int da = w;
		int db = n-1 - w;
		if (da + db > m) match = false;
		else {
			for (int i = 0; i < da; ++i) {
				if (s[i] != t[i]) match = false;
			}
			for (int i = 1; i <= db; ++i) {
				if (s[n-i] != t[m-i]) match = false;
			}
		}
	}
	if (match) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}