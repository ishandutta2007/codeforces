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

int S[100010], D[100010], cs;
int C[100010], F[100010];
vector <int> E[100010];
int N;
int num[200020];
int up[100010][20], dep[100010];

void dfs(int x, int fa) {
	S[x] = ++cs;
	num[cs] = x;
	for(int e : E[x]) if(e != fa) {
		dep[e] = dep[x] + 1;
		up[e][0] = x;
		for(int i=1;i<20;i++) up[e][i] = up[ up[e][i-1] ][i-1];
		dfs(e, x);
	}
	D[x] = ++cs;
	num[cs] = x;
}

int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	rep(i, 20) if(1<<i & (dep[x] - dep[y])) x = up[x][i];
	for(int i=19;i>=0;i--) if(up[x][i] != up[y][i]) x = up[x][i], y = up[y][i];
	return x == y ? x : up[x][0];
}

struct str{
	str(){}
	str(int lv, int rv, int c, int u = -1) : lv(lv), rv(rv), c(c), u(u){}
	int lv, rv, c;
	int u;
	bool operator<(const str &rhs) const{
		if((rhs.lv >> 9) == (lv >> 9)) return rv < rhs.rv;
		return lv < rhs.lv;
	}
};

vector <str> V;

ll ans[100010];

ll X[100010][2];
ll now;
int act[100010];

inline void update(int x, int b, int e) {
	if(e == 1) now += X[x][!b], ++X[x][b];
	else now -= X[x][!b], --X[x][b];
}

inline void update(int x, int c) {
	if(c == 0) act[x] ^= 1;
	if(act[x] == 0) update(F[x], C[x], c);
	else update(F[x], C[x], !c);
	if(c == 1) act[x] ^= 1;
}

void solve(){
	scanf("%d", &N);
	for(int i=1;i<=N;i++) scanf("%d", C+i);
	for(int i=1;i<=N;i++) scanf("%d", F+i);
	vector <int> fx;
	for(int i=1;i<=N;i++) fx.pb(F[i]);
	sort(all(fx)); fx.resize(unique(all(fx)) - fx.begin());
	for(int i=1;i<=N;i++) {
		F[i] = (int)(lower_bound(all(fx), F[i]) - fx.begin() + 1);
	}
	rep(i, N-1) {
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
	}
	dfs(1, -1);
	int q; scanf("%d", &q);
	rep(i, q) {
		int x, y; scanf("%d%d", &x, &y);
		if(S[x] > S[y]) swap(x, y);
		if(D[x] > D[y]) {
			V.emplace_back(S[x], S[y], i);
		}
		else {
			V.emplace_back(D[x], S[y], i, lca(x, y));
		}
	}
	
	sort(all(V));
	
	int L = 1, R = 0;
	for(int i=0;i<sz(V);i++) {
		int lv = V[i].lv, rv = V[i].rv;
		while(L < lv) {
			update(num[L], 0);
			++L;
		}
		while(L > lv) {
			--L;
			update(num[L], 1);
		}
		while(R > rv) {
			update(num[R], 0);
			--R;
		}
		while(R < rv) {
			++R;
			update(num[R], 1);
		}
		if(V[i].u != -1) {
			update(V[i].u, 1);
			ans[V[i].c] = now;
			update(V[i].u, 0);
		}
		else ans[V[i].c] = now;
	}
	
	rep(i, q) printf("%lld\n", ans[i]);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case #%d\n", tc);
		solve();
	}
	return 0;
};