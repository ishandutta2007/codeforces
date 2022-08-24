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

const int MAXN = 210000;

int n;
vector<int> eds[MAXN];
int cc[MAXN];
int h[MAXN];

void dfs1(int v, int p) {
	for (int u: eds[v]) {
		if (u == p)
			continue;
		h[u] = h[v] + 1;
		dfs1(u, v);
	}
}

set<pair<int, int> > ss;
int used[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	if (n % 2 == 0) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		if (x != -1)
			eds[x].push_back(i), eds[i].push_back(x);
	}
	for (int i = 0; i < n; ++i)
		cc[i] = eds[i].size() % 2;
	dfs1(0, -1);
	for (int i = 0; i < n; ++i)
		if (cc[i] == 0)
			ss.emplace(-h[i], i);
	while (!ss.empty()) {
		int x = ss.begin()->second;
		ss.erase(ss.begin());
		cout << x + 1 << "\n";
		used[x] = 1;
		for (int u: eds[x]) {
			if (!used[u]) {
				cc[u] ^= 1;
				if (cc[u] == 1)
					ss.erase({-h[u], u});
				else
					ss.insert({-h[u], u});
			}
		}
	}
	return 0;
}