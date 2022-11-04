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
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxN= 100000 + 5;

bool mark[maxN];
int n,root;
int d[maxN];
ll dp[maxN];
vector <int> adj[maxN], child[maxN];

inline bool cmp (const int &a1, const int &a2){
	return dp[a1] > dp[a2];
}
/****************************************/
inline void dfs (int v){
	mark[v]= true;
	for (int i=0;i<(int)adj[v].size();i++){
		int tmp= adj[v][i];
		if (!mark[tmp] && d[tmp]){
			d[tmp]--;
			dfs (tmp);
			child[v].push_back (tmp);
		}
	}

	sort (child[v].begin(), child[v].end(), cmp);

	for (int i=0;i<(int)child[v].size();i++) if (d[v]){
		d [v]--;
		dp[v]+= dp[child[v][i]] + 2;
	}

	for (int i=0;i<(int)child[v].size();i++){
		int mines= min(d[v], d[child[v][i]]);
		d[v]-=mines, d[child[v][i]]-= mines;
		dp[v]+= 2*mines;
	}
}
/******************************************/
int main(){
	scanf ("%d", &n);
	for (int i=1;i<=n;i++)
		scanf ("%d", &d[i]);

	for (int i=1;i<n;i++){
		int x,y;
		scanf ("%d%d", &x, &y);
		adj[x].push_back (y);
		adj[y].push_back (x);
	}

	scanf ("%d", &root);

	if (d[root]==0){
		cout << 0 << endl;
		return 0;
	}

	dfs (root);

	cout << dp[root] << endl;

	return 0;
}