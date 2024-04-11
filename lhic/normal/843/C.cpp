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
const int MAXN = 210000;

int was[MAXN];
vector<int> eds[MAXN];
int sz[MAXN];
int p[MAXN];
int n;

vector<tuple<int, int, int> > an;

void ask(int a, int b, int c) {
	an.push_back(make_tuple(a, b, c));
}

void dfs1(int v) {
	was[v] = 1;
	sz[v] = 1;
	for (int u: eds[v]) {
		if (!was[u]) {
			p[u] = v;
			dfs1(u);
			sz[v] += sz[u];
		}
	}
}

vector<int> st;
vector<vector<int> > gg;

void dfs2(int v) {
	was[v] = 1;
	st.push_back(v);
	for (int u: eds[v]) {
		if (!was[u]) {
			p[u] = v;
			dfs2(u);
		}
	}
}


void solve1(int x) {
	memset(was, 0, sizeof(was));
	was[x] = 1;
	for (int u: eds[x]) {
		if (was[u])
			continue;
		st.clear();
		dfs2(u);
		int cur = x;
		int nx = u;
		for (int i = st.size() - 1; i >= 0; --i) {
			ask(cur, nx, st[i]);
			cur = st[i];
			nx = p[cur];
		}
		gg.push_back(st);
	}
	for (int i = 0; i < gg.size(); ++i) {
		if (gg[i].size() <= 2)
			continue;
		int c = gg[i][1];
		int u = gg[i][2];
		for (int j = 3; j < gg[i].size(); ++j) {
			ask(gg[i][j], u, c);
			u = gg[i][j];
		}
		ask(x, u, c);
	}
}

void solve2(int x, int y) {
	memset(was, 0, sizeof(was));
	was[x] = 1;
	was[y] = 1;
	for (int u: eds[x]) {
		if (was[u])
			continue;
		st.clear();
		dfs2(u);
		int cur = x;
		int nx = u;
		for (int i = st.size() - 1; i >= 0; --i) {
			ask(cur, nx, st[i]);
			cur = st[i];
			nx = p[cur];
		}
		gg.push_back(st);
	}
	for (int i = 0; i < gg.size(); ++i) {
		if (gg[i].size() <= 2)
			continue;
		int c = gg[i][1];
		int u = gg[i][2];
		for (int j = 3; j < gg[i].size(); ++j) {
			ask(gg[i][j], u, c);
			u = gg[i][j];
		}
		ask(x, u, c);
	}
	gg.clear();
	x = y;
	for (int u: eds[x]) {
		if (was[u])
			continue;
		st.clear();
		dfs2(u);
		int cur = x;
		int nx = u;
		for (int i = st.size() - 1; i >= 0; --i) {
			ask(cur, nx, st[i]);
			cur = st[i];
			nx = p[cur];
		}
		gg.push_back(st);
	}
	for (int i = 0; i < gg.size(); ++i) {
		if (gg[i].size() <= 2)
			continue;
		int c = gg[i][1];
		int u = gg[i][2];
		for (int j = 3; j < gg[i].size(); ++j) {
			ask(gg[i][j], u, c);
			u = gg[i][j];
		}
		ask(x, u, c);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(0);
	int mn = -1;
	for (int i = 0; i < n; ++i) {
		if (sz[i] * 2 >= n && (mn == -1 || sz[i] < sz[mn]))
			mn = i;
	}
	if (sz[mn] * 2 == n)
		solve2(mn, p[mn]);
	else
		solve1(mn);
	printf("%d\n", (int)an.size());
	for (auto x: an) {
		int a, b, c;
		tie(a, b, c) = x;
		++a, ++b, ++c;
		printf("%d %d %d\n", a, b, c);
	}
    return 0;
}