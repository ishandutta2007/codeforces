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
vec< vec< pii > > g;

void read() {
	scanf("%d", &n);
	g.resize(n + 1);
	for(int u, v, w, i = 0;i < n - 1;i++) {
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back(mp(v, w));
		g[v].push_back(mp(u, w));
	}
}

const int LOG = 21;
vec< int > p[LOG], h, tout, order;
vec< ll > sum;
int timer = 0;

void dfs(int v, int par = -1, int H = 0, ll S = 0) {
	p[0][v] = par;
	h[v] = H;
	sum[v] = S;
	for(auto it : g[v]) {
		int to = it.first;
		if(to == par) continue;
		int len = it.second;
		dfs(to, v, H + 1, S + len);
	}
	tout[v] = timer++;
	order.push_back(v);
}

void precalc() {
	for(int i = 0;i < LOG;i++) p[i].resize(n + 1, -1);
	h.resize(n + 1);
	sum.resize(n + 1);
	tout.resize(n + 1);
	dfs(1);
	for(int i = 1;i < LOG;i++) {
		for(int j = 1;j <= n;j++) {
			int x = p[i - 1][j];
			if(x != -1) p[i][j] = p[i - 1][x];
		}
	}
}

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

ll dist(int u, int v) {
	return sum[u] + sum[v] - 2ll * sum[lca(u, v)];
}

bool solve() {
	
	read();
	precalc();

	int m;
	scanf("%d", &m);

	char ty;
	ll res = 0;

	set< int > q;

	for(int x, i = 0;i < m;i++) {

		scanf(" %c", &ty);
		if(ty == '?') {
			printf("%I64d\n", res / 2);
		}else {
			scanf("%d", &x);
			if(ty == '+') {			
				if((int)q.size() == 0) 
					q.insert(tout[x]);
				else if((int)q.size() == 1) {
					res += 2ll * dist(x, order[*q.begin()]);
					q.insert(tout[x]);
				}else {
					int nxt, prv;
					set< int > :: iterator it = q.lower_bound(tout[x]);
					if(it != q.end()) nxt = *it;
					else nxt = *q.begin();
					if(it != q.begin()) {
						it--;
						prv = *it;
					}else {
						prv = *(--q.end());
					}
					nxt = order[nxt];
					prv = order[prv];
					res -= dist(prv, nxt);
					res += dist(prv, x);
					res += dist(x, nxt);
					q.insert(tout[x]);
				}
			}else { // ty == '-'
				if((int)q.size() == 1) {
					q.erase(tout[x]);
				}else if((int)q.size() == 2) {
					res = 0;
					q.erase(tout[x]);
				}else {
					int nxt, prv;
					set< int > :: iterator it = q.lower_bound(tout[x]);
					it++;
					if(it != q.end()) nxt = *it;
					else nxt = *q.begin();
					it--;
					if(it != q.begin()) {
						it--;
						prv = *it;
					}else prv = *(--q.end());
					prv = order[prv];
					nxt = order[nxt];
					res -= dist(prv, x);
					res -= dist(x, nxt);
					res += dist(prv, nxt);
					q.erase(tout[x]);
				}
			}
		}
	}

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}