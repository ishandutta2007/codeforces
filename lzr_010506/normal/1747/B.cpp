#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int T;
	scanf("%d", &T);
	while(T --)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", (n + 1) / 2);
		for(int i = 1; i <= n / 2; i ++)
			printf("%d %d\n", (i - 1) * 3 + 1, (n - i) * 3 + 2);
		if(n & 1) printf("%d %d\n", n / 2 * 3 + 1, 3 * n);
	}
	return 0;
}