#include <cstdio>
#include <iostream>

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int a, b; scanf("%d%d", &a, &b);
		if(a > b) std::swap(a, b);
		if(2 * a <= b) printf("%d\n", a);
		else printf("%d\n", (a + b) / 3);
	}
}