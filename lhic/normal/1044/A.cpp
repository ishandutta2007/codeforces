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

int n, m;

vector<int> vv;
vector<int> go;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		vv.push_back(x);
	}
	for (int i = 0; i < m; ++i) {
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		--x1, --x2;
		--y;
		if (x1 != 0)
			continue;
		go.push_back(x2);
	}
	vv.push_back(int(1e9) - 1);
	sort(ALL(go));
	sort(ALL(vv));
	int ans = n + m;
	int now = 0;
	for (int i = 0; i < vv.size(); ++i) {
		while (now < go.size() && go[now] < vv[i])
			++now;
		ans = min(ans, i + (int)go.size() - now);
	}
	cout << ans << "\n";
	return 0;
}