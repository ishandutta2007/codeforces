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
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll T;
ll n, Q;
ll a[200005], sum[200005], mx[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> Q;
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n) sum[i] = sum[i-1] + a[i];
		rep(i, 1, n) mx[i] = max(mx[i-1], sum[i]);

		ll x;
		rep(q, 1, Q){
			cin >> x;
			if(sum[n] <= 0 && mx[n] < x){
				cout << -1 << " ";
				continue;
			}
			ll ans = 0;
			if(mx[n] < x){
				ll k = (x - mx[n] + sum[n] - 1) / sum[n];
				ans += k * n;
				x -= k * sum[n];
			}
			ans += lower_bound(mx, mx+n+1, x) - mx;
			cout << ans - 1 << " ";
		}
		cout << endl;
	}
	
	return 0;
}