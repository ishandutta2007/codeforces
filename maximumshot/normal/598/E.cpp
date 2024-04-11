#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve()
{
	vec< vec< vec< ll > > > dp(31, vec< vec< ll > >(31, vec< ll >(51, inf64)));
	// dp[n][m][k]

	for(int k = 1;k <= 50;k++)
	for(int n = 1;n <= 30;n++) {
		for(int m = 1;m <= 30;m++) {
			dp[n][m][0] = 0;	
			if(n * m == k) dp[n][m][k] = 0;
		}
	}
	

	for(int k = 1;k <= 50;k++) {
		for(int n = 1;n <= 30;n++) {
			for(int m = 1;m <= 30;m++) {
				for(int k1 = 0;k1 <= k;k1++) {

					//if(n == 1 && m == 2 && k == 1 && k1 == 1) cout << "DA " << dp[n][1][k1] << " " << dp[n][1];

					for(int i = 1;i < n;i++) {
						dp[n][m][k] = min(dp[n][m][k], dp[i][m][k1] + 1ll * m * m + dp[n - i][m][k - k1]);
					}
					for(int j = 1;j < m;j++) {
						dp[n][m][k] = min(dp[n][m][k], dp[n][j][k1] + 1ll * n * n + dp[n][m - j][k - k1]);
					}
				}
			}
		}
	}
	
	// 50 * 30 * 30 * 50 * 60

	int t, n, m, k;
	cin >> t;

	for(;t;t--) {
		cin >> n >> m >> k;
		cout << dp[n][m][k] << '\n';
	}

	return true;
} 

int main() {
	
	//while(solve());
	solve();	

	return 0;
}