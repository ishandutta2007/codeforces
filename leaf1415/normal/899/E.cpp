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
set<ll> S;
set<P> Q;
P p[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	a[n+1] = -1;
	
	ll cnt = 0;
	rep(i, 1, n){
		cnt++;
		if(a[i] != a[i+1]){
			p[i] = P(a[i], cnt);
			cnt = 0;
		}
	}
	rep(i, 1, n){
		if(p[i].second == 0) continue;
		S.insert(i);
		Q.insert(P(-p[i].second, i));
	}
	p[0] = P(0, 1), p[n+1] = P(-1, 1);
	S.insert(0), S.insert(n+1);
	
	ll ans = 0;
	while(Q.size()){
		ll x = Q.begin()->second;
		Q.erase(Q.begin());
		auto it = S.lower_bound(x);
		auto pre = it, suc = it;
		pre--, suc++;
		S.erase(it);
		
		ll px = *pre, sx = *suc;
		if(p[px].first == p[sx].first){
			Q.erase(P(-p[px].second, px));
			Q.erase(P(-p[sx].second, sx));
			S.erase(pre);
			p[sx].second += p[px].second;
			Q.insert(P(-p[sx].second, sx));
		}
		
		ans++;
	}
	cout << ans << endl;
	
	return 0;
}