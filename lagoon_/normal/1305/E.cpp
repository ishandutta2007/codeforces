#include<bits/stdc++.h>
#define re register
int a[5010];
int main()
{
	re int n,m,i;
	scanf("%d%d",&n,&m);
	re int nw=0;
	for(re int i=1;i<=n;i++)
	{
		nw+=(i-1)/2;
	}
	if(m>nw){puts("-1");return 0;}
	for(i=1;i<=n;i++)a[i]=i;
	for(i=n;i;i--)
	{
		if(nw-(i-1)/2<=m)
		{
			if((i&1))a[i]--;
			a[i]+=2*(nw-m);
			if(!a[i])a[i]++;
			break;
		}
		nw-=(i-1)/2;
	}
	a[i+1]=5010*5010;
	for(re int j=i+2;j<=n;j++)a[j]=a[j-1]+5010;
	for(re int i=1;i<=n;i++)printf("%d ",a[i]);
}