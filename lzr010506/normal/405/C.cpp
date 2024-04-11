#include <bits/stdc++.h>
#define N 1010
using namespace std;
int a[N][N];
int n,t,q,k;
int get_ans()
{
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			ans ^= a[i][j] * a[j][i];
	return ans;
}

int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			scanf("%d",&a[i][j]);

	int ans = get_ans();
	scanf("%d", &q);
	for(int i = 1; i <= q; i ++)
	{
		scanf("%d",&k);
		if(k == 3) printf("%d", ans);
		else 
		{
			scanf("%d", &t);
			ans ^= 1;
		}
	}
	printf("\n"); 
	return 0;
}