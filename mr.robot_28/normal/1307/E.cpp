#include <bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 1e9 + 7;
signed main()
{
	int n, m;
	cin >> n >> m;
	vector <int> s(n);
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
		s[i]--;
	}
	vector <int> f(m), h(m);
	vector <vector <int> > p(n);
	for(int i = 0; i < m; i++)
	{
		cin >> f[i] >> h[i];
		p[f[i] - 1].push_back(h[i]);
	}
	for(int i = 0; i < n; i++)
	{
		if(p[i].size() != 0)
		{
			sort(p[i].begin(), p[i].end());
		}
	}
	vector <int> sumpref(n);
	vector <int> sumpost(n);
	vector <int> iter1(n, 0), iter2(n, 0);
	for(int i = 0; i < n; i++)
	{
		sumpost[s[i]]++;
	}
	for(int j = 0; j < n; j++)
	{
		while(iter2[j] < p[j].size() && p[j][iter2[j]] <= sumpost[j])
		{
			iter2[j]++;
		}
	}
	int sum = 0;
	long long val = 1;
	bool flag = false;
	for(int j = 0; j < n; j++)
	{
		if(iter2[j] != 0)
		{
			sum++;
			val = (val * iter2[j]) % const1;
		}
	}
	int anscnt, ansres;
	anscnt = sum;
	ansres = val;
	for(int i = 0; i < n; i++)
	{
		int sum = 0;
		int val = 1;
		sumpref[s[i]]++;
		sumpost[s[i]]--;
		while(iter2[s[i]] > 0 && p[s[i]][iter2[s[i]] - 1] > sumpost[s[i]])
		{
			iter2[s[i]]--;
		}
		int prefval = iter1[s[i]];
		while(iter1[s[i]] < p[s[i]].size() && p[s[i]][iter1[s[i]]] <= sumpref[s[i]])
		{
			iter1[s[i]]++;
		}
		if(i == n - 1)
		{
			for(int j = 0; j < n; j++)
			{
				if(s[i] != j)
				{
					if(iter1[j] != 0)
					{
						val = (val * iter1[j]) % const1;
						sum++;
					}
				}
				else
				{
					sum++;
					val = (val * (iter1[s[i]] - prefval)) % const1; 
				}
			}
		}
		else
		{
			for(int j = 0; j < n; j++)
			{
				if(s[i] == j)
				{
					if(iter1[j] > iter2[j])
					{
						if(iter2[j] == 0 && iter1[j] - prefval != 0)
						{
							sum++;
						}
						else if(iter1[j] != prefval)
						{
							sum += 2;
						}
						int k2 = iter2[j];
						if(iter2[j] == 0)
						{
							k2 = 1;
						}
						val = val * ((iter1[j] - prefval) * k2 % const1) % const1;
					}
				else
				{
					if(iter2[j] == 1 && iter1[j] - prefval == 1)
					{
						sum++;
					}
					else
					{
						if(iter1[j] != prefval)
						{
							sum += 2;
						}
						int k1 = iter1[j] - prefval;
						int k2 = iter2[j];
						val = (val * (k1 * (k1 - 1) + (k2 - k1) * k1)) % const1;
					}
				}
				}
				else
				{
					int k1 = max(iter1[j], iter2[j]);
					int k2 = min(iter1[j], iter2[j]);
					if(max(k1, k2) >= 2 && min(k1, k2) >= 1)
					{
						sum += 2;
						val = val * ((k1 - k2) * k2 + k2 * (k2 - 1)) % const1;
					}
					else if(max(k1, k2) > 0)
					{
						sum++;
						val = val * (k1 + k2) % const1;
					}
				}
			}
		}
		if(val != 0)
		{
			if(sum == anscnt)
			{
				ansres = (ansres + val) % const1;
			}
			else if(sum > anscnt)
			{
				ansres = val;
				anscnt = sum;
			}
		}
	}
	cout << anscnt << " " << ansres;
    return 0;
}