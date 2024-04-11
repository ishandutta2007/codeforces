#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x;
	cin >> n >> x;
	vector <int> d(n);
	vector <int> pref(n), post(n + 1, 0);
	vector <int> pref1(n), post1(1 + n, 0);
	for(int i = 0; i < n; i++)
	{
		cin >> d[i];
		if(i == 0)
		{
			pref1[i] = d[i] * (d[i] + 1) / 2;
			pref[i] = d[i];
		}
		else
		{
			pref1[i] = pref1[i - 1] +  d[i] * (d[i] + 1) / 2;
			pref[i] = pref[i - 1] + d[i];
		}
	}
	for(int i  = n - 1; i >= 0; i--)
	{
		if(i == n - 1)
		{
			post1[i] = d[i] * (d[i] + 1) / 2;
			post[i] = d[i];
		}
		else
		{
			post1[i] = post1[i + 1] + d[i] * (d[i] + 1) / 2;
			post[i] = post[i + 1] + d[i];
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int val = 0;
		int a = 0;
		if(pref[i] <= x)
		{
			val += pref1[i];
			a += pref[i];
			int l = 0, r = n;
			while(r - l > 1)
			{
				int midd = (r + l) / 2;
				if(post[midd] > x - a)
				{
					l = midd;
				}
				else
				{
					r = midd;
				}
			}
			if(r != n)
			{
				a += post[r];
				val += post1[r];
			}
			a = x - a;
			val += a * (d[l] * 2 - a + 1) / 2;
		}
		else
		{
			int l = -1, r = n;
			while(r - l > 1)
			{
				int midd = (r + l) / 2;
				if(pref[i] - pref[midd] > x)
				{
					l = midd;
				}
				else
				{
					r = midd;
				}
			}
			val += pref1[i] - pref1[r];
			a = x - (pref[i] - pref[r]);
			val += a * (d[r] * 2 - a + 1) / 2;
		}
		ans = max(ans, val);
		a = 1;
		val = d[i];
		if(i == n - 1 || post[i + 1] <= x - a)
		{
			if(i != n - 1)
			{
				val += post1[i + 1];
				a += post[i + 1];
			}
			int l = -1, r = n - 1;
			while(r - l > 1)
			{
				int midd = (r + l) / 2;
				if(pref[midd] <= x - a)
				{
					l = midd;
				}
				else
				{
					r = midd;
				}
			}
			if(l != -1)
			{
				a += pref[l];
				val += pref1[l];
			}
			a = x - a;
			val += a * (a + 1) / 2;
		}
		else
		{
			int l = 0, r = n;
			while(r - l > 1)
			{
				int midd = (r + l) / 2;
				if(post[i + 1] - post[midd] <= x - a)
				{
					l = midd;
				}
				else
				{
					r = midd;
				}
			}
			val += post1[i + 1] - post1[l];
			a += (post[i + 1] - post[l]);
			a = x - a;
			val += a * (a + 1) / 2;
		}
		ans = max(ans, val);
	}
	cout << ans;
    return 0;
}