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

ll T;
ll n;
ll a[300005];
bool b[300005];

bool check(ll i)
{
	if(i == 1 || i == n) return false;
	if(a[i] > a[i-1] && a[i] > a[i+1]) return true;
	if(a[i] < a[i-1] && a[i] < a[i+1]) return true;
	return false;
}

ll calc(ll i, ll x)
{
	ll pre = 0;
	rep(j, i-5, i+5){
		if(j < 1 || j > n) continue;
		if(check(j)) pre++;
	}
	
	ll org = a[i];
	a[i] = x;
	
	ll cur = 0;
	rep(j, i-5, i+5){
		if(j < 1 || j > n) continue;
		if(check(j)) cur++;
	}
	
	a[i] = org;
	
	return pre - cur;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n) b[i] = check(i);
		
		ll sum = 0;
		rep(i, 1, n) if(b[i]) sum++;
		
		ll ans = sum;
		rep(i, 1, n){
			ans = chmin(ans, sum - calc(i, a[i-1]));
			ans = chmin(ans, sum - calc(i, a[i+1]));
			ans = chmin(ans, sum - calc(i, inf));
			ans = chmin(ans, sum - calc(i, -inf));
		}
		cout << ans << endl;
	}
	
	return 0;
}