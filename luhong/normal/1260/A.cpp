#include <iostream>
#include <cstdio>
 
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n, m; scanf("%d%d", &n, &m);
		n = std::min(n, m);
		int t = m / n;
		for(int v = 0; v <= n; v++)
		{
			if(v * t + (n - v) * (t + 1) == m)
			{
				printf("%d\n", v * t * t + (n - v) * (t + 1) * (t + 1)); break;
			}
		}
	}
}