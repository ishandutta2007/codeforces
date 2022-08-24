#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1e9 + 7;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}

const int MAXN = 220000;
int n;
vector<int> vx, vy;
int x[MAXN], y[MAXN];
vector<int> eds[MAXN];
int was[MAXN];
int gfl = 0;
int cc = 0;
int h[MAXN];

int fnd(const vector<int> &vv, int x) {
	return lower_bound(vv.begin(), vv.end(), x) - vv.begin();
}


void dfs1(int v) {
	was[v] = 1;
	++cc;
	for (int u: eds[v]) {
		if (was[u]) {
			if (h[u] > h[v]) {
				gfl = 1;
			}
		}
		else {
			h[u] = h[v] + 1;
			dfs1(u);
		}
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> 	x[i] >> y[i];
		vx.push_back(x[i]);
		vy.push_back(y[i]);
	}
	sort(vx.begin(), vx.end());
	vx.resize(unique(ALL(vx)) - vx.begin());
	sort(vy.begin(), vy.end());
	vy.resize(unique(ALL(vy)) - vy.begin());
	for (int i = 0; i < n; ++i) {
		x[i] = fnd(vx, x[i]);
		y[i] = fnd(vy, y[i]);
		eds[x[i]].push_back(vx.size() + y[i]);
		eds[vx.size() + y[i]].push_back(x[i]);
	}
	ll ans = 1;
	for (int i = 0; i < vx.size() + vy.size(); ++i) {
		if (was[i])
			continue;
		gfl = 0;
		cc = 0;
		dfs1(i);
		if (gfl) {
			ans = (ans * pw(2, cc)) % MOD;
		}
		else {
			ans = (ans * (pw(2, cc) + MOD - 1)) % MOD;
		}
	}
	cout << ans << "\n";
	return 0;
}