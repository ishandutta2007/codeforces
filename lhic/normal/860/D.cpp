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


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int MAXN = 220000;

int n, m;
vector<int> eds[MAXN];
int was[MAXN];
vector<array<int, 3>> ans;
int h[MAXN];

int dfs1(int v, int p) {
	was[v] = 1;
	vector<int> go;
	for (int u: eds[v]) {
		if (was[u]) {
			if (h[u] > h[v]) {
				go.push_back(u);
			}
		} else {
			h[u] = h[v] + 1;
			if (dfs1(u, v))
				go.push_back(u);
		}
	}
	while (go.size() >= 2) {
		int x = go.back();
		go.pop_back();
		int y = go.back();
		go.pop_back();
		ans.push_back({x, v, y});
	}
	if (go.empty())
		return 1;
	if (p != -1)
		ans.push_back({p, v, go[0]});
	return 0;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		if (was[i])
			continue;
		dfs1(i, -1);
	}
	cout << ans.size() << "\n";
	for (auto x: ans) {
		for (int j: x)
			cout << j + 1 << " ";
		cout << "\n";
	}
	return 0;
}