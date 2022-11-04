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

const int maxN = 500 + 5;
const int inf = 1000 * 1000 * 1000;

int n,m;
int mat[maxN][maxN];
int sc[maxN][maxN],sr[maxN][maxN];
int dp[2][maxN][maxN][2];

int main(){

	cin >> n >> m;

	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++){
			cin >> mat[i][j];
			sc[i][j]= sc[i-1][j] + mat[i][j];
			sr[i][j]= sr[i][j-1] + mat[i][j];
		}

	for (int i=0; i<maxN; i++)
		for (int j=0; j<maxN; j++)
			for (int z=0; z<2; z++)
				for (int k=0; k<2; k++)
					dp[z][i][j][k] = -inf;

	int ans = -inf;

	for (int i=1; i+2<=n; i++)
		for (int j=1; j+2<=m; j++){
			dp[0][i][j][0] = sr[i][j+2]-sr[i][j-1] + sr[i+2][j+2]-sr[i+2][j-1] + mat[i+1][j+2];
			dp[0][i][j][1] = dp[0][i][j][0] - mat[i+1][j+2] + mat[i+1][j];
			ans = max(ans,dp[0][i][j][0]);
		}

	int cur=0,oth=1;

	for (int k=5; k<=min(n,m); k+=2){
		swap(cur,oth);
		for (int i=1; i+k-1<=n; i++)
			for (int j=1; j+k-1<=m; j++){
				dp[cur][i][j][0] = dp[oth][i+2][j][1] + sr[i][j+k-1]-sr[i][j-1] + sc[i+k-1][j+k-1]-sc[i][j+k-1] + mat[i+k-1][j+k-2];
				dp[cur][i][j][1] = dp[oth][i][j+2][0] + sr[i+k-1][j+k-1]-sr[i+k-1][j-1] + sc[i+k-2][j]-sc[i-1][j] + mat[i][j+1];
				ans = max(ans,dp[cur][i][j][0]);
			}
	}

	cout << ans << endl;

	return 0;
}