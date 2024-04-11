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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
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

ll T;
ll n;
ll a[200005], b[200005];

bool check(ll x)
{
	ll sum = 0;
	rep(i, 1, n){
		if(b[i] <= x || sum >= b[i]) sum += b[i];
		else return false;
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i], b[i] = a[i];
		sort(b+1, b+n+1);
		
		ll ub = 1e9+7, lb = 0, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(check(mid)) ub = mid;
			else lb = mid;
		}
		
		vector<ll> ans;
		rep(i, 1, n) if(a[i] >= ub) ans.push_back(i);
		sort(all(ans));
		
		cout << ans.size() << endl;
		for(auto x : ans) cout << x << " "; cout << endl;
	}
	
	return 0;
}