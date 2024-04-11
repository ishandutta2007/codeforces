#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int n, k, len;
	cin >> n >> k >> len;
	string s;
	cin >> s;
	if(k * len >= n)
	{
		cout << 0;
		return 0;
	}
	vector <int> pref(n + 1), pref1(n + 1);
	for(int i = 0; i < n; i++)
	{
			pref[i + 1] = pref[i];
			pref1[i + 1] = pref1[i];
			if(s[i] >= 'A' && s[i] <= 'Z')
			{
				pref[i + 1]++;
			} 
			else
			{
				pref1[i + 1]++;
			}
	}
	int l = -1, r = 1e9;
	int cnt1 = 0;
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		vector <pair <int, int> > ans(n);
		for(int i = len - 1; i < n; i++)
		{
			pair <int, int> v, v1;
			if(i == len - 1)
			{
				v = {0, 0};
				v1 = {0, 0};
			}
			else
			{
				v1 = ans[i - 1];
				v = ans[i - len];
			}
			int sum1 = pref[i + 1] - pref[i - len + 1];
			if(sum1 + v.second - midd > v1.second)
			{
				ans[i] = {v.first + 1, sum1 + v.second - midd};
			}
			else
			{
				ans[i] = {v1.first, v1.second};
			}
		}
		if(ans[n - 1].first > k)
		{
			l = midd;
		}
		else
		{
			cnt1 = ans[n - 1].first;
			r = midd;
		}
	}
	vector <pair <int, int> > ans(n);
	vector <int> pred(n, -2);
		for(int i = len - 1; i < n; i++)
		{
			pair <int, int> v, v1;
			if(i == len - 1)
			{
				v = {0, 0};
				v1 = {0, 0};
			}
			else
			{
				v1 = ans[i - 1];
				v = ans[i - len];
			}
			int sum1 = pref[i + 1] - pref[i - len + 1];
			if(sum1 + v.second - r > v1.second)
			{
				ans[i] = {v.first + 1, sum1 + v.second - r};
				pred[i] = i - len;
			}
			else
			{
				ans[i] = {v1.first, v1.second};
				if(i == 0)
				{
					pred[i] = -2;
				}
				else
				{
					pred[i] = pred[i - 1];
				}
			}
		}
	int j = n - 1;
	vector <bool> used(n);
	while(j >= 0)
	{
		if(pred[j] != -2)
		{
			for(int t = pred[j] + 1; t <= pred[j] + len; t++)
			{
				used[t] = true;
			}
		}
		j = pred[j];
	}
	int p1 = ans[n - 1].first;
	int ln = 0;
	for(int j = 0; j < n; j++)
	{
		if(!used[j])
		{
			ln++;
		}
		else
		{
			ln = 0;
		}
		if(ln >= len && pref[j + 1] - pref[j - len + 1] == r)
		{
			p1++;
			ln = 0;
		}
	}
	int sum = ans[n - 1].second + r * min(p1, k) + pref1[n];
	l = -1, r = 1e9;
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		vector <pair <int, int> > ans1(n);
		for(int i = len - 1; i < n; i++)
		{
			pair <int, int> v, v1;
			if(i == len - 1)
			{
				v = {0, 0};
				v1 = {0, 0};
			}
			else
			{
				v1 = ans1[i - 1];
				v = ans1[i - len];
			}
			int sum1 = pref1[i + 1] - pref1[i - len + 1];
			if(sum1 + v.second - midd > v1.second)
			{
				ans1[i] = {v.first + 1, sum1 + v.second - midd};
			}
			else
			{
				ans1[i] = {v1.first, v1.second};
			}
		}
		if(ans1[n - 1].first > k)
		{
			l = midd;
		}
		else
		{
			cnt1 = ans1[n - 1].first;
			r = midd;
		}
	}
	cnt1 = k - cnt1;
	vector <pair <int, int> > ans1(n);
	vector <int> pred1(n, -2);
		for(int i = len - 1; i < n; i++)
		{
			pair <int, int> v, v1;
			if(i == len - 1)
			{
				v = {0, 0};
				v1 = {0, 0};
			}
			else
			{
				v1 = ans1[i - 1];
				v = ans1[i - len];
			}
			int sum1 = pref1[i + 1] - pref1[i - len + 1];
			if(sum1 + v.second - r > v1.second)
			{
				ans1[i] = {v.first + 1, sum1 + v.second - r};
				pred1[i] = i - len;
			}
			else
			{
				ans1[i] = {v1.first, v1.second};
				if(i == 0)
				{
					pred1[i] = -2;
				}
				else
				{
					pred1[i] = pred1[i - 1];
				}
			}
		}
	vector <bool> used1(n);
	j = n - 1;
	while(j >= 0)
	{
		if(pred1[j] != -2)
		{
			for(int t = pred1[j] + 1; j < pred1[j] + len; j++)
			{
				used1[t] = true;
			}
		}
		j = pred1[j];
	}
	p1 = ans1[n - 1].first;
	ln = 0;
	for(int j = 0; j < n; j++)
	{
		if(!used1[j])
		{
			ln++;
		}
		else
		{
			ln = 0;
		}
		if(ln >= len && pref1[j + 1] - pref1[j - len + 1] == r)
		{
			p1++;
			ln = 0;
		}
	}
	sum = max(sum, ans1[n - 1].second + r * min(p1, k) + pref[n]);
	sum = min(sum, n);
	cout << n - sum;
	return 0;
}