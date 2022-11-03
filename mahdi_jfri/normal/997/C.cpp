#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;
const int mod = 998244353;

int fac[maxn] , caf[maxn];

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

inline int bpw(int a , ll b)
{
	b %= mod - 1;

	int res = 1;
	for(int i = 0; i < 31; i++)
	{
		if((b>>i)&1)
			res = 1LL * res * a % mod;

		a = 1LL * a * a % mod;
	}

	return res;
}

inline int c(int r , int s)
{
	if(r > s || r < 0)
		return 0;

	return 1LL * fac[s] * caf[r] % mod * caf[s - r] % mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fac[0] = 1;
	for(int i = 1; i < maxn; i++)
		fac[i] = 1LL * fac[i - 1] * i % mod;

	caf[maxn - 1] = bpw(fac[maxn - 1] , mod - 2);
	for(int i = maxn - 1; i > 0; i--)
		caf[i - 1] = 1LL * caf[i] * i % mod;

	int n;
	cin >> n;

	int ans = 0;
	mkay(ans = bpw(3 , 1LL * n * n) - bpw(bpw(3 , n) - 3 , n));
	ans = 1LL * ans * 2 % mod;

	for(int i = 1; i <= n; i++)
	{
		int tmp = 0;

		tmp = 1LL * c(i , n) * (bpw(3 , 1LL * (n - i) * n) - bpw(bpw(3 , n - i) - 1 , n) + mod) % mod;
		tmp = 1LL * tmp * 3 % mod;

		if(i&1)
			mkay(ans -= tmp);
		else
			mkay(ans += tmp);
	}

	cout << ans << endl;
}