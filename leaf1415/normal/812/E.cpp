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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
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

ll n;
ll a[100005];
vector<ll> G[100005];
vector<ll> ovec, evec;
map<ll, ll> mp;
ll dep;

void dfs(int v, int d)
{
	if(d % 2) ovec.push_back(a[v]);
	else evec.push_back(a[v]);
	
	if(G[v].size() == 0) dep = d;
	for(auto u : G[v]) dfs(u, d+1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	ll p;
	rep(i, 2, n){
		cin >> p;
		G[p].push_back(i);
	}
	
	dfs(1, 0);
	if(dep % 2 == 0) swap(evec, ovec);
	
	ll ans = 0, sum = 0;
	for(auto x : ovec) sum ^= x;
	for(auto x : evec) mp[x]++;
	
	if(sum == 0){
		ans += (ll)ovec.size() * ((ll)ovec.size()-1) / 2;
		ans += (ll)evec.size() * ((ll)evec.size()-1) / 2;
	}
	for(auto x : ovec) ans += mp[sum^x];
	cout << ans << endl;
	
	return 0;
}