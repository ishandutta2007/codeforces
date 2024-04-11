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
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
ll a[75];
bool prime[105];
vector<ll> pvec;
ll beki[100005];
ll dp[2][1<<11];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	rep(i, 2, 100){
		if(prime[i]) continue;
		for(int j = 2*i; j < 105; j+=i) prime[j] = true;
	}
	rep(i, 2, 35) if(!prime[i]) pvec.push_back(i);

	beki[0] = 1;
	rep(i, 1, 100000) beki[i] = beki[i-1] * 2 % mod;

	cin >> n;
	ll x;
	rep(i, 1, n){
		cin >> x;
		a[x]++;
	}

	ll m = 1<<11;
	dp[1][0] = 1;

	rep(i, 1, 70){

		rep(j, 0, m-1) dp[(i+1)&1][j] = 0;
		if(a[i] == 0){
			rep(j, 0, m-1) dp[(i+1)&1][j] = dp[i&1][j];
			continue;
		}

		ll x = i, b = 0;
		rep(j, 0, 10){
			ll p = pvec[j], cnt = 0;
			while(x % p == 0){
				x /= p;
				cnt++;
			}
			if(cnt % 2) b |= 1<<j;
		}
		if(x > 1) b = 0;

		//cout << i << " " << x << " " << b << endl;

		rep(j, 0, m-1){
			if(x == 1) dp[(i+1)&1][j^b] += dp[i&1][j] * beki[a[i]-1] % mod, dp[(i+1)&1][j^b] %= mod;
			dp[(i+1)&1][j] += dp[i&1][j] * beki[a[i]-1] % mod, dp[(i+1)&1][j] %= mod;
		}
	}
	ll ans = dp[1][0] + mod -1;
	cout << ans % mod << endl;

	return 0;
}