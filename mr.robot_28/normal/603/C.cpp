#include<bits/stdc++.h>
using namespace std;
int rec(int a, int k)
{
	if(k % 2 == 0)
	{
		if(a == 1)
		{
			return 1;
		}
		if(a == 2)
		{
			return 2;
		}
		return ((a % 2) ^ 1);
	}
	else
	{
		if(a == 1)
		{
			return 1;
		}
		else if(a == 2)
		{
			return 0;
		}
		else if(a == 3)
		{
			return 1;
		}
		else if(a == 4)
		{
			return 2;
		}
		else if( a % 2 == 1)
		{
			return 0;
		}
		else
		{
			return (rec(a / 2, k) == 1 ? 2 : 1);
		}
	}
}
signed main()
{
	int n, k;
	cin >> n >> k;
	int res = 0;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		res ^= rec(a, k);
	}
	if(res)
	{
		cout << "Kevin";
	}
	else
	{
		cout << "Nicky";
	}
	return 0;
}