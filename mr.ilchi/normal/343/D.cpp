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

const int MAXN = 1000000+10;

int n,que;
int fil[MAXN],emp[MAXN],mark[MAXN],poi[MAXN];
int type[MAXN],ver[MAXN];
vector <int> adj[MAXN];
set <int> SET;
set <int> store[MAXN];
vector <int> Q[MAXN][3];

inline int merge (int x, int y){
	if (store[x].size() < store[y].size())
		swap(x,y);
	for (set <int> :: iterator it = store[y].begin(); it!=store[y].end(); it++)
		store[x].insert(*it);
	return x;
}

inline void dfs (int v){
	mark[v] = 1;
	for (int i=0; i<(int)Q[v][0].size(); i++)
		SET.insert(Q[v][0][i]);
	for (int i=0; i<(int)adj[v].size(); i++){
		int temp = adj[v][i];
		if (!mark[temp])
			dfs(temp);
	}
	for (int i=0; i<(int)Q[v][2].size(); i++){
		set <int> :: iterator it = SET.upper_bound(Q[v][2][i]); 
		if (it!=SET.begin()){
			it--;
			fil[Q[v][2][i]] = *it;
		}
	}
	for (int i=0; i<(int)Q[v][0].size(); i++)
		SET.erase(Q[v][0][i]);
	poi[v] = v;
	for (int i=0; i<(int)Q[v][1].size(); i++)
		store[v].insert(Q[v][1][i]);
	int cur = v;
	for (int i=0; i<(int)adj[v].size(); i++){
		int temp = adj[v][i];
		if (mark[temp] == 2)
			cur = merge(cur, poi[temp]); 
	}
	poi[v] = cur;
	for (int i=0; i<(int)Q[v][2].size(); i++){
		set <int> :: iterator it = store[cur].upper_bound(Q[v][2][i]); 
		if (it!=store[cur].begin()){
			it--;
			emp[Q[v][2][i]] = *it;
		}
	}
	mark[v] = 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=0; i<n-1; i++){
		int e1,e2; cin >> e1 >> e2;
		e1--; e2--;
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}
	cin >> que;
	memset(fil, -1, sizeof fil);
	memset(emp, 0, sizeof emp);
	for (int i=1; i<=que; i++){
		cin >> type[i] >> ver[i]; 
		type[i]--; ver[i]--;
		Q[ver[i]][type[i]].push_back(i);
	}
	dfs(0);
	for (int i=1; i<=que; i++) if (type[i] == 2)
		cout << (emp[i] < fil[i]) << '\n';
	return 0;
}