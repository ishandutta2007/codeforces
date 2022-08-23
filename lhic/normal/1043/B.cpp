#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int MX = 1200;

int n;
int a[MX];
int x[MX];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		x[i] = a[i + 1] - a[i];
	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		int fl = 0;
		for (int j = 0; j < n; ++j)
			if (x[j] != x[j % i])
				fl = 1;
		if (!fl)
			ans.push_back(i);
	}
	cout << ans.size() << "\n";
	for (int i: ans)
		cout << i << " ";
	cout << "\n";
	return 0;
}