#include <bits/stdc++.h>
using namespace std;
#define int long long
bool f[10009];
int g[10009][24];
int a[200009];
int ans[209];
const int const1 = 998244353;
int max(int a, int b)
{
	if(a > b)
	{
		return a;
	}
	return b;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	vector <int> v;
	for(int i = m - 1; i >= 0; i--)
	{
		for(int j = 1; j <= n; j++)
		{
			if(a[j] & (1ll << i))
			{
				v.push_back(a[j]);
				int x = a[j];
				for(int k = 1; k <= n; k++)
				{
					if(a[k] & (1ll << i))
					{
						a[k] ^= x;
					}
				}
				break;
			}
		}
	}
	int pr = 1;
	for(int i = 0; i < n - v.size(); i++)
	{
		pr = pr * 2 % const1;
	}
	vector <int> w, u;
	w.push_back(0);
	u.push_back(0);
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i] >= (1ll << 12))
		{
			int d = w.size();
			for(int j = 0; j < d; j++)
			{
				w.push_back(v[i] ^ w[j]);
			}
		}
		else
		{
			int d = u.size();
			for(int j = 0; j < d; j++)
			{
				u.push_back(v[i] ^ u[j]);
			}
		}
	}
	for(int i = 0; i < u.size(); i++)
	{
		f[u[i]] = 1;
	}
	for(int i = 0; i < w.size(); i++)
	{
		int x = w[i];
		int y = x >> 12;
		g[x & ((1ll << 12) - 1)][__builtin_popcount(y)]++;
	}
	for(int x = 0; x < (1ll << 12); x++)
	{
		for(int y = 0; y < (1ll << 12); y++)
		{
			for(int z = 0; z <= max(0, m - 12); z++)
			{
				if(f[y])
				{
					ans[z + __builtin_popcount(x ^ y)] += g[x][z];
				}
			}
		}
	}
	for(int i = 0; i <= m; i++)
	{
		cout << ans[i] % const1 * pr % const1 << " ";
	}
	return 0;
}