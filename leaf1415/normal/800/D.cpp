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
#define eps 1e-11
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

ll n;
ll beki[1000005];
ll a[1000005];
ll num[1000005], sum[1000005], sum2[1000005];

void calc(ll a[])
{
	ll mul = 1;
	rep(i, 0, 5){
		for(int j = 999999; j >= 0; j--){
			if(j/(mul*10) == (j+mul)/(mul*10)) a[j] += a[j+mul], a[j] %= mod;
		}
		mul *= 10;
	}
}
void calc2(ll a[])
{
	ll mul = 1;
	rep(i, 0, 5){
		for(int j = 0; j <= 999999; j++){
			if(j/(mul*10) == (j+mul)/(mul*10)) a[j] += mod - a[j+mul], a[j] %= mod;
		}
		mul *= 10;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	beki[0] = 1;
	rep(i, 1, 1000000) beki[i] = beki[i-1] * 2 % mod;
	
	cin >> n;
	ll x;
	rep(i, 1, n){
		cin >> x;
		num[x]++;
		sum[x] += x, sum[x] %= mod;
		sum2[x] += x*x%mod, sum2[x] %= mod;
	}
	
	calc(num), calc(sum), calc(sum2);
	rep(i, 0, 999999){
		if(num[i] >= 1) a[i] = beki[num[i]-1] * sum2[i] % mod;
		if(num[i] >= 2) a[i] += (sum[i] * sum[i] % mod + mod - sum2[i]) % mod * beki[num[i]-2] % mod, a[i] %= mod;
	}
	calc2(a);
	
	ll ans = 0;
	rep(i, 0, 999999) ans ^= i * a[i];
	cout << ans << endl;
	
	return 0;
}