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

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll T;
ll n, dep;
ll a[200005], p[200005];
ll dp[200005][3];
vector<ll> G[200005];
vector<P> vec[200005];

void dfs(int v, int par, ll d)
{
	chmax(dep, d);
	p[v] = par;
	vec[d].push_back(P(a[v], v));
	for(auto u : G[v]) if(u != par) dfs(u, v, d+1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) G[i].clear();
		ll v;
		rep(i, 2, n){
			cin >> v;
			G[i].push_back(v);
			G[v].push_back(i);
		}
		rep(i, 2, n) cin >> a[i];
		
		dep = 0;
		rep(i, 0, n) vec[i].clear();
		dfs(1, -1, 0);
		rep(i, 0, dep) sort(all(vec[i]));
		
		rep(i, 1, n) rep(j, 0, 2) dp[i][j] = -inf;
		dp[1][0] = 0;
		
		ll mx[3];
		rep(i, 1, dep){
			rep(j, 0, 2){
				mx[j] = -inf;
				for(auto w : vec[i-1]) chmax(mx[j], dp[w.second][j]);
			}
			//rep(j, 0, 2) cout<< mx[j] << " "; cout << endl;
			
			for(auto w : vec[i]){
				ll v = w.second;
				ll x = dp[p[v]][0];
				chmax(x, mx[1]-a[p[v]]);
				chmax(x, mx[2]+a[p[v]]);
				
				//cout << v << " " << x << endl;
				dp[v][0] = x + max(abs(a[v]-vec[i].front().first), abs(a[v]-vec[i].back().first));
				dp[v][1] = x + a[v];
				dp[v][2] = x - a[v];
				//rep(j, 0, 2) cout << dp[v][j] << " "; cout << endl;
				
			}
		}
		
		/*rep(i, 1, n){
			rep(j, 0, 2) cout << dp[i][j] << " "; cout << endl;
		}*/
		
		ll ans = -inf;
		rep(i, 1, n) chmax(ans, dp[i][0]);
		cout << ans << endl;
	}
	
	return 0;
}