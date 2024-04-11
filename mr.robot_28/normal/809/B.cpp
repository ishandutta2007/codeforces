#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n, k;
	cin >> n >> k;
	int l = 1, r = n;
	while(r > l)
	{
		int midd = (r + l) / 2;
		cout << 1 << " " << midd << " " << midd + 1 << endl;
		fflush(stdout);
		string s;
		cin >> s;
		if(s == "NIE")
		{
			l = midd + 1;
		}
		else
		{
			r = midd;
		}
	}
	int l1 = 1, r1 = l - 1;
	while(r1 > l1)
	{
		int midd = (r1 + l1) / 2;
		cout << 1 << " " << midd<< " " << midd + 1 << endl;
		fflush(stdout);
		string s;
		cin >> s;
		if(s == "TAK")
		{
			r1 = midd;
		}
		else
		{
			l1 = midd + 1;
		}
	}
	bool flag = true;
	if(r1 == 0)
	{
		flag = false;
	}
	else
	{
		cout << 1 << " " << l1 << " " << l << endl;
		fflush(stdout);
		string s;
		cin >> s;
		if(s == "NIE")
		{
			flag = false;
		}
	}
	if(flag)
	{
		cout << 2 << " " << l << " " << l1 << endl;
		fflush(stdout);
		return 0;
	}
	l1 = l + 1, r1 = n;
	while(l1 < r1)
	{
		int midd = (r1 + l1) / 2;
		cout << 1 << " " << midd << " " << midd+ 1 << endl;
		fflush(stdout);
		string s;
		cin >> s;
		if(s == "TAK")
		{
			r1 = midd;
		}
		else
		{
			l1 = midd + 1;
		}
	}
	cout << 2 << " " << l << " " << l1 << endl;
	fflush(stdout);
	return 0;
}