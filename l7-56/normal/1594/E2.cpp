#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef double db;
using namespace std;

const ll maxn = 2010, maxk = 70, maxc = 10, mod = 1e9 + 7;
ll pw(ll a, ll p) {
	ll ans = 1;
	while(p) {
		if(p & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		p >>= 1;
	}
	return ans;
}

map <string, ll> col;
map <ll, ll> id;
ll k,n,tr[maxn * maxk][2],cnt_n,dp[maxn * maxk][maxc],c[maxn * maxk];
ll dfs(ll i, ll j) {
	if(dp[i][j] != -1) return dp[i][j];
	if(c[i] && c[i] != j) return dp[i][j] = 0;
	ll s[2] = {0, 0};
	for(ll k = 1; k <= 6; ++k)
		if(k != j && k + j != 7) {
			if(tr[i][0]) s[0] += dfs(tr[i][0], k), s[0] %= mod;
			if(tr[i][1]) s[1] += dfs(tr[i][1], k), s[1] %= mod;
		}
	if(tr[i][0] == 0) s[0] = 1;
	if(tr[i][1] == 0) s[1] = 1;
	dp[i][j] = (s[0] * s[1]) % mod;
	return dp[i][j];
}

int main() {
	col["white"] = 1, col["yellow"] = 6;
	col["red"] = 2, col["orange"] = 5;
	col["green"] = 3, col["blue"] = 4;
	scanf("%lld%lld", &k, &n);
	for(int i = 1; i <= n; ++i) {
		string s; ll v;
		cin >> v >> s;
		for(ll j = v; j; j >>= 1) {
			if(id.find(j) != id.end()) break;
			id[j] = ++cnt_n;
		}
		c[id[v]] = col[s];
	}
	for(auto x : id) {
		ll raw = x.first, nw = x.second;
		if(id.find(raw << 1) != id.end()) tr[nw][0] = id[raw << 1];
		if(id.find(raw << 1 | 1) != id.end()) tr[nw][1] = id[raw << 1 | 1];
	}
	memset(dp, -1, sizeof dp);
	ll ans = 0;
	for(int j = 1; j <= 6; ++j)
		ans = (ans + dfs(id[1], j)) % mod;
	printf("%lld\n", pw(4, (1ll << k) - 1 - cnt_n) * ans % mod);
	return 0;
}