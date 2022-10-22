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
ll t[100005], x[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> t[i] >> x[i];
		t[n+1] = inf;
		
		ll ans = 0, p = 0, s = 0, g = 0, l = 0;
		rep(i, 1, n){
			if(abs(s-g) <= t[i] - l){
				s = g, g = x[i], l = t[i];
				if(abs(s-g) <= t[i+1]-t[i]) ans++;
				continue;
			}
			ll L = t[i] - l, R = min(abs(s-g), t[i+1] - l);
			if(s <= g) L = s + L, R = s + R;
			else L = s - L, R = s - R, swap(L, R);
			if(L <= x[i] && x[i] <= R) ans++;
		}
		cout << ans << endl;
	}
	
	return 0;
}