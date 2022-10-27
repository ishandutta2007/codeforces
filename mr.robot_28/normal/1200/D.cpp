#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n, k;
	cin >> n >> k;
	int ans = 0;
	vector <vector <char> > a(n, vector <char> (n));
	vector <vector <int> > pref(n, vector <int> (n, 0)), post(n, vector <int> (n, 0));
	vector <vector <int> > pref1(n, vector <int> (n, 0)), post1(n, vector <int> (n, 0));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if(j > 0)
			{
				pref[i][j] = pref[i][j - 1];
			}
			if(a[i][j] == 'B')
			{
				pref[i][j]++;
			}
		}
		for(int j = n - 1; j >= 0; j--)
		{
			if(j < n - 1)
			{
				post[i][j] = post[i][j + 1];
			}
			if(a[i][j] == 'B')
			{
				post[i][j]++;
			}
		}
		if(pref[i][n - 1] == 0)
		{
			ans++;
		}
	}
	for(int j = 0; j < n; j++)
	{
		for(int i = 0; i < n; i++)
		{
			if(i != 0)
			{
				pref1[i][j] = pref1[i - 1][j];
			}
			if(a[i][j] == 'B')
			{
				pref1[i][j]++;
			}
		}
		for(int i = n - 1; i >= 0; i--)
		{
			if(i != n - 1)
			{
				post1[i][j] = post1[i + 1][j]; 
			}
			if(a[i][j] == 'B')
			{
				post1[i][j]++;
			}
		}
		if(pref1[n - 1][j] == 0)
		{
			ans++;
		}
	}
	int max = 0;
	vector <vector <int> > dp1(n, vector <int> (n, 0)), dp2(n, vector <int> (n, 0));
	for(int i = 0; i <= n - k; i++)
	{
		int cnt = 0;
		for(int j = 0; j < k; j++)
		{
			int a = 0;
			if(i != 0)
			{
				a += pref1[i - 1][j];
			}
			if(i != n - k)
			{
				a += post1[i + k][j];
			}
			if(a == 0 && pref1[n - 1][j] != 0)
			{
				cnt++;
			}
		}
		for(int j = 0; j <= n - k; j++)
		{
			dp1[i][j] = cnt;
			int a = 0;
			if(i != 0)
			{
				a += pref1[i - 1][j];
			}
			if(i != n - k)
			{
				a += post1[i + k][j];
			}
			if(pref1[n - 1][j] != 0 && a == 0)
			{
				cnt--;
			}
			if(j != n - k)
			{
				a = 0;
				if(i != 0)
				{
					a += pref1[i - 1][j + k];
				}
				if(i != n - k)
				{
					a += post1[i + k][j + k];
				}
				if(pref1[n - 1][j + k] != 0 && a == 0)
				{
					cnt++;
				}
			}
		}
	}
	for(int j = 0; j <= n - k; j++)
	{
		int cnt = 0;
		for(int i = 0; i < k; i++)
		{
			int a = 0;
			if(j != 0)
			{
				a += pref[i][j - 1];
			}
			if(j != n - k)
			{
				a += post[i][j + k];
			}
			if(pref[i][n - 1] != 0 && a == 0)
			{
				cnt++;
			}
		}
		for(int i = 0; i <= n - k; i++)
		{
			dp2[i][j] = cnt;
			int a = 0;
			if(j != 0)
			{
				a += pref[i][j - 1];
			}
			if(j != n - k)
			{
				a += post[i][j + k];
			}
			if(pref[i][n - 1] != 0 && a == 0)
			{
				cnt--;
			}
			if(i != n - k)
			{
				a = 0;
				if(j != 0)
				{
					a += pref[i + k][j - 1];
				}
				if(j != n - k)
				{
					a += post[i + k][j + k];
				}
				if(pref[i + k][n - 1] != 0 && a == 0)
				{
					cnt++;
				}
			}
		}
	}
	for(int i = 0; i <= n - k; i++)
	{
		for(int j = 0; j <= n - k; j++)
		{
			if(dp1[i][j] + dp2[i][j] > max)
			{
				max = dp1[i][j] + dp2[i][j];
			}
		}
	}
	cout << ans + max;
	return 0;
}