#include<bits/stdc++.h>
using namespace std;
#define int long long
const int CONST = 1e9 + 7;
signed main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector <vector <int> > dp1(m, vector <int> (n + 1, 0));
    vector <vector <int> > dp2(m, vector <int> (n + 1, 0));
    for(int i = 1; i <= n; i++)
    {
    	dp1[0][i] = dp2[0][i] = 1;
    }
    for(int i = 1; i < m; i++)
    {
    	for(int j = 1; j <= n; j++)
    	{
    		dp1[i][j] += dp1[i - 1][j] + dp1[i][j - 1];
    		dp1[i][j] %= CONST;
    	}
    }
    for(int i = 1; i < m; ++i)
    {
    	for(int j = n; j >= 1; j--)
    	{
    		if(j == n)
    		{
    			dp2[i][j] = dp2[i - 1][j];
    		}
    		else
    		{
    			dp2[i][j] += dp2[i - 1][j] + dp2[i][j + 1];
    			dp2[i][j] %= CONST;
    		}
    	}
    }
    vector <int> pref(n + 1);
	for(int i = 1; i <= n; i++)
	{
		pref[i] = pref[i - 1] + dp1[m - 1][i];
		pref[i] %= CONST;
	} 
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans = (ans + pref[i] * dp2[m - 1][i]);
	 	ans %= CONST;
	}
	cout << ans;
    return 0;
}