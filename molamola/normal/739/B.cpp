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

vector <Pi> E[200020];
int a[200020];
int ans[200020], down[200020], ans2[200020];
int up[200020][20];
ll L[200020][20];

int dfs(int x){
	int ux = x, res = 0;
	for(int i=19;i>=0;i--){
		if(L[ux][i] <= a[x]){
			a[x] -= L[ux][i];
			ux = up[ux][i];
		}
	}
	down[x] = 1;
	ans[up[ux][0]]++;
	for(auto e : E[x]){
		up[e.Se][0] = x;
		L[e.Se][0] = e.Fi;
		for(int i=1;i<20;i++){
			up[e.Se][i] = up[ up[e.Se][i-1] ][i-1];
			L[e.Se][i] = L[e.Se][i-1] + L[ up[e.Se][i-1] ][i-1];
		}
		res += dfs(e.Se);
		down[x] += down[e.Se];
	}
	res += ans[x];
	ans2[x] = down[x] - res - 1;
	return res;
}

void solve(){
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++)scanf("%d", a+i);
	for(int i=1;i<=n-1;i++){
		int p,w; scanf("%d%d", &p, &w);
		E[p].pb(Pi(w, i+1));
	}
	dfs(1);
	for(int i=1;i<=n;i++)printf("%d ", ans2[i]);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}