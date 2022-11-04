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

const int MAXN = 300 + 10; 
const LL inf = (1LL<<60);

int n,m,k;
int lo[1<<20],hi[1<<20],c[1<<20];
LL dp[MAXN][MAXN],full[MAXN][MAXN];

int main(){
	cin >> n >> m >> k;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			full[i][j] = inf;
	for (int i=0; i<m; i++){
		cin >> lo[i] >> hi[i] >> c[i];
		lo[i]--; hi[i]--;
		full[lo[i]][hi[i]] = min(full[lo[i]][hi[i]], (LL)c[i]);
	}
	for (int len=n; len>0; len--)
		for (int i=0; i+len<=n; i++){
			if (i!=0) full[i][i+len-1] = min(full[i][i+len-1], full[i-1][i+len-1]);
			if (i+len!=n) full[i][i+len-1] = min(full[i][i+len-1], full[i][i+len]);
		}
	for (int len=1; len<=n; len++)
		for (int i=0; i+len<=n; i++)
			for (int k=0; k<len-1; k++)
				full[i][i+len-1] = min(full[i][i+len-1], full[i][i+k] + full[i+k+1][i+len-1]);
	for (int i=0; i<n; i++)
		for (int j=0; j<=n; j++)
			dp[i][j] = inf;
	for (int i=0; i<n; i++){
		dp[i][i+1] = full[0][i];
		dp[i][0] = 0;
		for (int j=1; j<=i; j++){
			if (i!=0)
				dp[i][j] = dp[i-1][j];
			for (int k=1; k<=j; k++)
				dp[i][j] = min(dp[i][j], full[i-k+1][i] + dp[i-k][j-k]);
		}
	}
	cout << (dp[n-1][k]!=inf ? dp[n-1][k] : -1) << endl;
	return 0;
}