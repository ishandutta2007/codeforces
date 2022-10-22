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
#include <math.h>
#include <unordered_map>
#include <array>
#include <complex>

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

int n, m;
vec< vec< int > > g;
vec< int > a;

void dfs(int v, int x = 1) {
	if(a[v] > 0) {
		if(a[v] != x) {
			printf("-1\n");
			exit(0);
		}
		return;
	}else a[v] = x;
	for(int to : g[v]) {
		dfs(to, 3 - x);
	}
}

bool solve() {

	scanf("%d %d", &n, &m);
	
	g.resize(n + 1);

	for(int u, v, i = 1;i <= m;i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	a.resize(n + 1);

	for(int v = 1;v <= n;v++) {
		if(a[v] == 0) dfs(v);
	}

	vec< int > ans[2];

	for(int v = 1;v <= n;v++) ans[a[v] - 1].push_back(v);

	for(int i = 0;i < 2;i++) {
		printf("%d\n", (int)ans[i].size());
		for(auto j : ans[i]) printf("%d ", j);
		printf("\n");
	}

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}