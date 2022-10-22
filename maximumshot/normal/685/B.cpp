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

const int LOG = 21;

int n, Q;
vec< int > p[LOG];
vec< vec< int > > g;

void read() {
	scanf("%d %d", &n, &Q);

	for(int i = 0;i < LOG;i++) p[i].resize(n + 1);
	g.resize(n + 1);
	
	for(int i = 2;i <= n;i++) {
		scanf("%d", &p[0][i]);	
		g[p[0][i]].push_back(i);
	}

	for(int i = 1;i < LOG;i++) {
		for(int j = 1;j <= n;j++) {
			int x = p[i - 1][j];
			if(x) p[i][j] = p[i - 1][x];
		}
	}
}

vec< int > mx, s;

void dfs(int v) {
	s[v] = 1;
	mx[v] = 0;
	for(auto to : g[v]) {
		dfs(to);
		mx[v] = max(mx[v], s[to]);
		s[v] += s[to];
	}
}

int first(int v) {
	int MX = mx[v], tmp = v;

	for(int i = LOG - 1;i >= 0;i--) {
		int to = p[i][v];
		if(to == 0 || MX <= s[to] / 2) continue;
		v = to;
	}

	if(v == tmp) v = p[0][v];

	while(v && MX > s[v] / 2) v = p[0][v];

	return v;
}

void precalc() {
	mx.resize(n + 1);
	s.resize(n + 1);
	dfs(1);
}

vec< int > res, lnk;

int link(int v) {
	if(v == 0) return 0;
	if(res[lnk[v]]) lnk[v] = link(lnk[v]);
	return lnk[v];
}

bool solve() {
	
	read();
	precalc();

	res.resize(n + 1);
	lnk.resize(n + 1);

	for(int i = 1;i <= n;i++) lnk[i] = p[0][i];

	for(int u = 1;u <= n;u++) {
		if(mx[u] <= s[u] / 2) res[u] = u;
		int v = first(u);
		while(v && s[v] - s[u] <= s[v] / 2) {
			res[v] = u;
			v = link(v);
		}
	}

	for(int v, iter = 0;iter < Q;iter++) {
		scanf("%d", &v);
		printf("%d\n", res[v]);
	}

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}