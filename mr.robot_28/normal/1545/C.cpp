#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
const int mod = 998244353;
const int N = 2e3;
int f[N];
int b[N][N];
int a[N][N];
vector <int> c[N][N];
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int t;
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				b[i][j] = 0;
				c[i][j].clear();
			}
		}
		for(int i = 1; i <= n * 2; i++)
		{
			f[i] = 0;
			for(int j = 1; j <= n; j++)
			{
				cin >> a[i][j];
				b[j][a[i][j]]++;
				c[j][a[i][j]].push_back(i);
			}
		}
		int top =0 ;
		int tail = 0;
		int cnt = 0, idx = 1;
		long long ans = 1;
		vector <pair <int, int> > v;
		v.clear();
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n;j++)
			{
				if(b[i][j] == 1)
				{
					tail++;
					v.push_back({i, j});
				}
			}	
		}
		while(cnt < n)
		{
			if(top < tail)
			{
				int x, y;
				x = v[top].X;
				y = v[top].Y;
				if(b[x][y] != 1)
				{
					top++;
					continue;
				}
				for(int i = 0; i < c[x][y].size(); i++)
				{
					if(f[c[x][y][i]] == 0)
					{
						t = c[x][y][i];
						break;
					}
				}
			}
			else
			{
				while(f[idx] != 0)
				{
					idx++;
				}
				t = idx;
				ans = ans * 2 % mod;
			}
			f[t] = 1;
			cnt++;
			for(int i = 1; i <= n; i++)
			{
				b[i][a[t][i]] = 0;
			}
			for(int i = 1; i <= n; i++)
			{
				for(int j = 0; j < c[i][a[t][i]].size(); j++)
				{
					int s1 = c[i][a[t][i]][j];
					if(f[s1] == 0)
					{
						f[s1] = 2;
						for(int k = 1; k <= n; k++)
						{
							b[k][a[s1][k]]--;
							if(b[k][a[s1][k]] == 1)
							{
								tail++;
								v.push_back({k, a[s1][k]});
							}
						}
					}
				}
			}
			top++;
		}
		int s = 0;
		cout << ans << "\n";
		for(int i = 1; i <= n * 2; i++)
		{
			if(f[i] == 1)
			{
				cout << i << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}