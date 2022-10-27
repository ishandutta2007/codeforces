#include<bits/stdc++.h>
 
using namespace std;
#define int long long
vector <int> V, K, OT;
int n;
string s;
int make_letter(int v, int k, int I, int t2)
{
	int c = 0;
	int t;
	if(t2 == 0)
	{
		t = OT[I - v - k];
	}
	else if(t2 == 1)
	{
		t = V[v];
	}
	else
	{
		t = K[k];
	}
	for(int i = v; i < V.size(); i++)
	{
		c += (V[i] < t);
	}
	for(int i = k; i < K.size(); i++)
	{
		c += (K[i] < t);
	}
	for(int i = I - k - v; i < OT.size(); i++)
	{
		c += (OT[i] < t);
	}
	return c;
}
signed main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	cin >> n;
	cin >> s;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == 'V')
		{
			V.push_back(i);
		}
		else if(s[i] == 'K')
		{
			K.push_back(i);
		}
		else
		{
			OT.push_back(i);
		}
	}
	int dp[V.size() + 1][K.size() + 1][n + 1][3];
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= V.size(); j++)
		{
			for(int d = 0; d <= K.size(); d++)
			{
				for(int t= 0; t < 3; t++)
				{
					dp[j][d][i][t] = 1e9;
				}
			}
		}
	}
	dp[0][0][0][0] = 0;
	for(int i = 0; i <= V.size(); i++)
	{
		for(int j = 0; j <= K.size(); j++)
		{
			for(int d = i + j; (d - i - j) <= OT.size() && d < n; d++) 
			{
				for(int t = 0; t < 3; t++)
				{
					if(i != V.size())
					{
						dp[i + 1][j][d + 1][1] = min(dp[i + 1][j][d + 1][1], dp[i][j][d][t] + make_letter(i, j, d, 1));
					}
					if(j != K.size() && t != 1)
					{
						dp[i][j + 1][d + 1][2] = min(dp[i][j + 1][d + 1][2], dp[i][j][d][t] + make_letter(i, j, d, 2));
					}
					if((d - i - j) < OT.size())
					{
					dp[i][j][d + 1][0]  = min(dp[i][j][d + 1][0], dp[i][j][d][t] + make_letter(i, j, d, 0));
				}
				}
			}
		}
	}
	int ans = 1e9;
	for(int i = 0; i < 3; i++)
	{
		ans = min(ans, dp[V.size()][K.size()][n][i]);
	}
	cout << ans;
	return 0;
}