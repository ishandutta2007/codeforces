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

const int MAXN= 100000+10;
const int mod = 1000000007;

int n,m,x;
int dp[2][400][400];

inline void add (int &A, const int &B) { A+=B; A%=mod; }

int main(){
	cin >> n >> m >> x;
	if (n > m){
		cout << 0 << endl;
		return 0;
	}
	dp[0][0][0] = 1;
	for (int i=0; i<m; i++){
		int cur = i%2;
		int oth = 1-i%2;
		for (int j=0; j<=n; j++)
			for (int k=0; k<=j; k++)
				dp[oth][j][k] = 0;
		for (int j=0; j<=n; j++)
			for (int k=0; k<=j; k++){
				if (i!=x-1)
					add(dp[oth][j][k], dp[cur][j][k]);
				if (k>0 && i!=x-1)
					add(dp[oth][j][k-1], dp[cur][j][k]);
				if (j<n)
					add(dp[oth][j+1][k+1], dp[cur][j][k]);
				if (j<n)
					add(dp[oth][j+1][k], dp[cur][j][k]);
			}
	}
	int ret = dp[m%2][n][0];
	for (int i=1; i<=n; i++)
		ret = (LL)ret * i % mod;
	cout << ret << endl;
	return 0;
}