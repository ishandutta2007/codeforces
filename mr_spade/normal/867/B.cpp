#include<cstdio>
const int N=1e7;
int ans,n,m;
int a[N];
signed main()
{
	int i,j;
	scanf("%d",&ans);
	if(ans==1)
	{
		puts("1 2");
		puts("1 2");
		return 0;
	}
	printf("%d 2\n1 2",(ans-1)<<1);
	return 0;
}