#include<cstdio>
int m,n,cnt;
int lie[1000];
signed main()
{
	int res;
	register int i;
	scanf("%d%d",&m,&n);
	printf("1\n");fflush(stdout);
	scanf("%d",&res);
	if(res==0)
		return 0;
	if(res==-1)
		lie[1]=1;
	for(i=2;i<=n;i++)
	{
		printf("1\n");fflush(stdout);
		scanf("%d",&res);
		if(res==-1)
			lie[i]=1;
	}
	cnt=n;
	int l=1,r=m,mid;
	i=0;
	while(l<=r)
	{
		mid=(l+r)>>1;
		printf("%d\n",mid);
		fflush(stdout);
		scanf("%d",&res);i++;
		if(i==n+1)
			i=1;
		if(lie[i])
			res=-res;
		if(res==0)
			return 0;
		if(res==-1)
			r=mid-1;
		else
			l=mid+1;
	}
	return 0;
}