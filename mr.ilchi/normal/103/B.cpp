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
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxN = 100 + 5;

bool mark[maxN];
int n,e;
vector <int> adj[maxN];

inline void dfs (int v){
	
	mark[v] = true;

	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		if (!mark[tmp])
			dfs (tmp);
	}
}

int main(){
	
	cin >> n >> e;

	if (n<3){
		cout << "NO" << endl;
		return 0;
	}

	for (int i=1; i<=e; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back (y);
		adj[y].push_back (x);
	}

	dfs (1);

	for (int i=1; i<=n; i++) if (!mark[i]){
		cout << "NO" << endl;
		return 0;
	}

	if (e==n)
		cout << "FHTAGN!" << endl; 
	else
		cout << "NO" << endl;
	
	return 0;
}