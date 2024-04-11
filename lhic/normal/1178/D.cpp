#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

int pr[5000];

void init() {
	for (int i = 2; i < 5000; ++i) {
		int fl = 0;
		for (int j = 2; j * j <= i; ++j)
			if (i % j == 0) {
				fl = 1;
				break;
			}
		if (!fl)
			pr[i] = 1;
	}
}

void solve(int n) {
	int mx = n + n / 2;
	for (int i = n; i <= mx; ++i) {
		if (!pr[i])
			continue;
		vector<pair<int, int>> ed;
		for (int i = 0; i < n; ++i)
			ed.emplace_back(i, (i + 1) % n);
		int lf = i - n;
		int go = n / 2;
		for (int j = 0; j < lf; ++j)
			ed.emplace_back(j, (j + go) % n);
		cout << ed.size() << "\n";
		for (auto e: ed)
			cout << e.first + 1 << " " << e.second + 1 << "\n";
		return;
	}
	assert(false);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	init();
	int n;
	cin >> n;
	solve(n);
	return 0;
}