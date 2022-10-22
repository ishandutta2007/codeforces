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
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
P p[1000005];
set<ll> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> p[i].first, p[i].second = i;
	sort(p+1, p+n+1), reverse(p+1, p+n+1);
	
	ll ans = 0;
	S.insert(0), S.insert(n+1);
	
	rep(i, 1, n){
		ll pos = p[i].second;
		auto it = S.lower_bound(pos); ll r = *it;
		it--; ll l = *it;
		ans += p[i].first * (r-pos)*(pos-l);
		S.insert(pos);
	}
	
	reverse(p+1, p+n+1);
	S.clear();
	S.insert(0), S.insert(n+1);
	
	rep(i, 1, n){
		ll pos = p[i].second;
		auto it = S.lower_bound(pos); ll r = *it;
		it--; ll l = *it;
		ans -= p[i].first * (r-pos)*(pos-l);
		S.insert(pos);
	}
	
	outl(ans);
	
	return 0;
}