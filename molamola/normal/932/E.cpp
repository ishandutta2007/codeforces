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

const int MOD = 1e9 + 7;

ll F[5050][5050];
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
	int n, k; scanf("%d%d", &n, &k);
	for(int i=0;i<=min(n, k);i++) F[k][i] = pw(2, n - i);
	for(int i=k-1;i>=0;i--) {
		for(int j=0;j<=min(n,k);j++) {
			F[i][j] = (F[i+1][j+1] * (ll)(n - j) + F[i+1][j] * (ll)j) % MOD;
		}
	}
	printf("%lld\n", F[0][0]);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}