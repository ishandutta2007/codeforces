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
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;
typedef long double ldouble;

int n;
ll A[100010];

const ll MOD = 1e9 + 7;

ll pw(ll x, ll y){
	ll res = 1;
	x %= MOD;
	while(y){
		if(y & 1)res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

void solve(){
	scanf("%d", &n);
	int t = 0;
	rep(i, n){
		scanf("%lld", A+i);
		if(A[i] % 2 == 0)t = 1;
	}
	ll Q = 2;
	rep(i, n){
		Q = pw(Q, A[i]);
	}
	Q = Q * pw(2, MOD - 2) % MOD;
	ll P = Q;
	if(t == 0)P = (P + MOD - 1) % MOD;
	else P = (P + 1) % MOD;
	P = P * pw(3, MOD - 2) % MOD;
	printf("%lld/%lld\n", P, Q);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}