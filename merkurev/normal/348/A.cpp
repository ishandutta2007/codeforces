#include <iostream>
using namespace std;


long long a[200500];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", &a[i] );
	}

	long long r = 3e15, l = 0;

	while (r - l > 1)
	{
		long long m = (l + r) / 2;
		long long x = m;
		bool gd = true;
		for (int i = 0; i < n; i++)
		{
			if (m < a[i] )
				gd = false;
			if (x < 0)
				x = 0;
			x -= (m - a[i] );
		}
		if (x <= 0 && gd)
			r = m;
		else
			l = m;
	}
	printf("%I64d\n", r);




	return 0;
}