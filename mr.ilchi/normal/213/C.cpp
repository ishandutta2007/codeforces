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

const int MAXN = 300+10;
const int dx[] = {0,1};
const int dy[] = {1,0};

int n;
int mat[MAXN][MAXN];
int dp [2*MAXN][MAXN][MAXN];

bool good (pii &A) { return A.first>0 && A.first<=n && A.second>0 && A.second<=n; }

int main(){
	cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			cin >> mat[i][j];
	memset(dp,128,sizeof dp);
	dp[2][1][1] = mat[1][1];
	for (int i=2; i<2*n; i++){
		int minx = max(1,i-n);
		int maxx = min(n,i-1);
		for (int j=minx,jj=i-minx; j<=maxx; j++,jj--)
			for (int k=j,kk=i-j; k<=maxx; k++,kk--)
				for (int m1=0; m1<2; m1++)
					for (int m2=0; m2<2; m2++){
						pii t1 = pii(j+dx[m1],jj+dy[m1]);
						pii t2 = pii(k+dx[m2],kk+dy[m2]);
						if (good(t1) && good(t2)){
							int tmp = dp[i][j][k] + mat[t1.first][t1.second];
							if (t1!=t2)
								tmp+= mat[t2.first][t2.second];
							dp[i+1][t1.first][t2.first] = max(dp[i+1][t1.first][t2.first],tmp);
						}
					}
	}
	cout << dp[2*n][n][n] << endl;
	return 0;
}