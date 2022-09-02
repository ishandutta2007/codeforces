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
#include <unordered_map>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

vector <int> E[100010];
int color[100010];
int ok = 1;

void dfs(int x, int fa, int c){
	color[x] = c;
	for(int e : E[x])if(e != fa){
		if(color[e] == 0)dfs(e, x, 3 - c);
		else if(color[e] == c){
			ok = 0;
		}
	}
}

void solve(){
	int n, m; scanf("%d%d", &n, &m);
	rep(i, m){
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
	}
	for(int i=1;i<=n;i++)if(color[i] == 0)dfs(i, -1, 1);
	if(!ok)puts("-1");
	else{
		vector <int> ans[3];
		for(int i=1;i<=n;i++)ans[color[i]].pb(i);
		printf("%d\n", sz(ans[1]));
		for(int e : ans[1])printf("%d ", e); puts("");
		printf("%d\n", sz(ans[2]));
		for(int e : ans[2])printf("%d ", e); puts("");
	}
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}