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

int f, T, t0;
int a[2], t[2], p[2];

ll Get(int rt, int rf, int a, int t, int p) {
	if(rf < 0) return 0;
	if((ll)t0 * rf <= rt) return 0;
	if(t0 <= t) return 1e16;
	int x = rf / a;
	ll res = 1e16;
	rep(u, 2) {
		int tx = x + u;
		ll tm = min((ll)rf, (ll)tx * a) * t + max(0LL, rf - (ll)a * tx) * t0;
		if(tm <= rt) {
			res = min(res, tx * (ll)p);
		}
	}
	ll temp = ((ll)t0*rf - rt + (ll)(t0-t)*a - 1) / ((ll)(t0-t)*a);
	if(temp < x) {
		res = min(res, p * temp);
	}
	return res;
}

void solve() {
	scanf("%d%d%d", &f, &T, &t0);
	rep(i, 2) scanf("%d%d%d", a+i, t+i, p+i);
	ll res = 1e16;
	rep(u, 2) res = min(res, Get(T, f, a[u], t[u], p[u]));
	rep(u, 2) for(int i=1;T-(ll)a[u]*t[u]*i>=0;i++) res = min(res, (ll)p[u] * i + Get(T-t[u]*a[u]*i, f-a[u]*i, a[!u], t[!u], p[!u]));
	printf("%lld\n", res == 1e16 ? -1 : res);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}