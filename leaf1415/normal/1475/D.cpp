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
ll n, m;
ll a[200005], b[200005];
vector<ll> vec[2], sum;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n) cin >> b[i];
		
		vec[0].clear(), vec[1].clear();
		rep(i, 1, n) vec[b[i]-1].push_back(a[i]);
		sort(all(vec[0])), reverse(all(vec[0]));
		sort(all(vec[1])), reverse(all(vec[1]));
		
		sum.clear(); sum.push_back(0);
		for(auto x : vec[1]) sum.push_back(sum.back() + x);
		
		ll ans = inf, s = 0;
		rep(i, 0, (int)vec[0].size()){
			ll p = lower_bound(all(sum), m - s) - sum.begin();
			if(p <= vec[1].size()) chmin(ans, i + 2*p);
			if(i < (int)vec[0].size()) s += vec[0][i];
		}
		if(ans > inf/2) ans = -1;
		cout << ans << endl;
	}
	
	return 0;
}