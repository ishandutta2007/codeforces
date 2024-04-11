#include <bits/stdc++.h>
using namespace std;
int dp[2002][2001];
int suf1[2002][26];
int suf2[2002][26];
string a, b;
int rec(int i, int j)
{
	if(j == 0)
	{
		return 0;
	}
	int &ans = dp[i][j];
	if(ans != -1)
	{
		return ans;
	}
	ans = 2e9;
	if(i != 0 && a[i - 1] == b[j - 1])
	{
		ans = min(ans, rec(i - 1, j - 1));
	}
	if(i != 0)
	{
		ans = min(ans, rec(i - 1, j) + 1);
	}
	if(suf1[i + 1][b[j - 1] - 'a'] > suf2[j + 1][b[j - 1] - 'a'])
	{
		ans = min(ans, rec(i, j - 1));
	}
	return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
    	int n;
    	cin >> n;
    	cin >> a >> b;
    	for(int i = 0; i <= n; i++)
    	{
    		for(int j = 0; j <= n; j++)
    		{
    			dp[i][j] = -1;
			}
		}
		for(int i = n; i > 0; i--)
		{
			for(int j = 0; j < 26; j++)
			{
				suf1[i][j] = suf1[i + 1][j];
				suf2[i][j] = suf2[i + 1][j];
			}
			if(i <= n)
			{
				suf1[i][a[i - 1] - 'a']++;
				suf2[i][b[i - 1] - 'a']++;
			}
		}
		int p = rec(n, n);
		if(p > n)
		{
			p = -1;
		}
		cout << p << "\n";
	}
    return 0;
}