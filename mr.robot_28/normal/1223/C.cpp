#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int n;
		cin >> n;
		vector <int> p(n);
		for(int j = 0; j < n; j++)
		{
			cin >> p[j];
		}
		sort(p.begin(), p.end());
		int x, a;
		cin >> x >> a;
		int y, b;
		cin >> y >> b;
		if(x > y)
		{
			swap(x, y);
			swap(a, b);
		}
		int k;
		cin >> k;
		int l = 0, r = n + 1;
		while(r - l > 1)
		{
			int sum = 0;
			int midd = (r + l) / 2;
			int u = n - 1;
			for(int j = midd; j >= 1; j--)
			{
				if(j % b ==0 && j % a == 0)
				{
					sum += p[u] * (x + y) / 100;
					u--;
				}
			}
			for(int j = midd; j >= 1; j--)
			{
				if(j % b == 0 && j % a != 0)
				{
					sum += p[u] * y / 100;
					u--;
				}
			}
			for(int j = midd; j >= 1; j--)
			{
				if(j % a == 0 && j % b != 0)
				{
					sum += p[u] * x / 100;
					u--;
				}
			}
			if(sum >= k)
			{
				r = midd;
			}
			else
			{
				l = midd;
			}
		}
		if(r == n + 1)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << r << "\n";
		}
	}
	return 0;
}