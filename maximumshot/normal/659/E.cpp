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
#include <list>
#include <stack>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

int n, m;
vec< vec< int > > g;
vec< int > col, used;

bool dfs(int v, int par = -1) {
	col[v] = 1;
	for(auto to : g[v]) {
		if(to == par) continue;
		if(col[to] == 0) {
			if(dfs(to, v)) return 1;
		}else {
			if(col[to] == 1) return 1;
		}
	}
	col[v] = 2;
	return 0;
}

void go(int v) {
	used[v] = 1;
	for(auto to : g[v]) {
		if(!used[to]) go(to);
	}
}

bool solve() {

	scanf("%d %d", &n, &m);

	g.resize(n + 1);

	for(int u, v, i = 0;i < m;i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	col.resize(n + 1);
	used.resize(n + 1);

	int res = 0;

	for(int i = 1;i <= n;i++) {
		if(used[i]) continue;
		res += !dfs(i);
		go(i);
	}

	printf("%d\n", res);

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}