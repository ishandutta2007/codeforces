#include <iostream>
#include <vector>
#define llint long long
#define mod 1000000007

using namespace std;

llint m;
bool prime[100005];
vector<int> vec[100005];
llint pro[1<<6], dp[1<<6];
llint inv;

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

void moebius_transform(llint a[], int n)
{
	int S = 1<<n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < S; j++){
			if(!(j&(1<<i))) a[j] += mod - a[j^(1<<i)], a[j] %= mod;
		}
	}
}

int main(void)
{
	cin >> m;
	inv = modpow(m, mod-2);
	
	for(int i = 2; i < 1005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 100005; j+=i) prime[j] = true;
	}
	for(int i = 2; i < 100005; i++){
		if(prime[i]) continue;
		for(int j = i; j < 100005; j+=i) vec[j].push_back(i);
	}
	
	llint ans = 0;
	for(int i = 1; i <= m; i++){
		int n = vec[i].size(), N = 1 << n;
		//cout << i << " " << n << " " << N << endl;
		for(int j = 0; j < N; j++){
			pro[j] = 0;
			llint mul = 1;
			for(int k = 0; k < n; k++) if(j&(1<<k)) mul *= vec[i][k];
			pro[j] = m / mul;
		}
		//for(int j = 0; j < N; j++) cout << pro[j] << " "; cout << endl;
		moebius_transform(pro, n);
		//for(int j = 0; j < N; j++) cout << pro[j] << " "; cout << endl;
		for(int j = 0; j < N; j++) pro[j] *= inv, pro[j] %= mod;
		
		
		dp[0] = 0;
		for(int j = 1; j < N; j++){
			dp[j] = 0;
			llint sum = 0;
			for(int k = 0; k < N; k++){
				if((j & k) == 0) continue;
				dp[j] += pro[(N-1)-k] * dp[j & ~k] % mod, dp[j] %= mod;
				sum += pro[(N-1)-k], sum %= mod;
			}
			dp[j]++, dp[j] %= mod;
			//cout << "!" << j << " " << dp[j] << " " << sum << endl;
			dp[j] *= modpow(sum, mod-2), dp[j] %= mod;
		}
		//for(int j = 0; j < N; j++) cout << dp[j] << " "; cout << endl;
		ans += dp[N-1], ans %= mod;
		//cout << ans << endl;
	}
	//cout << "*" << endl;
	ans *= inv, ans %= mod;
	ans++, ans %= mod;
	cout << ans << endl;
	
	return 0;
}