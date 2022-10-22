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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) =) min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, d, b;
ll a[100005], c[100005];

bool check(ll x)
{
	set<P> S;
	rep(i, 1, n) if(a[i] > 0) S.insert(P(i, a[i]));

	ll l = x+1, r = (n+1)/2;
	rep(i, l, r){
		ll rem = b;
		while(rem > 0){
			auto it = S.lower_bound(P(i-i*d, -inf));
			if(it == S.end() || it->first > i+i*d) return false;
			ll p = it->first, v = it->second;
			ll m = min(rem, v);
			rem -= m, v -= m;
			S.erase(it);
			if(v > 0) S.insert(P(p, v));
		}
	}

	//for(auto p : S) cout << p.first << " " << p.second << endl;


	l = r+1, r = n-x;
	for(int i = r; i >= l; i--){
		ll rem = b;
		while(rem > 0){
			auto it = S.upper_bound(P(i+i*d, inf));
			if(S.size() == 0 || it == S.begin()) return false;
			it--;
			if(it->first < i-(n+1-i)*d) return false;
			ll p = it->first, v = it->second;
			ll m = min(rem, v);
			rem -= m, v -= m;
			S.erase(it);
			if(v > 0) S.insert(P(p, v));
		}
	}

	//for(auto p : S) cout << p.first << " " << p.second << endl;


	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d >> b;
	rep(i, 1, n) cin >> a[i];

	ll ub = n/2, lb = -1, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;

	return 0;
}