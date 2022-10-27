#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> p(2021, -1);
int query(int q)
{
	cout << "? " << q << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cnt = 1;
	int pr = 1;
	for(int i = 2; i <= 2020; i++)
	{
		if(p[i] == -1)
		{
			if(1e18 / pr >= i)
			{
				pr *= i;
			}
			else
			{
				pr = i;
				cnt++;
			}
			int k = i * 2;
			while(k <= 2020)
			{
				p[k] = i;
				k += i;
			}
		}
	}
	int t;
	cin >> t;
	while(t--)
	{
		int x1 = 1;
		int P = 1;
		int C = 1e9 / 4;
		vector <int> del;
		vector <int> pr;
		for(int i = 2; i < 2020; i++)
		{
			if(p[i] != -1)
			{
				continue;
			}
			int c1 = C;
			c1 = c1 / i / i / i;
			if(c1 == 0)
			{
				break;
			}
			if(1e18 / i < P)
			{
				int g = query(P);
				while(del.size() > 0)
				{
					if(g % del.back() == 0)
					{
						pr.push_back(del.back());
						if(pr.size() <= 2)
						{
							C *=2;
						}
						C /= pr.back();
					}
					del.pop_back();
				}
				P = 1;
			}
			P *= i;
			del.push_back(i);
		}
		if(del.size() > 0)
		{
			int g = query(P);
			while(del.size() > 0)
			{
				if(g % del.back() == 0)
				{
					pr.push_back(del.back());
				}
				del.pop_back();
			}
		}
		if((int)pr.size() % 2 == 1)
		{
			for(int j = 2; j < 2020; j++)
			{
				if(p[j] != -1)
				{
					continue;
				}
				bool flagfind = false;
				for(int i = 0; i < pr.size(); i++)
				{
					flagfind |= pr[i] == j;
				}
				if(!flagfind)
				{
					pr.push_back(j);
					break;
				}
			}
		}
		int ans = 2;
		for(int j = 0; j < pr.size(); j += 2)
		{
			int t1 = pr[j];
			int t2 = pr[j + 1];
			int cnt1 = 0;
			int cnt2 = 0;
			while(t1 * pr[j] <= 1e9)
			{
				t1 *= pr[j];
			}
			while(t2 * pr[j + 1] <= 1e9)
			{
				t2 *= pr[j + 1];
			}
			int q = query(t1 * t2);
			while(q % pr[j] == 0)
			{
				q = q / pr[j];
				cnt1++;
			}
			while(q % pr[j + 1] == 0)
			{
				q = q / pr[j + 1];
				cnt2++;
			}
			ans = ans * (cnt1 + 1) * (cnt2 + 1);
		}
		if(8 > ans)
		{
			ans = 8;
		}
		cout << "! " << ans << endl;
		fflush(stdout);
	}
	return 0;
}