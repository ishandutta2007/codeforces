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

int n;
ll L;
ll c[33];

void solve() {
	scanf("%d%lld", &n, &L);
	rep(i, n) scanf("%lld", c+i);
	for(int i=1;i<n;i++) c[i] = min(c[i], c[i-1] * 2);
	ll ans = 1e18;
	for(int i=n-1;i>=0;i--) {
		ll t = 1LL << i;
		ll tl = L + t - 1;
		ll cc = 0;
		for(int j=i;j<n-1;j++) {
			if(1LL << j & tl) cc += c[j];
		}
		cc += c[n-1] * (tl >> (n-1));
		ans = min(ans, cc);
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