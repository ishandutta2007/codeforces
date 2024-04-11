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
typedef tuple<ll, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<ldouble, ldouble> pdd;

ll last;
int par[400040][20];
int pp[400040][20];
ll vp[400040][20];
ll vmx[400040][20];
int cnt = 1;

int get_mx(int r, ll W) {
	if(vmx[r][19] < W) return 0;
	for(int i=19;i>=0;i--) {
		if(vmx[r][i] < W) r = par[r][i];
	}
	return r;
}

void add(int R, ll W) {
	int nd = ++cnt;
	par[nd][0] = R;
	vmx[nd][0] = W;
	for(int i=1;i<20;i++) {
		par[nd][i] = par[ par[nd][i-1] ][i-1];
		vmx[nd][i] = max(vmx[nd][i-1], vmx[ par[nd][i-1] ][i-1]);
	}
	int mp = get_mx(R, W);
	pp[nd][0] = mp;
	vp[nd][0] = W;
	for(int i=1;i<20;i++) {
		pp[nd][i] = pp[ pp[nd][i-1] ][i-1];
		vp[nd][i] = vp[nd][i-1] + vp[ pp[nd][i-1] ][i-1];
	}
}

ll Get(int R, ll X) {
	ll ans = 0;
	for(int i=19;i>=0;i--) {
		if(pp[R][i] == 0) continue;
		if(X >= vp[R][i]) {
			ans += 1<<i;
			X -= vp[R][i];
			R = pp[R][i];
		}
	}
	if(X >= vp[R][0]) ++ans;
	return ans;
}

void solve() {
	int q; scanf("%d", &q);
	while(q--) {
		int cmd; ll R, X;
		scanf("%d%lld%lld", &cmd, &R, &X);
		R ^= last; X ^= last;
		if(cmd == 1) {
			add((int)R, X);
		}
		else {
			ll v = Get((int)R, X);
			last = v;
			printf("%lld\n", v);
		}
	}
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}