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

const int maxN = 50 + 5;

const int dx[] = {0,-1,0,1};
const int dy[] = {-1,0,1,0};

char mat[maxN][maxN];
int n,m,cnt,code;
int mark[maxN][maxN];

int dfs (int x, int y){
	
	mark[x][y] = code;

	int ret = 1;

	for (int i=0; i<4; i++){
		
		int xx = x + dx[i];
		int yy = y + dy[i];
		
		if (xx>0 && xx<=n && yy>0 && yy<=m && mat[xx][yy]=='#' && mark[xx][yy]!=code){
			ret+= dfs(xx,yy);
		}
	}

	return ret;
}

int main(){

	cin >> n >> m;

	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++){
			cin >> mat[i][j];
			if (mat[i][j] == '#')
				cnt++;
		}

	if (cnt < 3){
		cout << -1 << endl;
		return 0;
	}

	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) if (mat[i][j] == '#'){
			mat[i][j] = '.';
			code++;
			for (int x=1; x<=n; x++)
				for (int y=1; y<=m; y++) if (mat[x][y] == '#'){
					int p = dfs(x,y);
					if (p != cnt-1){
						cout << 1 << endl;
						return 0;
					}
					x = n+1 , y=m+1;
				}
			mat[i][j] = '#';
		}

	cout << 2 << endl;

	return 0;
}