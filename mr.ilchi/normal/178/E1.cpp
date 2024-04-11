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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <complex>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int maxN = 2000 + 10;

bool mark[maxN][maxN];
char mat[maxN][maxN];
int n;
int row[maxN][maxN];
int col[maxN][maxN];

const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

void bfs (int x, int y){
	

	mark[x][y] = true;

	queue <pii> Q; Q.push(pii(x,y));

	while (!Q.empty()){

		int x = Q.front().first;
		int y = Q.front().second; Q.pop();

		for (int z=0; z<4; z++){
			int xx = x + dx[z];
			int yy = y + dy[z];
			if (xx<1 || xx>n || yy<1 || yy>n || mark[xx][yy] || mat[xx][yy]=='0') continue;
			mark[xx][yy] = true;
			Q.push(pii(xx,yy));
		}
	}
}

int main(){

	scanf ("%d" , &n);

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++){
			scanf (" %c" , &mat[i][j]); 
		}

	for (int i=n; i; i--)
		for (int j=n; j; j--) if (mat[i][j]=='1'){
			row[i][j] = row[i][j+1] + 1;
			col[i][j] = col[i+1][j] + 1;
		}

	int sq=0 , cir=0;

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) if (!mark[i][j] && mat[i][j]=='1'){
			bfs (i,j);
			if (row[i][j]==col[i][j])
				sq++;
			else
				cir++;
		}

	printf ("%d %d\n" , cir, sq);

	return 0;
}