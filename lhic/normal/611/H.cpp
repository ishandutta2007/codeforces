#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef double ld;

using namespace std;

const int MAXN = 220000;

void ex() {
	cout << -1 << "\n";
	exit(0);
}

int was[10];
int mn[10];
int m;
int n;

vector<int> eee[10];
int ed[10][10];
int cnt[10];

void dfs(int v) {
	was[v] = 1;
	for (int i = 0; i < (int)eee[v].size(); ++i) {
		int u = eee[v][i];
		if (!was[u])
			dfs(u);
	}
}


struct dinic {
	const int INF = 1e9;
	struct edge {
		int a, b;
		int f, c;
	};
	int s, t;
	vector<edge> ed;
	int n;
	vector<vector<int> > eds;
	vector<int> dd;
	vector<int> pp;
	dinic(int n) : n(n) {
		eds.resize(n);
		dd.resize(n);
		pp.resize(n);
	}
	void make_edge(int a, int b, int c) {
		edge x;
		x.a = a;
		x.b = b;
		x.f = 0;
		x.c = c;
		eds[a].push_back(ed.size());
		eds[b].push_back(ed.size() + 1);
		ed.push_back(x);
		x.c = 0;
		swap(x.a, x.b);
		ed.push_back(x);
	}
	int dfs(int v, int fl) {
		if (v == t)
			return fl;
		if (dd[v] == dd[t])
			return 0;
		int sum = 0;
		while (pp[v] < (int)eds[v].size() && fl) {
			int x = eds[v][pp[v]];
			int u = ed[x].b;
			int fr = ed[x].c - ed[x].f;
			if (fr == 0 || dd[u] != dd[v] + 1 || pp[u] == (int)eds[u].size()) {
				++pp[v];
				continue;
			}
			fr = dfs(u, min(fl, fr));
			ed[x].f += fr;
			ed[x ^ 1].f -= fr;
			sum += fr;
			fl -= fr;
			if (fl > 0)
				++pp[v];
		}
		return sum;
	}
	int flow() {
		int sum = 0;
		int lst = 0;
		do {
			lst = 0;
			fill(dd.begin(), dd.end(), INF);
			dd[s] = 0;
			queue<int> qu;
			qu.push(s);
			while (!qu.empty()) {
				int x = qu.front();
				qu.pop();
				for (int i = 0; i < (int)eds[x].size(); ++i) {
					if (ed[eds[x][i]].f < ed[eds[x][i]].c) {
						int u = ed[eds[x][i]].b;
						if (dd[u] > dd[x] + 1)
							dd[u] = dd[x] + 1, qu.push(u);
					}
				}
			}
			if (dd[t] == INF)
				break;
			fill(pp.begin(), pp.end(), 0);
			lst = dfs(s, INF);
			sum += lst;
		} while (lst);
		return sum;
	}
};



vector<pair<int, int> > ans;
vector<pair<int, int> > go;

void solve() {
	int s = 0;
	int t = m + go.size() + 1;
	dinic dd(t + 1);
	dd.s = 0;
	dd.t = m + go.size() + 1;
	int nd = 0;
	for (int i = 1; i <= m; ++i)
		dd.make_edge(s, i, cnt[i] - 1), nd += cnt[i] - 1;
	for (int i = 0; i < (int)go.size(); ++i) {
		int x = i + 1 + m;
		int a = go[i].first;
		int b = go[i].second;
		dd.make_edge(x, t, ed[a][b]);
		dd.make_edge(a, x, MAXN);
		dd.make_edge(b, x, MAXN);
	}
	int gt = dd.flow();
	if (gt != nd)
		return;
	for (auto x: dd.ed) {
		int a = x.a;
		int b = x.b;
		int c = x.c;
		if (c != MAXN)
			continue;
		int f = x.f;
		b -= m + 1;
		b = go[b].first ^ go[b].second ^ a;
		while (f) {
			--cnt[a];
			ans.push_back(make_pair(mn[b], mn[a] + cnt[a]));
			--f;
		}
	}
	for (auto x: ans)
		printf("%d %d\n", x.first, x.second);
	exit(0);
}


char s[20];

int main() {
//	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf(" %s", s);
		a = strlen(s);
		scanf(" %s", s);
		b = strlen(s);
		if (a == b)
			++ed[a][b];
		else
			++ed[a][b], ++ed[b][a];
	}
	for (int i = 1; i <= 6; ++i)
		mn[i] = MAXN;
	for (int i = 1; i <= n; ++i) {
		int cc = 0;
		int x = i;
		while (x)
			++cc, x /= 10;
		++cnt[cc];
		mn[cc] = min(mn[cc], i);
	}

	for (int i = 1; i <= 6; ++i) {
		if (cnt[i] == 0)
			break;
		m = i;
		if (ed[i][i] >= cnt[i])
			ex();
		while (ed[i][i]) {
			--ed[i][i];
			--cnt[i];
			ans.push_back(make_pair(mn[i], mn[i] + cnt[i]));
		}
	}
	for (int i = 1; i <= m; ++i)
		for (int j = i + 1; j <= m; ++j)
			go.push_back(make_pair(i, j));

	for (int msk = 0; msk < (1 << (int)(go.size())); ++msk) {
		if (__builtin_popcount(msk) != m - 1)
			continue;
		for (int i = 1; i <= m; ++i)
			eee[i].clear(), was[i] = 0;
		for (int i = 0; i < (int)go.size(); ++i) {
			if (msk & (1 << i))
				eee[go[i].first].push_back(go[i].second), eee[go[i].second].push_back(go[i].first);
		}
		dfs(1);
		int fl = 1;
		for (int i = 1; i <= m; ++i)
			fl &= was[i];
		if (!fl)
			continue;
		for (int i = 0; i < (int)go.size(); ++i)
			if (msk & (1 << i)) {
				int a = go[i].first, b = go[i].second;
				--ed[a][b];
				--ed[b][a];
				if (ed[a][b] < 0)
					fl = 0;
				ans.push_back(make_pair(mn[a], mn[b]));
			}
		if (fl)
			solve();
		for (int i = 0; i < (int)go.size(); ++i)
			if (msk & (1 << i)) {
				int a = go[i].first, b = go[i].second;
				++ed[a][b];
				++ed[b][a];
				ans.pop_back();
			}
	}
	ex();

	return 0;
}