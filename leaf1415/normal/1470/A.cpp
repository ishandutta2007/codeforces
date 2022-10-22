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
ll n, m;
ll k[300005], c[300005];

bool check(ll x)
{
	rep(i, 1, x){
		if(i > k[n-x+i]) return false;
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, 1, n) cin >> k[i];
		sort(k+1, k+n+1);
		rep(i, 1, m) cin >> c[i];
		
		ll sum = 0;
		rep(i, 1, n) sum += c[k[i]];
		ll ans = sum;
		
		rep(i, 1, min(m, n)){
			sum += c[i], sum -= c[k[n+1-i]];
			chmin(ans, sum);
		}
		cout << ans << endl;
	}
	
	return 0;
}