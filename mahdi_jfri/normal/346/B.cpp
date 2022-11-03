#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e2 + 20;
const int S = 28;

int nxt[maxn][S] , f[maxn] , dp[maxn][maxn][maxn];

pair<pair<int , int> , int> par[maxn][maxn][maxn];

int main()
{
	int n , m , k;
	string s , t , virus;
	cin >> s >> t >> virus;
	n = s.size();
	m = t.size();
	k = virus.size();

	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			for(int k = 0; k < maxn; k++)
			{
				dp[i][j][k] = -1;
				par[i][j][k] = {{-1 , -1} , -1};
			}

	for(int i = 1; i < k; i++)
	{
		int state = f[i];
		while(state && virus[state] != virus[i])
			state = f[state];
		if(virus[state] == virus[i])
			state++;
		f[i + 1] = state;
	}

	for(int i = 0; i <= k; i++)
		for(int j = 0; j < 26; j++)
		{
			if(i < k && virus[i] == j + 'A')
				nxt[i][j] = i + 1;
			else
				nxt[i][j] = nxt[f[i]][j];
		}
	dp[0][0][0] = 0;

	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++)
			for(int z = 0; z < k; z++)
			{
				if(dp[i + 1][j][z] < dp[i][j][z])
				{
					dp[i + 1][j][z] = dp[i][j][z];
					par[i + 1][j][z] = {{i , j} , z};
				}
				if(dp[i][j + 1][z] < dp[i][j][z])
				{
					dp[i][j + 1][z] = dp[i][j][z];
					par[i][j + 1][z] = {{i , j} , z};
				}
				int x = nxt[z][s[i] - 'A'];
				if(i < n && j < m && s[i] == t[j] && dp[i + 1][j + 1][x] < dp[i][j][z] + 1)
				{
					dp[i + 1][j + 1][x] = dp[i][j][z] + 1;
					par[i + 1][j + 1][x] = {{i , j} , z};
				}
			}
	int ans = 0;
	string res = "";
	for(int i = 0; i < k; i++)
		if(dp[n][m][i] > dp[n][m][ans])
			ans = i;
	int a = n, b = m;
	while(par[a][b][ans].second != -1)
	{
		par[maxn - 1][maxn - 1][maxn - 1] = par[a][b][ans];

		if(a > par[a][b][ans].first.first && b > par[a][b][ans].first.second)
			res += s[a - 1];

		a = par[maxn - 1][maxn - 1][maxn - 1].first.first;
		b = par[maxn - 1][maxn - 1][maxn - 1].first.second;
		ans = par[maxn - 1][maxn - 1][maxn - 1].second;
	}
	if(res == "")
		res += "0";
	
	reverse(res.begin() , res.end());

	cout << res << endl;
}