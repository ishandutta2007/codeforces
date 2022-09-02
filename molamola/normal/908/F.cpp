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
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int N;
int P[300030], color[300030];

ll Do(int l, int r) {
	ll res = 2 * (P[r] - P[l]);
	vector <ll> L[2];
	for(int i=l;i<=r;i++) {
		if(color[i] == 0 || color[i] == 1) L[0].pb(P[i]);
		if(color[i] == 0 || color[i] == 2) L[1].pb(P[i]);
	}
	ll val[2]; val[0] = val[1] = 0;
	rep(u, 2) {
		for(int i=1;i<szz(L[u]);i++) {
			val[u] = max(val[u], L[u][i] - L[u][i-1]);
		}
	}
	res = min(res, 3LL * (P[r] - P[l]) - val[0] - val[1]);
	return res;
}

void solve() {
	scanf("%d", &N);
	int o = 1;
	for(int i=1;i<=N;i++) {
		int x; char c;
		scanf("%d %c", &x, &c);
		P[i] = x; color[i] = (c == 'G' ? 0 : (c == 'B' ? 1 : 2));
		if(color[i] == 0) o = 0;
	}
	if(o == 1) {
		vector <int> L[2];
		for(int i=1;i<=N;i++) L[color[i] - 1].pb(P[i]);
		ll ans = 0;
		rep(i, 2) if(szz(L[i])) ans += L[i].back() - L[i][0];
		printf("%lld\n", ans);
		return;
	}
	int sg = 1, lg = N;
	while(color[sg] != 0) ++sg;
	while(color[lg] != 0) --lg;
	int chk[2] = {};
	ll ans = 0;
	for(int i=1;i<sg;i++) {
		if(chk[color[i]-1] == 0) ans += P[sg] - P[i], chk[color[i]-1] = 1;
	}
	chk[0] = chk[1] = 0;
	for(int i=N;i>lg;i--) {
		if(chk[color[i]-1] == 0) ans += P[i] - P[lg], chk[color[i]-1] = 1;
	}
	for(int i=sg+1, p=sg;i<=lg;i++) {
		if(color[i] == 0) {
			ans += Do(p, i);
			p = i;
		}
	}
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}