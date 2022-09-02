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
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int N, Q;
vector <pii> E[500050];
int cut[500050];
int down[500050];
int leaf[500050];

void pdfs(int x, int fa) {
	down[x] = 1;
	for(pii e : E[x]) if(e.Se != fa && cut[e.Se] == 0) {
		pdfs(e.Se, x);
		down[x] += down[e.Se];
	}
}

vector <pll> V[500050];
vector <ll> T[500050];
int T_ADD[500050];
int CN, CD;
int up[500050][20]; ll upl[500050][20];
void dfs(int x, int fa, ll len = 0) {
	if(leaf[x]) V[CN].pb(pll(x, len));
	up[x][CD] = CN; upl[x][CD] = len;
	for(pii e : E[x]) if(e.Se != fa && cut[e.Se] == 0) {
		dfs(e.Se, x, len + e.Fi);
	}
}

void Do(int x, int depth = 0) {
	pdfs(x, -1);
	int h = down[x] / 2;
	while(1) {
		int f = 0;
		for(pii e : E[x]) if(down[x] > down[e.Se] && down[e.Se] > h) {
			x = e.Se; f = 1; break;
		}
		if(f == 0) break;
	}
	CN = x; CD = depth;
	dfs(x, -1);
	sort(all(V[x]));
	T_ADD[x] = 1; while(T_ADD[x] < szz(V[x])) T_ADD[x] *= 2;
	int m = szz(V[x]);
	T[x].resize(2*T_ADD[x]);
	for(int i=0;i<m;i++) T[x][T_ADD[x]+i] = V[x][i].Se;
	for(int i=m;i<T_ADD[x];i++) T[x][T_ADD[x]+i] = 1e18;
	for(int i=T_ADD[x]-1;i;i--) T[x][i] = min(T[x][i*2], T[x][i*2+1]);
	
	cut[x] = 1;
	for(pii e : E[x]) if(cut[e.Se] == 0) {
		Do(e.Se, depth + 1);
	}
}

ll read(int x, int l, int r) {
	int lv = (int)(lower_bound(all(V[x]), pll(l, -1)) - V[x].begin());
	int rv = (int)(lower_bound(all(V[x]), pll(r+1, -1)) - V[x].begin() - 1);
	lv += T_ADD[x]; rv += T_ADD[x];
	ll res = 1e18;
	while(lv <= rv) {
		if(lv & 1) res = min(res, T[x][lv++]);
		if(!(rv & 1)) res = min(res, T[x][rv--]);
		lv >>= 1, rv >>= 1;
	}
	return res;
}

int main() {
	scanf("%d%d", &N, &Q);
	for(int i=2;i<=N;i++) {
		int p, x;
		scanf("%d%d", &p, &x);
		E[p].pb(pii(x, i));
		E[i].pb(pii(x, p));
	}
	for(int i=1;i<=N;i++) leaf[i] = (szz(E[i]) == 1);
	Do(1);
	for(int i=1;i<=Q;i++) {
		int v, l, r;
		scanf("%d%d%d", &v, &l, &r);
		ll ans = 1e18;
		for(int i=19;i>=0;i--) if(up[v][i] != 0) {
			int vi = up[v][i];
			ll len = upl[v][i] + read(vi, l, r);
			ans = min(ans, len);
		}
		printf("%lld\n", ans);
	}
	return 0;
}