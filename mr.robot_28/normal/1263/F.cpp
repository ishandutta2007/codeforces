#include <bits/stdc++.h>
using namespace std;
vector <int> pred1, pred2;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int a;
	cin >> a;
	pred1.resize(a);
	for(int i = 1; i < a; i++)
	{
		cin >> pred1[i];
		pred1[i]--;
	}
	vector <int> x1(n);
	for(int i = 0; i < n; i++)
	{
		cin >> x1[i];
		x1[i]--;
	}
	int b;
	cin >> b;
	pred2.resize(b);
	for(int i = 1; i < b; i++)
	{
		cin >> pred2[i];
		pred2[i]--;
	}
	vector <int>x2(n);
	for(int i = 0; i < n; i++)
	{
		cin >> x2[i];
		x2[i]--;
	}
	vector <vector <int> > upperCount(n, vector <int> (n));
	vector <vector <int> > lowerCount(n, vector <int> (n));
	for(int l = 0; l < n; l++)
	{
		vector <int> deg(a);
		for(int i = 1; i < a; i++)
		{
			deg[pred1[i]]++;
		}
		for(int r = l; r < n; r++)
		{
			int cnt = 0;
			int t = x1[r];
			while(t != 0 && deg[t] == 0)
			{
				t = pred1[t];
				deg[t]--;
				cnt++;
			}
			if(r == l)
			{
				upperCount[l][r] = cnt;
			}
			else
			{
				upperCount[l][r] = upperCount[l][r - 1] + cnt;
			}
		}
	}
	for(int l = 0; l < n; l++)
	{
		vector <int> deg(b);
		for(int i = 1; i < b; i++)
		{
			deg[pred2[i]]++;
		}
		for(int r = l; r < n; r++)
		{
			int cnt = 0;
			int t = x2[r];
			while(t != 0 && deg[t] == 0)
			{
				t = pred2[t];
				deg[t]--;
				cnt++;
			}
			if(r == l)
			{
				lowerCount[l][r] = cnt;
			}
			else
			{
				lowerCount[l][r] = lowerCount[l][r - 1] + cnt;
			}
		}
	}
	vector <int> dp(n + 1);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			dp[i] = max(dp[i], dp[j] + max(upperCount[j][i - 1], lowerCount[j][i - 1]));
		}
	}
	cout << dp[n];
    return 0;
}