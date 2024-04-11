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

int n;
int a[200005];
int cnt[1000005], mcnt[1000005];
vector<int> vec[1000005];
bool prime[1000005];
ll dp[1000005];

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


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 2, 1005){
		if(prime[i]) continue;
		for(int j = 2*i; j < 1000005; j+=i) prime[j] = true;
	}
	
	cin >> n;
	rep(i, 1, n) cin >> a[i], cnt[a[i]]++;
	
	rep(i, 1, 1000000){
		for(int j = i; j <= 1000000; j+=i) vec[j].push_back(i), mcnt[i] += cnt[j];
		if(mcnt[i] >= 1) dp[i] = mcnt[i] * modpow(2, mcnt[i]-1) % mod;
	}
	
	for(int i = 2; i < 1000005; i++){
		if(prime[i]) continue;
		for(int j = 1; j <= 1000004/i; j++){
			dp[j] += mod - dp[j*i];
			if(dp[j] >= mod) dp[j] -= mod;
		}
	}
	
	ll ans = 0;
	rep(i, 2, 1000000){
		ans += dp[i] * i % mod;
		if(ans >= mod) ans -= mod;
	}
	cout << ans << endl;
	
	return 0;
}