#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sit set<int>::iterator

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 3e5 + 10;
int n, ns;
int f[N], l[N], r[N], dfn[N], id[N], dfc = 0;
vector<int> g[N];
set<int> s;
void dfs(int u) {
	dfn[u] = l[u] = ++dfc;
	id[dfc] = u;
	for(int &v: g[u]) dfs(v);
	r[u] = dfc;
	return;
}

void calc(int u) {
	sit it = s.lower_bound(dfn[u]);
	int del = -1, add = -1;
	if(it != s.begin()) {
		it--;
		int a = id[*it];
		if(l[a] <= dfn[u] && dfn[u] <= r[a]) {
			del = a;
		}
	}
	it = s.upper_bound(dfn[u]);
	if(it == s.end()) add = u;
	else {
		int a = id[*it];
		if(dfn[a] < l[u] || r[u] < dfn[a]) add = u;
	}
	if(del != -1) s.erase(dfn[del]);
	if(add != -1) s.insert(dfn[add]);
	ns = max(ns, (int) s.size());
	for(int &v : g[u]) calc(v);
	if(add != -1) s.erase(dfn[add]);
	if(del != -1) s.insert(dfn[del]);
	return;
}

void work() {
	scanf("%d", &n);
	dfc = 0;
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 2; i <= n; i++) scanf("%d", &f[i]);
	for(int i = 2, x; i <= n; i++) {
		scanf("%d", &x);
		g[x].push_back(i); 
	}
	dfs(1);
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 2; i <= n; i++) g[f[i]].push_back(i);
	ns = 0;
	s.clear();
	calc(1);
	printf("%d\n", ns);
	return;
}

int main() {
	int T;
	for(scanf("%d", &T); T--; work());
	return 0;
}