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

namespace MaxFlow{
	const int MV = 200020;
	const int ME = 400040;
	const int INF = 1e9;
	int dis[MV];
	int st[MV], en[ME<<1], nxt[ME<<1], flow[ME<<1], ce;
	int start[MV];
	void init() {
		memset(st, 0, sizeof st);
		ce = 1;
	}
	void addE(int s, int e, int f = 1) {
		++ce; nxt[ce] = st[s]; st[s] = ce; en[ce] = e; flow[ce] = f;
		++ce; nxt[ce] = st[e]; st[e] = ce; en[ce] = s; flow[ce] = 0;
	}
	int que[MV];
	int bfs(int N, int S, int E) {
		for(int i=1;i<=N;i++) dis[i] = -1;
		dis[S] = 0;
		int *fr = que, *re = que;
		*fr++ = S;
		while(fr != re) {
			int t = *re++;
			for(int i=st[t];i;i=nxt[i]) if(flow[i] > 0 && dis[en[i]] == -1) {
				dis[en[i]] = dis[t] + 1;
				*fr++ = en[i];
			}
		}
		return dis[E] != -1;
	}
	
	int dfs(int x, int E, int f) {
		if(x == E) return f;
		for(int &i=start[x],t;i;i=nxt[i]) if(flow[i] > 0 && dis[en[i]] == dis[x] + 1 && (t = dfs(en[i], E, min(f, flow[i]))) > 0){
			flow[i] -= t;
			flow[i^1] += t;
			return t;
		}
		return 0;
	}
	
	int Get(int N, int S, int E) {
		int res = 0;
		while(bfs(N, S, E)) {
			for(int i=1;i<=N;i++) start[i] = st[i];
			while(1) {
				int t = dfs(S, E, INF);
				if(t == 0) break;
				res += t;
			}
		}
		return res;
	}
	
	void trace(int N, int S, int E, int chk[]) {
		bfs(N, S, E);
		for(int i=1;i<=N;i++) chk[i] = (dis[i] != -1);
	}
}

int n, m;
vector <pii> E[10010];
int color[10010];
int upc[10010], par[10010];
vector <vector <int> > cyc;

void dfs(int x, int fa) {
	color[x] = 1;
	for(pii e : E[x]) if(e.Se != fa) {
		if(color[e.Se] == 0) {
			upc[e.Se] = e.Fi;
			par[e.Se] = x;
			dfs(e.Se, x);
		}
		else if(color[e.Se] == 1) {
			vector <int> v; v.pb(e.Fi);
			int t = x;
			while(t != e.Se) v.pb(upc[t]), t = par[t];
			cyc.pb(v);
		}
	}
	color[x] = 2;
}

int cnt[20020];

int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		E[x].pb(pii(z, y));
		E[y].pb(pii(z, x));
		cnt[z]++;
	}
	dfs(1, -1);
	int L = szz(cyc);
	int ans = 0;
	for(int i=1;i<=m;i++) if(cnt[i] > 0) ++ans;
	MaxFlow::init();
	int ST = L + m + 1, EN = ST + 1;
	for(int i=1;i<=m;i++) if(cnt[i] > 1) MaxFlow::addE(ST, i, cnt[i] - 1);
	for(int i=m+1;i<=m+L;i++) MaxFlow::addE(i, EN, 1);
	for(int i=m+1;i<=m+L;i++) {
		for(int e : cyc[i-m-1]) MaxFlow::addE(e, i, 1);
	}
	int r = L - MaxFlow::Get(EN, ST, EN);
	ans -= r;
	printf("%d\n", ans);
	return 0;
}