#include<bits/stdc++.h>
 
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, pr;
	cin >> n >> pr;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int l = 0, r = 1e9 + 1;
	vector <int> cnt(n + 1);
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		for(int j = 0; j < n; j++)
		{
			cnt[j] = 0;
		}
		bool flag = true;
		for(int j = 0; j < n; j++)
		{
			if(a[j] - midd > n - 1)
			{
				flag = false;
			}
			cnt[min(n - 1, max(0, a[j] - midd))]++;
		}
		int c = 0;
		for(int j = 0; j < n; j++)
		{
			c += cnt[j];
			if(c == 0)
			{
				flag = false;
				break;
			}
			c--;
		}
		if(!flag)
		{
			l = midd;
		}
		else
		{
			r = midd;
		}
	}
	vector <int> cnt1(n + 1);
	vector <int> p(n + 1, -1);
	for(int i = 2; i <= n; i++)
	{
		if(p[i] == -1)
		{
			int j = i * 2;
			while(j <= n)
			{
				p[j] = i;
				j += i;
			}
		}
	}
	bool flag = true;
	for(int j = 1; j <= n; j++)
	{
		cnt[j] = 0;
		cnt1[j - 1] = 0;
	}
	for(int j = 0; j < n; j++){
		if(a[j] - r > n - 1)
		{
			flag = false;
		}
		cnt1[min(n - 1, max(0, a[j] - r))]++;
	}
	int c = 0;
	for(int j = 0; j < n; j++)
	{
		c += cnt1[j];
		if(c == 0)
		{
			flag = false;
			break;
		}
		cnt[c]++;
		c--;
	}
	for(int j = n; j >= 1; j--){
		if(p[j] != -1)
		{
			cnt[j / p[j]] += cnt[j];
			cnt[p[j]] += cnt[j];
		}
	}
	if(!flag || cnt[pr] != 0)
	{
		cout << 0;
		return 0;
	}
	int l1 = r, r1 = 1e9 + 1;
	while(r1 - l1 > 1)
	{
		int midd = (r1 + l1) / 2;
		bool flag = true;
		for(int j = 1; j <= n; j++)
		{
			cnt[j] = 0;
			cnt1[j - 1] = 0;
		}
		for(int j = 0; j < n; j++){
			if(a[j] - midd > n - 1)
			{
				flag = false;
			}
			cnt1[min(n - 1, max(0, a[j] - midd))]++;
		}
		int c = 0;
		for(int j = 0; j < n; j++)
		{
			c += cnt1[j];
			if(c == 0)
			{
				flag = false;
				break;
			}
			cnt[c]++;
			c--;
		}
		if(!flag)
		{
			continue;
		}
		for(int j = n; j >= 1; j--){
			if(p[j] != -1)
			{
				cnt[j / p[j]] += cnt[j];
				cnt[p[j]] += cnt[j];
			}
		}
		if(cnt[pr] == 0 && flag)
		{
			l1 = midd;
		}
		else
		{
			r1 = midd;
		}
	}
	cout << l1 - r + 1 << "\n";
	for(int j = r; j <= l1; j++)
	{
		cout << j << " ";
	}
    return 0;
}