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

int n,e,code;
int h [maxN],dp[maxN],ind [maxN],par[maxN];
int e1[maxN],e2[maxN],cost[maxN],mark[maxN];
vector <int> adj[maxN],index[maxN];

struct UnionFind{
	
	int par[maxN],h[maxN];

	void norm (int n){
		for (int i=1; i<=n; i++)
			h[i]=0, par[i]=i;
	}

	int root (int x){
		return par[x]!=x ? par[x] = root(par[x]) : x;
	}

	bool Union (int x, int y){
		x = root(x);
		y = root(y);
		if (x==y)
			return false;
		(h[x]<=h[y]) ? (par[y] = x) : (par[x] = y);
		h[y]+= h[x]==h[y];
	}
}gr;

void dfs (int v, int hei){
	
	ind[v] = code; h[v] = hei;

	dp[v] = hei;

	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		if (ind[tmp]!=code){
			par[tmp] = index[v][i];
			dfs (tmp,hei+1);
			dp[v] = min (dp[v],dp[tmp]);
			if (dp[tmp]>h[v])
				mark[index[v][i]] = 2;
		}
		else if (index[v][i]!=par[v])
			dp[v] = min (dp[v],h[tmp]);
	}
}

void solve (vector <int> &Q){

	code++;
	vector <int> ver;
	for (int i=0; i<(int)Q.size(); i++){
		int x = e1[Q[i]]; x = gr.root(x);
		int y = e2[Q[i]]; y = gr.root(y);
		if (ind[x]!=code) { ind[x]=code; adj[x].clear(); ver.push_back(x); index[x].clear(); }
		if (ind[y]!=code) { ind[y]=code; adj[y].clear(); ver.push_back(y); index[y].clear(); }
		adj[x].push_back (y); index[x].push_back (Q[i]);
		adj[y].push_back (x); index[y].push_back (Q[i]);
	}

	code++;
	for (int i=0; i<(int)ver.size(); i++) if (ind[ver[i]]!=code)
		dfs(ver[i],0);
}


bool cmp (const int &a, const int &b){
	return cost[a]<cost[b];
}

void go (){
	
	vector <int> E;
	for (int i=1; i<=e; i++) 
		E.push_back(i);

	sort(E.begin(),E.end(),cmp);

	gr.norm(n);

	for (int i=0; i<(int)E.size(); i++){
		int j = i;
		while (j<(int)E.size() && cost[E[i]]==cost[E[j]])
			j++;
		vector <int> edge;
		for (int z=i; z<j; z++){
			int x = e1[E[z]];
			int y = e2[E[z]];
			if (gr.root(x)!=gr.root(y)){
				edge.push_back(E[z]);
				mark[E[z]] = 1;
			}
		}
		solve(edge);
		for (int z=i; z<j; z++)
			gr.Union(e1[E[z]],e2[E[z]]);
		i = j-1;
	}
}

int main(){
	
	scanf ("%d%d" , &n, &e);
	for (int i=1; i<=e; i++)
		scanf ("%d%d%d" , &e1[i] , &e2[i], &cost[i]);

	go();

	for (int i=1; i<=e; i++){
		if (mark[i]==0) puts ("none");
		if (mark[i]==1) puts ("at least one");
		if (mark[i]==2) puts ("any");
	}

	return 0;
}