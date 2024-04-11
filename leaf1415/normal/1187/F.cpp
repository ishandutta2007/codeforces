#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdio.h>
#include <map>
#define llint long long
#define mod 1000000007
#define inf 1e9

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint l[200005], r[200005];
llint Ef[200005];

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
	for(int i = 1; i <= n; i++) cin >> l[i];
	for(int i = 1; i <= n; i++) cin >> r[i];
	
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	
	for(int i = 1; i <= n-1; i++){
		llint ll = max(l[i], l[i+1]), rr = min(r[i], r[i+1]);
		llint len = max(0LL, rr - ll + 1) % mod;
		llint base = (r[i]-l[i]+1) * (r[i+1]-l[i+1]+1) % mod;
		Ef[i] = len * modpow(base, mod-2) % mod;
	}
	
	llint Efsum = 0, Ef2sum = 0, Efsum2;
	for(int i = 1; i <= n-1; i++) Efsum += Ef[i], Efsum %= mod;
	for(int i = 1; i <= n-1; i++) Ef2sum += Ef[i] * Ef[i] % mod, Ef2sum %= mod;
	Efsum2 = Efsum * Efsum % mod;
	
	llint ans = n*n%mod;
	ans += mod - 2*n%mod*Efsum%mod, ans %= mod;
	
	ans += Efsum2, ans %= mod;
	ans += mod - Ef2sum, ans %= mod;
	ans += Efsum, ans %= mod;
	
	for(int i = 1; i <= n-2; i++) ans += mod - 2*Ef[i]%mod*Ef[i+1] % mod, ans %= mod;
	for(int i = 1; i <= n-2; i++){
		llint ll = max(l[i], max(l[i+1], l[i+2])), rr = min(r[i], min(r[i+1], r[i+2]));
		llint len = max(0LL, rr - ll + 1) % mod;
		llint base = (r[i]-l[i]+1) * (r[i+1]-l[i+1]+1) % mod * (r[i+2]-l[i+2]+1) % mod;
		ans += 2 * len % mod * modpow(base, mod-2) % mod, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}