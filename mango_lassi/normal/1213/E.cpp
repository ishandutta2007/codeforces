#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	string s1, s2;
	cin >> s1 >> s2;
	
	cout << "YES\n";
	if (s1[0] != s1[1] && s2[0] != s2[1]) {
		char c1, c2, c3;
		c1 = s1[1];
		if (c1 == s2[0]) {
			c3 = s2[1];
		} else {
			c3 = s2[0];
		}
		c2 = 'a' + 'b' + 'c' - c1 - c3;

		for (int i = 0; i < n; ++i) cout << c1;
		for (int i = 0; i < n; ++i) cout << c2;
		for (int i = 0; i < n; ++i) cout << c3;
	} else {
		int v = (s1[1] - s1[0]) + (s2[1] - s2[0]);
		if (v == 1 || v == -2) {
			for (int i = 0; i < 3*n; ++i) cout << (char)('a' + 2 - (i % 3));
		} else {
			for (int i = 0; i < 3*n; ++i) cout << (char)('a' + (i % 3));
		}
	}
	cout << '\n';
}