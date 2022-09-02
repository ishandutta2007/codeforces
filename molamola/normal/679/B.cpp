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

ll M;
ll D[1100010];
ll P3[100010];
pll MX[1000010];

pll f(ll X){
	if(X <= 1000000){
		return MX[X];
	}
	int t = (int)(upper_bound(P3+1, P3+100006, X) - P3 - 1);
	auto A = f(X - P3[t]);
	auto B = f(P3[t] - P3[t-1] - 1);
	if(A.Fi < B.Fi)return pll(B.Fi + 1, B.Se + P3[t-1]);
	else return pll(A.Fi + 1, A.Se + P3[t]);
}

void solve(){
	P3[1] = 1;
	for(int i=2;i<=100005;i++)P3[i] = (ll)i * i * i;
	for(int i=1;i<8;i++)D[i] = i;
	for(int i=2;i<=100;i++){
		for(int j=(int)P3[i];j<(int)P3[i+1];j++){
			D[j] = D[j-P3[i]] + 1;
		}
	}
	MX[1] = pll(1, 1);
	for(int i=2;i<=1000005;i++){
		MX[i] = pll(D[i], i);
		if(MX[i].Fi < MX[i-1].Fi)MX[i] = MX[i-1];
	}
	cin >> M;
	auto A = f(M);
	printf("%lld %lld\n", A.Fi, A.Se);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}