#include <bits/stdc++.h>
#define N 1000000
using namespace std;
int n, cnt;
int a[N + 10];
int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; i ++)
	{
		int x;
		scanf("%d",&x);
		a[x] = 1;
	}
	printf("%d\n",n);
	for(int i = 1; i <= N; i ++)
		if(a[i] && !a[N - i + 1])
		{
			printf("%d ", N - i + 1);
			cnt ++;
		}
	for(int i = 1; i <= N && cnt != n; i ++)
		if(!a[i] && !a[N - i + 1])
		{
			printf("%d %d ",i, N - i + 1);
			cnt += 2;
		}

	return 0;
}