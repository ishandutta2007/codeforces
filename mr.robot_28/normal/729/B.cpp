#include <bits/stdc++.h>

using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <vector <bool> > up(n, vector <bool> (m)),
	down(n + 1, vector <bool> (m + 1)), left(n, vector <bool> (m)), right(n + 1, vector <bool> (m + 1));
	vector <vector <int> > a(n, vector <int> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			up[i][j] = left[i][j] = a[i][j]; 
			if(i != 0)
			{
				up[i][j] = up[i][j] | up[i - 1][j];
			}
			if(j != 0)
			{
				left[i][j] = left[i][j] | left[i][j - 1];
			}
		}
	}
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = m - 1; j >= 0; j--)
		{
			right[i][j] = down[i][j] = a[i][j];
			right[i][j] = right[i][j] | right[i][j + 1];
			down[i][j] = down[i][j] | down[i + 1][j];
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] == 0)
			{
				cnt += right[i][j];
				cnt += left[i][j];
				cnt += up[i][j];
				cnt += down[i][j];
			}
		}
	}
	cout << cnt;
	return 0;
}