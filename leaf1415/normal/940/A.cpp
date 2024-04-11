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

ll n, d;
ll a[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d;
	rep(i, 1, n) cin >> a[i];
	sort(a+1, a+n+1);

	ll ans = inf;
	rep(i, 1, n){
		ll p = upper_bound(a+1, a+n+1, a[i]+d) - a;
		chmin(ans, n+1-p + i-1);
	}
	cout << ans << endl;

	return 0;
}