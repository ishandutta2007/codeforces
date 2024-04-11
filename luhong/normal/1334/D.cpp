#include <cstdio>
#include <iostream>

int n;

int Find(long long p)
{
	int l = 1, r = n;
	while(l < r)
	{
		int x = l + r >> 1;
		if(1ll * (2 * n - 2 + 2 * n - 2 * x) * x / 2 >= p) r = x;
		else l = x + 1;
	}
	return r;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		long long l, r; scanf("%d%lld%lld", &n, &l, &r);
		int st = Find(l);
		int now = l - 1ll * (2 * n - 2 + 2 * n - 2 * (st - 1)) * (st - 1) / 2;
		bool p = now & 1; 
		now = (now + 1) / 2 + st;
		for(long long i = l; i <= r; i++)
		{
			if(i == 1ll * n * (n - 1) + 1) printf("1 "); 
			else
			{
				if(p) printf("%d ", st), p = 0;
				else
				{
					printf("%d ", now); p = 1;
					now++; 
					if(now == n + 1) 
					{
						st++; 
						now = st + 1;
					}
				}
			}
		}
		puts("");
	}
}