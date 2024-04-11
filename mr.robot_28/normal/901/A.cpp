#include <bits/stdc++.h>
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int h;
	cin >> h;
	h++;
	vector <int> a(h);
	int n = 0;
	bool flag = false;
	for(int i = 0; i < h; i++)
	{
		cin >> a[i];
		n += a[i];
	}
	for(int i = 0; i < h - 1; i++)
	{
		
		if(a[i] > 1 && i < h - 1 && a[i + 1] > 1)
		{
			flag = true;
		}
	}
	if(!flag)
	{
		cout << "perfect";
		return 0;
	}
	cout << "ambiguous\n";
	int v = 0;
	cout << 0 << " ";
	v = 1;
	for(int i = 1; i < h; i++)
	{
		if(a[i - 1] > 1 && flag && a[i] > 1)
		{
			cout << v << " ";
			for(int j = 2; j <= a[i]; j++)
			{
				cout << v - 1 << " ";
			}
			v += a[i];
			flag = false;
		}
		else
		{
			for(int j = 1; j <= a[i]; j++)
			{
				cout << v << " ";
			}
			v += a[i];
		}
	}
	cout << "\n";
	v = 1;
	cout << 0 << " ";
	for(int i = 1; i < h; i++)
	{
		for(int j = 1; j <= a[i]; j++)
		{
			cout << v << " ";
		}
		v += a[i];
	}
    return 0;
}