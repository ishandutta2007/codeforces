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

const int MAXN = 1000+10;

char mat[MAXN][MAXN];
int n,m;
int row[MAXN],col[MAXN];
ll ans;
ll cnt[MAXN][MAXN],sumx[MAXN][MAXN],sumy[MAXN][MAXN],dp[MAXN][MAXN];

ll getC (int x, int y, int xx, int yy) { x--; y--; return cnt [xx][yy] - cnt [x][yy] - cnt [xx][y] + cnt [x][y]; }
ll getX (int x, int y, int xx, int yy) { x--; y--; return sumx[xx][yy] - sumx[x][yy] - sumx[xx][y] + sumx[x][y]; }
ll getY (int x, int y, int xx, int yy) { x--; y--; return sumy[xx][yy] - sumy[x][yy] - sumy[xx][y] + sumy[x][y]; }

ll go (){
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++){
			cnt [i][j] = cnt [i-1][j] + cnt [i][j-1] - cnt [i-1][j-1] + (mat[i][j]=='.');
			sumx[i][j] = sumx[i-1][j] + sumx[i][j-1] - sumx[i-1][j-1] + (mat[i][j]=='.' ? i : 0);
			sumy[i][j] = sumy[i-1][j] + sumy[i][j-1] - sumy[i-1][j-1] + (mat[i][j]=='.' ? j : 0);
		}
	row[0] = m+1;
	for (int i=1; i<=n; i++){
		row[i] = m+1;
		for (int j=m; j>0; j--) if (mat[i][j]=='X')
			row[i] = j;
	}
	col[0] = n+1;
	for (int j=1; j<=m; j++){
		col[j] = n+1;
		for (int i=n; i>0; i--) if (mat[i][j]=='X')
			col[j] = i;
	}
	memset(dp,0,sizeof dp);
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++) if (mat[i][j]=='.'){
			if (row[i-1]>j || (row[i]>row[i-1] && row[i]<j)){
				dp[i][j] = dp[i-1][j] + (row[i]<j ? j-row[i] : j); 
				continue;
			}
			else if (col[j]>i)
				dp[i][j] = getC(1,1,i,j);
			else
				dp[i][j] = getC(col[j]+1,1,i,j) + dp[col[j]][j-1];
			if (row[i]<j)
				dp[i][j]-= (row[i]-1);
		}
	}
	ll ret = 0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) if (mat[i][j]=='.')
			ret+= cnt[i][j] * i + cnt[i][j] * j - sumx[i][j] - sumy[i][j] + 2 * (cnt[i][j]-dp[i][j]);	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			cin >> mat[i][j];
	ans+= go(); 
	for (int i=1; i<=n; i++) reverse(mat[i]+1,mat[i]+m+1);
	ans+= go();
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) if (mat[i][j]=='.'){
			ans-= (row[i]<j) ? ((j-1)*j/2+2*(row[i]-1)-(j-row[i])) : ((j-1)*j/2);
			ans-= (col[j]<i) ? ((i-1)*i/2+2*(col[j]-1)-(i-col[j])) : ((i-1)*i/2);
		}
	cout << fixed << setprecision(10) << (ldb)(2*ans)/(ldb)(cnt[n][m] * cnt[n][m]) << endl;
	return 0;
}