/*
 * in the name of god
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
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXN = 1000000+10;

bool mark[MAXN];
int n,e;
vector <int> adj[MAXN];

int dfs (int v){
	mark[v] = true;
	int ret = 0;
	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		if (!mark[tmp])
			ret+=dfs(tmp);
	}
	return ret + (int)adj[v].size()%2;
}

int main(){
	cin >> n >> e;
	for (int i=1; i<=e; i++){
		int e1,e2; cin >> e1 >> e2;
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}
	int cnt0=0,comp=0,odd=0;
	for (int i=1; i<=n; i++) if (!mark[i] && (i==1 || !adj[i].empty())){
		comp++; 
		int tmp = dfs(i); 
		odd+= tmp;
		if (tmp==0)
			cnt0++;
	}
	if (comp==1 || cnt0==0) 
		cout << odd/2 << endl;
	else
		cout << cnt0 + odd/2 << endl;
	return 0;
}