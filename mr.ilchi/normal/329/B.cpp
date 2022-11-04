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

const int MAXN = 1000+10;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

char mat [MAXN][MAXN];
bool mark[MAXN][MAXN];
int n,m;
int dis [MAXN][MAXN];

inline void bfs (int rx, int ry){
	mark[rx][ry] = true;
	dis [rx][ry] = 0;
	queue <pii> Q;
	Q.push(pii(rx,ry));
	while (!Q.empty()){
		pii begin = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir ++){
			int xx = begin.first + dx[dir];
			int yy = begin.second + dy[dir];
			if (xx<0 || xx>=n || yy<0 || yy>=m || mark[xx][yy] || mat[xx][yy]=='T') continue;
			dis [xx][yy] = dis[begin.first][begin.second] + 1;
			mark[xx][yy] = true;
			Q.push(pii(xx,yy));
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	int ex = 0, ey = 0;
	int sx = 0, sy = 0;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++){
			cin >> mat[i][j];
			if (mat[i][j] == 'E')
				ex = i, ey = j;
			else if (mat[i][j] == 'S')
				sx = i, sy = j;
		}
	bfs(ex,ey);
	int ans = 0;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) if (isdigit(mat[i][j]) && mark[i][j] && dis[i][j]<=dis[sx][sy])
			ans+= mat[i][j] - '0';
	cout << ans << endl;
	return 0;
}