#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int x1, x2, a, b;
	cin >> x1 >> x2 >> a >> b;
	if(a <= 0 && b >= 0)
	{
		if(x1 + a <= x2 && x1 + b >= x2)
		{
			cout << "FIRST\n";
			cout << x2;
		}
		else
		{
			cout << "DRAW";
	}
	return 0;
	}
	int d = x2 - x1;
	if(a < 0)
	{
		a = -a;
		b = -b;
		d = -d;
	}
	if(a > b)
	{
		swap(a, b);
	}
	if(d < 0)
	{
		cout << "DRAW";
		return 0;
	}
	if(d % (a + b) == 0)
	{
		cout << "SECOND";
		return 0;
	}
	if(d % (a + b) >= a && d % (a + b) <= b)
	{
		cout << "FIRST\n";
		int k = d % (a + b);
		if(x1 > x2)
		{
			k = -k;
		}
		cout << x1 + k << "\n";
		return 0;
	}
	cout << "DRAW";
	return 0; 
}