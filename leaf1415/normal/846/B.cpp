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

ll n, k, m;
ll a[55];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> m;
	
	ll s = 0;
	rep(i, 1, k) cin >> a[i], s += a[i];
	
	ll ans = 0;
	rep(i, 0, n){
		ll rem = m - s*i;
		if(rem < 0) break;
		
		ll cnt = (k+1)*i;
		priority_queue<ll, vector<ll>, greater<ll> > Q;
		rep(j, 1, k) rep(l, 1, n-i) Q.push(a[j]);
		while(Q.size() && rem >= Q.top()){
			cnt++;
			rem -= Q.top();
			Q.pop();
		}
		chmax(ans, cnt);
	}
	cout << ans << endl;
	
	return 0;
}