#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

template<typename T>
struct dinic {
	const T INF = 1e9;
	const int INF1 = 1e9;
	struct edge {
		int a, b;
		T f, c;
		int n;
	};
	int s, t;
	vector<edge> ed;
	int n;
	vector<vector<int> > eds;
	vector<T> dd;
	vector<int> pp;
	vector<int> inCut;
	dinic(int N, int S, int TT) {
		n = N;
		s = S;
		t = TT;
		eds.clear();
		dd.clear();
		pp.clear();
		ed.clear();
		eds.resize(n);
		dd.resize(n);
		pp.resize(n);
		inCut.clear();
	}
	void make_edge(int a, int b, int c, int n) {
		edge x;
		x.n = n;
		x.a = a;
		x.b = b;
		x.f = 0;
		x.c = c;
		eds[a].push_back(ed.size());
		eds[b].push_back(ed.size() + 1);
		ed.push_back(x);
		x.c = 0;
		swap(x.a, x.b);
		x.n = -1;
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
			if (dd[t] == INF1)
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
};

int n, m, s, t;
int ff[10001];
int cc[10001];

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	--s, --t;
	dinic<int> dn1(n, s, t);
	dinic<int> dn2(n + 2, n, n + 1);
	dn2.make_edge(t, s, 10010, -1);
	int c2 = 0;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a, --b;
		if (c == 0) {
			dn1.make_edge(a, b, 10010, -1);
		}
		else {
			dn1.make_edge(a, b, 1, i);
			dn1.make_edge(b, a, 10010, -1);
			dn2.make_edge(n, b, 1, -1);
			dn2.make_edge(a, n + 1, 1, -1);
			dn2.make_edge(a, b, 10010, i);
			++c2;
		}
	}
	for (int i = 0; i < m; ++i)
		cc[i] = 1;
	int ans = dn1.flow();
	dn2.flow();
	for (int i = 0; i < dn2.ed.size(); ++i) {
		int k = dn2.ed[i].n;
		if (k == -1)
			continue;
		ff[k] = dn2.ed[i].f + 1;
		cc[k] = dn2.ed[i].f + 2;
	}
	dn1.markCut();
	for (int i = 0; i < dn1.ed.size(); ++i) {
		int k = dn1.ed[i].n;
		if (k == -1)
			continue;
		if (dn1.inCut[i])
			--cc[k];
	}
	cout << ans << "\n";
	for (int i = 0; i < m; ++i)
		cout << ff[i] << " " << cc[i] << "\n";
    return 0;
}