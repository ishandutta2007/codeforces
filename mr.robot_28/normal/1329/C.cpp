#include <bits/stdc++.h>
 
using namespace std;
#define int long long
vector <int> a, hto;
int h, g;
int n;
void go_to(int v, int cnt)
{
	if(a[v * 2] == 0 && a[v * 2 + 1] == 0)
	{
		hto[v] = 0;
		a[v] = 0;
		return;
	}
	if(a[v * 2] > a[v * 2 + 1])
	{
		a[v] = a[v * 2];
		go_to(v * 2, cnt + 1);
	}
	else
	{
		a[v] = a[v * 2 + 1];
		go_to(v * 2 + 1, cnt + 1);
	}
	if(a[v * 2] == 0 && a[v * 2 + 1] == 0)
	{
		hto[v] = cnt;
	}
	else if(a[v * 2] > a[v * 2 + 1])
	{
		hto[v] = hto[v * 2];
	}
	else
	{
		hto[v] = hto[v * 2 + 1];
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> h >> g;
		n = (1 << h) - 1;
		a.resize(n * 2 + 2);
		for(int i = 0; i < n * 2 + 2; i++)
		{
			a[i] = 0;
		}
		int sum = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		vector <int> deep(n + 1);
		for(int i = 1; i <= n; i++)
		{
			deep[i] = deep[i / 2] + 1;
		}
		hto.resize(n * 2 + 2);
		for(int i = 1; i <= n; i++)
		{
			hto[i] = h;
		}
		for(int i = n + 1; i < n * 2 + 2; i++)
		{
			hto[i] = 0;
		}
		vector <int> p;
		for(int i = 1; i <= n; i++)
		{
			while(hto[i] > g)
			{
				p.push_back(i);
				sum -= a[i];
				go_to(i, deep[i]);
			}
		}
		cout << sum << "\n";
		for(int i = 0; i < p.size(); i++)
		{
			cout << p[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}