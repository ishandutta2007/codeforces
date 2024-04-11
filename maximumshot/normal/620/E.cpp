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
typedef pair< ll, ll > pll;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

int n, m;
vec< int > color;
vec< vec< int > > g;

void read() {
	scanf("%d %d", &n, &m);
	color.resize(n + 1);
	g.resize(n + 1);
	for(int i = 1;i <= n;i++) scanf("%d", &color[i]);
	for(int u, v, i = 0;i < n - 1;i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

vec< int > tin, tout;
int timer = 1;

void dfs(int v, int par = -1) {
	tin[v] = timer++;
	for(auto to : g[v]) {
		if(to != par) dfs(to, v);
	}
	tout[v] = timer++;
}

vec< ll > t; 
vec< ll > delt;

void push(int v) {
	if(delt[v]) {
		delt[v << 1] = delt[v << 1 | 1] = delt[v];
		t[v << 1] = t[v << 1 | 1] = delt[v];
		delt[v] = 0;
	}
}

void up(int v) {
	delt[v] = 0;
	t[v] = t[v << 1] | t[v << 1 | 1];
}

void upd(int v, int tl, int tr, int l, int r, int c) {
	if(l <= tl && tr <= r) {
		t[v] = delt[v] = (1ll << c);
	}else {
		int tm = (tl + tr) / 2;
		push(v);
		if(l <= tm) upd(v << 1, tl, tm, l, r, c);
		if(r > tm) upd(v << 1 | 1, tm + 1, tr, l, r, c);
		up(v);
	}
}

ll get(int v, int tl, int tr, int l, int r) {
	if(l <= tl && tr <= r) return t[v];
	else {
		int tm = (tl + tr) / 2;
		push(v);
		ll ans = 0;
		if(l <= tm) ans |= get(v << 1, tl, tm, l, r);
		if(r > tm) ans |= get(v << 1 | 1, tm + 1, tr, l, r);
		up(v);
		return ans;
	}
}

bool solve() {
	
	read();

	tin.resize(n + 1);
	tout.resize(n + 1);
	dfs(1);

	delt.resize(8 * n + 1);
	t.resize(8 * n + 1);

	for(int i = 1;i <= n;i++) {
		upd(1, 1, 2 * n, tin[i], tin[i], color[i]);
		upd(1, 1, 2 * n, tout[i], tout[i], color[i]);
	}

	for(int ty, v, c;m;m--) {
		scanf("%d %d", &ty, &v);
		if(ty == 1) {
			scanf("%d", &c);
			upd(1, 1, 2 * n, tin[v], tout[v], c);
		}else {
			ll ans = get(1, 1, 2 * n, tin[v], tout[v]);
			int cnt = 0;
			for(int j = 1;j <= 60;j++) {
				if((1ll << j) & ans) cnt++;
			}
			printf("%d\n", cnt);
		}
	}

	return true;
}

int main() {

	//while(solve());
	solve();

	return 0;
}