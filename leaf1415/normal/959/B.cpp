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

llint n, k, m;
string s[100005];
map<string, ll> mp;
ll a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> m;
	rep(i, 1, n) cin >> s[i], mp[s[i]] = i;
	rep(i, 1, n) cin >> a[i];
	
	ll x, y;
	rep(i, 1, k){
		cin >> x;
		vector<ll> vec;
		rep(j, 1, x){
			cin >> y;
			vec.push_back(y);
		}
		ll mn = inf;
		for(auto y : vec) chmin(mn, a[y]);
		for(auto y : vec) a[y] = mn;
	}
	string t; ll ans = 0;
	rep(i, 1, m){
		cin >> t;
		ans += a[mp[t]];
	}
	cout << ans << endl;
	
	return 0;
}