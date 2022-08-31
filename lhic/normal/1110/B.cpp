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

const int MAXN = 120000;

ll n, m, k;
ll b[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	vector<ll> vv;
	for (int i = 0; i + 1 < n; ++i)
		vv.push_back(b[i + 1] - b[i] - 1);
	sort(vv.begin(), vv.end());
	reverse(ALL(vv));
	int now = n;
	ll len = n;
	while (now > k) {
		--now;
		len += vv.back();
		vv.pop_back();
	}
	cout << len << "\n";
	return 0;
}