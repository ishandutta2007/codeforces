#include<bits/stdc++.h>
 
using namespace std;
#define int long long
signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n, d, val;
	cin >> n >> d >> val;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector <int> b(n);
	int l = -1, r = (n + 1) / 2;
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		for(int i = 0; i < n; i++)
		{
			b[i] = a[i];
		}
		queue <int> q;
		int j = 0;
		int cnt = 0;
		int sum1 = 0;
		for(int i = 0; i < (n + 1) / 2; i++)
		{
			while(j < n && j - i <= d * (i + 1))
			{
				sum1 += b[j];
				q.push(j);
				j++;
			}
			int sum = 0;
			if(sum1 >= val)
			{
				while(sum < val)
				{
					int v = q.front();
					int t = min(val - sum, b[v]);
					b[v] -= t;
					sum += t;
					sum1 -= t;
					if(b[v] == 0)
					{
						q.pop();
					}
				}
				cnt++;
			}
			if(cnt == (n + 1) / 2 - midd)
			{
				break;
			}
		}
		if(cnt != (n + 1) / 2 - midd)
		{
			l = midd;
			continue;
		}
		cnt = 0;
		j = n - 1;
		sum1 = 0;
		while(q.size() > 0)
		{
			q.pop();
		}
		for(int i = n - 1; i >= (n + 1) / 2; i--)
		{
			while(j >= 0 && i - j <= d * (n - i))
			{
				sum1 += b[j];
				q.push(j);
				j--;
			}
			int sum = 0;
			if(sum1 >= val)
			{
				cnt++;
				while(sum < val)
				{
					int v = q.front();
					int t = min(val - sum, b[v]);
					b[v] -= t;
					sum += t;
					sum1 -= t;
					if(b[v] == 0)
					{
						q.pop();
					}
				}
			}
			if(cnt == n / 2 - midd)
			{
				break;
			}
		}
		if(cnt != n / 2 - midd)
		{
			l = midd;
		}
		else
		{
			r = midd;
		}
	}
	cout << r;
	return 0;
}