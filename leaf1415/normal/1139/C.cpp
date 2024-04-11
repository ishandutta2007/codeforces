#include <iostream>
#include <vector>
#define llint long long
#define mod 1000000007

using namespace std;

llint n, k;
bool used[100005];
vector<int> G[100005];
vector<llint> vec;

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

llint dfs(int v, int pre)
{
	used[v] = true;
	int ret = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		ret += dfs(G[v][i], v);
	}
	return ret;
}

int main(void)
{
	cin >> n >> k;
	int u, v, c;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v >> c;
		if(c == 1) continue;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= n; i++){
		if(!used[i]) vec.push_back(dfs(i, -1));
	}
	
	llint ans = 0;
	for(int i = 0; i < vec.size(); i++){
		ans += modpow(vec[i], k);
		ans %= mod;
	}
	ans = modpow(n, k) - ans + mod;
	ans %= mod;
	
	cout << ans << endl;
	return 0;
}