#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
#include <math.h>

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

int n;
vec< int > p, c;
vec< vec< int > > g;
vec< double > ans;

void dfs(int v) {
	c[v] = 1;
	for(auto to : g[v]) {
		dfs(to);
		c[v] += c[to];
	}
}

void go(int v) {
	for(auto to : g[v]) {
		ans[to] = ans[v] + 1.0 + double(c[v] - 1 - c[to]) / 2.0;
		go(to);
	}
}

bool solve() {

	scanf("%d", &n);

	p.resize(n + 1);
	g.resize(n + 1);
	ans.resize(n + 1);
	c.resize(n + 1);

	for(int i = 2;i <= n;i++) scanf("%d", &p[i]), g[p[i]].push_back(i);

	dfs(1);

	ans[1] = 1.0;

	go(1);

	for(int i = 1;i <= n;i++) {
		printf("%.7lf ", ans[i]);
	}

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}