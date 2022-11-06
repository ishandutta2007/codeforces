#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N = 1e5 + 10, mod = 998244353;
int n, a[N];
ll s[N];
int fac[N], inv[N], invfac[N];
void init() 
{
	fac[0] = inv[1] = invfac[0] = 1;
	for(int i = 1; i < N; i ++) fac[i] = 1LL * fac[i - 1] * i % mod;
	for(int i = 2; i < N; i ++) inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 1; i < N; i ++) invfac[i] = 1LL * invfac[i - 1] * inv[i] % mod;
}
int c(int n, int m) 
{
	return 1LL * fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}
int main() 
{	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	init();
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
		map<ll, int> mp;
		for(int i = 1; i <= n; i ++) 
        {
            scanf("%d", a + i);
            s[i] = s[i - 1] + a[i];
		}
        int ans = 1;
		for(int i = 1; i <= n; i ++) mp[s[i]] ++;
		for(auto [x, y] : mp) 
			if(mp.count(s[n] - x) && x * 2 < s[n]) 
            {
				int a = y, b = mp[s[n] - x] - (x == 0), ret = 0;
				for(int k = 0; k <= min(a, b); k ++) 
					ret = (ret + 1LL * c(a, k) * c(b, k)) % mod;
				ans = 1LL * ans * ret % mod;
			}
		if(s[n] % 2 == 0 && mp.count(s[n] / 2)) 
        {
			int a = mp[s[n] / 2] - (s[n] == 0), ret = 1;
			for(int i = 1; i <= a; i ++) ret = 1LL * ret * 2 % mod;
			ans = 1LL * ans * ret % mod;
		}
		cout << ans << '\n';
	}
	return 0;
}