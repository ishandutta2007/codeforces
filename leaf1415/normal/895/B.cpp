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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, x, k;
ll a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x >> k;
	rep(i, 1, n) cin >> a[i];
	sort(a+1, a+n+1);

	ll ans = 0;
	rep(i, 1, n){
		ll l = (a[i]-1) / x + k, r = l + 1;
		l *= x, r *= x;
		chmax(l, a[i]);
		l = lower_bound(a+1, a+n+1, l) - a;
		r = lower_bound(a+1, a+n+1, r) - a - 1;
		ans += r - l + 1;
	}

	cout << ans << endl;

	return 0;
}