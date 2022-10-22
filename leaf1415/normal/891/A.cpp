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
ll a[2005];

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	ll g = 0, cnt = 0;
	rep(i, 1, n){
		g = gcd(g, a[i]);
		if(a[i] > 1) cnt++;
	}
	if(g > 1){
		cout << -1 << endl;
		return 0;
	}
	if(cnt < n){
		cout << cnt << endl;
		return 0;
	}
	
	ll ans = inf;
	rep(i, 1, n){
		ll g = 0;
		rep(j, i, n){
			g = gcd(g, a[j]);
			if(g == 1){
				chmin(ans, j-i + n-1);
				break;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}