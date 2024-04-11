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
ll a[100005], s[100005];
set<ll> S;

void calc(ll l, ll r)
{
	S.insert(s[r] - s[l-1]);
	if(a[l] == a[r]) return;
	
	ll m = (a[l]+a[r]) / 2;
	m = upper_bound(a+1, a+n+1, m) - a;
	calc(l, m-1), calc(m, r);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> Q;
		rep(i, 1, n) cin >> a[i];
		sort(a+1, a+n+1);
		rep(i, 1, n) s[i] = s[i-1] + a[i];
		
		S.clear();
		calc(1, n);
		
		ll x;
		rep(i, 1, Q){
			cin >> x;
			if(S.count(x)) cout << "Yes" << "\n";
			else cout << "No" << "\n";
		}
	}
	flush(cout);
	
	return 0;
}