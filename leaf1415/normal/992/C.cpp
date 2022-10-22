#include <iostream>
#define llint long long
#define mod 1000000007

using namespace std;

llint pow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (pow(a, n-1)%mod)) % mod;
	}
	else{
		return pow((a*a)%mod, n/2) % mod;
	}
}


llint x, k;

int main(void)
{
	cin >> x >> k;
	if(x == 0){
		cout << 0 << endl;
		return 0;
	}
	
	llint ans = pow(2, k+1) * (x % mod) % mod + 1;
	ans += mod - pow(2, k) % mod;
	ans %= mod;
	cout << ans << endl;
	return 0;
}