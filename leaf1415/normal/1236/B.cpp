#include <iostream>
#define llint long long
#define mod 1000000007

using namespace std;

llint n, m;

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
	
	cin >> n >> m;
	llint ans = modpow(2, m);
	ans += mod-1, ans %= mod;
	ans = modpow(ans, n);
	cout << ans << endl;
	
	return 0;
}