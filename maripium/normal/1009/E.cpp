#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int mod = 998244353;

int n;
int a[N], pw2[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n; pw2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pw2[i] = (pw2[i - 1] + pw2[i - 1]) % mod;
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		int cur = i == n ? 1 : 1LL * pw2[n - i - 1] * (n - i + 2) % mod;
		res = (res + 1LL * cur * a[i] % mod) % mod;
	}
	cout << res << '\n';
}