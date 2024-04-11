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
ll a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		a[n+1] = a[n];
		
		ll cnt = 0;
		vector<ll> vec; map<ll, ll> mp;
		rep(i, 1, n){
			vec.push_back(a[i]);
			if(a[i] == a[i+1]){
				cnt++;
				mp[vec.front()]++;
				mp[vec.back()]++;
				vec.clear();
			}
		}
		
		ll mx = -1, mx_i;
		for(auto x : mp){
			if(x.second > mx){
				mx = x.second;
				mx_i = x.first;
			}
		}
		
		if(mx <= cnt+1){
			cout << cnt-1 << "\n";
			continue;
		}
		
		ll rem = 0;
		rep(i, 1, n-1){
			if(a[i] != a[i+1] && a[i] != mx_i && a[i+1] != mx_i) rem++;
		}
		if(mx - (cnt+1) > rem) cout << -1 << "\n";
		else{
			cnt += mx - (cnt+1);
			cout << cnt-1 << "\n";
		}
	}
	flush(cout);
	
	return 0;
}