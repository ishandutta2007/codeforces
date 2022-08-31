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
const int MAXN = 310000;

int n, m;
ll sum;
vector<ll> vv;

ll x[MAXN];
ll y[MAXN];
vector<int> eds[MAXN];
ll sm[MAXN];

ll get(int a, int b) {
	return min(x[a] + y[b], x[b] + y[a]);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		vv.push_back(y[i] - x[i]);
		sum += x[i];
	}
	sort(vv.begin(), vv.end());
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	sm[0] = 0;
	for (int i = 0; i < vv.size(); ++i)
		sm[i + 1] = sm[i] + vv[i];
	for (int i = 0; i < n; ++i) {
		ll ans = sum - x[i] + x[i] * (n - 1);
		int p = lower_bound(vv.begin(), vv.end(), y[i] - x[i]) - vv.begin();
		ans += sm[p] + (n - 1 - p) * (y[i] - x[i]);
		for (int j: eds[i]) {
			ans -= get(i, j);
		}
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}