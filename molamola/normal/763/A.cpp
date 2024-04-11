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
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;

vector <int> E[100010];
int C[100010];

int cnt[100010], tot;

void dfs(int x, int fa){
	for(int e : E[x])if(e != fa){
		if(C[e] != C[x]) cnt[x]++, cnt[e]++, tot += 2;
		dfs(e, x);
	}
}

void solve(){
	int n; scanf("%d", &n);
	int deg[100010] = {};
	rep(i, n-1){
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
		deg[x]++; deg[y]++;
	}
	for(int i=1;i<=n;i++)scanf("%d", C+i);
	dfs(1, -1);
	for(int i=1;i<=n;i++){
		if(tot == cnt[i] * 2){
			puts("YES");
			printf("%d\n", i);
			return;
		}
	}
	puts("NO");
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}