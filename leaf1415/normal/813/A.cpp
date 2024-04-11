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
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, m;
ll a[1005];
ll l[1005], r[1006];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	cin >> m;
	rep(i, 1, m) cin >> l[i] >> r[i];
	
	ll sum = 0;
	rep(i, 1, n) sum += a[i];
	
	ll ans = inf;
	rep(i, 1, m){
		if(l[i] <= sum && sum <= r[i]) ans = sum;
		if(sum <= l[i]) chmin(ans, l[i]);
	}
	if(ans > inf/2) ans = -1;
	cout << ans << endl;
	
	return 0;
}