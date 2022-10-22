#include <iostream>
#define llint long long
#define mod 1000000007

using namespace std;

llint n;
llint a[1000005], b[1<<20];

void zeta_transform(llint a[], int n)
{
	int S = 1<<n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < S; j++){
			if(!(j&(1<<i))) a[j] += a[j^(1<<i)];
		}
	}
}

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
	
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) b[a[i]]++;
	zeta_transform(b, 20);
	
	llint ans = modpow(2, n);
	for(int i = 1; i < (1<<20); i++){
		llint sgn = 1;
		for(int j = 0; j < 20; j++){
			if(i & (1<<j)) sgn *= -1;
		}
		llint tmp = (modpow(2, b[i]) + mod - 1) % mod;
		ans += (mod + sgn * tmp) % mod, ans %= mod;
	}
	ans += mod - 1, ans %= mod;
	cout << ans << endl;
	
	return 0;
}