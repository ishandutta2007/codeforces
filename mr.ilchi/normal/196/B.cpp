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

char mat[1600][1600];
bool vis[1600][1600];
int n,m;
pii mark[1600][1600];

void dfs (int x, int y){

	int xx = (x%n); if (xx<0) xx+=n;
	int yy = (y%m); if (yy<0) yy+=m;

	if (mat[xx][yy]=='#')
		return;

	if (!vis[xx][yy]){
		vis[xx][yy] = true;
		mark[xx][yy] = pii(x,y);
	}	

	else if (pii(x,y)!=mark[xx][yy]){
		cout << "Yes" << endl;
		exit(0);
	}

	else 
		return;

	dfs (x-1,y);
	dfs (x+1,y);
	dfs (x,y-1);
	dfs (x,y+1);
}

int main(){

	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	int rx=0,ry=0;

	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++){
			cin >> mat[i][j];
			if (mat[i][j] == 'S'){
				rx = i , ry = j;
			}
		}

	dfs(rx,ry);

	cout << "No" << endl;

	return 0;
}