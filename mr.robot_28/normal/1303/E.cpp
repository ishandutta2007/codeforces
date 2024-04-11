#include<bits/stdc++.h>
 
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		string s, p;
		cin >> s >> p;
		vector <vector <int> > dp(p.size(), vector <int> (p.size() + 1)), dp1(p.size(), vector <int> (p.size() + 1));
		vector <vector <bool> > used(p.size(), vector <bool> (p.size() + 1, false));
		for(int i = 0; i < s.size(); i++)
		{
			if(i == 0)
			{
				for(int j = 0; j < p.size(); j++)
				{
					if(j != 0 && s[i] == p[0])
					{
						dp[j][j] = 1;
						used[j][j] = true;
					}
					else
					{
						dp[j][j] = 0;
						used[j][j] = true;
					}
					if(s[i] == p[j])
					{
						dp[j][j + 1] = 0;
						used[j][j + 1] = true;
					}
				}
			}
			else
			{
				for(int j = 0; j < p.size(); j++)
				{
					for(int w = p.size(); w >= j; w--)
					{
						if(!used[j][w])
						{
							continue;
						}
						int k = dp[j][w];
						if(k < j && p[k] == s[i])
						{
							dp1[j][w] = max(dp1[j][w], dp[j][w] + 1);
						}
						if(w < p.size() && p[w] == s[i])
						{
							used[j][w + 1] = true;
							dp1[j][w + 1] = max(dp1[j][w + 1], dp[j][w]);
						}
					}
				}
				for(int j = 0; j < p.size(); j++)
				{
					for(int w = j; w <= p.size(); w++)
					{
						dp[j][w] = max(dp[j][w], dp1[j][w]);
						dp1[j][w] = 0;
					}
				}
			}
		}
		bool flag = false;
		for(int i = 0; i < p.size(); i++)
		{
			if(used[i][p.size()] && dp[i][p.size()] == i)
			{
				flag = true;
			}
		}
		if(flag)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}