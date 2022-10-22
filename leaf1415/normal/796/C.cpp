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
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

ll n, mx;
ll a[300005];
vector<ll> G[300005];
ll cnt[300005];

void add(ll x)
{
	if(x >= mx) cnt[x-mx]++;
}
void erase(ll x)
{
	if(x >= mx) cnt[x-mx]--;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	ll u, v;
	rep(i, 1, n-1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	mx = -inf;
	rep(i, 1, n) chmax(mx, a[i]);
	rep(i, 1, n) add(a[i]+2);
	
	ll ans = inf;
	rep(i, 1, n){
		erase(a[i]+2), add(a[i]);
		for(auto u : G[i]) erase(a[u]+2), add(a[u]+1);
		
		ll tmp = -inf;
		rep(i, 0, 5) if(cnt[i]) chmax(tmp, mx+i);
		chmin(ans, tmp);
		
		erase(a[i]), add(a[i]+2);
		for(auto u : G[i]) erase(a[u]+1), add(a[u]+2);
	}
	cout << ans << endl;
	
	return 0;
}