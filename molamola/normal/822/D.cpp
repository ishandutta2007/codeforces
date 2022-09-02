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

ll D[5000050];
const int MOD = 1e9 + 7;

void solve(){
	for(int i=1;i<=5000000;i++) D[i] = (ll)i * (i-1) / 2;
	for(int i=1;i<=5000000;i++) {
		if((ll)i * i > 5000000) continue;
		for(int j=i*i, c=i;j<=5000000;j+=i, c++) {
			D[j] = min(D[j], min(i * D[c] + D[i], c * D[i] + D[c]));
		}
	}
	for(int i=1;i<=5000000;i++) D[i] %= MOD;
	int t, l, r; cin >> t >> l >> r;
	ll a = 1, ans = 0;
	for(int i=l;i<=r;i++) {
		ans += D[i] * a;
		ans %= MOD;
		a = a * t % MOD;
	}
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