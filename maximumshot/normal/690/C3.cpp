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

const int LOG = 21;

int n;
vec< int > p[LOG], h;

int lca(int u, int v) {
	if(h[u] < h[v]) swap(u, v);
	for(int i = LOG - 1;i >= 0;i--) {
		int pu = p[i][u];
		if(pu == -1 || h[pu] < h[v]) continue;
		u = pu;
	}
	for(int i = LOG - 1;i >= 0;i--) {
		int pu, pv;
		pu = p[i][u];
		pv = p[i][v];
		if(pu == -1 || pv == -1 || pu == pv) continue;
		u = pu;
		v = pv;
	}
	if(u != v) u = p[0][u];
	return u;
}

int dist(int u, int v) {
	return h[u] + h[v] - 2 * h[lca(u, v)];
}

bool solve() {
	
	scanf("%d", &n);

	h.resize(n + 1);
	for(int i = 0;i < LOG;i++) p[i].resize(n + 1, -1);
	
	for(int i = 2;i <= n;i++) scanf("%d", &p[0][i]), h[i] = h[p[0][i]] + 1;

	for(int i = 1;i < LOG;i++) {
		for(int j = 1;j <= n;j++) {
			int x = p[i - 1][j];
			if(x != -1) p[i][j] = p[i - 1][x];
		}
	}

	int f, s, d;

	f = s = 1;
	d = 0;

	for(int t, i = 2;i <= n;i++) {
		t = dist(i, f);
		if(t > d) {
			d = t;
			s = i;
		}
		t = dist(i, s);
		if(t > d) {
			d = t;
			f = i;
		}
		printf("%d ", d);
	}

	printf("\n");

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}