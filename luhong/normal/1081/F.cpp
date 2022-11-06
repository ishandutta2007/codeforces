#include <cstdio>
#include <iostream>

int s[333];
int main()
{
	int n, t; scanf("%d%d", &n, &t);
	s[n] = t;
	for(int i = 1; i < n; i++)
	{
		int T = 18;
		bool ok = 0;
		while(T--)
		{
			printf("? %d %d\n", i + 1, n);
			fflush(stdout);
			int tt; scanf("%d", &tt);
			if(tt != n - t)
			{
				ok = 1;
				s[i] = (tt - n + t + i) / 2;
				int opt = 0;
				int now = tt;
				while(1)
				{
					printf("? %d %d\n", i + 1, n);
					fflush(stdout);
					scanf("%d", &tt);
					if(tt != n - now) break;
					now = n - now;
					opt ^= 1;
				}
				if(opt) 
				{
					printf("? %d %d\n", 1, n);
					fflush(stdout);
					scanf("%d", &tt);
				}
				break;
			}
			printf("? %d %d\n", 1, n);
			fflush(stdout);
			scanf("%d", &tt);
		}
		if(!ok) s[i] = i >> 1;
	}
	printf("! ");
	for(int i = 1; i <= n; i++) printf("%d", s[i] - s[i - 1]);
}