#include <bits/stdc++.h>
using namespace std;

signed main()
{
	int t;
	cin >> t;
	vector <int> R(1e5 + 1);
	for(int i = 2; i <= 1e5; i++)
	{
		R[i] = R[i / 2] + 1;
	}
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> A(n);
		vector <vector <int> > maxa(n, vector <int> (log2(n) + 1));
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
			maxa[i][0] = A[i];
		}
		for(int i = 1; i <= log2(n); i++)
		{
			for(int j = 0; j <= n - (1 << i); j++)
			{
				maxa[j][i] = max(maxa[j][i - 1], maxa[j + (1 << (i - 1))][i - 1]);
			}
		}
		int m;
		cin >> m;
		vector <pair <int, int> > hero(m);
		for(int i = 0; i < m; i++)
		{
			cin >> hero[i].first >> hero[i].second;
			swap(hero[i].first, hero[i].second);
		}
		sort(hero.begin(), hero.end());
		vector <int> maxhero(m);
		for(int i = m - 1; i >= 0; i--)
		{
			if(i == m - 1)
			{
				maxhero[i] = hero[i].second;
			}
			else
			{
				maxhero[i] = max(hero[i].second, maxhero[i + 1]);
			}
		}
		int cnt = 0;
		bool flag = true;
		for(int i = 0; i < n; i++)
		{
			int l1 = -1, r1 = m;
			while(r1 - l1 > 1)
			{
				int midd1 = (r1 + l1) / 2;
				int midd = min(hero[midd1].first, n - i);
				int t = R[midd];
				int maxon = max(maxa[i][t], maxa[i + midd - (1 << t)][t]);
				if(maxhero[midd1] >= maxon)
				{
					l1 = midd1;
				}
				else
				{
					r1 = midd1;
				}
			}
			if(l1 == m - 1)
			{
				i += hero[l1].first - 1;
				cnt++;
			}
			else
			{
				int l = i - 1, r = min(hero[l1 + 1].first + i, n);
				if(l1 != -1)
				{
					l = hero[l1].first + i - 1;
				}
				while(r - l > 1)
				{
					int midd = (r + l) / 2;
					int t = R[midd - i + 1];
					int maxon = max(maxa[i][t], maxa[midd - (1 << t) + 1][t]);
					if(maxhero[l1 + 1] >= maxon)
					{
						l = midd;
					}
					else
					{r = midd;
					}
				}
				if(l == i - 1)
				{
					flag = false;
					break;
				}
				i += (l - i);
				cnt++;
			}
		}
		if(!flag)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << cnt << "\n";
		}
	}
    return 0;
}