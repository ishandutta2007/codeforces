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
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, Q;
ll w[1000005];
vector<ll> vec[1000005], svec[1000005];

ll getnum(ll v, ll d)
{
	return upper_bound(all(vec[v]), d) - vec[v].begin();
}
ll getsum(ll v, ll d)
{
	ll p = getnum(v, d);
	if(p == 0) return 0;
	return svec[v][p-1];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	rep(i, 2, n) cin >> w[i];
	
	for(int i = n; i >= 1; i--){
		vec[i].push_back(0);
		if(i*2 <= n) for(auto x : vec[i*2]) vec[i].push_back(w[i*2] + x);
		if(i*2+1 <= n) for(auto x : vec[i*2+1]) vec[i].push_back(w[i*2+1] + x);
	}
	rep(i, 1, n){
		sort(all(vec[i]));
		ll sum = 0;
		for(auto x : vec[i]){
			sum += x;
			svec[i].push_back(sum);
		}
		//for(auto x : vec[i]) cout << x << " "; cout << endl;
	}
	
	ll v, d;
	while(Q--){
		cin >> v >> d;
		ll ans = d*getnum(v, d) - getsum(v, d), len = 0, pre = v;
		while(1){
			//cout << ans << endl;
			len += w[v], v /= 2;
			if(len > d || v < 1) break;
			ans += d - len;
			if(v*2 != pre) ans += (d-len-w[v*2])*getnum(v*2, d-len-w[v*2]) - getsum(v*2, d-len-w[v*2]);
			if(v*2+1 != pre) ans += (d-len-w[v*2+1])*getnum(v*2+1, d-len-w[v*2+1]) - getsum(v*2+1, d-len-w[v*2+1]);
			pre = v;
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}