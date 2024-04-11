#include <iostream>
#include <string>
#include <math.h>
#define llint long long
#define mod 1000000009

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

llint n, a, b, k;
string s;

int main(void)
{
	cin >> n >> a >> b >> k;
	cin >> s;
	
	llint m = sqrt(n+1);
	m = m/k * k;
	if(m < k) m = k;
	
	llint ans = 0;
	for(int i = 0; i < m; i++){
		llint mul = pow(a, n-i) * pow(b, i) % mod;
		if(s[i % k] == '+') ans += mul;
		else ans += mod - mul;
		ans %= mod;
	}
	
	llint ans2 = 0;
	for(int j = 0; j < (n+1)/m; j++){
		llint mul = pow(pow(a, m*j), mod-2);
		mul *= pow(b, m*j), mul %= mod;
		ans2 += mul;
		ans2 %= mod;
	}
	ans = ans * ans2 % mod;
	
	for(int i = (n+1)/m*m; i < n+1; i++){
		llint mul = pow(a, n-i) * pow(b, i) % mod;
		if(s[i % k] == '+') ans += mul;
		else ans += mod - mul;
		ans %= mod;
	}
	
	cout << ans << endl;
	return 0;
}