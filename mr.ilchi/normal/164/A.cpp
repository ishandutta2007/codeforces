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

const int maxN = 100 * 1000 + 10;

bool mark[maxN],vis[maxN];
int n,e;
int f[maxN];
vector <int> adj[maxN],bak[maxN];

void dfs (int v){
	mark[v] = true;
	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		if (!mark[tmp])
			dfs (tmp);
	}
}

void dfs2 (int v){
	vis[v] = true;
	for (int i=0; i<(int)bak[v].size(); i++){
		int tmp = bak[v][i];
		if (!vis[tmp])
			dfs2 (tmp);
	}
}

int main(){

	scanf ("%d%d" , &n, &e);

	for (int i=1; i<=n; i++) scanf ("%d" , &f[i]);

	for (int i=1; i<=e; i++){
		int x,y; scanf ("%d%d" , &x, &y);
		if (f[y]==1)
			continue;
		adj[x].push_back(y);
		bak[y].push_back(x);
	}

	for (int i=1; i<=n; i++) if (f[i]==1 && !mark[i])
		dfs (i);
	for (int i=1; i<=n; i++) if (f[i]==2 && !vis [i])
		dfs2(i);

	for (int i=1; i<=n; i++){
		if (mark[i] && vis[i])
			printf ("1\n");
		else
			printf ("0\n");
	}

	return 0;
}