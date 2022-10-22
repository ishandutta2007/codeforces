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

int n;
vec< vec< pii > > g;
vec< int > a;

void read() {
	scanf("%d", &n);
	g.resize(n + 1);
	for(int u, v, i = 0;i < n - 1;i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(mp(v, i));
		g[v].push_back(mp(u, i));
	}
}

void dfs(int v, int par = -1, int day = -1, int edge_id = -1) {
	int cur = 1;
	if(par != -1) {
		a[edge_id] = day;
	}
	for(auto it : g[v]) {
		int to = it.first;
		if(to == par) continue;
		if(cur == day) cur++;
		dfs(to, v, cur++, it.second);
	}
}

bool solve() {
	
	read();
	
	a.resize(n - 1);

	dfs(1);

	int mx = *max_element(ALL(a));

	vec< vec< int > > way(mx + 1);

	for(int i = 0;i < n - 1;i++) way[a[i]].push_back(i);

	printf("%d\n", mx);

	for(int i = 1;i <= mx;i++) {
		printf("%d ", (int)way[i].size());
		for(auto e : way[i]) printf("%d ", e + 1);
		printf("\n");
	}

	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}