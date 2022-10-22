#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint n;
int a[200005];
vector<int> G[200005];
vector<int> fact[200005], pvec;
bool prime[200005];

llint size[200005];
bool used[200005];

llint sizedfs(llint v, llint pre)
{
	llint ret = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		if(used[G[v][i]]) continue;
		ret += sizedfs(G[v][i], v);
	}
	return size[v] = ret;
}

llint centdfs(llint v, llint pre, llint sz)
{
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		if(used[G[v][i]]) continue;
		if(size[G[v][i]] > sz/2) return centdfs(G[v][i], v, sz);
	}
	return v;
}

int lendfs(int v, int pre, int d)
{
	int ret = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		if(used[G[v][i]]) continue;
		if(a[G[v][i]] % d) continue;
		ret = max(ret, lendfs(G[v][i], v, d));
	}
	return ret+1;
}

int ans;
void solve(llint v, llint sz)
{
	sizedfs(v, -1);
	v = centdfs(v, -1, sz);
	
	for(int i = 0; i < fact[a[v]].size(); i++){
		int mx = 0, mx2 = 0;
		for(int j = 0; j < G[v].size(); j++){
			if(used[G[v][j]]) continue;
			if(a[G[v][j]] % fact[a[v]][i]) continue;
			int res = lendfs(G[v][j], v, fact[a[v]][i]);
			if(mx < res) mx2 = mx, mx = res;
			else if(res > mx2) mx2 = res;
		}
		ans = max(ans, mx + mx2 + 1);
	}
	
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(used[G[v][i]]) continue;
		solve(G[v][i], size[G[v][i]]);
	}
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int u, v;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(int i = 2; i < 200005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 200005; j+=i) prime[j] = true;
		pvec.push_back(i);
	}
	for(int i = 0; i < pvec.size(); i++){
		int v = pvec[i];
		for(int j = 1; v*j < 200005; j++) fact[v*j].push_back(v);
	}
	
	solve(1, n);
	cout << ans << endl;
	
	return 0;
}