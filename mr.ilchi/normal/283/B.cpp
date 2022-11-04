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

const int MAXN = 200000+10;

bool cycle[MAXN][2];
bool mark[MAXN][2];
int n;
int a[MAXN];
LL cost[MAXN][2],deg[MAXN][2],next[MAXN][2];
vector <pii> adj[MAXN][2];

inline void addEdge (int e1, int t, int e2){
	if (e2>n || e2<=0)
		next[e1][t] = 0;
	else
		next[e1][t] = e2;
	adj[next[e1][t]][1-t].push_back(pii(e1,t));
	deg[next[e1][t]][1-t]++;
}

inline void getCycle (int x, int y){
	cycle[x][y] = true;
	for (int i=0; i<(int)adj[x][y].size(); i++){
		int f1 = adj[x][y][i].first;
		int f2 = adj[x][y][i].second;
		if (!cycle[f1][f2])
			getCycle(f1,f2);
	}
}

inline void dfs(int x, int y, LL h){
	h+=a[x];
	cost[x][y] = h;
	mark[x][y] = true;
	for (int i=0; i<(int)adj[x][y].size(); i++){
		int f1 = adj[x][y][i].first;
		int f2 = adj[x][y][i].second;
		if (!mark[f1][f2])
			dfs(f1,f2,h);
	}
}

int main(){
	cin >> n;
	for (int i=2; i<=n; i++)
		cin >> a[i];
	for (int i=2; i<=n; i++){
		addEdge(i, 0, i + a[i]);
		addEdge(i, 1, i - a[i]);
	}
	queue <pii> Q;
	for (int i=0; i<=n; i++)
		for (int j=0; j<2; j++) if (deg[i][j]==0)
			Q.push(pii(i,j));
	while (!Q.empty()){
		pii front = Q.front(); Q.pop();
		int nex = next[front.first][front.second];
		deg[next[front.first][front.second]][1-front.second]--;
		if (deg[nex][1-front.second] == 0)
			Q.push(pii(nex, 1-front.second));
	}
	deg[1][0] = 1;
	for (int i=0; i<=n; i++)
		for (int j=0; j<2; j++) if (deg[i][j]>0 && cycle[i][j]==false)
			getCycle(i,j);
	for (int i=0; i<=n; i++) 
		for (int j=0; j<2; j++) if (!cycle[i][j] && !mark[i][j])
			dfs(i,j,0);
	for (int i=1; i<n; i++){
		if (cycle[i+1][1])
			cout << -1 << endl;
		else
			cout << cost[i+1][1] + i << endl;
	}
	return 0;
}