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

const int MX = 1000010;

int isp[MX];
int pr[MX], prz;

ll get(ll X){
	if(X == 1)return 1;
	ll res = X;
	for(int i=1;i<=prz;i++){
		int pp = pr[i];
		if((ll)pp*pp > X)break;
		if(X % pp == 0){
			res /= pp;
			res *= (pp-1);
			while(X % pp == 0)X /= pp;
		}
	}
	if(X != 1){
		res /= X;
		res *= (X-1);
	}
	return res;
}

const int MOD = 1e9 + 7;

void solve(){
	for(int i=2;i<MX;i++)isp[i] = 1;
	for(int i=2;i<MX;i++)if(isp[i]){
		pr[++prz] = i;
		for(int j=i+i;j<MX;j+=i)isp[j] = 0;
	}
	ll n, k; cin >> n >> k;
	k = (k+1) / 2;
	while(k--){
		n = get(n);
		if(n == 1)break;
	}
	printf("%lld\n", n % MOD);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}