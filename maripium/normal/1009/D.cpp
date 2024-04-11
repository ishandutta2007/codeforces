#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
long long f[N], cnt[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; j += i) cnt[i]++;
	}
	for (int i = n; i >= 1; --i) {
		f[i] = cnt[i] * (cnt[i] - 1) / 2LL;
		for (int j = i + i; j <= n ; j += i) f[i] -= f[j];
	}
	if (m < n - 1 || (1LL * m > f[1])) return cout << "Impossible\n",0;
	int cnt = 0;
	cout << "Possible\n";
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n;++j) {
			if (__gcd(i, j) == 1) cout << i << ' ' << j << '\n', cnt++;;
			if (cnt == m) break;
		}
		if (cnt == m) break;
	}
}