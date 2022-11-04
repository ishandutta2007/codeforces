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
typedef pair<int,int> pii;
typedef complex<double> point;

const int MAXN = 1000+10;
const int mod = 1000000007;

int fact[MAXN];
int C [MAXN][MAXN];
int dp[50][MAXN][MAXN];

int main(){
	for (int i=0; i<MAXN; i++){
		C[i][0] = 1;
		for (int j=1; j<=i; j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
	for (int c = 0; c < 50; c++)
		for (int sum = 0; sum < MAXN; sum++)
			for (int m = 0; m < MAXN; m++){
				if (c == 0)
					dp[c][sum][m] = (sum == 0);
				else if (m == 0)
					dp[c][sum][m] = (sum == 0) && (c == 1);
				else
					dp[c][sum][m] = (dp[c][sum][m-1] + ((sum>=m) ? (dp[c-1][sum-m][m-1]) : (0))) % mod;
			}
	fact[0] = 1;
	for (int i=1; i<MAXN; i++)
		fact[i] = (LL)fact[i-1] * i % mod;
	int t; cin >> t;
	for (int o=0; o<t; o++){
		int k,n; cin >> n >> k;
		if (k >= 50)
			cout << 0 << endl;
		else{
			int ret = 0;
			for (int sum = 0; sum <= n-k; sum++)
				ret = (ret + (LL)dp[k][sum][sum] * fact[k] % mod * C[n-sum][k]) % mod;
			cout << ret << endl;
		}
	}
	return 0;
}