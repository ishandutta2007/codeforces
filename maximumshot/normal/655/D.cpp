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

bool bp(vec< int > & a, int x) {
	if(a.empty()) return 0;
	int p = lower_bound(ALL(a), x) - a.begin();
	if(0 <= 0 && p < (int)a.size() && a[p] == x) return 1;
	else return 0;
}

int n, m;
vec< pii > edge;
vec< vec< int > > g; 
vec< int > tops;
vec< char > used;

void dfs(int v) {
	used[v] = 1;
	for(auto to : g[v]) {
		if(!used[to]) dfs(to);
	}
	tops.push_back(v);
}

bool check(int k) {
	for(int i = 1;i <= n;i++) {
		g[i].clear();
		used[i] = 0;
	}

	for(int i = 0;i <= k;i++) {
		g[edge[i].first].push_back(edge[i].second);
	}

	for(int i = 1;i <= n;i++) {
		sort(ALL(g[i]));
	}

	tops.clear();

	for(int i = 1;i <= n;i++) {
		if(!used[i]) dfs(i);
	}

	reverse(ALL(tops));
	
	for(int i = 0;i + 1 < n;i++) {
		int u, v;
		u = tops[i];
		v = tops[i + 1];
		// u -> v
		if(!bp(g[u], v)) return 0;
	}

	return 1;
}

bool solve() {

	scanf("%d %d", &n, &m);

	g.resize(n + 1);
	used.resize(n + 1);

	edge.resize(m);
	for(int i = 0;i < m;i++) {
		scanf("%d %d", &edge[i].first, &edge[i].second);
	}

	int bl, br, bm;
	bl = 0;
	br = m - 1;

	while(br - bl > 1) {
		bm = (bl + br) / 2;
		if(check(bm)) br = bm;
		else bl = bm + 1;
	}

	if(check(bl)) printf("%d\n", bl + 1);
	else if(check(br)) printf("%d\n", br + 1);
	else printf("-1\n");

	return true;
}

int main() {

	//while(solve());	
	solve();
	
	return 0;
}