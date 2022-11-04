/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long ll;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

const int MAXN= 100+10;
const int mod = 1000000007;

int n,k;
int C [MAXN][MAXN];
int dp[MAXN][MAXN*MAXN],way[2][MAXN];
ll m;

int POWER (ll base, ll p){
	ll ret=1, cur=base;
	while (p){
		if (p & 1) ret = ret * cur % mod;
		p>>=1;
		cur = cur * cur % mod;
	}
	return ret;
}

int main(){
	cin >> n >> m >> k;
	for (int i=0; i<=100; i++){
		C[i][0] = 1;
		for (int j=1; j<=i; j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
	for (int j=0; j<=n; j++){
		way[0][j] = POWER(C[n][j],m/n);
		way[1][j] = POWER(C[n][j],m/n+1);
	}	
	dp[0][0] = 1;
	for (int i=1; i<=n; i++){
		int rep = 0;
		if (i<=m%n) 
			rep++;
		for (int j=0; j<=k; j++){
			for (int z=0; z<=min(n,j); z++)
				dp[i][j] = (dp[i][j] + (ll)dp[i-1][j-z] * way[rep][z]) % mod; 
		}
	}
	cout << dp[n][k] << endl;
	return 0;
}