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

ll D[1020];
ll C[1020][1020];
char A[55][1010];
ll v[1010];

void solve() {
	for(int i=0;i<1010;i++) {
		C[i][0] = 1;
		for(int j=1;j<=i;j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	}
	D[0] = D[1] = 1;
	for(int i=2;i<1010;i++) {
		for(int j=1;j<=i;j++) {
			D[i] = (D[i] + D[i-j] * C[i-1][j-1]) % MOD;
		}
	}
	int m, n; scanf("%d%d", &m, &n);
	rep(i, n) scanf("%s", A[i]);
	rep(i, n) rep(j, m) if(A[i][j] == '1') v[j] |= 1LL << i;
	map <ll, int> M;
	rep(i, m) M[v[i]]++;
	ll ans = 1;
	for(auto e : M) {
		ans = ans * D[e.Se] % MOD;
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