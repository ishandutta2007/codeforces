#include<bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 998244353;
int dp[105][105];
int inver[105];
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t= power(a, b / 2);
		return t * t % const1;
	}
	else
	{
		int t = power(a, b / 2);
		t =  t * t % const1;
		return t * a % const1;
	}
}
int inv(int x)
{
	return power(x, const1 - 2);
}
int c(int n, int k)
{
	if(k == 0)
	{
		return 1;
	}
	else
	{
		return (c(n, k - 1) * (n - k + 1) % const1) * inver[k] % const1;
	}
}
signed main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		inver[i] = inv(i);
	}
	vector <int> un;
	vector <int> l(n), r(n);
	for(int i = n - 1; i >= 0; i--)
	{
		cin >> l[i] >> r[i];
		r[i]++;
		un.push_back(l[i]);
		un.push_back(r[i]);
	}
	sort(un.begin(), un.end());
	int m = unique(un.begin(), un.end()) - un.begin();
	dp[0][0] = 1;
	for(int j = 0; j < m; j++){
		dp[0][j] = 1;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j + 1 < m; j++){
			int siz = un[j + 1] - un[j];
			for(int k = 0; k <= i + 1; k++)
			{
				bool fl = true;
				for(int d = k + 1; d <= i + 1; d++)
				{
					if(un[j] < l[d - 1] || un[j + 1] > r[d - 1])
					{
						fl = false;
					}
				}
				if(fl)
				{
					dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[k][j] * c(siz + i + 1 - k - 1, i + 1 - k)) % const1;
				}
			}
		}
	}
	int ans = dp[n][m - 1];
	for(int i = 0; i < n; i++){
		ans = ans * inv(r[i] - l[i]) % const1;
	}
	cout << ans << "\n";
    return 0;
}