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



template<typename T>
struct Dinic {
	const T INF = 1e9;
	const int INF1 = 1e9;
	struct edge {
		int a, b;
		T f, c;
	};
	int s, t;
	vector<edge> ed;
	int n;
	vector<vector<int> > eds;
	vector<T> dd;
	vector<int> pp;
	vector<int> inCut;
	Dinic(int N, int S, int TT) {
		n = N, s = S, t = TT;
		eds.clear();
		dd.clear();
		pp.clear();
		ed.clear();
		eds.resize(n);
		dd.resize(n);
		pp.resize(n);
		inCut.clear();
	}
	void add_edge(int a, int b, T c) {
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
	T dfs(int v, T fl) {
		if (v == t)
			return fl;
		if (dd[v] == dd[t])
			return 0;
		T sum = 0;
		for (; pp[v] < (int)eds[v].size(); ++pp[v]) {
			int e = eds[v][pp[v]];
			int u = ed[e].b;
			T fr = ed[e].c - ed[e].f;
			if (fr == 0 || dd[u] != dd[v] + 1 || pp[u] == (int)eds[u].size())
				continue;
			fr = dfs(u, min(fl, fr));
			ed[e].f += fr;
			ed[e ^ 1].f -= fr;
			sum += fr;
			fl -= fr;
			if (fl == 0)
				break;
		}
		return sum;
	}
	T flow() {
		T sum = 0;
		T lst = 0;
		do {
			lst = 0;
			fill(dd.begin(), dd.end(), INF1);
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
	void dfs1(int s) {
		pp[s] = 1;
		for (int e: eds[s]) {
			if (ed[e].c != ed[e].f && !pp[ed[e].b])
				dfs1(ed[e].b);
		}
	}
	void markCut() {
		inCut.resize(ed.size());
		fill(pp.begin(), pp.end(), 0);
		dfs1(s);
		for (int i = 0; i < ed.size(); ++i)
			if (pp[ed[i].a] && !pp[ed[i].b])
				inCut[i] = 1;
			else
				inCut[i] = 0;
	}
	vector<int> st;
	int dfs2(int v) {
		st.push_back(v);
		if (v == t)
			return 1;
		for (int e: eds[v]) {
			if (ed[e].f > 0) {
				--ed[e].f;
				dfs2(ed[e].b);
				return 1;
			}
		}
		return 0;
	}
	vector<vector<int>> dec() {
		vector<vector<int>> now;
		while (true) {
			st.clear();
			if (dfs2(s)) {
				now.push_back(st);
			}
			else
				break;
		}
		return now;
	}
};

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
const int MAXN = 5100;

int n, m;
vector<int> go[MAXN];
int l[MAXN];
int r[MAXN];
int tp[MAXN];
int cc;
int gg[MAXN * 4];

void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		gg[v] = n + tl;
		return;
	}
	int m = (tl + tr) >> 1;
	gg[v] = cc++;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
}
int s, t;

int fl[MAXN];
void build2(int v, int tl, int tr, Dinic<int> &cur) {
	if (tl + 1 == tr) {
		if (!fl[tl]) {
			cur.add_edge(gg[v], t, 1);
		}
		return;
	}
	int m = (tl + tr) >> 1;
	cur.add_edge(gg[v], gg[v * 2 + 1], MAXN);
	cur.add_edge(gg[v], gg[v * 2 + 2], MAXN);
	build2(v * 2 + 1, tl, m, cur);
	build2(v * 2 + 2, m, tr, cur);
}

void add(int v, int tl, int tr, int l, int r, int k, Dinic<int> &cur) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		cur.add_edge(k, gg[v], 1);
		return;
	}
	int m = (tl + tr) >> 1;
	add(v * 2 + 1, tl, m, l, r, k, cur);
	add(v * 2 + 2, m, tr, l, r, k, cur);
}
int kl[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	cc = n + m;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		tp[i] = t;
		if (t == 0) {
			int k;
			cin >> k;
			for (int j = 0; j < k; ++j) {
				int x;
				cin >> x;
				--x;
				go[i].push_back(x);
			}
		}
		else if (t == 1) {
			cin >> l[i] >> r[i];
			--l[i];
		}
		else {
			for (int j = 0; j < 3; ++j) {
				int x;
				cin >> x;
				--x;
				go[i].push_back(x);
				fl[x] = 1;
			}
			++cc;
		}
	}
	build(0, 0, m);
	s = cc;
	t = cc + 1;
	Dinic<int> cur(cc + 2, s, t);
	build2(0, 0, m, cur);
	int nw = n + m;
	for (int i = 0; i < n; ++i) {
		if (tp[i] == 0) {
			cur.add_edge(s, i, 1);
			for (int j: go[i])
				cur.add_edge(i, n + j, 1);
		}
		else if (tp[i] == 1) {
			cur.add_edge(s, i, 1);
			add(0, 0, m, l[i], r[i], i, cur);
		}
		else {
			cur.add_edge(nw, t, 1);
			for (int j = 0; j < 3; ++j)
				cur.add_edge(n + go[i][j], nw, 1);
			++nw;
		}
	}
	cur.flow();
	vector<vector<int>> tmp = cur.dec();
	vector<pair<int, int>> ans;
	for (int i = 0; i < tmp.size(); ++i) {
		int x = tmp[i][1];
		int y = tmp[i][tmp[i].size() - 2] - n;
		if (y >= m)
			y = tmp[i][tmp[i].size() - 3] - n;
		ans.emplace_back(x, y);
		kl[y] = 1;
	}
	for (int i = 0; i < n; ++i) {
		if (tp[i] == 2) {
			int fr = 2;
			for (int j: go[i])
				if (!kl[j] && fr)
					ans.emplace_back(i, j), --fr;
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
	return 0;
}