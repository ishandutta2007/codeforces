#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

int main()
{
	
	int x1, y1, x2, y2, x, y;
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x, &y);
	x2 -= x1;
	y2 -= y1;
	if (x2%x || y2%y)
	{
		puts("NO");
		return 0;
	}
	x2 /= x;
	y2 /= y;
	puts((x2+y2)%2 == 0? "YES" : "NO");
	
	return 0;
}