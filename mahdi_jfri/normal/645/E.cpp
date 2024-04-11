#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;
const ll mod = 1e9 + 7;
const int S = 27;

int nxt[maxn][S] , last[S];

ll dp[maxn * 2] , res = 1;

int main()
{
	int n , m , k;
	string s;
	cin >> n >> k >> s;
	m = s.size();
	for(int i = m - 1; i >= 0; i--)
		for(int j = 0; j < k; j++)
		{
			if(i < m - 1 && s[i + 1] == j + 'a')
				nxt[i][j] = i + 1;
			else if(i < m - 1)
				nxt[i][j] = nxt[i + 1][j];
			else
				nxt[i][j] = m;
		}
	for(int i = 0; i < k; i++)
	{
		if(s[0] == i + 'a')
			dp[0] = 1;
		else if(nxt[0][i] < m)
			dp[nxt[0][i]] = 1;
	}
	fill(last , last + S , -1);
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < k; j++)
			if(nxt[i][j] < m)
				dp[nxt[i][j]] = (dp[nxt[i][j]] + dp[i]) % mod;
		last[s[i] - 'a'] = i;
		res = (res + dp[i]) % mod;
	}
	for(int i = 0; i < n; i++)
	{
		int node = 0;
		for(int j = 0; j < k; j++)
			if(last[j] < last[node])
				node = j;
		if(last[node] == -1)
			dp[i + m] = 1;
		for(int j = max(last[node] , 0); j < i + m; j++)
			dp[i + m] = (dp[i + m] + dp[j]) % mod;
		res += dp[i + m];
		res %= mod;
		last[node] = i + m;
	}
	cout << res << endl;
}