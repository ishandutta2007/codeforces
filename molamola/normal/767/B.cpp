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
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

ll ts, tf, t;
int n;
ll A[100010];
ll T[100010];

ll ans = -1, tm = 1e18;

void Do(ll tt) {
	int l = (int)(upper_bound(T+1, T+1+n, tt) - T - 1);
	ll s = (l ? A[l] + t : ts);
	s = max(s, tt);
	if(s + t <= tf && s - tt < tm) tm = s - tt, ans = tt;
}

void solve(){
	scanf("%lld%lld%lld", &ts, &tf, &t);
	scanf("%d", &n);
	if(n == 0) {
		printf("%lld\n", ts);
		return;
	}
	for(int i=1;i<=n;i++) scanf("%lld", T+i);
	sort(T+1, T+1+n);
	for(int i=1;i<=n;i++) {
		ll s = (i > 1 ? A[i-1] + t : ts);
		A[i] = max(T[i], s);
	}
	for(int i=1;i<=n;i++) if(T[i]) {
		Do(T[i] - 1);
	}
	for(int i=1;i<=n;i++) Do(A[i] + t);
	Do(ts);
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d\n", tc);
		solve();
	}
	return 0;
};