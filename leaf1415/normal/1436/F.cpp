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
#define mod 998244353

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint m;
llint a[100005], b[100005], c[100005], ans[100005];
bool prime[100005];
vector<llint> pvec;

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
	
	for(int i = 2; i < 1005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 100005; j+=i) prime[j] = true;
	}
	for(int i = 2; i < 100005; i++){
		if(!prime[i]) pvec.push_back(i);
	}
	
	cin >> m;
	llint x, y;
	for(int i = 1; i <= m; i++){
		cin >> x >> y;
		a[x] += y;
		b[x] += x*y%mod, b[x] %= mod;
		c[x] += x*x%mod*y%mod, c[x] %= mod;
	}
	
	for(int i = 0; i < pvec.size(); i++){
		llint p = pvec[i];
		for(int j = 100004/p; j >= 1; j--){
			a[j] += a[j*p];
			b[j] += b[j*p], b[j] %= mod;
			c[j] += c[j*p], c[j] %= mod;
		}
	}
	
	for(int i = 1; i <= 100000; i++){
		llint sum = 0, mul, mul2;
		if(a[i] >= 2){
			mul = c[i], mul2 = (a[i]-1)%mod * modpow(2, a[i]-2) % mod;
			sum += mul * mul2 % mod, sum %= mod;
		}
		if(a[i] >= 3){
			mul = b[i]*b[i]%mod + mod - c[i], mul %= mod;
			mul2 = (a[i]-2)%mod * modpow(2, a[i]-3) % mod;
			sum += mul * mul2 % mod, sum %= mod;
		}
		if(a[i] >= 2){
			mul = b[i]*b[i]%mod + mod - c[i], mul %= mod;
			mul2 = modpow(2, a[i]-2);
			sum += mul * mul2 % mod, sum %= mod;
		}
		ans[i] = sum;
	}
	
	for(int i = 0; i < pvec.size(); i++){
		llint p = pvec[i];
		for(int j = 1; j <= 100004/p; j++){
			ans[j] += mod - ans[j*p], ans[j] %= mod;
		}
	}
	cout << ans[1] << endl;
	
	return 0;
}