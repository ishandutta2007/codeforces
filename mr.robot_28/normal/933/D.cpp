#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2, inv3 = (mod + 1) / 3, inv5 = (mod * 2 + 1) / 5, inv7 = (mod + 1) / 7;
const int inv6 = inv2 * inv3 % mod, inv30 = inv5 * inv6 % mod, inv42 = inv6 * inv7 % mod;
const int coeff[4][8] = {
	{0, 1},
	{0, inv6, inv2, inv3},
	{0, mod - inv30, 0, inv3, inv2, inv5},
	{0, inv42, 0, mod - inv6, 0, inv2, inv2, inv7}
};
int n;
int f[4], g[4], ans;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int nn =  n % mod;
    f[0] = nn * (nn + 1) % mod * (nn + 2) % mod;
    f[1] = (3 * nn + 4) % mod;
    f[2] = mod - 3 * (nn + 2) % mod;
    f[3] = 2;
    for(int x = 0; x * x <= n; x++)
    {
    	int rem = n - x * x;
    	int ylim = ceil(sqrt(rem));
    	while(ylim * ylim <= rem)
    	{
    		ylim++;
		}
		while(ylim * ylim > rem)
		{
			ylim--;
		}
		int sum = 0, x2 = x * x % mod, x4 = x2 * x2 % mod, x6 = x2 * x4 % mod;
		g[0] = (f[0] +  f[1] * x2 +  f[2] * x4 + f[3] * x6) % mod;
		g[1] =(f[1] + 2 * f[2] * x2 + 3 * f[3] * x4) % mod;
		g[2] = (f[2] + 3 * f[3] * x2) % mod;
		g[3] = f[3];
		for(int i = 0; i < 4; i++)
		{
			int tmp = 0;
			for(int j = i << 1 | 1; j >= 0; j--)
			{
				tmp = (tmp * ylim + coeff[i][j]) % mod;
			}
			sum = (sum + g[i] * (tmp << 1 | !i)) % mod;
		}
		x && (sum <<= 1) >= mod && (sum -= mod);
		(ans += sum) >= mod && (ans -= mod);
	}
	ans = ans * inv6 % mod;
	cout << ans;
    return 0;
}