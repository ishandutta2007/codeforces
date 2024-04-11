#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

int n, m, k;
vec< vec< int > > g;

vec< char > vis;
vec< int > lnk;

int link(int v) {
	if(lnk[v] <= n && vis[lnk[v]]) lnk[v] = link(lnk[v]);
	return lnk[v];
}

void dfs(int v) {
	vis[v] = 1;
	for(int cur = 0, to = 1;to <= n;to = link(to)) {
		if(vis[to]) continue;
		while(cur < (int)g[v].size() && g[v][cur] < to) cur++;
		if(cur < (int)g[v].size() && g[v][cur] == to) continue;
		dfs(to);
	} 
}

bool solve() {
	
	scanf("%d %d %d", &n, &m, &k);

	g.resize(n + 1);

	int deg = n - 1;

	for(int u, v, i = 0;i < m;i++) {
		scanf("%d %d", &u, &v);
		if(u == 1 || v == 1) deg--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	if(deg < k) {
		printf("impossible\n");
		return true;
	}

	vis.resize(n + 1);
	lnk.resize(n + 1);

	for(int i = 1;i <= n;i++) {
		lnk[i] = i + 1;
		vis[i] = 0;
		sort(ALL(g[i]));
	}

	dfs(1);

	for(int i = 1;i <= n;i++) {
		if(!vis[i]) {
			printf("impossible\n");
			return true;
		}
	}

	for(int i = 1;i <= n;i++) {
		lnk[i] = i + 1;
		vis[i] = 0;
	}

	vis[1] = 1;
	
	int ob = 0;

	for(int v = 2;v <= n;v = link(v)) {
		if(vis[v]) continue;
		ob++;
		dfs(v);
	}

	if(ob <= k) {
		printf("possible\n");
	}else {
		printf("impossible\n");
	}

	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}