#include<cstdio>
#include<cmath>
const int N=1e5+5;
int n,m,p;
signed main()
{
	register int i,k;
	scanf("%d",&n);
	m=sqrt(n);p=0;
	for(k=n/m;k>=0;k--)
	{
		for(i=k*m+1;i<=(k+1)*m&&i<=n;i++)
			printf("%d ",i);
	}
	putchar('\n');
}