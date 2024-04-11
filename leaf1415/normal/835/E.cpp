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

ll n, x, y;

ll query(vector<ll> &vec)
{
	cout << "?" << " " << vec.size();
	for(auto x : vec) cout << " " << x;
	cout << endl;
	
	ll res;
	cin >> res;
	return res;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x >> y;
	
	vector<ll> diff;
	rep(i, 0, 9){
		vector<ll> vec;
		rep(j, 1, n){
			if(j & (1<<i)) vec.push_back(j);
		}
		if(vec.size() == 0) continue;
		ll res = query(vec);
		if(res == y || res == (x^y)) diff.push_back(i);
	}
	
	
	ll p = diff.front(), ans = 1<<p;
	rep(i, 0, 9){
		if(i == p) continue;
		vector<ll> vec;
		rep(j, 1, n){
			if((j & (1<<i)) && (j & (1<<p))) vec.push_back(j);
		}
		if(vec.size() == 0) continue;
		ll res = query(vec);
		if(res == y || res == (x^y)) ans |= 1<<i;
	}
	
	ll ans2 = ans;
	for(auto b : diff) ans2 ^= 1<<b;
	if(ans > ans2) swap(ans, ans2);
	cout << "!" << " " << ans << " " << ans2 << endl;
	
	return 0;
}