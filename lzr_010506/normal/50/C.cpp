#include <bits/stdc++.h>
#define inf 100000000
using namespace std;

int main()
{
	int n;
	cin >> n;
	int lmin = inf, lmax = -inf, rmin = inf, rmax = -inf;
	for(int i = 1; i <= n; i ++)
	{
		int x, y;
		cin >> x >> y;
		if(x + y > lmax) lmax = x + y;
		if(x + y < lmin) lmin = x + y;
		if(y - x > rmax) rmax = y - x;
		if(y - x < rmin) rmin = y - x;
	}
	printf("%d\n",lmax - lmin + rmax - rmin + 4);
	return 0;
}