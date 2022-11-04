/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXN = 1000000+10;
const int mod  = 1000000007;

int k,w;
int fact[MAXN],dfact[MAXN];

int POWER(int base, int p){
	int ret=1,now=base;
	while (p){
		if (p & 1) ret=(ll)ret*now%mod;
		now=(ll)now*now%mod; p>>=1;
	}
	return ret;
}

int getC(int n, int k){
	if (k<0 || k>n)
		return 0;
	return (ll)fact[n] * dfact[k] % mod * (ll)dfact[n-k] % mod;
}

int go (int len, int MAX){
	int ret = (ll)getC(k,len-MAX) * fact[len-MAX] % mod;
	if (len<=2*MAX)
		ret = (ll)ret * ret % mod * (ll)POWER(k,2*MAX-len) % mod;
	else
		ret = (ll)ret * getC(k-(len-2*MAX),MAX) % mod * (ll)fact[MAX] % mod;
	return ret;
}

int main(){
	cin >> k >> w;
	fact[0]=dfact[0]=1;
	for (int i=1; i<MAXN; i++){
		fact [i]=(ll)fact[i-1]*i%mod;
	//	dfact[i]=POWER(fact[i],mod-2);
	}
	dfact[1]=1;
	for (int i=2; i<MAXN; i++){
		dfact[i] = ((ll)-dfact[mod%i] * (ll)(mod/i)) % mod;
		if (dfact[i]<0) dfact[i]+=mod;
	}
	for (int i=1; i<MAXN; i++)
		dfact[i] = (ll)dfact[i-1] * dfact[i] % mod;
	int ans = 0;
	for (int i=1; i<=k; i++)
		ans = ((ll)ans+(ll)go(w+i,w)-go(w+i,w-1)+mod)%mod;
	cout << ans << endl;
	return 0;
}