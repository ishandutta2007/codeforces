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

llint comb(llint n, llint k)
{
	llint ret = 1;
	rep(i, 1, k) ret *= n+1-i;
	rep(i, 1, k) ret /= i;
	return ret;
}

ll T;
ll n, m = 3, k = 2;
ll a[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		sort(a+1, a+n+1);
		
		ll ans = 0;
		rep(i, 1, n){
			ll l = lower_bound(a+1, a+n+1, a[i]-k) - a;
			if(l > i-m+1) continue;
			ans += comb(i-l, m-1);
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}