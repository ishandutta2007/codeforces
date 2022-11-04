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

const int maxD = 2000 + 10;
const int maxN = 1000000 + 10;

bool mark[maxN];
bool g[maxD][maxD];
int n,e;
int pos[maxN],par[maxN];
vector <int> adj[maxN],group[maxN],graph[maxN];

void Union (int a, int b){
	graph[a].push_back(b);
	graph[b].push_back(a);
}

void dfs (int v, int comp){
	group[comp].push_back(v);
	mark[v] = true;
	for (int i=0; i<(int)graph[v].size(); i++){
		int tmp= graph[v][i];
		if (!mark[tmp])
			dfs(tmp,comp);
	}
}

int main(){
	scanf("%d%d" , &n, &e);
	for (int i=1; i<=e; i++){
		int x,y; scanf("%d%d" , &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int posMin = 1;
	for (int i=1; i<=n; i++) if (adj[i].size()<adj[posMin].size())
		posMin = i;
	for (int i=1; i<=n; i++) 
		par[i]=i;
	for (int i=0; i<(int)adj[posMin].size(); i++){
		mark[adj[posMin][i]] = true;
		pos [adj[posMin][i]] = i;
	}
	for (int i=1; i<=n; i++) if (!mark[i]) 
		Union(i,posMin);
	for (int i=0; i<(int)adj[posMin].size(); i++){
		int v=adj[posMin][i],cnt=0;
		for (int j=0; j<(int)adj[v].size(); j++){
			int tmp = adj[v][j];
			if (!mark[tmp])
				cnt++;
			else
				g[i][pos[tmp]] = true;
		}
		if (cnt < n-(int)adj[posMin].size())
			Union(posMin,v);
	}
	for (int i=0; i<(int)adj[posMin].size(); i++)
		for (int j=i+1; j<(int)adj[posMin].size(); j++) if (!g[i][j])
			Union(adj[posMin][i],adj[posMin][j]);
	memset(mark,false,sizeof mark);
	int comp = 0;
	for (int i=1; i<=n; i++) if (!mark[i]){
		comp++; dfs(i,comp);
	}
	printf("%d\n",comp);
	for (int i=1; i<=n; i++) if (!group[i].empty()){
		printf("%d " , (int)group[i].size());
		for (int j=0; j<(int)group[i].size(); j++)
			printf ("%d " , group[i][j]);
		printf("\n");
	}
	return 0;
}