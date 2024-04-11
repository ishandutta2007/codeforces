#include<bits/stdc++.h>
#define re register
int a[310][310];
int main()
{
	re int n,t,m,x;
	scanf("%d",&t);
	for(;t--;)
	{
		re bool bl=1;
		scanf("%d%d",&n,&m);
		for(re int i=1;i<=n;i++)
			for(re int j=1;j<=m;j++)
			{
				re int x1=(i!=1)+(i!=n)+(j!=1)+(j!=m);
				scanf("%d",&x);
				if(x>x1)bl=0;
				a[i][j]=x1;
			}
		if(bl)
		{puts("YES");
		for(re int i=1;i<=n;i++,puts(""))
			for(re int j=1;j<=m;j++)printf("%d ",a[i][j]);
		}else puts("NO");
	}
}