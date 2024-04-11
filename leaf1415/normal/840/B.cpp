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

struct edge{
	ll to, id;
	edge(){}
	edge(ll a, ll b){
		to = a, id = b;
	}
};

ll n, m;
vector<edge> G[300005];
ll d[300005];
bool used[300005];
vector<ll> ans;

void dfs(int v, int p, int eid)
{
	used[v] = true;
	for(auto e : G[v]){
		if(e.id == eid) continue;
		ll u = e.to;
		if(used[u]) continue;
		dfs(u, v, e.id);
	}
	if(eid != 0){
		if(d[v]){
			ans.push_back(eid);
			d[p] ^= 1;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	rep(i, 1, n) cin >> d[i];
	ll u, v;
	rep(i, 1, m){
		cin >> u >> v;
		G[u].push_back(edge(v, i));
		G[v].push_back(edge(u, i));
	}
	
	ll sum = 0;
	rep(i, 1, n){
		if(d[i] == -1){
			sum = 0;
			break;
		}
		sum += d[i];
	}
	if(sum % 2){
		cout << -1 << endl;
		return 0;
	}
	
	ll root = 1;
	rep(i, 1, n){
		if(d[i] == -1) root = i, d[i] = 0;
	}
	dfs(root, 0, 0);
	
	cout << ans.size() << endl;
	for(auto v : ans) cout << v << " "; cout << endl;
	
	return 0;
}