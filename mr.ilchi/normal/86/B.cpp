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
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXN = 1000+10;
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

char mat [MAXN][MAXN];
bool mark[MAXN][MAXN];
int n,m;
vector <pii> comp[MAXN][MAXN];


bool dfs (int x, int y, bool root=false){
	if (x<1 || x>n || y<1 || y>m || mark[x][y] || mat[x][y]!='.')
		return false;
	mark[x][y] = true;
	vector <pii> Q;
	if (dfs(x-1,y)) Q.push_back(pii(x-1,y));
	if (dfs(x+1,y)) Q.push_back(pii(x+1,y));
	if (dfs(x,y-1)) Q.push_back(pii(x,y-1));
	if (dfs(x,y+1)) Q.push_back(pii(x,y+1));
	if (!Q.empty()){
		vector <bool> mark(10,0);
		Q.push_back(pii(x,y));
		for (int i=0; i<(int)Q.size(); i++) 
			for (int d=0; d<4; d++){
				int xx = Q[i].first + dx[d];
				int yy = Q[i].second+ dy[d];
				if (isdigit(mat[xx][yy]))
					mark[mat[xx][yy]-'0'] = true;
			}
		int pos = -1;
		for (int i=0; i<10; i++) if (!mark[i]){
			pos = i; break;
		}
		assert(pos!=-1);
		for (int i=0; i<(int)Q.size(); i++)
			mat[Q[i].first][Q[i].second] = pos+'0';
		comp[x][y] = Q;
	}
	else if (root){
		if (isdigit(mat[x+1][y]))
			Q = comp[x+1][y];
		else
			Q = comp[x][y+1];
		Q.push_back(pii(x,y));
		for (int i=0; i<(int)Q.size(); i++)
			mat[Q[i].first][Q[i].second] = '.';
		vector <bool> mark(10,0);
		for (int i=0; i<(int)Q.size(); i++) 
			for (int d=0; d<4; d++){
				int xx = Q[i].first + dx[d];
				int yy = Q[i].second+ dy[d];
				if (isdigit(mat[xx][yy]))
					mark[mat[xx][yy]-'0'] = true;
			}
		int pos = -1;
		for (int i=0; i<10; i++) if (!mark[i]){
			pos = i; break;
		}
		assert(pos!=-1);
		for (int i=0; i<(int)Q.size(); i++)
			mat[Q[i].first][Q[i].second] = pos+'0';
		comp[x][y] = Q;
	}
	return mat[x][y]=='.';
}

int main(){
	memset(mat,'#',sizeof mat);
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			scanf(" %c", &mat[i][j]);
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++) if (mat[i][j]=='.'){
			if (mat[i-1][j]=='#' && mat[i+1][j]=='#' && mat[i][j-1]=='#' && mat[i][j+1]=='#'){
				cout << -1 << endl;
				return 0;
			}
			dfs(i,j,true);
		}
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++)
			printf("%c", mat[i][j]);
		printf("\n");
	}
	return 0;
}