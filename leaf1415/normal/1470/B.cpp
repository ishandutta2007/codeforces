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
ll n, Q;
ll a[300005];
ll ans[300005];
ll prime[1000005];
map<ll, ll> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 2, 1005){
		if(prime[i]) continue;
		for(int j = 2*i; j < 1000005; j+=i) prime[j] = i;
	}
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		
		mp.clear();
		rep(i, 1, n){
			ll x = a[i], mul = 1;
			while(prime[x]){
				ll p = prime[x];
				if(mul % p == 0) mul /= p;
				else mul *= p;
				x /= p;
			}
			if(x > 1){
				if(mul % x == 0) mul /= x;
				else mul *= x;
			}
			//cout << mul << endl;
			mp[mul]++;
		}
		
		rep(i, 0, 5){
			ans[i] = 0;
			//for(auto p : mp) cout << p.first << " "; cout << endl;
			map<ll, ll> tmp;
			for(auto p : mp){
				chmax(ans[i], p.second);
				if(p.second % 2) tmp[p.first] += p.second;
				else tmp[1] += p.second;
			}
			mp = tmp;
		}
		
		//rep(i, 0, 5) cout << ans[i] << " "; cout << endl;
		
		cin >> Q;
		ll w;
		rep(q, 1, Q){
			cin >> w;
			if(w <= 4) cout << ans[w] << "\n";
			else cout << ans[5] << "\n";
		}
	}
	flush(cout);
	
	return 0;
}