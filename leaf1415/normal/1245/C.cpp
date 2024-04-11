#include <iostream>
#include <string>
#define llint long long
#define mod 1000000007

using namespace std;

string s;

const int FACT_MAX = 200005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

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

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < FACT_MAX; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	fact_inv[FACT_MAX-1] = modpow(fact[FACT_MAX-1], mod-2);
	for(int i = FACT_MAX-2; i >= 0; i--){
		fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
	}
}

llint comb(llint n, llint k)
{
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_inv[k], ret %= mod;
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
}

llint calc(llint x)
{
	llint ret = 0;
	for(int i = 0; i <= x/2; i++){
		ret += comb(x-i, i), ret %= mod;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> s;
	s +="#";
	
	llint ans = 1, cnt = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'm' || s[i] == 'w'){
			cout << 0 << endl;
			return 0;
		}
		if(s[i] != 'u' && s[i] != 'n'){
			if(cnt > 0) ans *= calc(cnt), ans %= mod;
			cnt = 0;
		}
		else{
			if(i == 0 || s[i-1] == s[i]) cnt++;
			else{
				if(cnt > 0) ans *= calc(cnt), ans %= mod;
				cnt = 1;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}