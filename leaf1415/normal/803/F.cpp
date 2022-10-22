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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

ll n;
ll a[100005], cnt[100005], seq[100005];
bool prime[100005];

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
		for(int j = 2*i; j < 100005; j+=i) prime[j] = true;
	}
	
	cin >> n;
	rep(i, 1, n) cin >> a[i], cnt[a[i]]++;
	
	rep(p, 2, 100000){
		if(prime[p]) continue;
		for(int i = 100003/p; i >= 1; i--) cnt[i] += cnt[i*p];
	}
	
	rep(i, 1, 100000) seq[i] = (modpow(2, cnt[i]) + mod - 1) % mod;
	
	rep(p, 2, 100000){
		if(prime[p]) continue;
		for(int i = 1; i <= 100003/p; i++) seq[i] += mod - seq[i*p], seq[i] %= mod;
	}
	cout << seq[1] << endl;
	
	return 0;
}