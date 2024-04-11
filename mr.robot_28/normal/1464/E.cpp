#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
const int mod = 998244353;
const int N = 2e5 + 100;
vector <int> g[N];
int sg[N];
int g_cnt[N];
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return 1LL * t * t % mod;
	}
	return 1LL * a * power(a, b - 1) % mod;
}
int mem[N];
int Sg(int u)
{
	if(~sg[u])
	{
		return sg[u];
	}
	for(auto to : g[u])
	{
		Sg(to);
	}
	for(auto to : g[u])
	{
		mem[sg[to]]++;
	}
	for(int i = 0; ; i++)
	{
		if(mem[i] == 0)
		{
			sg[u] = i;
			break;
		}
	}
	for(auto to : g[u])
	{
		mem[sg[to]]--;
	}
	return sg[u];
}
int f[600][600];
signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int n, m;
	cin >> n >> m;
	fill(sg, sg + N, -1);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
	}
	for(int i = 0; i < n; i++)
	{
		g_cnt[Sg(i)]++;
	}
	for(int i = 0; i < 512; i++)
	{
		for(int j = 0; j < 512; j++)
		{
			f[i][j] = 1LL * g_cnt[i ^ j] * power(n + 1, mod - 2) % mod;
		}
	}
	for(int i = 0; i < 512; i++)
	{
		f[i][i]--;
		if(f[i][i] < 0)
		{
			f[i][i] += mod;
		}
	}
	f[0][512] = power(n + 1, mod - 2);
	for(int i = 0; i < 512; i++)
	{
		for(int j = i; j < 512; j++)
		{
			if(f[i][j])
			{
				swap(i, j);
				break;
			}
		}
		for(int j = i + 1; j < 512; j++)
		{
			int p = 1LL * f[j][i] * power(f[i][i], mod - 2) % mod;
			for(int k = i; k <= 512; k++)
			{
				f[j][k] = (f[j][k] + mod - 1LL * f[i][k] * p % mod) % mod;
			}
		}
	}
	for(int i = 511; i >= 0; i--)
	{
		int p = power(f[i][i], mod - 2);
		for(int j = i; j <= 512; j++)
		{
			f[i][j] = 1LL * f[i][j] * p % mod;
		}
		for(int j = i - 1; j >= 0; j--)
		{
			int p1 = f[j][i];
			for(int k = i; k <= 512; k++)
			{
				f[j][k] = (f[j][k] + mod - 1LL * f[i][k] * p1 % mod) % mod;
			}
		}
	}
	cout << (1 + f[0][512]) % mod;
	return 0;
}