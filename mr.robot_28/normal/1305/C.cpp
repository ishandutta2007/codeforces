#include<bits/stdc++.h>
using namespace std;
int m;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return t * t % m;
	}
	else
	{
		return a * power(a, b - 1) % m;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int p = 1;
	int n;
	cin >> n >> m;
	vector <int>cnt(m);
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++)
	{
		a[i] = a[i] % m;
		for(int j = 0; j < m; j++)
		{
			int raz = (a[i] - j + m) % m;
			p = p * power(raz, cnt[j]) % m;
		}
		if(p == 0)
		{
			break;
		}
		cnt[a[i] % m]++;
	}
	cout << p;
    return 0;
}