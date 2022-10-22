#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

int n, m, d;
vec< vec< int > > g;
vec< char > cur;

void read() {
	scanf("%d %d %d", &n, &m, &d);
	
	g.resize(n + 1);
	cur.resize(n + 1, 0);

	for(int x, i = 1;i <= m;i++) {
		scanf("%d", &x);
		cur[x] = 1;
	}

	for(int u, v, i = 1;i <= n - 1;i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

vec< int > dp, mx;

void dfs(int v, int p = -1) {
	if(cur[v]) dp[v] = 0;
	for(int i = 0;i < (int)g[v].size();i++) {
		int to = g[v][i];
		if(to == p) continue;
		dfs(to, v);
		if(dp[to] != -1) dp[v] = max(dp[v], dp[to] + 1);
	}
}

void go(int v, int p = -1, int value = -1) {
	mx[v] = max(value, dp[v]);

	vec< int > tmp, preff, suff;
	
	for(int i = 0;i < (int)g[v].size();i++) {
		int to = g[v][i];
		if(to == p) tmp.push_back(-1);
		else tmp.push_back(dp[to] == -1?-1 : dp[to] + 1);
	}

	int sz = (int)tmp.size(), mx = -1;

	preff.resize(sz, -1);
	suff.resize(sz, -1);

	for(int i = 0;i < sz;i++) {
		mx = max(mx, tmp[i]);
		preff[i] = mx;
	}

	mx = -1;

	for(int i = sz - 1;i >= 0;i--) {
		mx = max(mx, tmp[i]);
		suff[i] = mx;
	}

	for(int i = 0;i < (int)g[v].size();i++) {
		int to = g[v][i];
		if(to == p) continue;
		mx = (cur[v]?0 : -1);
		mx = max(mx, value);
		if(i > 0) mx = max(mx, preff[i - 1]);
		if(i + 1 < sz) mx = max(mx, suff[i + 1]);
		go(to, v, (mx == -1?mx : mx + 1));
	}
}

void precalc() {
	dp.resize(n + 1, -1);
	mx.resize(n + 1, -1);
	dfs(1);
	go(1);
}

bool solve() {

	read();	
	precalc();

	int ans = 0;

	for(int i = 1;i <= n;i++) {
		if(mx[i] <= d) ans++;
	}

	printf("%d\n", ans);

	return true;
}

int main() {

	//while(solve());
	solve();    

	return 0;
}