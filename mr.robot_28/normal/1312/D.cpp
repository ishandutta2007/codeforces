#include<bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 998244353;
vector <int> pow1, pow2;
int binpow(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 1)
	{
		int t = binpow(a, b /2);
		t = t * t % const1;
		return t * a % const1;
	}
	else
	{
		int t = binpow(a, b / 2);
		return t * t % const1;
	}
}
int c(int k, int n)
{
	return (pow1[n] * pow2[n - k] % const1) * pow2[k] % const1;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	pow1.resize(m + 1);
	pow2.resize(m + 1);
	pow1[0] = 1;
	for(int i = 1; i <= m; i++)
	{
		pow1[i] = pow1[i - 1] * i % const1;
	}
	pow2[m] = binpow(pow1[m], const1 - 2);
	for(int i = m - 1; i >= 0; i--)
	{
		pow2[i] = pow2[i + 1] * (i + 1) % const1;
	}
	int ans = 0;
	for(int i = 1; i < n - 1; i++)
	{
		int cnt1 = c(n - 1, m) * (n - 2) % const1;
		cnt1 = cnt1 * c(i - 1, n - 3) % const1;
		ans += cnt1;
		if(ans >= const1)
		{
			ans -= const1;
		}
	}
	if(ans >= const1)
	{
		ans -= const1;
	}
	cout << ans;
	return 0;
}