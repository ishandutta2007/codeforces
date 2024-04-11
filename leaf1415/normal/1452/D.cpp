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
#define mod 998244353

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

ll n;
ll dp[200005], sum[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	dp[0] = 1, sum[0] = 1;
	rep(i, 1, n){
		dp[i] = sum[i-1];
		sum[i] = dp[i];
		if(i-2 >= 0) sum[i] += sum[i-2], sum[i] %= mod;
	}
	ll ans = dp[n];
	ans *= modpow((mod+1)/2, n), ans %= mod;
	cout << ans << endl;
	
	return 0;
}