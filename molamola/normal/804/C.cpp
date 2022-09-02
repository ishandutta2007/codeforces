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
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;

vector <int> E[300030], color[300030];
int n, m;
int ans[300030], now;
int temp[300030];

void dfs(int x, int fa){
	for(int e : color[x]) if(ans[e] != 0) temp[ans[e]] = x;
	int now = 1;
	for(int e : color[x]) if(ans[e] == 0){
		while(temp[now] == x) ++now;
		temp[now] = x; ans[e] = now;
	}
	for(int e : E[x]) if(e != fa) dfs(e, x);
}

void solve(){
	scanf("%d%d", &n, &m);
	int C = 0, Cv = 0;
	for(int i=1;i<=n;i++){
		int x; scanf("%d", &x);
		if(C < x)C = x, Cv = i;
		rep(j, x){
			int y; scanf("%d", &y);
			color[i].pb(y);
		}
	}
	rep(i, n-1){
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
	}
	if(C == 0){
		puts("1");
		for(int i=1;i<=m;i++)printf("1 "); puts("");
		return;
	}
	printf("%d\n", C);
	for(int e : color[Cv]) ans[e] = ++now;
	for(int e : E[Cv]) dfs(e, Cv);
	for(int i=1;i<=m;i++)printf("%d ", ans[i] ? ans[i] : 1); puts("");
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1; tc<=Tc; tc++){
		solve();
	}
	return 0;
}