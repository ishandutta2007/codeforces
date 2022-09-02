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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;
typedef pair<double, double> pdd;

const int MOD = 998244353;

ll pw(int x, int y = MOD - 2) {
	ll res = 1;
	while(y) {
		if(y & 1) res = res * x % MOD;
		x = (ll)x * x % MOD;
		y >>= 1;
	}
	return res;
}

int N;
vector <int> E[500050];
int P2[500050];
const int DEBU = 0;
int down[500050];

void pdfs(int x, int fa) {
	down[x] = 1;
	for(int e : E[x]) if(e != fa) {
		pdfs(e, x);
		down[x] += down[e];
	}
}

ll dp[500050][2];
ll dpc[500050][2];
void dfs(int x, int fa) {
	dpc[x][0] = 1;
	dp[x][0] = 0;
	int c = 0;
	for(int e : E[x]) if(e != fa) ++c;
	if(c == 0) {
		return;
	}
	int cnt = 0;
	for(int e : E[x]) if(e != fa) {
		dfs(e, x);
		ll tdp[2] = {}, tdpc[2] = {};
		tdpc[1] = (dpc[x][1] * P2[down[e]] + dpc[x][0] * dpc[e][0]) % MOD;
		tdpc[0] = (P2[cnt+down[e]] - tdpc[1] + MOD) % MOD;
		tdp[0] = (dp[x][0] * (P2[down[e]-1] + dpc[e][1])) % MOD;
		tdp[0] = (tdp[0] + dp[e][0] * dpc[x][0] + dp[e][1] * 2LL * dpc[x][0]) % MOD;
		tdp[1] = (2LL * dpc[x][0] * dpc[e][0] + dp[x][0] * dpc[e][0] + dpc[x][0] * dp[e][0] + dp[x][1] * P2[down[e]]) % MOD;
		tdp[1] = (tdp[1] + 2LL * dpc[x][1] * (dp[e][0] + dp[e][1])) % MOD;
		rep(u, 2) dp[x][u] = tdp[u], dpc[x][u] = tdpc[u];
		cnt += down[e];
	}
}

int main() {
	P2[0] = 1;
	for(int i=1;i<500050;i++) P2[i] = (P2[i-1] * 2LL) % MOD;
	N = 500000;
	if(!DEBU) scanf("%d", &N);
	for(int i=1;i<N;i++) {
		int x, y;
		if(!DEBU) scanf("%d%d", &x, &y);
		else x = i + 1, y = rand() % i + 1;
		E[x].pb(y);
		E[y].pb(x);
	}
	pdfs(1, -1);
	dfs(1, -1);
	ll ans = (dp[1][0] + dp[1][1]) % MOD;
	
	if(ans < 0) ans += MOD;
	printf("%lld\n", ans);
	return 0;
}