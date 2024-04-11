// ConsoleApplication1.cpp :     "main".      .
//
// ConsoleApplication1.cpp :     "main".      .
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
int f(int l, int r)
{
	int ret = 0;
	int zero = 0;
	for (int i = 1; i <= r; i <<= 1)
	{
		if (r & i)
		{
			r ^= i;
			if (!(l & r))
			{
				ret += (1 << zero);
			}
		}
		if (!(l & i))
		{
			zero++;
		}
	}
	return ret;
}
int rec(int l, int r)
{
	if (l == r)
	{
		return 0;
	}
	if (l == 0)
	{
		return 2 * r - 1 + rec(1, r);
	}
	int ans = 0;
	if (l & 1)
	{
		ans = f(l, r) * 2 - 2 * f(l, l);
		l++;
	}
	if (r & 1)
	{
		ans += 2 * f(r - 1, r) - 2 * f(r - 1, l);
		r--;
	}
	return (ans + 3 * rec(l / 2, r / 2));
}
signed main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		cout << rec(a, b + 1) << "\n";
	}
	return 0;
}