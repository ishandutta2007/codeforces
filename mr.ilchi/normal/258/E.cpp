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

const int MAXN = 100000+10;
const int MAXT = (1<<18);

bool mark[MAXN];
int n,que,now;
int c[MAXN],lo[MAXN],hi[MAXN];
int flag[MAXT], dp[MAXT];
vector <int> Q[MAXN],adj[MAXN];

inline int dfs (int v){
	mark[v] = true;
	lo[v] = hi[v] = now++;
	for (int i=0; i<(int)adj[v].size(); i++) if (!mark[adj[v][i]])
		hi[v]= dfs(adj[v][i]);
	return hi[v];
}

inline void add (int root, int lo, int hi, int l, int r, int cost){
	if (r<lo || hi<l)
		return;
	if (l<=lo && hi<=r){
		flag[root]+= cost;
		if (flag[root] > 0)
			dp[root] = hi-lo+1;
		else
			dp[root] = (lo!=hi) ? (dp[root<<1] + dp[(root<<1)+1]) : 0;
		return;
	}
	int mid = (lo+hi)/2;
	add(root<<1, lo, mid, l, r, cost);
	add((root<<1)+1, mid+1, hi, l, r, cost);
	dp[root] = (flag[root]==0) ? (dp[root<<1] + dp[(root<<1)+1]) : (hi-lo+1);
}

inline void go (int v){
	mark[v] = true;
	for (int i=0; i<(int)Q[v].size(); i++)
		add(1, 0, n-1, lo[Q[v][i]], hi[Q[v][i]], 1);
	if (!Q[v].empty())
		add(1, 0, n-1, lo[v], hi[v], 1);
	c[v] = max(0, dp[1]-1);
	for (int i=0; i<(int)adj[v].size(); i++) if (!mark[adj[v][i]])
		go(adj[v][i]);
	for (int i=0; i<(int)Q[v].size(); i++)
		add(1, 0, n-1, lo[Q[v][i]], hi[Q[v][i]], -1);
	if (!Q[v].empty())
		add(1, 0, n-1, lo[v], hi[v], -1);
}

int main(){
	cin >> n >> que;
	for (int i=0; i<n-1; i++){
		int e1,e2; cin >> e1 >> e2;
		e1--; e2--;
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}
	dfs(0);
	for (int o=0; o<que; o++){
		int a,b; cin >> a >> b;
		a--; b--;
		Q[a].push_back(b);
		Q[b].push_back(a);
	}
	memset(mark,false,sizeof mark);
	go(0);
	for (int i=0; i<n; i++)
		cout << c[i] << ' ';
	cout << endl;
	return 0;
}