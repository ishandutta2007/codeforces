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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, m, c;
vector<ll> vec[300005];
vector<ll> G[300005];
ll ans[300005];

set<ll> S;
vector<ll> tmp;

void dfs(int v, int p)
{
	for(auto u : vec[v]){
		if(ans[u]) S.erase(ans[u]), tmp.push_back(ans[u]);
	}
	for(auto u : vec[v]){
		if(ans[u]) continue;
		ans[u] = *S.begin();
		S.erase(S.begin()), tmp.push_back(ans[u]);
	}
	
	for(auto z : tmp) S.insert(z);
	tmp.clear();
	
	for(auto u : G[v]) if(u != p) dfs(u, v);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	c = 1;
	rep(i, 1, n){
		ll s, x;
		cin >> s;
		chmax(c, s);
		rep(j, 1, s){
			cin >> x;
			vec[i].push_back(x);
		}
	}
	ll u, v;
	rep(i, 1, n-1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	rep(i, 1, c) S.insert(i);
	dfs(1, 0);

	rep(i, 1, m) if(ans[i] == 0) ans[i] = 1;
	cout << c << endl;
	rep(i, 1, m) cout << ans[i] << " "; cout << endl;
	
	return 0;
}