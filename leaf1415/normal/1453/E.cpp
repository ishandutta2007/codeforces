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

ll dfs(int v, int p, int d)
{
	//cout << d << " " << v << endl;
	ll ret = inf, ret2 = -1;
	for(auto u : G[v]){
		if(u == p) continue;
		ll res = dfs(u, v, d);
		if(res >= d){
			//cout << d << " " << v << " " << "x" << endl;
			return inf;
		}
		if(res == d-1){
			if(ret2 == d-1) return inf;
			ret2 = res;
		}
		chmin(ret, res);
	}
	if(ret > inf/2){
		//cout << d << " " << v << " " << 0 << endl;
		return 0;
	}
	
	if(ret2 == d-1) ret = ret2;
	//cout << d << " " << v << " " << ret+1 << endl;
	
	return ret+1;
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
		rep(i, 1, n-1){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		ll ub = n, lb = 0, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(mid && dfs(1, -1, mid) <= mid) ub = mid;
			else lb = mid;
		}
		cout << ub << endl;
	}
	
	return 0;
}