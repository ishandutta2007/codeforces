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

ll n, x;
map<ll, ll> mp;
ll l[200005], r[200005], c[200005];
vector<ll> lvec[200005], rvec[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x;
	rep(i, 1, n){
		cin >> l[i] >> r[i] >> c[i];
		lvec[l[i]].push_back(i);
		rvec[r[i]].push_back(i);
	}
	
	ll ans = inf;
	rep(i, 1, 200000){
		for(auto id : lvec[i]){
			ll len = r[id]-l[id]+1;
			if(mp.count(x-len)) chmin(ans, c[id] + mp[x-len]);
		}
		for(auto id : rvec[i]){
			ll len = r[id]-l[id]+1;
			if(mp.count(len) == 0) mp[len] = inf;
			chmin(mp[len], c[id]);
		}
	}
	if(ans > inf/2) ans = -1;
	cout << ans << endl;
	
	return 0;
}