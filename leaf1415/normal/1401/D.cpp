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
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n, m;
vector<llint> G[100005];
vector<llint> pvec, mvec;

llint dfs(int v, int p)
{
	llint ret = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		llint res = dfs(G[v][i], v);
		mvec.push_back(res * (n - res));
		ret += res;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) G[i].clear();

		llint u, v;
		for(int i = 0; i < n-1; i++){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		cin >> m;
		pvec.clear();
		
		llint p;
		for(int i = 0; i < m; i++){
			cin >> p;
			pvec.push_back(p);
		}
		sort(pvec.rbegin(), pvec.rend());
		
		mvec.clear();
		dfs(1, -1);
		sort(mvec.rbegin(), mvec.rend());
		
		while(pvec.size() < n-1) pvec.push_back(1);
		
		llint ans = 0, x = 1 + max(0LL, m - (n-1)), mul = 1;
		for(int i = 0; i < x; i++){
			mul *= pvec[i], mul %= mod;
		}
		ans += (mvec[0] % mod) * mul % mod, ans %= mod;
		
		for(int i = 1; i < n-1; i++){
			ans += (mvec[i] % mod) * pvec[x+i-1] % mod, ans %= mod;
		}
		cout << ans << endl;
	}
	
	return 0;
}