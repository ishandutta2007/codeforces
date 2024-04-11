#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
string s;
int f[N + N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s; n = s.size(); s = '~' + s + s;
	int res = 0;
	for (int i = 1; i <= n + n; ++i) {
		if (s[i] != s[i - 1]) f[i] = f[i - 1] + 1;
		else f[i] = 1;
		res = max(res, f[i]);
	}
	cout << min(n, res);
}