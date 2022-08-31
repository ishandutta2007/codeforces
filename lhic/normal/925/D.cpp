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
const int MAXN = 310000;
const int INF = 1e9;

vector<int> eds[MAXN];
int n, m;
set<pair<int, int>> ed;

queue<int> qu;
int dd[MAXN];
int go[MAXN];
int fl[MAXN];
int was[MAXN];
vector<int> vv;

void dfs1(int v) {
	was[v] = 1;
	vv.push_back(v);
	for (int u: eds[v]) {
		if (!was[u])
			dfs1(u);
	}
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
		ed.insert(make_pair(a, b));
		ed.insert(make_pair(b, a));
	}
	fill(dd, dd + n, INF);
	fill(go, go + n, -1);
	dd[0] = 0;
	qu.push(0);
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (int u: eds[x]) {
			if (dd[u] > dd[x] + 1)
				dd[u] = dd[x] + 1, qu.push(u), go[u] = x;
		}
	}
	vector<int> ans;
	if (dd[n - 1] != INF) {
		ans.clear();
		int now = n - 1;
		while (now != -1)
			ans.push_back(now), now = go[now];
		reverse(ans.begin(), ans.end());
	}
	for (int u: eds[0])
		fl[u] = 1;
	for (int i = 1; i < n - 1; ++i) {
		if (!fl[i])
			continue;
		for (int u: eds[i]) {
			if (u != 0 && !fl[u]) {
				if (ans.empty() || ans.size() > 5) {
					ans = {0, i, u, 0, n - 1};
				}
			}
		}
	}
	if (ans.size() > 6 || ans.empty()) {
		was[0] = 1;
		int gfl = 0;
		for (int i = 1; i < n - 1 && !gfl; ++i) {
			if (!fl[i] || was[i])
				continue;
			vv.clear();
			dfs1(i);
			if (eds[i].size() != vv.size()) {
				int cur = 1;
				while (cur < vv.size() && ed.count(make_pair(i, vv[cur])))
					++cur;
				for (int j = 1; j < cur; ++j)
					if (ed.count(make_pair(vv[j], vv[cur]))) {
						ans = {0, i, vv[j], vv[cur], i, n - 1};
						gfl = 1;
						break;
					}
			}
			else {
				for (int j = 0; j < eds[i].size() && !gfl; ++j)
					for (int k = j + 1; k < eds[i].size() && !gfl; ++k) {
						if (eds[i][j] != 0 && eds[i][k] != 0 && !ed.count(make_pair(eds[i][j], eds[i][k]))) {
							ans = {0, eds[i][j], i, eds[i][k], eds[i][j], n - 1};
							gfl = 1;
							break;
						}
					}
			}
		}
	}
	if (ans.empty()) {
		cout << -1 << "\n";
	}
	else {
		cout << ans.size() - 1 << "\n";
		for (int i: ans)
			cout << i + 1 << " ";
		cout << "\n";
	}
	return 0;
}