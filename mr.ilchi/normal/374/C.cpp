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

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
const int MAXN = 1000+10;
const string DIMA = "DIMA";

char mat[MAXN][MAXN];
int mark[MAXN][MAXN];
int n,m;
int dp[MAXN][MAXN];
vector <pii> adj[MAXN][MAXN];

bool dfs (int x, int y){
	mark[x][y] = 1;
	dp[x][y] = 1;
	for (int i=0; i<(int)adj[x][y].size(); i++){
		int xx = adj[x][y][i].first;
		int yy = adj[x][y][i].second;
		if (mark[xx][yy] == 0){
			if (dfs(xx,yy))
				return true;
			dp[x][y] = max(dp[x][y], dp[xx][yy] + 1);
		}
		else if (mark[xx][yy]==1)
			return true;
		else
			dp[x][y] = max(dp[x][y], dp[xx][yy] + 1);
	}
	mark[x][y] = 2;
	return false;
}

int main(){
	cin >> n >> m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> mat[i][j];
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			int pos = DIMA.find(mat[i][j]);
			pos = (pos+1)%4;
			for (int k=0; k<4; k++){
				int ii = i + dx[k];
				int jj = j + dy[k];
				if (ii>=0 && ii<n && jj>=0 && jj<m && mat[ii][jj]==DIMA[pos]){
					adj[i][j].push_back(pii(ii,jj));
				}
			}
		}
	}
	for (int i=0; i<n; i++) 
		for (int j=0; j<m; j++) if (mark[i][j] == 0){
			if (dfs(i,j)){
				cout << "Poor Inna!" << endl;
				return 0;
			}
		}
	int ans = 0;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) if (mat[i][j] == 'D')
			ans = max(ans, dp[i][j]);
	if (ans < 4)
		cout << "Poor Dima!" << endl;
	else
		cout << ans/4 << endl;
	return 0;
}