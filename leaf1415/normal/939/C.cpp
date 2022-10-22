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

ll n;
ll a[300005], s[300005];
ll l, r;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i], a[n+i] = a[i], a[2*n+i] = a[i];
	rep(i, 1, 3*n) s[i] = s[i-1] + a[i];
	cin >> l >> r;
	
	P ans = P(0, -inf);
	for(int i = 1; i+(r-l)-1 <= 3*n; i++){
		ll x = s[i+(r-l)-1] - s[i-1];
		ll t = l - (i - 1);
		while(t > n) t -= n;
		while(t <= 0) t += n;
		chmax(ans, P(x, -t));
	}
	cout << -ans.second << endl;
	
	return 0;
}