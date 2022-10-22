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

#include <conio.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 3;

int n, timer = 1;
vec< vec< int > > g; 	
vec< int > in, out, t, delt, par;

void read() {
	scanf("%d", &n);
	g.resize(n + 1);
	for(int u, v, i = 0;i < n - 1;i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void dfs(int v, int p = -1) {
	par[v] = p;
	in[v] = timer++;
	for(int i = 0;i < (int)g[v].size();i++) {
		int to = g[v][i];
		if(to != p) dfs(to, v);
	}
	out[v] = timer++;
}

void pushup(int v) {
	delt[v] = 0;
	t[v] = min(t[v << 1], t[v << 1 | 1]);
}

void precalc() {
	in.resize(n + 1);
	out.resize(n + 1);
	par.resize(n + 1, -1);
	dfs(1);
	t.resize(8 * n, 0);
	delt.resize(8 * n, 0);
}

void push(int  v) {
	if(delt[v]) {
		delt[v << 1] = delt[v << 1 | 1] = 1;
		t[v << 1] = t[v << 1 | 1] = 1;
		delt[v] = 0;
	}
}

int get(int v, int tl, int tr, int l, int r) {
	if(l <= tl && tr <= r) return t[v];
	else {
		int tm = (tl + tr) >> 1, ans = 1;
		push(v);
		if(l <= tm) ans &= get(v << 1, tl, tm, l, r);
		if(r > tm) ans &= get(v << 1 | 1, tm + 1, tr, l, r);
		pushup(v);
		return ans;
	}
}

void update(int v, int tl, int tr, int l, int r, int x) {
	if(l <= tl && tr <= r) {
		t[v] = delt[v] = x;
	}else {
		int tm = (tl + tr) >> 1;
		push(v);
		if(l <= tm) update(v << 1, tl, tm, l, r, x);
		if(r > tm) update(v << 1 | 1, tm + 1, tr, l, r, x);
		pushup(v);
	}
}

bool solve() 
{
	read();
	precalc();

	int q, ty, v;
	scanf("%d", &q);

	while(q--) {
		scanf("%d %d", &ty, &v);
		if(ty == 1) {
			int s = get(1, 1, 2 * n, in[v], out[v]);
			update(1, 1, 2 * n, in[v], out[v], 1);
			if(s == 0 && par[v] != -1) update(1, 1, 2 * n, in[par[v]], in[par[v]], 0);
		}else if(ty == 2) {
			update(1, 1, 2 * n, in[v], in[v], 0);
		}else {
			printf("%d\n", get(1, 1, 2 * n, in[v], out[v]));
		}
	}

	return true;
}

int main() {

	//while(solve());
	solve();    

	return 0;
}