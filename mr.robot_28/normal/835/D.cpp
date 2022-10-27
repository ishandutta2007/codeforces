#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <vector <int> > dp;
vector <int> hash1, hash2, hash3, hash4;
const int const1 = 998244353;
const int const2 = 1e9 + 7;
vector <int> Pow1, Pow2;
pair <int, int>  get_hash1(int l, int r)
{
	if(l == 0)
	{
		return {hash1[r], hash2[r]};
	}
	else
	{
		return {(hash1[r] - hash1[l - 1] * Pow1[r - l + 1] % const1 + const1) % const1,
		(hash2[r] - hash2[l - 1] * Pow2[r - l + 1] % const2 + const2) % const2};
	}
}
pair <int, int>  get_hash2(int l, int r)
{
	if(r == hash1.size() - 1)
	{
		return {hash3[l], hash4[l]};
	}
	else
	{
		return {(hash3[l] - hash3[r + 1] * Pow1[r - l + 1] %const1 + const1) % const1,
		(hash4[l] - hash4[r + 1] * Pow2[r - l + 1] % const2 + const2) % const2};
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int n = s.size();
	dp.resize(n, vector <int> (n, 0));
	Pow1.resize(n + 1);
	Pow2.resize(n + 1);
	Pow1[0] = Pow2[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		Pow1[i] = Pow1[i - 1] * 27 % const1;
		Pow2[i] = Pow2[i - 1] * 27 % const2;
	}
	hash1.resize(n);
	hash2.resize(n);
	hash3.resize(n);
	hash4.resize(n);
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			hash1[i] = hash2[i] = s[i] - 'a' + 1;
		}
		else
		{
			hash1[i] = (hash1[i - 1] * 27 + s[i] - 'a' + 1) % const1;
			hash2[i] = (hash2[i - 1] * 27 + s[i] - 'a' + 1) % const2;
		}
	}
	for(int i = n - 1; i >= 0; i--)
	{
		if(i == n - 1)
		{
			hash3[i] = hash4[i] = s[i] - 'a' + 1;
		}
		else
		{
			hash3[i] = (hash3[i + 1] * 27 + s[i] - 'a' + 1) % const1;
			hash4[i] = (hash4[i + 1] * 27 + s[i] - 'a' + 1) % const2;
		}
	}
	for(int i = 0; i < n; i++)
	{
		dp[i][i] = 1;
	}
	for(int len = 2; len <= n; len++)
	{
		for(int i = 0; i + len <= n; i++)
		{
			pair <int, int> v1 = get_hash1(i, i + len - 1);
			pair <int, int> v2 = get_hash2(i, i + len - 1);
			pair <int, int> v3 = get_hash1(i, i + len / 2 - 1);
			pair <int, int> v4 = get_hash1(i + len - len / 2, i + len - 1);
			if(v1 == v2 && v3 == v4)
			{
				dp[i][i + len - 1] = min(dp[i][i + len / 2 - 1], dp[i + len - len / 2][i + len - 1]) + 1;
			}
			else if(v1 == v2)
			{
				dp[i][i + len - 1] = 1;
			}
		}
	}
	vector <int> ans(n + 1);
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			ans[dp[i][j]]++;
		}
	}
	int a = 0;
	for(int i = n; i >= 1; i--)
	{
		ans[i] += a;
		a = ans[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}