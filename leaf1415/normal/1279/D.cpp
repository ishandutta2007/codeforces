#include <iostream>
#include <vector>
#define llint long long
#define mod 998244353

using namespace std;

llint n;
llint k[1000005];
vector<llint> vec[1000005];
llint cnt[1000005];
llint inv[1005];

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
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		llint x;
		for(int j = 0; j < k[i]; j++){
			cin >> x;
			vec[i].push_back(x);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < vec[i].size(); j++){
			cnt[vec[i][j]]++;
		}
	}
	llint invN = modpow(n, mod-2);
	for(int i = 1; i <= 1000; i++) inv[i] = modpow(i, mod-2);
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		llint p = invN;
		if(k[i] <= 1000) p *= inv[k[i]], p %= mod;
		else p *= modpow(k[i], mod-2), p %= mod;
		
		llint sum = 0;
		for(int j = 0; j < vec[i].size(); j++){
			sum += cnt[vec[i][j]] * invN % mod, sum %= mod;
		}
		ans += sum * p % mod, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}