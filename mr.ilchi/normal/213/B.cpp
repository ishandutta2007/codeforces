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

const int MAXN = 100+10;
const int mod = 1000000007;

int n;
int a[MAXN];
int C[MAXN][MAXN],dp[MAXN][MAXN];

int main(){
	for (int i=0; i<MAXN; i++){
		C[i][0]=1;
		for (int j=1; j<=i; j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	cin >> n;
	for (int i=0; i<10; i++)
		cin >> a[i];
	for (int i=a[1]; i<=n; i++)
		dp[1][i] = 1;
	for (int i=2; i<10; i++){
		for (int j=a[i]; j<=n; j++)
			for (int k=a[i]; k<=j; k++)
				dp[i][j] = (dp[i][j] + (ll)dp[i-1][j-k] * C[j][k])%mod;
	}
	ll ans = 0;
	for (int j=min(1,a[0]); j<=n; j++)
		for (int k=a[0]; k<j; k++)
			ans = (ans + (ll)dp[9][j-k] * C[j-1][k]) % mod;
	cout << ans << endl;
	return 0;
}