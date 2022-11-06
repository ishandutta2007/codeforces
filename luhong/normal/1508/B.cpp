#include <cstdio>
#include <iostream>

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n; long long k; 
		scanf("%d%lld", &n, &k);
		if(n <= 63 && k > 1ll << n - 1) {puts("-1"); continue;}
		for(int i = 1; i <= n; )
		{
			int j;
			for(j = 1; j < n - i + 1; j++)
			{
				int w = n - (i - 1 + j) - 1;
				if(w >= 63 || k <= 1ll << w) break;
				k -= 1ll << w;
			}
			for(int k = 1; k <= j; k++) printf("%d ", i + j - k);
			i += j;
		}
		puts("");
	}
}