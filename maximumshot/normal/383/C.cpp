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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

struct fen {
	int n;
	vec< int > f;
	// [0 .. n - 1]
	
	fen() {
		n = 0;
		f.clear();
	}

	fen(int nn) {
		n = nn;
		f.resize(n);
	}

	void upd(int l, int r, int value) {
		if(l > r) return;
		for(int i = l;i < n;i = i | (i + 1)) f[i] += value;
		for(int i = r + 1;i < n;i = i | (i + 1)) f[i] -= value;
	}

	int get(int p) {
		int ans = 0;
		for(int i = p;i >= 0;i = (i & (i + 1)) - 1) ans += f[i];
		return ans;
	}
};

int n, m;
vec< int > a, h;
vec< vec< int > > g;

void read() {
	scanf("%d %d", &n, &m);
	a.resize(n + 1);
	g.resize(n + 1);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int u, v, i = 0;i < n - 1;i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}	
}

vec< int > euler[2], l, r;
int timer = 0;

void dfs(int v, int par = -1, int H = 0) {
	h[v] = H;
	euler[H].push_back(timer++);
	l[v] = (int)euler[H].size() - 1;
	for(auto to : g[v]) {
		if(to != par) dfs(to, v, H ^ 1);
	}
	euler[H].push_back(timer++);
	r[v] = (int)euler[H].size() - 1;
}

bool solve() {

	read();
	
	l.resize(n + 1);
	r.resize(n + 1);
	h.resize(n + 1);
	dfs(1);

	fen f[2] = {fen((int)euler[0].size()), fen((int)euler[1].size())};

	for(int ty, x, value, i = 0;i < m;i++) {
		scanf("%d %d", &ty, &x);
		if(ty == 1) {
			scanf("%d", &value);
			f[h[x]].upd(l[x], r[x], value);
			int L, R;
			L = lower_bound(ALL(euler[h[x] ^ 1]), euler[h[x]][l[x]]) - euler[h[x] ^ 1].begin();
			R = upper_bound(ALL(euler[h[x] ^ 1]), euler[h[x]][r[x]]) - euler[h[x] ^ 1].begin() - 1;
			f[h[x] ^ 1].upd(L, R, -value);
		}else printf("%d\n", a[x] + f[h[x]].get(l[x]));
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}