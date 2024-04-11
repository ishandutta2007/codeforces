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

llint n, m;
llint s1[100005], s2[100005];

int main(void)
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> s1[i];
	for(int i = 0; i < n; i++) cin >> s2[i];
	
	llint ans = 0, coe = 1, p;
	for(int i = 0; i < n; i++){
		if(s1[i] == 0 && s2[i] == 0){
			p = m-1;
			p *= pow(2*m, mod-2);
			p %= mod;
		}
		else if(s1[i] == 0){
			p = m-s2[i];
			p *= pow(m, mod-2);
			p %= mod;
		}
		else if(s2[i] == 0){
			p = s1[i]-1;
			p *= pow(m, mod-2);
			p %= mod;
		}
		else{
			if(s1[i] > s2[i]) p = 1;
			else p = 0;
		}
		p *= pow(coe, mod-2);
		ans += p;
		ans %= mod;
		if(s1[i] == 0 || s2[i] == 0){
			coe *= m;
			coe %= mod;
		}
		if(s1[i] && s2[i] && s1[i] != s2[i]) break;
	}
	
	cout << ans << endl;
	return 0;
}