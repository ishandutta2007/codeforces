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

ll n, m, k;
ll a[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	ll x;
	rep(i, 1, n){
		cin >> x;
		a[x] = 1;
	}
	
	ll ans = 0, sum = 0;
	rep(i, 1, 1000000){
		if(i-m >= 0) sum -= a[i-m];
		sum += a[i];
		if(sum >= k) sum--, a[i]--, ans++;
	}
	cout << ans << endl;
	
	return 0;
}