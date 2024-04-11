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
typedef pair<ll, ll> P;
typedef pair<P, ll> T;

ll n, m;
set<ll> S[200005];
bool used[200005];
bool in[200005];
ll parent[200005], depth[200005];
priority_queue<P> Q;
vector<T> ans;

void dfs(int v, int p, int d)
{
	used[v] = true, parent[v] = p, depth[v] = d;
	ll cnt = 0;
	for(auto u : S[v]){
		if(used[u]) continue;
		dfs(u, v, d+1);
		cnt++;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	ll u, v;
	rep(i, 1, m){
		cin >> u >> v;
		S[u].insert(v);
		S[v].insert(u);
	}
	rep(i, 1, n) if(!used[i]) dfs(i, -1, 0);
	rep(i, 1, n) Q.push(P(depth[i], i));
	
	while(Q.size()){
		ll v = Q.top().second; Q.pop();
		while(S[v].size() >= 2){
			auto it = S[v].begin();
			while(S[v].size() > 2 && *it == parent[v]) it++;
			ll x = *it; it++;
			while(S[v].size() > 2 && *it == parent[v]) it++;
			ll y = *it;
			S[v].erase(x), S[v].erase(y);
			S[x].erase(v), S[y].erase(v);
			ans.push_back(T(P(x, v), y));
		}
	}
	
	cout << ans.size() << "\n";
	for(auto t : ans) cout << t.first.first << " " << t.first.second << " " << t.second << "\n";
	flush(cout);
	
	return 0;
}