#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e2 + 20;
const int maxk = 25;
const int mod = 1e9 + 7;

int k , dp[maxn][maxk][maxk] , tmp[maxk][maxk];

vector<int> adj[maxn];

void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

void dfs(int v , int p = -1)
{
	for(int i = 1; i <= k; i++)
		dp[v][k + 1][i] = 1;
	for(int i = 1; i <= k + 1; i++)
		dp[v][0][i] = 1;

	for(auto u : adj[v])
		if(u != p)
		{
			dfs(u , v);

			for(int upv = 1; upv <= k + 1; upv++)
				for(int downv = 0; downv <= k + 1; downv++)
					for(int downu = 0; downu <= k + 1; downu++)
					{
						int Upv = min(upv , downu + 1);
						int Upu = min(k + 1 , min(upv + 1 , downv + 1));
						int Downv = min(downv , downu + 1);

						mkay(tmp[Downv][upv] += 1LL * dp[v][downv][Upv] * dp[u][downu][Upu] % mod);
					}

			for(int i = 0; i <= k + 1; i++)
				for(int j = 0; j <= k + 1; j++)
					dp[v][i][j] = tmp[i][j] , tmp[i][j] = 0;
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n >> k;

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs(0);

	int res = 0;

	for(int i = 0; i <= k; i++)
		mkay(res += dp[0][i][k + 1]);

	cout << res << endl;
}