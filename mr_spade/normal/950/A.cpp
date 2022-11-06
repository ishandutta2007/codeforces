#include<cstdio>
int l,r,a;
signed main()
{
	scanf("%d%d%d",&l,&r,&a);
	if(l+a<=r)
	{
		printf("%d\n",(l+a)<<1);
		return 0;
	}
	else if(l>=r+a)
	{
		printf("%d\n",(r+a)<<1);
		return 0;
	}
	int n=(l+r+a)>>1;
	printf("%d\n",n<<1);
	return 0;
}