#ifndef BZ
#ifndef __clang__
#pragma GCC optimize "-O3"
#endif
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
const int MAXN = 1200;

int n, m, s, t;
vector<int> eds[MAXN];
int dds[MAXN];
int ddt[MAXN];
const int INF = 1e9;

void bfs(int v, int *dd) {
	fill(dd, dd + n, INF);
	dd[v] = 0;
	queue<int> qu;
	qu.push(v);
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (int u: eds[x]) {
			if (dd[u] == INF)
				dd[u] = dd[x] + 1, qu.push(u);
		}
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m >> s >> t;
	--s, --t;
	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	bfs(s, dds);
	bfs(t, ddt);
	int ans = 0;
	int go = ddt[s];
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if ((dds[i] + 1 + ddt[j]) >= go && (dds[j] + 1 + ddt[i]) >= go)
				++ans;
	cout << ans - m << "\n";
	return 0;
}