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

int n, m;
vec< int > a;
vec< vec< int > > g;

void read() {
	scanf("%d %d", &n, &m);
	a.resize(n + 1);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
		a[i] %= m;
	}
	g.resize(n + 1);
	for(int u, v, i = 0;i < n - 1;i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

vec< int > mas, tin, tout;
int timer = 0;

void dfs(int v, int par = -1) {
	tin[v] = timer++;
	mas.push_back(a[v]);
	for(auto to : g[v]) {
		if(to != par) dfs(to, v);
	}
	tout[v] = timer++;
	mas.push_back(a[v]);
}

bitset< 1000 > pr;
vec< bitset< 1000 > > t;
vec< int > delt;

void up(int v) {
	t[v] = t[v * 2 + 1] | t[v * 2 + 2];
}

void shift(int v, int sh) {
	t[v] = (t[v] << sh) | (t[v] >> (m - sh));
}

void push(int v) {
	if(delt[v]) {
		delt[v * 2 + 1] = (delt[v * 2 + 1] + delt[v]) % m;
		delt[v * 2 + 2] = (delt[v * 2 + 2] + delt[v]) % m;
		shift(v * 2 + 1, delt[v]);
		shift(v * 2 + 2, delt[v]);
		delt[v] = 0;
	}
}

void build(int v, int tl, int tr) {
	if(tl == tr) {
		delt[v] = 0;
      t[v].set(mas[tl]);
	}else {
		int tm = (tl + tr) / 2;
		build(v * 2 + 1, tl, tm);
		build(v * 2 + 2, tm + 1, tr);
		up(v);
	}
}

void add(int v, int tl, int tr, int l, int r, int x) {
	if(l > r) return;
	if(l <= tl && tr <= r) {
		delt[v] = (delt[v] + x) % m;
		shift(v, x);
	}else {
		int tm = (tl + tr) / 2;
		push(v);
		if(l <= tm) add(v * 2 + 1, tl, tm, l, r, x);
		if(r > tm) add(v * 2 + 2, tm + 1, tr, l, r, x);
		up(v);
	}
}

bitset< 1000 > zero;

bitset< 1000 > get(int v, int tl, int tr, int l, int r) {
	if(l > r) return zero;
	if(l <= tl && tr <= r) {
		return t[v];
	}else {
		int tm = (tl + tr) / 2;
		push(v);
		bitset< 1000 > ans;
		if(l <= tm) {
			if(r > tm) ans = get(v * 2 + 1, tl, tm, l, r) | get(v * 2 + 2, tm + 1, tr, l, r);
			else ans = get(v * 2 + 1, tl, tm, l, r);
		}else ans = get(v * 2 + 2, tm + 1, tr, l, r);
		up(v);
		return ans;
	}
}

void get_primes() {
	pr.reset();
	vec< char > prime(m, 1);
	for(int i = 2;i * i < m;i++) {
		if(!prime[i]) continue;
		for(int j = i * i;j < m;j += i) prime[j] = 0;
	}
	for(int i = 2;i < m;i++) {
		if(prime[i]) pr.set(i);
	}
}

void precalc() {
	
	zero.reset();

	tin.resize(n + 1);
	tout.resize(n + 1);

	dfs(1);

	t.resize(8 * n);
	delt.resize(8 * n);

	build(0, 0, 2 * n - 1);

	get_primes();
}

bool solve() {

	read();
	precalc();

	int q;
	scanf("%d", &q);

	for(int ty, v, x;q;q--) {
		scanf("%d %d", &ty, &v);
		if(ty == 1) {
			scanf("%d", &x);
			x %= m;
			add(0, 0, 2 * n - 1, tin[v], tout[v], x);
		}else {
			printf("%d\n", (get(0, 0, 2 * n - 1, tin[v], tout[v]) & pr).count());
		}
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}