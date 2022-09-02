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

const int MOD = 1e9 + 7;
int D[2020][1010];
int k, pa, pb;

int pw(int x, int y) {
	int res = 1;
	while(y) {
		if(y & 1) res = (ll)res * x % MOD;
		x = (ll)x * x % MOD;
		y >>= 1;
	}
	return res;
}

void solve() {
	scanf("%d%d%d",&k, &pa, &pb);
	D[0][1] = 1;
	ll ans = 0;
	int xa = (ll)pa * pw(pa + pb, MOD - 2) % MOD;
	int xb = (ll)pb * pw(pa + pb, MOD - 2) % MOD;
	ll ya = pw(xb, MOD - 2);
	for(int i=0;i<k;i++) {
		for(int j=0;j<=k;j++) {
			if(j < k) {
				D[i][j+1] = (D[i][j+1] + (ll)D[i][j] * xa) % MOD;
				D[i+j][j] = (D[i+j][j] + (ll)D[i][j] * xb) % MOD;
			}
			else {
				ll p = ya * (i + k) % MOD;
				p = (p + ya * ya % MOD * xa) % MOD;
				p = p * xb % MOD;
				ans = (ans + p * D[i][j]) % MOD;
			}
		}
	}
	for(int i=k;i<k+k;i++) {
		for(int j=0;j<=k;j++) if(D[i][j]) ans = (ans + (ll)D[i][j] * i) % MOD;
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