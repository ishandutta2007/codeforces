#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
ll n, m;
ll Pow(ll x,ll y)
{
	ll ret = 1;
	while(y)
	{
		if(y & 1) ret = ret * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return ret;
}
int main()
{
	cin >> n >> m;
	if(m == 1) cout << n + 1 << endl;
	else cout << (Pow(m, n) + m * Pow(m - 1, mod - 2) % mod * (Pow(2 * m - 1, n) - Pow(m, n) + mod)) % mod;
	return 0;
}