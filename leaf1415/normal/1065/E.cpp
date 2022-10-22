#include <iostream>
#define llint long long
#define mod 998244353

using namespace std;

llint n, m, A;
llint b[200005];
llint beki[200005];

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

int main(void)
{
	cin >> n >> m >> A;
	for(int i = 1; i <= m; i++) cin >> b[i];
	
	/*beki[0] = 1;
	for(int i = 1; i < 200005; i++){
		beki[i] = beki[i-1] * A;
		beki[i] %= mod;
	}*/
	llint inv2 = pow(2, mod-2);
	
	llint ans = 1;
	for(int i = 1; i <= m; i++){
		llint l = b[i] - b[i-1];
		llint tmp = (pow(A, 2*l)+mod-pow(A, l)) % mod;
		tmp *= inv2, tmp %= mod;
		tmp += pow(A, l), tmp %= mod;
		ans *= tmp, ans %= mod;
	}
	ans *= pow(A, n-2*b[m]), ans %= mod;
	cout << ans << endl;
	return 0;
}