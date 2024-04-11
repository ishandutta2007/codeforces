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
#define outl(x) cout << (x) << endl
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
ll a[300005];
map<ll, ll> mp;

ll comb(ll n, ll k)
{
	ll ret = 1;
	rep(i ,1, k) ret *= (n+1-i);
	rep(i ,1, k) ret /= i;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i], mp[a[i]]++;
	
	ll ans = 1, rem = 3;
	auto it = mp.begin();
	while(rem > 0){
		ll x = min(rem, it->second);
		ans *= comb(it->second, x);
		rem -= x;
		it++;
	}
	cout << ans << endl;
	
	return 0;
}