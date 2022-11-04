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
#include <cstdlib>
#include <map>

using namespace std;

const int maxN= 5000+5;

bool mark[maxN];
int n;
int cost[maxN][maxN], par[maxN], res[maxN];
vector <int> Q[2][maxN];
vector <int> adj[maxN];
map <int,int> code;

inline void dfs (int v){
	mark[v]= true;
	for (int i=0;i<(int)adj[v].size();i++) if (!mark[adj[v][i]]){
		dfs (adj[v][i]);
		par[adj[v][i]]= v;
	}
}
/***********************************/
int main(){
	cin >> n;
	for (int i=1;i<=n;i++){
		int x; cin >> x;
		Q[0][i].push_back (x);
		code[x]= i;
	}

	for (int i=1;i<n;i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back (y);
		adj[y].push_back (x);
		cin >> cost[x][y];
		cost[y][x]= cost[x][y];
	}

	dfs (1);

	memset (res, -1, sizeof res);

	for (int t=0; true; t++){
		
		bool flag= false;
		for (int i=1;i<=n;i++) if (res[i]==-1)
			flag= true;

		if (flag==false)
			break;

		int now= t%2;
		int aft= (t+1)%2;

		for (int i=0;i<(int)Q[now][1].size();i++)
			res[code[Q[now][1][i]]]= t;

		for (int i=2;i<=n;i++){
			
			int p= par[i];

			for (int j= (int)Q[now][i].size()-1, c=cost[i][p]-1; j>=0 && c>=0; j--, c--){
				Q[aft][p].push_back (Q[now][i].back());
				Q[now][i].pop_back();
			}
		}

		Q[now][1].clear();
		for (int i=2;i<=n;i++)
			while (Q[now][i].size()){
				Q[aft][i].push_back (Q[now][i].back());
				Q[now][i].pop_back();
			}

		for (int i=2;i<=n;i++)
			sort (Q[aft][i].rbegin(), Q[aft][i].rend());
	}

	for (int i=1;i<=n;i++)
		cout << res[i] << ' ';
	cout << endl;

	return 0;
}