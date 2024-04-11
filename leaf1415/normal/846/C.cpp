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
ll a[5005], s[5005];
P l[5005], r[5005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i], s[i] = s[i-1] + a[i];
	
	l[0] = P(0, 0);
	rep(i, 1, n){
		l[i] = P(-inf, -inf);
		rep(j, 0, i) chmax(l[i], P(s[j] - (s[i] - s[j]), j));
	}
	
	r[n+1] = P(0, n);
	for(int i = n; i >= 1; i--){
		r[i] = P(-inf, -inf);
		rep(j, i-1, n) chmax(r[i], P(s[j] - s[i-1] - (s[n] - s[j]), j));
	}
	
	ll ans = -inf, ans_i;
	rep(i, 0, n){
		ll val = l[i].first + r[i+1].first;
		if(ans < val){
			ans = val;
			ans_i = i;
		}
	}
	cout << l[ans_i].second << " " << ans_i << " " << r[ans_i+1].second << endl;
	
	return 0;
}