#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

vector <pii> E[300030];
vector <int> F[300030];
int n, m, s;
int ans[300030], chk[300030];
int ans2[300030];

void dfs(int x) {
	chk[x] = 1;
	for(pii e : E[x]) {
		if(e.Se != 0) {
			if(e.Se > 0) { if(ans[e.Se] == -1) ans[e.Se] = 1; }
			else { if(ans[-e.Se] == -1) ans[-e.Se] = 0; }
		}
		if(chk[e.Fi] == 0) dfs(e.Fi);
	}
}

void dfs3(int x) {
	chk[x] = 1;
	for(pii e : E[x]) {
		if(e.Se != 0) {
			if(e.Se > 0) { if(ans2[e.Se] == -1) ans2[e.Se] = 0; }
			else { if(ans2[-e.Se] == -1) ans2[-e.Se] = 1; }
		}
		if(e.Se == 0 || (e.Se > 0) == ans2[abs(e.Se)]) {
			if(chk[e.Fi] == 0) dfs3(e.Fi);
		}
	}
}

int dfs2(int x) {
	chk[x] = 1;
	int res = 1;
	for(int e : F[x]) if(chk[e] == 0) res += dfs2(e);
	return res;
}

int ori[300030];

void solve() {
	scanf("%d%d%d", &n, &m, &s);
	rep(i, m) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		if(x == 1) {
			E[y].pb(pii(z, 0));
		}
		else {
			ori[i+1] = 1;
			E[y].pb(pii(z, i+1));
			E[z].pb(pii(y, -(i+1)));
		}
	}
	memset(ans, -1, sizeof ans);
	memset(ans2, -1, sizeof ans2);
	dfs(s);
	memset(chk, 0, sizeof chk);
	dfs3(s);
	for(int i=1;i<=m;i++) if(ans[i] == -1) ans[i] = 0;
	for(int i=1;i<=m;i++) if(ans2[i] == -1) ans2[i] = 0;
	for(int i=1;i<=n;i++) F[i].clear();
	for(int i=1;i<=n;i++) {
		for(pii e : E[i]) if(e.Se == 0 || ((e.Se > 0) == ans[abs(e.Se)])) F[i].pb(e.Fi);
	}
	memset(chk, 0, sizeof chk);
	printf("%d\n", dfs2(s));
	for(int i=1;i<=m;i++) if(ori[i]) printf("%c", ans[i] ? '+' : '-');
	puts("");
	for(int i=1;i<=n;i++) F[i].clear();
	for(int i=1;i<=n;i++) {
		for(pii e : E[i]) if(e.Se == 0 || ((e.Se > 0) == ans2[abs(e.Se)])) F[i].pb(e.Fi);
	}
	memset(chk, 0, sizeof chk);
	printf("%d\n", dfs2(s));
	for(int i=1;i<=m;i++) if(ori[i]) printf("%c", ans2[i] ? '+' : '-');
	puts("");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}