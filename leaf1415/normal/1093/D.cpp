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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 998244353

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n, m;
vector<llint> G[300005];
llint color[300005];

llint bcnt, wcnt;
bool dfs(int v, int p, int c)
{
	color[v] = c;
	if(c == 1) bcnt++;
	else wcnt++;
	
	for(int i = 0; i < G[v].size(); i++){
		int u = G[v][i];
		if(color[u] == c) return false;
		if(color[u] == -c || u == p) continue;
		if(!dfs(u, v, -c)) return false;
	}
	return true;
}

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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m;
		for(int i = 1; i <= n; i++) G[i].clear();
		
		llint u, v;
		for(int i = 1; i <= m; i++){
			 cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		for(int i = 1; i <= n; i++) color[i] = 0;
		
		llint ans = 1;
		for(int i = 1; i <= n; i++){
			if(color[i]) continue;
			bcnt = 0, wcnt = 0;
			if(!dfs(i, -1, 1)) ans = 0;
			llint tmp = modpow(2, bcnt) + modpow(2, wcnt);
			ans *= tmp % mod, ans %= mod;
		}
		cout << ans << endl;
	}
	
	return 0;
}