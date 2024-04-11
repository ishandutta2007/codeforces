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

bool mark[4000],vis[4000];
int n;
int x[200],y[200];
vector <int> adj[4000];

void dfs (int v){
	vis[v] = true;
	for (int i=0; i<(int)adj[v].size(); i++) if (!vis[adj[v][i]])
		dfs(adj[v][i]);
}

int main(){
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> x[i] >> y[i];
		mark[x[i]] = true;
		mark[y[i]+1100] = true;
		adj[x[i]].push_back(y[i]+1100);
		adj[y[i]+1100].push_back(x[i]);
	}
	int cnt = 0;
	for (int i=1; i<=2200; i++) if (mark[i] && !vis[i]){
		dfs(i);
		cnt++;
	}
	cout << cnt-1 << endl;
	return 0;
}