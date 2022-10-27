#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	vector <int> a(n), b(n);
	vector <int> prefmina(n);
	vector <int> prefminb(n);
	vector <int> pref1(n), pref2(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(i != 0)
		{
			prefmina[i] = min(prefmina[i - 1], a[i]);
		}
		else
		{
			prefmina[i] = a[i];
		}
		if(prefmina[i] == a[i])
		{
			pref1[i] = i;
		}
		else
		{
			pref1[i] = pref1[i - 1];
		}
	}
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
		if(i != 0)
		{
			prefminb[i] = min(prefminb[i - 1], b[i]);
		}
		else
		{
			prefminb[i] = b[i];
		}
		if(prefminb[i] == b[i])
		{
			pref2[i] = i;
		}
		else
		{
			pref2[i] = pref2[i - 1];
		}
	}
	vector <pair <int, int> > t(m);
	for(int i =0; i < m; i++)
	{
		cin >> t[i].first >> t[i].second;
	}
	int imin = -1;
	int l = -1, r = n + 1;
	vector <int> p(m);
	int k1 = prefmina[n - 1];
	int k2 = prefminb[n - 1];
	for(int i = 0; i < m; i++)
	{
		if(t[i].first == 1)
		{
			p[i] += t[i].second * k1;
		}
		else
		{
			p[i] += t[i].second * k2;
		}
	}
	sort(p.begin(), p.end());
	int sum = 0;
	for(int i = 0; i < k; i++)
	{
		sum += p[i];
	}
	if(sum > s)
	{
		cout << -1;
		return 0;
	}
	sum = 0;
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		int cost1 = prefmina[midd];
		int cost2 = prefminb[midd];
		for(int i = 0; i < m; i++)
		{
			if(t[i].first == 1)
			{
				p[i] = (t[i].second * cost1);
			}
			else
			{
				p[i] = (t[i].second * cost2);
			}
		}
		sort(p.begin(), p.end());
		int sum1 = 0;
		for(int i = 0; i < k; i++)
		{
			sum1 += p[i];
		}
		if(sum1 <= s)
		{
			r = midd;
		}
		else
		{
			l = midd;
		}
	}
	k1 = prefmina[r];
	k2 = prefminb[r];
	cout << r + 1 << "\n";
	vector <pair <int, int> > ans;
	for(int i = 0; i < m; i++)
	{
		if(t[i].first == 1)
		{
			ans.push_back({t[i].second * k1, i});
		}
		else
		{
			ans.push_back({t[i].second * k2, i});
		}
	}
	sort(ans.begin(), ans.end());
	for(int i = 0; i < k; i++)
	{
		cout << ans[i].second + 1 << " ";
		if(t[ans[i].second].first == 1)
		{
			cout << pref1[r] + 1 << "\n";
		}
		else
		{
			cout << pref2[r] + 1 << "\n";	
		}
	}
	return 0;
}