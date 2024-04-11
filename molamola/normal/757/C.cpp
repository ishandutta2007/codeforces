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
#include <list>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

ll PP[1000010], P = 1e9 + 33;
ll F[1000010];
ll MOD = 1e9 + 7;
ll T[1000010];

void solve(){
	PP[0] = 1;
	for(int i=1;i<1000010;i++)PP[i] = PP[i-1] * P;
	F[0] = 1;
	for(int i=1;i<1000010;i++)F[i] = F[i-1] * i % MOD;
	int n, m; scanf("%d%d", &n, &m);
	rep(i, n){
		int g; scanf("%d", &g);
		rep(j, g){
			int y; scanf("%d", &y);
			T[y] += PP[i];
		}
	}
	sort(T+1, T+1+m);
	int now = 0;
	ll ans = 1;
	for(int i=1;i<=m;i++){
		now++;
		if(i == m || T[i] != T[i+1]){
			ans *= F[now]; ans %= MOD;
			now = 0;
		}
	}
	printf("%lld", ans);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}