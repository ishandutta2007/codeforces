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

const int maxN = 100 * 1000 + 10;

bool mark[maxN];
int n,e,k;
int h[maxN],sum[maxN],mini[maxN];
int par[maxN][20];
vector <int> adj[maxN];

void dfs (int v , int hei){

	mark[v] = true; h[v] = hei;

	if (v==1){
		par[v][0] = 1;
		for (int i=1; i<=17; i++)
			par[v][i] = 1;
	}
	else{
		for (int i=1; i<=17; i++)
			par[v][i] = par[par[v][i-1]][i-1];
	}

	mini[v] = hei;

	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		if (!mark[tmp]){
			par[tmp][0] = v;
			dfs (tmp,hei+1);
			mini[v] = min(mini[v] , mini[tmp]);
		}
		else if (tmp!=par[v][0]){
			mini[v] = min(mini[v] , h[tmp]);
		}
	}
}

void DFS (int v){

	mark[v] = true;
	
	if (v!=1 && mini[v]>h[par[v][0]])
		sum[v]++;

	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		if (!mark[tmp]){
			sum[tmp] = sum[v];
			DFS (tmp);
		}
	}
}

int lca (int x, int y){

	if (x==y)
		return x;
	
	if (h[x]<h[y]) swap(x,y);
	
	for (int pw=17; pw>=0; pw--) if (h[par[x][pw]]>=h[y]) x = par[x][pw];

	for (int pw=17; pw>=0; pw--) if (par[x][pw]!=par[y][pw]) x=par[x][pw],y=par[y][pw];

	if (x!=y) x=par[x][0] , y=par[y][0];

	return x;
}

int main(){

	ios_base::sync_with_stdio(false);

	cin >> n >> e;

	for (int i=1; i<=e; i++){
		int e1,e2; cin >> e1 >> e2;
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}

	dfs (1,0); memset (mark,false, sizeof mark);
	DFS (1);

	cin >> k;

	for (int i=1; i<=k; i++){
		int e1,e2; cin >> e1 >> e2;
		int e3 = lca (e1,e2);
		cout << sum[e1] + sum[e2] - 2 * sum[e3] << endl;
	}

	return 0;
}