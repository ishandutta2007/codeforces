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

const int MAXN = 250+10;
const int mod = 1000000007;

bool fh[MAXN][MAXN],fv[MAXN][MAXN];
char mat[4*MAXN][4*MAXN];
int n,m;
int dp[MAXN],test[MAXN];

int main(){
	scanf("%d%d", &n, &m);
	for (int i=1; i<=4*n+1; i++)
		scanf("%s",&mat[i][1]);
	for (int i=3; i<=4*n+1; i+=4)
		for (int j=3; j<=4*m+1; j+=4){
			int cnt = 0;
			for (int ii=-1; ii<=1; ii+=1)
				for (int jj=-1; jj<=1; jj++)
					cnt+= (mat[i+ii][j+jj]=='O');
			int x = i/4 + 1;
			int y = j/4 + 1;
			fv [x][y] = true;
			fh [x][y] = true;
			if (cnt==2 || cnt==3)
				fv[x][y]=(mat[i-1][j+1]=='O'), 
				fh[x][y]=(mat[i-1][j-1]=='O');
			if (cnt==6)
				fv[x][y]=(mat[i][j-1]=='O'),
				fh[x][y]=(mat[i-1][j]=='O');
		}
	dp[0] = 1;
	for (int i=1; i<=m; i++){
		bool allV = (n%2==0);
		for (int j=1; j<=n; j++)
			allV&=fv[j][i];
		dp[i] = allV * dp[i-1];
		if (i==1)
			continue;
		memset(test,0,sizeof test);
		test[0] = 1;
		for (int j=1; j<=n; j++){
			if (fh[j][i-1] && fh[j][i])
				test[j] = (test[j] + test[j-1]) % mod;
			if (fv[j][i-1] && fv[j][i] && fv[j-1][i-1] && fv[j-1][i])
				test[j] = (test[j] + test[j-2]) % mod;
		}
		for (int j=1; j<=n; j++)
			allV&=fv[j][i-1];
		dp[i] = (dp[i] + (ll)(test[n] - allV) * dp[i-2]) % mod;
	}
	printf("%d\n" , (dp[m]+mod)%mod);
	return 0;
}