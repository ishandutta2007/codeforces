#include <cstdio>

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n, m; scanf("%d%d", &n, &m);
		m++;
		int k = 0;
		for(int i = 30; i >= 0; i--)
		{
			if(!(n >> i & 1) && m >> i & 1)
				k += 1 << i;
			if(n >> i & 1 && !(m >> i & 1))
				break;
		}
		printf("%d\n", k);
	}
}