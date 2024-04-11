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

const int MOD = 998244353;
int n, p, q;

ll pw(ll x, int y = MOD - 2) {
	x %= MOD; ll res = 1;
	while(y) {
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

ll scc[2020], R[2020][2020], D[2020];

void solve() {
	int a, b;
	scanf("%d%d%d", &n, &a, &b);
	p = pw(b) * a % MOD;
	q = (1 + MOD - p) % MOD;
	R[1][0] = R[1][1] = 1; scc[1] = 1;
	for(int i=2;i<=n;i++) {
		R[i][0] = 1;
		for(int j=1;j<=i;j++) {
			R[i][j] = (pw(p, i-j) * R[i-1][j-1] + pw(q, j) * R[i-1][j]) % MOD;
		}
		scc[i] = 1;
		for(int j=1;j<i;j++) scc[i] = (scc[i] - scc[j] * R[i][j]) % MOD;
		if(scc[i] < 0) scc[i] += MOD;
	}
	for(int i=2;i<=n;i++) {
		ll s = 0, s1 = (1 - scc[i] + MOD) % MOD;
		for(int j=1;j<=i;j++) {
			ll v1 = scc[j] * R[i][j] % MOD;
			ll v2 = D[j] + D[i-j] + j * (i - j) + j * (j - 1) / 2;
			s = (s + v1 * v2) % MOD;
		}
		D[i] = s * pw(s1) % MOD;
	}
	printf("%lld\n", D[n]);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}