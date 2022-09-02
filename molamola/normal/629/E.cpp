#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <time.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()

ll total[100010];
ll down[100010][2];

vector <int> v[100010];
int n, m;
int up[100010][20];
int dep[100010];

void dfs(int x,int fa){
	down[x][0] = 1;
	rep(i,sz(v[x])){
		int u = v[x][i];
		if(u != fa){
			dep[u] = dep[x] + 1;
			up[u][0] = x;
			for(int j=1;j<20;j++)up[u][j] = up[ up[u][j-1] ][j-1];
			dfs(u, x);
			down[x][0] += down[u][0];
			down[x][1] += down[u][1] + down[u][0];
		}
	}
}

void dfs2(int x,int fa){
	rep(i,sz(v[x])){
		int u = v[x][i];
		if(u != fa){
			total[u] = total[x] + n - 2 * down[u][0];
			dfs2(u, x);
		}
	}
}

int uu(int x,int v){
	for(int i=0;i<20;i++)if(1<<i & v)x = up[x][i];
	return x;
}

int lca(int x,int y){
	for(int i=0;i<20;i++)if(1<<i & (dep[x] - dep[y]))x = up[x][i];
	for(int i=19;i>=0;i--)if(up[x][i] != up[y][i])x = up[x][i], y = up[y][i];
	return x == y ? x : up[x][0];
}

double get(int x,int y){
	if(dep[x] < dep[y])swap(x, y);
	int L = lca(x, y);
	if(y == L){
		double res = dep[x] - dep[y];
		res += (double)down[x][1] / down[x][0];
		int tmp = uu(x, dep[x] - dep[y] - 1);
		res += (double)(total[tmp] - down[tmp][1]) / (n - down[tmp][0]);
		return res;
	}
	else{
		double res = dep[x] + dep[y] - dep[L] * 2 + 1;
		res += (double)down[x][1] / down[x][0];
		res += (double)down[y][1] / down[y][0];
		return res;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	rep(i, n-1){
		int x, y;
		scanf("%d%d", &x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,-1);
	total[1] = down[1][1];
	dfs2(1,-1);
	rep(i,m){
		int u, v;
		scanf("%d%d",&u,&v);
		printf("%.10f\n",get(u,v));
	}
	return 0;
}