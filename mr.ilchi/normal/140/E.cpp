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

const int MAXL = 5000+10;
const int MAXN = 1000000+10;

int n,m,mod;
int l[MAXN],dp[MAXL],fact[MAXL];
int c[MAXL][MAXL];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> mod;
	for (int i=1; i<=n; i++)
		cin >> l[i];
	c[1][1] = 1;
	for (int i=2; i<MAXL; i++)
		for (int j=2; j<=min(m,i); j++)
			c[i][j] = (c[i-1][j-1] + (ll)c[i-1][j] * (j-1)) % mod;
	for (int j=1; j<=l[1]; j++)
		dp[j] = c[l[1]][j];
	fact[0]=1;
	for (int i=1; i<MAXL; i++)
		fact[i]=(ll)fact[i-1]*i%mod;
	int ans = 0;
	for (int i=2; i<=n+1; i++){
		int tot = 0 , cur = m;
		for (int j=1; j<=l[i-1]; j++){
			tot = (tot + (ll)cur * dp[j]) % mod;
			cur = (ll)cur * (m-j) % mod;
		}
		ans = tot;
		for (int j=1; j<=l[i]; j++)
			dp[j] = (j<=l[i-1]) ? ((ll)c[l[i]][j] * (tot-(ll)dp[j]*fact[j]%mod) % mod) : ((ll)c[l[i]][j] * tot % mod);
	}
	if (ans<0) ans+=mod;
	cout << ans << endl;
	return 0;
}