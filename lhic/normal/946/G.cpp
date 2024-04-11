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
typedef long long llong;
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

const ll INF = 1e10;
const int MAXN = 220000;
int n;
ll a[MAXN];

set<pair<ll, int> > ss;

ll go[MAXN];
int gl[MAXN];
int gr[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i], a[i] -= i;
	for (int i = 0; i <= n; ++i)
		go[i] = INF;
	go[0] = -INF;
	for (int i = 0; i < n; ++i) {
		int x = upper_bound(go, go + n, a[i]) - go;
		go[x] = a[i];
		gl[i] = x;
	}
	for (int i = 0; i <= n; ++i)
		go[i] = INF;
	go[0] = -INF;
	for (int i = n - 1; i >= 0; --i) {
		int x = upper_bound(go, go + n, -a[i]) - go;
		go[x] = -a[i];
		gr[i] = x;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, gr[i]);
		auto it = ss.lower_bound(make_pair(a[i] + 2, 0));
		if (it != ss.begin()) {
			--it;
			ans = max(ans, it->second + gr[i]);
		}
		if (i >= 1) {
			it = ss.lower_bound(make_pair(a[i - 1] + 1, 0));
			if (it != ss.begin() && prev(it)->second >= gl[i - 1])
				continue;
			it = ss.insert(make_pair(a[i - 1], gl[i - 1])).first;
			while (next(it) != ss.end() && next(it)->second <= gl[i - 1])
				ss.erase(next(it));
		}
	}
	cout << max(0, n - ans - 1) << "\n";
	return 0;
}