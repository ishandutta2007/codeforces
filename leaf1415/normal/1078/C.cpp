#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18
#define mod 998244353

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n;
vector<llint> G[300005];
llint dp[300005][3];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

void dfs(int v, int p)
{
	for(auto u: G[v]){
		if(u == p) continue;
		dfs(u, v);
	}
	
	dp[v][0] = 1;
	for(auto u: G[v]){
		if(u == p) continue;
		dp[v][0] *= (dp[u][0] + dp[u][2]) % mod, dp[v][0] %= mod;
	}
	
	dp[v][1] = 1;
	for(auto u: G[v]){
		if(u == p) continue;
		dp[v][1] *= (dp[u][0] + dp[u][2]*2)% mod, dp[v][1] %= mod;
	}
	dp[v][1] += mod - dp[v][0], dp[v][1] %= mod;
	
	llint mul = 1, sum = 0;
	for(auto u: G[v]){
		if(u == p) continue;
		mul *= (dp[u][0] + dp[u][2]*2%mod) % mod, mul %= mod;
		sum += (dp[u][0] + dp[u][1]) % mod  * modpow((dp[u][0]+dp[u][2]*2%mod)%mod, mod-2) % mod, sum %= mod;
	}
	dp[v][2] = mul * sum % mod;
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint u, v;
	rep(i, 1, n-1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	if(n == 2){
		cout << 2 << endl;
		return 0;
	}
	
	dfs(1, -1);
	
	/*rep(i, 1, n){
		rep(j, 0, 2){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	llint ans = dp[1][0] + dp[1][2];
	cout << ans % mod << endl;
	
	
	return 0;
}