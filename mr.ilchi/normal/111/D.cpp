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

const int mod = 1000000007;
const int MAXN= 1000+10;
const int MAXF= 1000000+10;

int n,m,k;
int fact[MAXF],dfact[MAXF],prePow[MAXN],preDyn[MAXN];
ll dp[MAXN][MAXN];

ll POWER (int base, int p){
	int ret=1,cur=base;
	while (p){
		if (p & 1)
			ret = (ll)ret * cur % mod;
		cur = (ll)cur * cur % mod;
		p>>=1;
	}
	return ret;
}

int getC (int n, int k){
	return (n<k || k<0) ? (0) : ((ll)fact[n]*dfact[k]%mod*dfact[n-k]%mod);
}

int main(){
	fact[0] = dfact[0] = 1;
	for (int i=1; i<MAXF; i++){
		fact[i] = (ll)fact[i-1] * i % mod;
		dfact[i]= POWER(fact[i],mod-2);
	}
	cin >> m >> n >> k;
	dp[0][0] = 1;
	for (int i=1; i<=m; i++)
		for (int j=1; j<=m; j++)
			dp[i][j] = ((ll)dp[i-1][j] * j + dp[i-1][j-1]) % mod;
	if (n==1){
		cout << POWER(k,m) << endl;
		return 0;
	}
	ll ret = 0;
	for (int j=0; j<=m; j++){
		prePow[j] = POWER(j,(n-2)*m);
		preDyn[j] = (ll)dp[m][j] * dp[m][j] %mod * fact[j] %mod * fact[j] % mod;
	}

	for (int i=0; 2*i<=k; i++)
		for (int j=0; 2*i+j<=k && i+j<=m; j++)
			ret = (ret + (ll)preDyn[i+j] % mod * prePow[j] % mod * getC(k,i) % mod * getC(k-i,j) % mod * getC(k-i-j,i) % mod) % mod;
	cout << ret << endl;
	return 0;
}