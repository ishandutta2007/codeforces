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
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int maxN= 300+5;

bool mark[maxN];
int n,dfsNum;
int l[maxN], r[maxN], par[maxN];
queue <int> leaf;
vector <int> res;
vector <int> adj[maxN];

inline void dfs (int v){
	mark[v]=true; l[v]= dfsNum++;
	for (int i=0;i<(int)adj[v].size();i++){
		int tmp= adj[v][i];
		if (!mark[tmp]){
			par[tmp]= v;
			dfs (tmp);
		}
	}
	r[v]= dfsNum++;
}
/******************************/
inline void add (int x, int y){
	int curSize= res.size();
	while (y!=x){
		res.push_back(y); y=par[y];
	}
	reverse (res.begin() + curSize, res.end());
}
/******************************/
int main(){
	scanf ("%d", &n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf ("%d%d", &x, &y);
		adj[x].push_back (y);
		adj[y].push_back (x);
	}

	int barg;
	while (scanf ("%d", &barg)!=EOF){
		leaf.push (barg); 
	}
	dfs (1);
	res.push_back (1);
	int cur=1;
	while (!leaf.empty()){
		int v= leaf.front(); leaf.pop();
		add (cur, v);
		if (leaf.empty()){
			while (v!=1){
				v=par[v];
				res.push_back (v);
			}
			break;
		}

		int next= leaf.front();
		v=par[v];
		while (l[next]<l[v] || r[v]<r[next]){
			res.push_back (v); v=par[v];
		}
		res.push_back (v);
		cur=v;
	}

	if ((int)res.size()== 2*n-1){
		for (int i=0;i<(int)res.size();i++)
			printf ("%d ", res[i]);
		printf ("\n");
	}
	else
		printf ("-1\n");

	return 0;
}