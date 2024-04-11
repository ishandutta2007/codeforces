#include<cstdio>
const int N=2e5+5;
int h;
int a[N];
int father[N],first[N],last[N];
signed main()
{
	bool flag=0;
	register int i,j;
	scanf("%d",&h);
	for(i=0;i<=h;i++)
	{
		scanf("%d",&a[i]);
		if(i>0)
			flag|=(a[i-1]>1&&a[i]>1);
	}
	if(!flag)
		return puts("perfect"),0;
	puts("ambiguous");
	int tot=1;
	father[1]=0;last[0]=1;
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=a[i];j++)
			father[++tot]=last[i-1];
		last[i]=tot;
	}
	for(i=1;i<=tot;i++)
		printf("%d ",father[i]);
	putchar('\n');
	tot=1;
	father[1]=0;first[0]=last[0]=1;
	for(i=1;i<=h;i++)
	{
		first[i]=tot+1;
		father[++tot]=first[i-1];
		for(j=2;j<=a[i];j++)
			father[++tot]=last[i-1];
		last[i]=tot;
	}
	for(i=1;i<=tot;i++)
		printf("%d ",father[i]);
	putchar('\n');
	return 0;
}