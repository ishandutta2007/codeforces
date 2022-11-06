#include <cstdio>
#include <iostream>

int main()
{
	int n; scanf("%d", &n);
	int Mxa = 0, Mxb = 0;
	for(int i = 1; i <= n; i++)
	{
		char c[2]; int a, b; scanf("%s%d%d", c, &a, &b);
		if(a > b) std::swap(a, b);
		if(c[0] == '+')
		{
			Mxa = std::max(Mxa, a);
			Mxb = std::max(Mxb, b);
		}
		else
		{
			if(a >= Mxa && b >= Mxb) puts("YES");
			else puts("NO");
		}
	}
}