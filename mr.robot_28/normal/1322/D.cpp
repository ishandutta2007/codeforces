#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 4005;
int n, m;
int s[maxn];
int l[maxn];
int c[maxn];
vector <int> all[maxn];
const int inf = 1e18;
int at_most[maxn];
int vals[maxn][maxn];
int new_val[maxn];
int cur_val[maxn];
signed main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> l[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		all[l[i]].push_back(i);
	}
	for(int i =1; i <= n + m; i++)
	{
		cin >> c[i];
	}
	for(int i = 1; i <= n; i++)
	{
		at_most[i] = 0;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			vals[j][i] = -inf;
		}
	}
	for(int i = 1; i <= n + m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			for(int p = 0; p <= at_most[j] / 2; p++)
			{
				new_val[p] = -inf;
			}
			for(int p = 0; p <= at_most[j]; p++)
			{
				new_val[p / 2] = max(new_val[p / 2], vals[j][p] + (p / 2) * c[i]);
			}
			for(int p = 0; p <= at_most[j]; p++)
			{
				vals[j][p] = -inf;
			}
			at_most[j] /= 2;
			for(int p = 0; p <= at_most[j]; p++)
			{
				vals[j][p] = new_val[p];
			}
		}
		for(int j = 0; j <= n; j++)
		{
			cur_val[j] = -inf;
		}
		reverse(all[i].begin(), all[i].end());
		for(int k = 0; k < all[i].size(); k++)
		{
			int p = all[i][k];
			for(int t = p + 1; t <= n; t++)
			{
				if(l[p] < l[t])
				{
					continue;
				}
				if(l[p] > l[t])
				{
					for(int j = 0; j <= at_most[t]; j++){
						cur_val[j] = max(cur_val[j], vals[t][j]);
					}
				}
				else
				{
					for(int j = 0; j <= at_most[t]; j++)
					{
						cur_val[j] = max(cur_val[j], vals[t][j]);
					}
					break;
				}
			}
			at_most[p] = n;
			cur_val[0] = max(cur_val[0], 0LL);
			vals[p][0] = -inf;
			for(int j = 0; j <= n; j++)
			{
				vals[p][j] = -inf;
			}
			for(int j = 0; j <= n; j++)
			{
				vals[p][j] = max(vals[p][j], cur_val[j]);
				vals[p][j + 1] = max(vals[p][j + 1], cur_val[j] - s[p] + c[i]);
			}
		}
	}
	int mx = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= at_most[j]; j++)
		{
			mx = max(mx, vals[i][j]);
		}
	}
	cout << mx;
	return 0;
}