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

ll n, m, S;
ll s[100005], a[100005], b[100005];
ll ssum[100005], asum[100005], bsum[100005];
P p[100005];

ll calc(ll x)
{
	ll pos = lower_bound(ssum+1, ssum+n, S*x) - ssum;
	ll tmp = asum[pos-1] + bsum[n] - bsum[pos];
	tmp += a[p[pos].second] * (S*x - ssum[pos-1]);
	tmp += b[p[pos].second] * (ssum[pos] - S*x);
	return tmp;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> S;
	
	ll sum = 0;
	rep(i, 1, n) cin >> s[i] >> a[i] >> b[i], sum += s[i];
	m = (sum+S-1)/S;
	s[n+1] = m*S - sum, n++;
	
	rep(i, 1, n) p[i] = P(a[i]-b[i], i);
	sort(p+1, p+n+1), reverse(p+1, p+n+1);
	rep(i, 1, n){
		ssum[i] = ssum[i-1] + s[p[i].second];
		asum[i] = asum[i-1] + a[p[i].second] * s[p[i].second];
		bsum[i] = bsum[i-1] + b[p[i].second] * s[p[i].second];
	}
	
	/*rep(i, 1, n){
		ll id = p[i].second;
		cout << s[id] << " " << a[id] << " " << b[id] << endl;
	}*/
	
	ll ans = bsum[n];
	ll ub = m, lb = 1, mid, mid2;
	while(ub-lb>4){
		mid = (lb*2+ub)/3, mid2 = (lb+ub*2)/3;
		if(calc(mid) < calc(mid2)) lb = mid;
		else ub = mid2;
	}
	
	rep(i, lb, ub) chmax(ans, calc(i));
	cout << ans << endl;
	
	return 0;
}