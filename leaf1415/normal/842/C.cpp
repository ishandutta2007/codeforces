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

ll n;
vector<ll> G[200005];
ll a[200005];
ll ans[200005];

ll gcd(ll a, ll b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

vector<ll> vec;
void dfs(int v, int p, ll g)
{
	ll tg = g;
	for(auto x : vec) tg = gcd(tg, x);
	
	ll ntg = gcd(tg, a[v]);
	if(tg == 0 || ntg < tg) vec.push_back(a[v]);
	else g = gcd(g, a[v]);
	
	//cout << v << " " << ntg << endl;
	//for(auto x : vec) cout << x << " "; cout << endl;
	
	ll m = vec.size();
	vector<ll> pre, suf;
	
	pre.push_back(0);
	for(auto x : vec) pre.push_back(gcd(pre.back(), x));
	
	suf.push_back(0);
	for(int i = (int)vec.size()-1; i >= 0; i--) suf.push_back(gcd(suf.back(), vec[i]));
	suf.push_back(0);
	reverse(all(suf));
	
	ans[v] = ntg;
	rep(i, 1, m) chmax(ans[v], gcd(g, gcd(pre[i-1], suf[i+1])));
	
	for(auto u : G[v]){
		if(u == p) continue;
		dfs(u, v, g);
		
	}
	if(ntg < tg) vec.pop_back();
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
	
	dfs(1, -1, 0);
	
	rep(i, 1, n) cout << ans[i] << " "; cout << endl;
	
	return 0;
}