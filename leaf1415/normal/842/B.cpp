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

ll R, d, n;
ll x[100005], y[100005], r[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> R >> d >> n;
	rep(i, 1, n) cin >> x[i] >> y[i] >> r[i];
	
	ll ans = 0;
	rep(i, 1, n){
		ll D = x[i]*x[i] + y[i]*y[i];
		if(D >= (R-d+r[i])*(R-d+r[i]) && D <= (R-r[i])*(R-r[i]) && R-r[i] >= 0) ans++;
	}
	cout << ans << endl;
	
	return 0;
}