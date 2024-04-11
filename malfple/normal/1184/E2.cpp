////////////////////////////////////////////
///                                      ///
///         Template ver. 1 rapel        ///
/// Fear is Temporary, Regret is Forever ///
///          Must Try and Get AC         ///
///                                      ///
////////////////////////////////////////////
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>

#include <math.h>
#include <complex>

#include <assert.h>
#include <time.h>
//#include <chrono>
//#include <random>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>

#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define endl '\n'
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

const int N = 1e5;
const int M = 1e6;
const int O = 18;
int par[N + 5];
int u[M + 5], v[M + 5], w[M + 5];
int mark[M + 5];
int subtree[N + 5];
vector<pair<int,int> > vec[N + 5];
vector<pair<pair<int,int>,int> > vec2[N + 5];

priority_queue<pair<pair<int,int>, pair<int,int> > > pq;

int find(int x) {
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}

int depth[N + 5];
pair<int,int> sparse[O + 1][N + 5];

void dfs(int idx,int pre,int h) {
	depth[idx] = h;
	subtree[idx]++;
	for(int i = 0;i < vec[idx].size();i++) {
		int nx = vec[idx][i].FI;
		int ct = vec[idx][i].SE;
		if(nx == pre) continue;
		sparse[0][nx] = {idx, ct};
		dfs(nx, idx, h + 1);
		subtree[idx] += subtree[nx];
	}
}

pair<int,int> LCA(int u,int v) {
	if(depth[u] < depth[v]) swap(u, v);
	int res = 0;
	int diff = depth[u] - depth[v];
	for(int i = O;i >= 0;i--) {
		if(diff & (1<<i)) {
			res = max(res, sparse[i][u].SE);
			u = sparse[i][u].FI;
		}
	}
	if(u == v) return {u, res};
	for(int i = O;i >= 0;i--) {
		if(sparse[i][u].FI != sparse[i][v].FI) {
			res = max(res, max(sparse[i][u].SE, sparse[i][v].SE));
			u = sparse[i][u].FI;
			v = sparse[i][v].FI;
		}
	}
	return {sparse[0][u].FI, max(res, max(sparse[0][u].SE, sparse[0][v].SE))};
}

int ST[4 * N + 5];
int ans[M + 5];
int big[N + 5];

void hora(int tc) {
	int n, m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) par[i] = i;
	for(int i = 0;i < m;i++) {
		cin>>u[i]>>v[i]>>w[i];
		pq.push({{-w[i], i},{u[i], v[i]}});
		vec2[u[i]].PB({{v[i], w[i]}, i});
		vec2[v[i]].PB({{u[i], w[i]}, i});
	}
	while(!pq.empty()) {
		int c = -pq.top().FI.FI;
		int idx = pq.top().FI.SE;
		int u = pq.top().SE.FI;
		int v = pq.top().SE.SE;
		pq.pop();
		if(find(u) != find(v)) {
			vec[u].PB({v, c});
			vec[v].PB({u, c});
			par[find(u)] = find(v);
			mark[idx] = 1;
		}
	}
	dfs(1, 1, 1);
	for(int i = 1;i <= O;i++) {
		for(int j = 1;j <= n;j++) {
			sparse[i][j] = {sparse[i - 1][sparse[i - 1][j].FI].FI, max(sparse[i - 1][sparse[i - 1][j].FI].SE, sparse[i - 1][j].SE)};
		}
	}
	for(int i = 0;i < m;i++) {
		if(mark[i] == 1) continue;
		int res = LCA(u[i], v[i]).SE;
		cout<<res<<endl;
	}
//	dfs2(1, 1, 1);
//	for(int i = 0;i < m;i++) {
//		cout<<ans[i]<<endl;
//	}
}

int main(){
	desperate_optimization(6);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}