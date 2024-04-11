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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll T;
ll n;
vector<ll> G[200005];
bool used[200005];

int cycledfs(vector<llint> G[], int v, int p, vector<int> &dest)
{
	used[v] = true;
	for(auto u : G[v]){
		if(u == p) continue;
		if(used[u]){
			dest.push_back(v);
			return u;
		}
		int res = cycledfs(G, u, v, dest);
		if(res == -1) return res;
		if(res == -2) continue;
		dest.push_back(v);
		if(v == res) return -1;
		else return res;
	}
	return -2;
}

//cycledestcycle
bool detectCycle(vector<llint> G[], int n, vector<int> &dest)
{
	dest.clear();
	for(int i = 0; i <= n; i++) used[i] = false;
	return cycledfs(G, 1, -1, dest) == -1;
}


int dfs2(int v, int p)
{
	used[v] = true;
	int ret = 1;
	for(auto u : G[v]){
		if(u == p) continue;
		if(used[u]) continue;
		ret += dfs2(u, v);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) G[i].clear();
		
		ll u, v;
		rep(i, 1, n){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		vector<int> vec;
		assert(detectCycle(G, n, vec));
		
		ll ans = n*(n-1);
		rep(i, 1, n) used[i] = false;
		for(auto v : vec) used[v] = true;
		for(auto r : vec){
			ll res = dfs2(r, -1);
			ans -= res*(res-1)/2;
		}
		cout << ans << endl;
	}
	
	return 0;
}