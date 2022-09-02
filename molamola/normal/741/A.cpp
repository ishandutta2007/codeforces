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

int n, p[110];
int deg[110];

ll gc(ll x, ll y){
	return y == 0 ? x : gc(y, x%y);
}

void solve(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)scanf("%d", p+i), deg[i]++, deg[p[i]]++;
	for(int i=1;i<=n;i++)if(deg[i] < 2){
		printf("-1");
		return;
	}
	int vis[110] = {};
	ll ans = 1;
	for(int i=1;i<=n;i++)if(vis[i] == 0){
		int t = i, c = 1;
		vis[i] = 1; t = p[i];
		while(t != i){
			vis[t] = 1; t = p[t];
			c++;
		}
		if(c % 2 == 0)c /= 2;
		ll g = gc(ans, c);
		ans /= g;
		ans *= c;
	}
	printf("%lld", ans);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}