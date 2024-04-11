#include <bits/stdc++.h>
using namespace std;

signed main()
{
	int n, l, r;
	cin >> n >> l >> r;
	int min = 0, max = 0;
	for(int i = 0; i < l; i++)
	{
		min = min * 2 + 1;
	}
	min += n - l;
	for(int i = 0; i < r; i++)
	{
		max = max * 2 + 1;
	}
	max += pow(2, r - 1) * (n - r);
	cout << min << " " << max;
	return 0;
}