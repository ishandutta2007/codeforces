#include <bits/stdc++.h>
 
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	vector <vector <char> > A(n, vector <char> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> A[i][j];
		}
	}
	vector <vector <vector <int> > > dpright(n, vector <vector <int> > (m, vector <int> (4, 0)));
	vector <vector <vector <int> > > dpdown(n, vector <vector <int> > (m, vector <int> (4, 0)));
	vector <vector <vector <int> > > dpup(n, vector <vector <int> > (m, vector <int> (4, 0)));
	vector <vector <vector <int> > > dpleft(n, vector <vector <int> > (m, vector <int> (4, 0)));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(A[i][j] == 'R')
			{
				dpup[i][j][0] = 1;
				dpleft[i][j][0] = 1;
				if(i != 0)
				{
					dpup[i][j][0] += dpup[i -1][j][0];
				}
				if(j != 0)
				{
					dpleft[i][j][0] += dpleft[i][j - 1][0];
				}
			}
			else if(A[i][j] == 'G')
			{
				dpup[i][j][1] = 1;
				dpleft[i][j][1] = 1;
				if(i != 0)
				{
					dpup[i][j][1] += dpup[i -1][j][1];
				}
				if(j != 0)
				{
					dpleft[i][j][1] += dpleft[i][j - 1][1];
				}
			}
			else if(A[i][j] == 'B')
			{
				dpup[i][j][2] = 1;
				dpleft[i][j][2] = 1;
				if(i != 0)
				{
					dpup[i][j][2] += dpup[i -1][j][2];
				}
				if(j != 0)
				{
					dpleft[i][j][2] += dpleft[i][j - 1][2];
				}
			}
			else
			{
				dpup[i][j][3] = 1;
				dpleft[i][j][3] = 1;
				if(i != 0)
				{
					dpup[i][j][3] += dpup[i -1][j][3];
				}
				if(j != 0)
				{
					dpleft[i][j][3] += dpleft[i][j - 1][3];
				}
			}
		}
	} 
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = m - 1; j >= 0; j--)
		{
			if(A[i][j] == 'R')
			{
				dpdown[i][j][0] = 1;
				dpright[i][j][0] = 1;
				if(i != n - 1)
				{
					dpdown[i][j][0] += dpdown[i + 1][j][0];
				}
				if(j != m - 1)
				{
					dpright[i][j][0] += dpright[i][j + 1][0];
				}
			}
			else if(A[i][j] == 'G')
			{
				dpdown[i][j][1] = 1;
				dpright[i][j][1] = 1;
				if(i != n - 1)
				{
					dpdown[i][j][1] += dpdown[i + 1][j][1];
				}
				if(j != m - 1)
				{
					dpright[i][j][1] += dpright[i][j + 1][1];
				}
			}
			else if(A[i][j] == 'B')
			{
				dpdown[i][j][2] = 1;
				dpright[i][j][2] = 1;
				if(i != n - 1)
				{
					dpdown[i][j][2] += dpdown[i + 1][j][2];
				}
				if(j != m - 1)
				{
					dpright[i][j][2] += dpright[i][j + 1][2];
				}
			}
			else
			{
				dpdown[i][j][3] = 1;
				dpright[i][j][3] = 1;
				if(i != n - 1)
				{
					dpdown[i][j][3] += dpdown[i + 1][j][3];
				}
				if(j != m - 1)
				{
					dpright[i][j][3] += dpright[i][j + 1][3];
				}
			}
		}
	} 
	vector <vector <int> > dp1(n, vector <int> (m)), dp2(n, vector <int> (m)), dp3(n, vector <int> (m)), dp4(n, vector <int> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(A[i][j] == 'R')
			{
				if(i == 0 || j == 0)
				{
					dp1[i][j] = 1;
				}
				else
				{
					dp1[i][j] = min(dp1[i - 1][j - 1] + 1, min(dpup[i][j][0], dpleft[i][j][0]));
				}
			}
		}
	}
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = 0; j < m; j++)
		{
			if(A[i][j] == 'Y')
			{
				if(i == n - 1 || j == 0)
				{
					dp4[i][j]  = 1;
				}
				else
				{
					dp4[i][j] = min(dp4[i + 1][j - 1] + 1, min(dpleft[i][j][3], dpdown[i][j][3]));
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = m - 1; j >= 0; j--)
		{
			if(A[i][j] == 'G')
			{
				if(i == 0 || j == m - 1)
				{
					dp2[i][j] = 1;
				}
				else
				{
					dp2[i][j] = min(dp2[i - 1][j + 1] + 1, min(dpup[i][j][1], dpright[i][j][1]));
				}
			}
		}
	}
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = m - 1; j >= 0; j--)
		{
			if(A[i][j] == 'B')
			{
				if(i == n - 1 || j == m - 1){
					dp3[i][j] = 1;
				}
				else
				{
					dp3[i][j] = min(dp3[i + 1][j + 1] + 1, min(dpright[i][j][2], dpdown[i][j][2]));
				}
			}
		}
	}
	vector <vector <int> > dp(n, vector <int> (m));
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < m - 1; j++)
		{
			dp[i][j] = min(min(dp1[i][j], dp4[i + 1][j]), min(dp2[i][j + 1], dp3[i + 1][j + 1]));
		}
	}
	int p1 = log2(n) + 1;
	int p2 = log2(m) + 1;
	vector <vector <vector <vector <int> > > > rmq(n, vector <vector <vector <int> > > (m, vector <vector <int> > (p1, vector <int> (p2))));
	for(int i = 0; i < p1; i++)
	{
		for(int j = 0; j < p2; j++)
		{
			for(int a = 0; a + (1 << i) - 1 < n; a++)
			{
				for(int b = 0; b + (1 << j) - 1< m; b++)
				{
					if(i == 0 && j == 0)
					{
						rmq[a][b][i][j] = dp[a][b];
					}
					else if(i == 0)
					{
						rmq[a][b][i][j] = max(rmq[a][b + (1 << (j - 1))][i][j - 1], rmq[a][b][i][j - 1]);
					}
					else
					{
						rmq[a][b][i][j] = max(rmq[a][b][i - 1][j], rmq[a + (1 << (i - 1))][b][i - 1][j]);
					}
				}
			}
		}
	}
	while(q--)
	{
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--;
		c1--;
		r2--;
		c2--;
		int l = 0, r = min((r2 - r1 + 1) / 2, (c2 - c1 + 1) / 2) + 1;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			int x1 = r1 + midd - 1;
			int x2 = r2 - midd;
			int y1 = c1 + midd - 1;
			int y2 = c2 - midd;
			if(x1 > x2 || y1 > y2)
			{
				r = midd;
				continue;
			}
			int k1 = log2(x2 - x1 + 1);
			int k2 = log2(y2 - y1 + 1);
			int ans = max(max(rmq[x1][y1][k1][k2], rmq[x2 - (1 << k1) + 1][y1][k1][k2]), max(rmq[x1][y2 - (1 << k2) + 1][k1][k2], rmq[x2 - (1 << k1) + 1][y2 - (1 << k2) + 1][k1][k2]));
			if(ans >= midd)
			{
				l = midd;
			}
			else
			{
				r = midd;
			}
		}
		cout << l * l * 4 << "\n";
	}
    return 0;
}