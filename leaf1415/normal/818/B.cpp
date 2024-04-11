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

ll n, m;
ll a[105];
ll ans[105];
set<ll> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	rep(i, 1, m) cin >> a[i], a[i]--;
	
	rep(i, 1, m-1){
		ll x = (a[i+1]-a[i]+n) % n;
		if(x == 0) x = n;
		
		if(ans[a[i]] != 0 && ans[a[i]] != x){
			cout << -1 << endl;
			return 0;
		}
		if(ans[a[i]] == 0 && S.count(x)){
			cout << -1 << endl;
			return 0;
		}
		
		ans[a[i]] = x;
		S.insert(x);
	}
	
	ll p = 1;
	rep(i, 0, n-1){
		if(ans[i]) continue;
		while(S.count(p)) p++;
		ans[i] = p, p++;
	}
	rep(i, 0, n-1) cout << ans[i] << " "; cout << endl;
	
	return 0;
}