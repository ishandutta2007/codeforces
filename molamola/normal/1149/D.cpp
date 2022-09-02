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
#define pb push_back
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int n, m, a, b;
int pp[80]; int Find(int x) { return pp[x] == x ? x : pp[x] = Find(pp[x]); }
int zz[80];
vector <pii> E[80];
vector <int> F[71<<17];
int D[71<<17];
int cn[80];

int main() {
	scanf("%d%d%d%d", &n, &m, &a, &b);
	vector <pii> edge[2];
	for(int i=1;i<=m;i++) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		edge[z==b].pb(pii(x, y));
	}
	auto add_edge = [&](int x, int y, int c) {
		E[x].pb(pii(c, y));
		E[y].pb(pii(c, x));
	};
	
	for(int i=1;i<=n;i++) pp[i] = i, zz[i] = 1;
	for(pii e : edge[0]) {
		int x = Find(e.Fi), y = Find(e.Se);
		if(x != y) {
			pp[x] = y;
			zz[y] += zz[x];
		}
		add_edge(e.Fi, e.Se, a);
	}
	for(pii e : edge[1]) {
		int x = Find(e.Fi), y = Find(e.Se);
		if(x != y) {
			add_edge(e.Fi, e.Se, b);
		}
	}
	memset(D, -1, sizeof D);
	memset(cn, -1, sizeof cn);
	int cnt = 0;
	for(int i=1;i<=n;i++) if(pp[i] == i && zz[i] >= 4) {
		cn[i] = cnt++;
	}
	for(int i=1;i<=n;i++) if(zz[Find(i)] >= 4) cn[i] = cn[Find(i)];
	auto f = [&](int x) { return cn[x] == -1 ? 0 : 1<<cn[x]; };
	for(int i=0;i<1<<cnt;i++) {
		for(int j=1;j<=n;j++) {
			for(pii e : E[j]) {
				int k = e.Se, cost = e.Fi;
				if(cost == b && (i & f(k))) continue;
				int ni = i | f(k);
				F[j<<cnt|i].pb((k<<cnt|ni)<<1|(cost==b));
			}
		}
	}
	D[1<<cnt|f(1)] = 0;
	priority_queue <pii, vector<pii>, greater<pii> > pq;
	pq.push(pii(0, 1<<cnt|f(1)));
	int ans[110]; for(int i=1;i<=n;i++) ans[i] = 2e9;
	while(!pq.empty()) {
		pii t = pq.top(); pq.pop();
		if(D[t.Se] != t.Fi) continue;
		ans[t.Se>>cnt] = min(ans[t.Se>>cnt], t.Fi);
		for(int e : F[t.Se]) {
			int u = (e>>1), cost = (e&1) ? b : a;
			if(D[u] == -1 || D[u] > cost + t.Fi) {
				D[u] = cost + t.Fi;
				pq.push(pii(D[u], u));
			}
		}
	}
	for(int i=1;i<=n;i++) printf("%d ", ans[i]); puts("");
	
	return 0;
}