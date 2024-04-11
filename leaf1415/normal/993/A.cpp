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

ll x[4], y[4];
ll X[4], Y[4];

bool check(ll x[], ll y[], ll X, ll Y)
{
	ll l = inf, r = -inf, d = inf, u = -inf;
	rep(i, 0, 3){
		l = min(l, x[i]), r = max(r, x[i]);
		d = min(d, y[i]), u = max(u, y[i]);
	}
	return X >= l && X <= r && Y >= d && Y <= u;
}

bool check2(ll x[], ll y[], ll X, ll Y)
{
	ll a[4], b[4], A, B;
	rep(i, 0, 3) a[i] = x[i]+y[i], b[i] = x[i]-y[i];
	A = X+Y, B = X-Y;
	
	ll l = inf, r = -inf, d = inf, u = -inf;
	rep(i, 0, 3){
		l = min(l, a[i]), r = max(r, a[i]);
		d = min(d, b[i]), u = max(u, b[i]);
	}
	return A >= l && A <= r && B >= d && B <= u;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 0, 3) cin >> x[i] >> y[i], x[i] *= 2, y[i] *= 2;
	rep(i, 0, 3) cin >> X[i] >> Y[i], X[i] *= 2, Y[i] *= 2;
	
	rep(i, 0, 3){
		if(check2(X, Y, x[i], y[i])){
			cout << "YES" << endl;
			return 0;
		}
		if(check(x, y, X[i], Y[i])){
			cout << "YES" << endl;
			return 0;
		}
	}
	if(check(x, y, (X[0]+X[2])/2, (Y[0]+Y[2])/2) || check2(X, Y, (x[0]+x[2])/2, (y[0]+y[2])/2)){
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	
	
	return 0;
}