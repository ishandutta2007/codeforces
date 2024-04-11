#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T --)
	{
		int n, k, ans = 0;
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i ++)
		{
			int x;
			scanf("%d", &x);
			ans = max(ans, x | k);
		}
		printf("%d\n", ans);
	}
	
	
}