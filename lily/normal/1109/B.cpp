#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define x first
#define y second
#pragma GCC optimize("-O3")

string s;
int ans =0;
int main() {
	cin >> s;
	int n = s.size();
	if (n & 1) {
		if (n > 1) s = s.substr(0, n / 2) + s.substr(n / 2 + 1, n / 2), n--, ans++;
		bool flag = 0;
		for (auto v : s) {
			if (v != s[0]) flag = 1;
		}
		if (!flag) {
			puts("Impossible");
		}
		else puts("2");
	}
	else {
		bool flag = 0;
		for (auto v : s) {
			if (v != s[0]) flag = 1;
		}
		if (!flag) {
			puts("Impossible");
			return 0;
		}
		for (int i = 1; i <= n / 2; i++) {
			string y = s.substr(i, n) + s.substr(0, i);
			if (y == s) break;
			string z = y; reverse(y.begin(), y.end());
			if (y == z) {
				puts("1");
				return 0;
			}
		}
		puts("2");
	}
	return 0;
}