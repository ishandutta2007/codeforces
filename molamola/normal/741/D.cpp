#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int,int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

vector <Pi> E[500050];
int N;
int down[500050];
int child[500050];
int ans[500050], dep[500050], val[500050];
int D[1<<22];

void del(int x, int fa){
	D[val[x]] = 0;
	for(Pi e : E[x])if(e.Se != fa){
		del(e.Se, x);
	}
}

int Do(int x, int fa){
	int res = -1e9;
	for(int i=0;i<23;i++){
		int w = val[x] ^ 1<<i;
		if(i == 22)w = val[x];
		if(D[w] != 0)res = max(res, D[w] + dep[x]);
	}
	for(Pi e : E[x])if(e.Se != fa){
		res = max(res, Do(e.Se, x));
	}
	return res;
}

void Ins(int x, int fa){
	D[val[x]] = max(D[val[x]], dep[x]);
	for(Pi e : E[x])if(e.Se != fa){
		Ins(e.Se, x);
	}
}

void dfs(int x, int fa){
	for(auto e : E[x])if(e.Se != fa && e.Se != child[x]){
		dfs(e.Se, x); del(e.Se, x);
		ans[x] = max(ans[x], ans[e.Se]);
	}
	if(child[x] != -1)dfs(child[x], x), ans[x] = max(ans[x], ans[child[x]]);
	rep(i, 23){
		int w = val[x] ^ 1<<i;
		if(i == 22)w = val[x];
		if(D[w] != 0)ans[x] = max(ans[x], D[w] - dep[x]);
	}
	D[val[x]] = max(D[val[x]], dep[x]);
	for(auto e : E[x])if(e.Se != fa && e.Se != child[x]){
		ans[x] = max(ans[x], Do(e.Se, x) - dep[x] * 2);
		Ins(e.Se, x);
	}
}

void pre(int x, int fa){
	down[x] = 1;
	child[x] = -1;
	for(Pi e : E[x])if(e.Se != fa){
		dep[e.Se] = dep[x] + 1;
		val[e.Se] = val[x] ^ 1<<e.Fi;
		pre(e.Se, x);
		if(child[x] == -1 || down[child[x]] < down[e.Se])child[x] = e.Se;
		down[x] += down[e.Se];
	}
}

void solve(){
	scanf("%d", &N);
	rep(i, N-1){
		int x; char c;
		scanf("%d %c", &x, &c);
		E[i+2].pb(Pi(c-'a', x));
		E[x].pb(Pi(c-'a', i+2));
	}
	dep[1] = 1; pre(1, -1);
	dfs(1, -1);
	for(int i=1;i<=N;i++)printf("%d ", ans[i]);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}