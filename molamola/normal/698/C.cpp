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

double D[1<<20];

void solve(){
	int n, k;
	double P[22];
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++)scanf("%lf", P+i);
	int c = 0;
	for(int i=0;i<n;i++)if(P[i] > 0)++c;
	k = min(k, c);
	D[0] = 1;
	double ans[22] = {};
	for(int i=0;i<1<<n;i++){
		for(int j=0;j<n;j++)if(!(1<<j & i) && P[j] == 0)continue;
		double pp = 0;
		for(int j=0;j<n;j++)if(!(1<<j & i) && P[j] > 0)pp += P[j];
		for(int j=0;j<n;j++)if(!(1<<j & i) && P[j] > 0){
			D[i | 1<<j] += D[i] * P[j] / pp;
		}
		if(__builtin_popcount(i) == k){
			for(int j=0;j<n;j++)if(1<<j & i)ans[j] += D[i];
		}
	}
	rep(i, n)printf("%.20f ", ans[i]); puts("");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}