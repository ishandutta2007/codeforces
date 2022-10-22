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
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll t, l, r;
ll dp[5000005];
ll prime[5000005];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t >> l >> r;
	
	rep(i, 2, 5000000){
		if(prime[i]) continue;
		for(int j = 2*i; j <= 5000000; j+=i){
			if(prime[j] == 0) prime[j] = i;
		}
	}
	
	rep(i, 2, r){
		if(prime[i] == 0) dp[i] = i*(i-1)/2;
		else dp[i] = dp[i/prime[i]]+i*(prime[i]-1)/2;
	}
	
	ll ans = 0, mul = 1;
	rep(i, l, r){
		ans += dp[i] % mod * mul % mod, ans %= mod;
		mul *= t, mul %= mod;
	}
	cout << ans << endl;
	
	return 0;
}