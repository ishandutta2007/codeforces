#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>
#include <time.h>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int n, m;
vector <int> E[200020];
int dep[200020], down[200020];
int son[200020], head[200020], par[200020];

void pdfs(int x) {
	down[x] = 1;
	son[x] = -1;
	for(int e : E[x]) {
		dep[e] = dep[x] + 1;
		par[e] = x;
		pdfs(e);
		if(son[x] == -1 || down[son[x]] < down[e]) son[x] = e;
		down[x] += down[e];
	}
}

int ST[200020], cs, rev[200020];
void dfs(int x, int p) {
	ST[x] = ++cs; rev[cs] = x;
	head[x] = p;
	if(son[x] != -1) dfs(son[x], p);
	for(int e : E[x]) if(e != son[x]) {
		dfs(e, e);
	}
}
int get_lca(int x, int y) {
	while(head[x] != head[y]) {
		if(dep[head[x]] < dep[head[y]]) swap(x, y);
		x = par[head[x]];
	}
	return dep[x] > dep[y] ? y : x;
}

ll T[1<<19]; const int ADD = 1<<18;

void update_t(int x, ll v) {
	x += ADD; T[x] += v; x >>= 1;
	while(x) T[x] = T[x<<1] + T[x<<1|1], x >>= 1;
}

ll read_t(int l, int r) {
	if(l > r) swap(l, r);
	ll res = 0;
	l += ADD, r += ADD;
	while(l <= r) {
		if(l & 1) res += T[l++];
		if(!(r & 1)) res += T[r--];
		l >>= 1, r >>= 1;
	}
	return res;
}

vector <t3> Q[200020];
ll dp[200020], ep[200020];

ll Get(int x, int y) {
	if(head[x] == head[y]) {
		if(dep[x] < dep[y]) swap(x, y);
		return read_t(ST[y], ST[x]);
	}
	else {
		if(dep[head[x]] < dep[head[y]]) swap(x, y);
		return read_t(ST[head[x]], ST[x]) + Get(par[head[x]], y);
	}
}

void dfs2(int x) {
	for(int e : E[x]) dfs2(e);
	ll dx = ep[x];
	for(t3 e : Q[x]) {
		int a, b, c; tie(a, b, c) = e;
		dx = max(dx, Get(a, b) + c);
	}
	
	dp[x] = dx;
	update_t(ST[x], -dp[x]);
	if(x != 1) {
		int p = par[x];
		ep[p] += dp[x];
		update_t(ST[p], dp[x]);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i=2;i<=n;i++) {
		int x; scanf("%d", &x);
		E[x].pb(i);
	}
	pdfs(1);
	dfs(1, 1);
	for(int i=1;i<=m;i++) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		Q[get_lca(x, y)].pb(t3(x, y, z));
	}
	dfs2(1);
	printf("%lld\n", dp[1]);
	return 0;
}