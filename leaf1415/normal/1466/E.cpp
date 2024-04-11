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

ll T;
ll n;
ll a[500005];
ll beki[65];
ll cnt[65];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	beki[0] = 1;
	rep(i, 1, 60) beki[i] = beki[i-1] * 2 % mod;
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		
		rep(i, 0, 60) cnt[i] = 0;
		rep(i, 1, n){
			rep(j, 0, 59){
				if(a[i] & (1LL<<j)) cnt[j]++;
			}
		}
		
		ll ans = 0;
		rep(i, 1, n){
			ll l = 0;
			rep(j, 0, 59){
				if(a[i] & (1LL<<j)) l += cnt[j] * beki[j] % mod, l %= mod;
			}
			ll r = 0;
			rep(j, 0, 59){
				if(a[i] & (1LL<<j)) r += n * beki[j] % mod, r %= mod;
				else r += cnt[j] * beki[j] % mod, r %= mod;
			}
			ans += l * r % mod, ans %= mod;
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}