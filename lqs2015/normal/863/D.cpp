#include<iostream>
#include<cstdio>
using namespace std;
int n,q,m,a[222222],tp[222222],l[222222],r[222222],x;
int main()
{
	scanf("%d%d%d",&n,&q,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&tp[i],&l[i],&r[i]);
	}
	while(m--)
	{
		scanf("%d",&x);
		for (int i=q;i>=1;i--)
		{
			if (x>=l[i] && x<=r[i])
			{
				if (tp[i]==1)
				{
					if (x==l[i]) x=r[i];
					else x--;
				}
				else x=l[i]+r[i]-x;
			}
		}
		printf("%d ",a[x]);
	}
	printf("\n");
	return 0;
}