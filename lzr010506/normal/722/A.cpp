#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	int x, y;
	scanf("%d:%d", &x, &y);
	if(t == 24)
	{
		if(x >= t || x < 10) x = x % 10, printf("0%d", x);
		else printf("%d", x);
		printf(":");
		if(y >= 60 || y < 10) y = y % 10, printf("0%d", y);
		else printf("%d", y);
	}
	else
	{
		if(x % 10 == 0) printf("10");
		else if(x == 11) printf("11");
		else if(x == 12) printf("12");
		else printf("0%d", x % 10);
		printf(":");
		if(y >= 60 || y < 10) y = y % 10,printf("0%d", y);
		else printf("%d", y);
	}
	return 0;
}