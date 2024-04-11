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

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

const int MAXN= 2000+10;
const int mod = 1000000007;

int n,m;
int dp[MAXN][MAXN],func[MAXN][MAXN],C[MAXN][MAXN],f0[MAXN][MAXN],f1[MAXN][MAXN],sum[MAXN][MAXN];

int main(){
	for (int i=0; i<MAXN; i++){
		C[i][0] = 1;
		for (int j=1; j<=i; j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
	cin >> n >> m;
	for (int i=2; i<=m; i++){
		dp[1][i] = 1;
		func[1][i] = (func[1][i-1] + (1-i)) % mod;
		sum [1][i] = sum[1][i-1] + 1;
	}
	for (int i=2; i<=n; i++){
		for (int j=2; j<=m; j++){
			dp[i][j]= ((LL)sum[i-1][j] * j + func[i-1][j]) % mod;
			sum [i][j] = (sum[i][j-1] + dp[i][j]) % mod;
			func[i][j] = (func[i][j-1] + (LL)(1-j) * dp[i][j]) % mod; 
		}
	}
	for (int j=2; j<=m; j++)
		for (int i=1; i<=n; i++){
			f0[j][i] = ((LL)f0[j][i-1] + (LL)dp[i][j] - dp[i-1][j]) % mod;
			f1[j][i] = ((LL)f1[j][i-1] + dp[i][j]) % mod;
		}
	int ret = 0;
	for (int i=1; i<=n; i++)
		for (int j=2; j<=m; j++)
			ret = (ret + (LL)(m-j+1) * (LL)f0[j][i] % mod * f1[j][n-i+1] % mod) % mod;
	ret%=mod; ret+=mod; ret%=mod;
	cout << ret << endl;
	return 0;
}