#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

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

const int INF = 100;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	ll n;
	cin >> n;
	ll tmp = n;
	vector<int> vv;
	while (tmp) {
		vv.push_back(tmp % 10);
		tmp /= 10;
	}
	int ans = INF;
	for (int i = 1; i * i <= n; ++i) {
		vector<int> u;
		int x = i * i;
		while (x) {
			u.push_back(x % 10);
			x /= 10;
		}
		int cur = u.size() - 1;
		for (int i = vv.size() - 1; i >= 0; --i) {
			if (cur >= 0 && vv[i] == u[cur]) {
				--cur;
			}
		}
		if (cur == -1) {
			ans = min(ans, int(vv.size() - u.size()));
		}
	}
	if (ans == INF)
		cout << -1 << "\n";
	else {
		cout << ans << "\n";
	}
	return 0;
}