#include <bits/stdc++.h>
using namespace std;
#define int long long
int go_to[70][70];
int ind[1 << 8];
vector <int> masks;
int m;
void bp(vector <vector <int> > &matrix, int n)
{
	if(n == 1)
	{
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < m; j++)
			{
				matrix[i][j] = go_to[i][j];
			}
		}
	}
	else if(n % 2 == 1)
	{
		vector <vector <int> > go_to1(m, vector <int> (m));
		bp(go_to1, n - 1);
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < m; j++)
			{
				matrix[i][j] = 1e18;
				for(int k =0; k < m; k++)
				{
					matrix[i][j] =  min(matrix[i][j], go_to1[i][k] + go_to[k][j]);
				}
			}
		}
	}
	else
	{
		vector <vector <int> > go_to1(m, vector <int> (m));
		bp(go_to1, n / 2);
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < m; j++)
			{
				matrix[i][j] = 1e18;
				for(int k = 0; k < m; k++)
				{
					matrix[i][j] = min(matrix[i][j], go_to1[i][k] + go_to1[k][j]);
				}
			}
		}
	}
}
signed main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int x, k, n, q;
	cin >> x >> k >> n >> q;
	vector <int> c(k);
	for(int i = 0; i < k; i++)
	{
		cin >> c[i];
	}
	vector <pair <int, int> > mass(q);
	for(int i = 0; i < q; i++)
	{
		cin >> mass[i].first >> mass[i].second;
	}
	sort(mass.begin(), mass.end());
	vector <int> xq(q), w(q);
	for(int i = 0; i < q; i++)
	{
		xq[i] = mass[i].first;
		w[i] = mass[i].second;
	}
	for(int mask = 0; mask < (1 << k); mask++)
	{
		if(__builtin_popcount(mask) == x)
		{
			masks.push_back(mask);
			ind[mask] = masks.size() - 1;
		}
	}
	m = masks.size();
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			go_to[i][j] = 1e18;
		}
	}
	for(int i = 0; i < masks.size(); i++)
	{
		int t = masks[i];
		if((t & 1) == 0)
		{
			int t1 = masks[i] / 2;
			go_to[i][ind[t1]] = 0;
		}
		else
		{
			int t1 = t / 2;
			for(int j = 1; j <= k; j++)
			{
				if((t & (1 << j)) == 0)
				{
					go_to[i][ind[t1 + (1 << (j - 1))]] = c[j - 1];
				}
			}
		}
	}
	int pos = 1;
	int iter = 0;
	vector <int> dp(m, 1e18);
	vector <int> dp1(m, 1e18);
	int index = 0;
	for(int i = 0; i < m; i++)
	{
		if(masks[i] == (1 << x) - 1)
		{
			index = i;
			dp[i] = 0;
		}
	}
	int ans = 1e18;
	if(pos == n - x + 1)
	{
		ans = 0;
	}
	while(pos < n - x + 1)
	{
		if(iter == xq.size())
		{
			vector <vector <int> > matrix(m, vector <int> (m));
			bp(matrix, n - x + 1 - pos);
			for(int i = 0; i < m; i++)
			{
				dp1[i] = 1e18;
			}
			for(int i = 0; i < m; i++)
			{
				for(int j = 0; j < m; j++)
				{
					dp1[j] = min(dp1[j], dp[i] + matrix[i][j]);
				}
			}
			ans = dp1[index];
			pos = n - x + 1;
		}
		else if(pos < xq[iter] - k)
		{
			vector <vector <int> > matrix(m, vector <int> (m));
			bp(matrix, xq[iter] - k - pos);
			for(int i = 0; i < m; i++)
			{
				dp1[i] = 1e18;
			}
			for(int i = 0; i < m; i++)
			{
				for(int j = 0; j < m; j++)
				{
					dp1[j] = min(dp1[j], dp[i] + matrix[i][j]);
				}
			}
			for(int i = 0; i < m; i++)
			{
				dp[i] = dp1[i];
			}
			pos = xq[iter] - k;
		}
		else
		{
			int st = iter;
			while(iter < q - 1 && xq[iter + 1] - xq[iter] <= k + 1)
			{
				iter++;
			}
			vector <int> weight(xq[iter] + 1 + k - pos, 0);
			for(int j = st; j <= iter; j++)
			{
				weight[xq[j] - pos] = w[j];
			}
			vector <vector <int> > dp2(xq[iter] + 2 - pos, vector <int> (m, 1e18));
			for(int i = 0; i < m; i++)
			{
				dp2[0][i] = dp[i];
			}
			for(int i = 0; i < xq[iter] + 2 - pos - 1; i++)
			{
				for(int j = 0; j < m; j++)
				{
					int mask1 = masks[j];
					if((mask1 & 1) == 0)
					{
						int toind = ind[mask1 / 2];
						dp2[i + 1][toind] = min(dp2[i + 1][toind], dp2[i][j]);
					}
					else
					{
						for(int t = 1; t <= k; t++)
						{
							if(((1 << t) & mask1) == 0)
							{
								int toind = ind[(mask1 / 2) + (1 << (t - 1))];
								int we = weight[i + t] + go_to[j][toind];
								dp2[i + 1][toind] = min(dp2[i + 1][toind], dp2[i][j] + we);
							}
						}
					}
				}
			}
			if(n - x + 1 <= xq[iter] + 1)
			{
				ans = dp2[n - x + 1 - pos][index];
				pos = n - x + 1;
			}
			else
			{
				for(int i = 0; i < m; i++)
				{
					dp[i] = dp2[xq[iter] + 1 - pos][i];
				}
				pos = xq[iter] + 1;
			}
			iter++;
		}
	}
	cout << ans;
    return 0;
}