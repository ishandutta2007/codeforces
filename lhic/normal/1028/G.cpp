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

const int K = 10000;
const ll INF = 1e18;

ll dp[6][K + 1];

ll get(int x, ll k) {
	return dp[x][min(ll(K), k)];
}


int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	for (int i = 1; i <= K; ++i)
		dp[1][i] = i;
	for (int i = 2; i <= 5; ++i) {
		for (int j = 1; j <= K; ++j) {
			ll now = get(i - 1, j);
			for (int k = 1; k <= j; ++k) {
				++now;
				now += get(i - 1, j + now);
				now = min(now, INF);
			}
			dp[i][j] = now;
		}
	}
	ll l = 1;
	for (int i = 5; i > 1; --i) {
		ll now = get(i - 1, l);
		int j = min(ll(K), l);
		vector<ll> vv;
		for (int k = 1; k <= j; ++k) {
			vv.push_back(l + now);
			++now;
			now += get(i - 1, j + now);
			now = min(now, INF);
		}
		cout << vv.size() << " ";
		for (ll i: vv)
			cout << i << " ";
		cout << "\n";
		cout.flush();
		int x;
		cin >> x;
		--x;
		if (x == -2) {
			return 0;
		}
		if (x != -1)
			l = vv[x] + 1;
	}
	int go = min(ll(K), l);
	vector<ll> vv;
	for (ll i = l; i < l + go; ++i)
		vv.push_back(i);
	cout << vv.size() << " ";
	for (ll i: vv)
		cout << i << " ";
	cout << "\n";
	cout.flush();
	int x;
	cin >> x;
	--x;
	if (x == -2) {
		return 0;
	}
	assert(false);
	return 0;
}