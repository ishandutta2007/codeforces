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
#define inf 1e9

using namespace std;

typedef long long llint;
typedef int ll;
typedef pair<llint, llint> P;

ll n, m, Q;
vector<ll> G[3005], revG[3005];
bool reach[3005][3005];
short succ[14][3005][3005];

void dfs(int v, int s)
{
	reach[v][s] = true;
	for(auto u : revG[v]){
		if(reach[u][s]) continue;
		dfs(u, s);
	}
}

ll get(ll s, ll t, ll k)
{
	ll v = s;
	for(int i = 13; i >= 0; i--){
		if(k & (1<<i)) v = succ[i][v][t];
	}
	return v;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> Q;
	ll u, v;
	rep(i, 1, m){
		cin >> u >> v;
		G[u].push_back(v);
		revG[v].push_back(u);
	}
	rep(i, 1, n) dfs(i, i);
	
	rep(i, 1, n){
		rep(j, 1, n){
			if(i == j){
				succ[0][i][j] = 0;
				continue;
			}
			ll mn = inf;
			for(auto u : G[i]){
				if(!reach[u][j]) continue;
				chmin(mn, u);
			}
			if(mn > inf/2) succ[0][i][j] = 0;
			else succ[0][i][j] = mn;
		}
	}
	
	rep(i, 1, 13){
		rep(j, 1, n){
			rep(k, 1, n){
				succ[i][j][k] = succ[i-1][succ[i-1][j][k]][k];
			}
		}
	}
	
	/*rep(i ,1, n){
		rep(j, 1, n) cout << succ[0][i][j] << " ";
		cout << endl;
	}*/
	
	ll s, t, k;
	while(Q--){
		cin >> s >> t >> k; k--;
		//cout << reach[s][t] << " " << get(s, t, 4000) << " " << get(s, t, k) << endl;
		if(!reach[s][t] || get(s, t, 4000) != 0 || get(s, t, k) == 0){
			cout << -1 << "\n";
			continue;
		}
		cout << get(s, t, k) << "\n";
	}
	flush(cout);
	
	return 0;
}