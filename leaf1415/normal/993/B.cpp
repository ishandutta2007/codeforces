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
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, m;
P p[15], q[15];
ll G[15][15];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	rep(i, 1, n){
		cin >> p[i].first >> p[i].second;
		if(p[i].first > p[i].second) swap(p[i].first, p[i].second);
	}
	rep(i, 1, m){
		cin >> q[i].first >> q[i].second;
		if(q[i].first > q[i].second) swap(q[i].first, q[i].second);
	}
	
	rep(i, 1, n){
		rep(j, 1, m){
			if(p[i] == q[j]) continue;
			ll a = p[i].first, b = p[i].second, c = q[j].first, d = q[j].second;
			if(a == c) G[i][j] = a;
			if(a == d) G[i][j] = a;
			if(b == c) G[i][j] = b;
			if(b == d) G[i][j] = b;
		}
	}
	
	ll mn = inf, mx = -inf;
	rep(i, 1, n) rep(j, 1, m) if(G[i][j]) chmin(mn, G[i][j]), chmax(mx, G[i][j]);
	if(mn == mx){
		cout << mn << endl;
		return 0;
	}
	
	/*rep(i, 1, n){
		rep(j, 1, m) cout << G[i][j] << " ";
		cout << endl;
	}*/
	
	rep(i, 1, n){
		ll mn = inf, mx = -inf;
		rep(j, 1, m) if(G[i][j]) chmin(mn, G[i][j]), chmax(mx, G[i][j]);
		if(mx > 0 && mn != mx){
			cout << -1 << endl;
			return 0;
		}
	}
	rep(j, 1, m){
		ll mn = inf, mx = -inf;
		rep(i, 1, n) if(G[i][j]) chmin(mn, G[i][j]), chmax(mx, G[i][j]);
		if(mx > 0 && mn != mx){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	
	return 0;
}