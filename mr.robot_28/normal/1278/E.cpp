#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef pair<int, int> pt;

const int N = 500 * 1000 + 13;

int n;
vector<int> g[N], vs[N];
pt segs[N];

void dfs(int v, int p = -1) {
	int sum = 0;
	int bst = -1;
	for (auto to : g[v]) if (to != p) {
		dfs(to, v);
		sum += 2 * sz(vs[to]);
		if (bst == -1 || sz(vs[to]) > sz(vs[bst]))
			bst = to;
	}
	
	if (bst == -1) {
		vs[v].pb(v);
		segs[v] = mp(1, 2);
		return;
	}
	
	swap(vs[v], vs[bst]);
	int lst = segs[bst].y;
	
	sum -= 2 * sz(vs[v]);
	sum += 1;
	segs[bst].y += sum;
	
	for (auto to : g[v]) if (to != p && to != bst) {
		int add = lst - 1;
		for (auto u : vs[to]) {
			segs[u].x += add;
			segs[u].y += add;
			vs[v].pb(u);
		}
		lst = segs[to].y;
		sum -= 2 * sz(vs[to]);
		segs[to].y += sum;
		vs[to].clear();
	}
	
	vs[v].pb(v);
	segs[v] = mp(lst, segs[bst].y + 1);
}	

int main() {
	scanf("%d", &n);
	forn(i, n - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	dfs(0);
	
	for (int i = 0; i < n; i++)
		printf("%d %d\n", segs[i].x, segs[i].y);
	
	return 0;
}