#include<bits/stdc++.h>
#define re register
int a[310310],q[100100],v[100100],ta,n;
int sp()
{
	for(re int i=0;i<=n;i++)v[i]=0;
	for(re int i=1;i<=n;i++)v[a[i]]++;
	for(re int i=0;i<=n;i++)if(!v[i])return i;
	return n;
}
int main()
{
	re int t;
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d",&n);
		for(re int i=1;i<=n;i++)scanf("%d",&a[i]);
		ta=0;
		while(1)
		{
			re int x=sp();
			if(x<n)q[++ta]=x+1,a[x+1]=x;
			else
			{
				re int j=1;
				while(j<=n&&a[j]==j-1)j++;
				if(j>n)break;
				q[++ta]=j;a[j]=x;
			}
		}
		printf("%d\n",ta);
		for(re int i=1;i<=ta;i++)printf("%d ",q[i]);puts("");
	}
}