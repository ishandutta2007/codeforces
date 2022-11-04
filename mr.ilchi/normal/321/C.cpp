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

bool del[MAXN];
char rank[MAXN];
int n,code;
int mark[MAXN],f[MAXN],sz[MAXN];
vector <int> Q;
vector <int> adj[MAXN];

inline void dfs (int v){
	mark[v] = code;
	sz[v] = 1;
	f[v] = 0;
	for (int i=0; i<(int)adj[v].size(); i++){
		int temp = adj[v][i];
		if (del[temp] || mark[temp]==code)
			continue;
		dfs(temp);
		f[v] = max(f[v], sz[temp]);
		sz[v]+=sz[temp];
	}
	Q.push_back(v);
}

inline void go (char ch, int root){
	code++;
	Q.clear();
	dfs(root);
	int tot = (int)Q.size();
	int pos = Q[0];
	for (int i=0; i<(int)Q.size(); i++){
		f[Q[i]] = max(f[Q[i]], tot - sz[Q[i]]);
		if (f[Q[i]] < f[pos])
			pos = Q[i];
	}
	rank[pos] = ch;
	del [pos] = true;
	int temp = code;
	for (int i=0; i<(int)adj[pos].size(); i++) if (mark[adj[pos][i]] == temp)
		go(ch+1,adj[pos][i]);
}

int main(){
	cin >> n;
	for (int i=0; i<n-1; i++){
		int e1,e2; cin >> e1 >> e2;
		e1--; e2--;
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}
	go('A',0);
	for (int i=0; i<n; i++)
		cout << rank[i] << ' ' ;
	cout << endl;
	return 0;
}