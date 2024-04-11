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
ll a[200005];
vector<ll> svec;
vector<ll> vec, vec2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	rep(i, 0, 1000000) svec.push_back(i*i);
	
	rep(i, 1, n){
		if(*lower_bound(all(svec), a[i]) == a[i]){
			if(a[i] == 0) vec2.push_back(2);
			else vec2.push_back(1);
		}
		else{
			ll p = lower_bound(all(svec), a[i]) - svec.begin();
			vec.push_back(min(svec[p]-a[i], a[i] - svec[p-1]));
		}
	}
	if(vec.size() >= vec2.size()){
		ll d = (int)vec.size() - n/2;
		sort(all(vec));
		ll ans = 0;
		rep(i, 0, d-1) ans += vec[i];
		cout << ans << endl;
	}
	else{
		ll d = (int)vec2.size() - n/2;
		sort(all(vec2));
		ll ans = 0;
		rep(i, 0, d-1) ans += vec2[i];
		cout << ans << endl;
	}
	
	return 0;
}