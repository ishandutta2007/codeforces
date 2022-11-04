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

const int MAXN = 40+5;

char mat[MAXN][MAXN];
int n,m;
int dp[MAXN][MAXN][MAXN][MAXN];

int get (int x, int xx, int y, int yy){
	if (x>xx || y>yy)
		return 0;
	int &ret = dp[x][xx][y+m][yy+m];
	if (ret!=-1)
		return ret;
	ret = 0;
	vector <bool> mark((xx-x+2)/2*(yy-y+2)/2+5,false);
	for (int i=x; i<=xx; i+=2){
		for (int j=y; j<=yy; j+=2) if ((i+j)%2==0){
			int r = (i+j)/2;
			int c = i - r;
			if (r<1 || r>n || c<1 || c>m) 
				continue;
			int NIM=0;
			if (mat[r][c]=='L')
				NIM = get(x,r+c-2,y,yy) ^ get(r+c+2,xx,y,yy);
			if (mat[r][c]=='R')
				NIM = get(x,xx,y,r-c-2) ^ get(x,xx,r-c+2,yy);
			if (mat[r][c]=='X')
				NIM = get(x,r+c-2,y,r-c-2) ^ get(x,r+c-2,r-c+2,yy) ^ get(r+c+2,xx,y,r-c-2) ^ get(r+c+2,xx,r-c+2,yy);
			if (NIM<(int)mark.size())
				mark[NIM] = true;
		}
	}
	for (int i=0; true; i++) if (!mark[i]){
		ret=i;
		break;
	}
	return ret;
}

int main(){
	cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			cin >> mat[i][j];
	memset(dp,-1,sizeof dp);
	int res;
	if (min(n,m)==1)
		res = max(n,m)%2;
	else
		res = get(2,(n+m)-(n+m)%2,(1-m)+(m%2==0),(n-1)-(n%2==0)) ^ get(3,(n+m)-(n%2==m%2),(1-m)+(m%2==1),(n-1)-(n%2==1));
	cout << (res ? "WIN" : "LOSE") << endl;
	return 0;
}