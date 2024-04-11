# include <bits/stdc++.h>
using namespace std;
#define double long double
vector <vector <double> > p, z;
signed main()
{
	int n;
	cin >> n;
	p.resize(n, vector <double> (n));
	z.resize((1 << n), vector <double> (n));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> p[i][j];
		}
	}
	if(n == 1)
	{
		cout << 1;
		return 0;
	}
	double ans = 0;
	z[1][0] = 1;
	for(int i = 0; i < (1 << n); i++)
	{
		for(int j = 0; j < n; j++)
		{
			if((1 << j) & i)
			{
				for(int k = 0; k < n; k++)
				{
					if(k != j && ((1 << k) & i))
					{
						z[i][j] = max(z[i][j], z[i ^ (1 << j)][k] * p[k][j] + z[i ^ (1 << k)][j] * p[j][k]);
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		ans = max(ans, z[(1 << n) - 1][i]);
	}
	cout << fixed << setprecision(10) << ans;
	return 0;
}