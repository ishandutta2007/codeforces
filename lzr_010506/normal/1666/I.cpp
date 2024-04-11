#include <bits/stdc++.h>
using namespace std;

int n, m;
int scan(int x, int y)
{
	printf("SCAN %d %d\n", x, y);
	fflush(stdout);
	int z;
	scanf("%d", &z);
	return z;
}

int dig(int x, int y)
{
	if(x < 1 || x > n || y < 1 || y > m) return 0;
	printf("DIG %d %d\n", x, y);
	fflush(stdout);
	int z;
	scanf("%d", &z);
	return z;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --)
	{
		scanf("%d%d", &n, &m);
		int ul = scan(1, 1);
		int ur = scan(1, m);
		int x1 = (ul + ur) / 2 + 3 - m;
		int y1 = (ul - ur) / 2 + 1 + m;
		int x2 = scan(x1 / 2, 1) - y1 + 2;
		int y2 = scan(1, y1 / 2) - x1 + 2;
		if(dig((x1 + x2) / 2, (y1 + y2) / 2)) dig((x1 - x2) / 2, (y1 - y2) / 2);
		else 
		{
			dig((x1 + x2) / 2, (y1 - y2) / 2);
			dig((x1 - x2) / 2, (y1 + y2) / 2);
		}
	}

	return 0;
}