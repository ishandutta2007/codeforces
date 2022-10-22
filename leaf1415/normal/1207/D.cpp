#include <iostream>
#include <vector>
#include <utility>
#include <map>
#define llint long long
#define mod 998244353

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint cnt[300005], cnt2[300005];
map<P, llint> mp;

const int FACT_MAX = 300005;
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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	make_fact();
	
	cin >> n;
	llint a, b;
	for(int i = 1; i <= n; i++){
		cin >> a >> b;
		cnt[a]++, cnt2[b]++;
		mp[make_pair(a, b)]++;
	}
	
	llint num1 = 1, num2 = 1, num12 = 1;
	for(int i = 1; i <= n; i++) num1 *= fact[cnt[i]], num1 %= mod;
	for(int i = 1; i <= n; i++) num2 *= fact[cnt2[i]], num2 %= mod;
	
	P pre = make_pair(0, 0);
	for(auto it = mp.begin(); it != mp.end(); it++){
		if(it->first.first < pre.first || it->first.second < pre.second){
			num12 = 0;
			break;
		}
		num12 *= fact[it->second], num12 %= mod;
		pre = it->first;
	}
	
	llint ans = fact[n];
	ans += mod - num1, ans %= mod;
	ans += mod - num2, ans %= mod;
	ans += num12, ans %= mod;
	cout << ans << endl;
	
	return 0;
}