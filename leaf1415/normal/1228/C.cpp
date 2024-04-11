#include <iostream>
#include <set>
#include <vector>
#define llint long long
#define mod 1000000007

using namespace std;

llint x, n;
vector<llint> vec;

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
	
	cin >> x >> n;
	for(int i = 2; i < 40000; i++){
		if(x % i == 0){
			vec.push_back(i);
			while(x % i == 0) x /= i;
		}
	}
	if(x > 1) vec.push_back(x);
	
	llint ans = 1;
	for(int i = 0; i < vec.size(); i++){
		llint p = vec[i], mul = p, cnt = 0;
		while(mul <= n){
			cnt += n / mul;
			//cout << p << " " << mul << " " << cnt << endl;
			if(mul > n/p) break;
			mul *= p;
		}
		ans *= modpow(p, cnt), ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}