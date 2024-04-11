#include<bits/stdc++.h>
#define re register
long long vv[110][110];
int main()
{
	re int n,q;
	scanf("%d",&n);
	for(re int i=2;i<=2*n;i++)
	{
		for(re int j=1;j<i&&j<=n;j++)if(i-j<=n)
		{
			vv[i-j][j]=(long long)(j&1)<<(i-2);
		}
	}
	for(re int i=1;i<=n;i++,puts(""))
	for(re int j=1;j<=n;j++)printf("%lld ",vv[i][j]);
	fflush(stdout);
	scanf("%d",&q);
	for(;q--;)
	{
		re long long x;
		fflush(stdout);
		scanf("%lld",&x);
		re int x1=1,y1=1;
		puts("1 1");
		while(x1!=n||y1!=n)
		{
			if(x1==n)y1++;
			else if(y1==n)x1++;
			else if(vv[x1][y1+1]&x)y1++;
			else if(vv[x1+1][y1]&x)x1++;
			else if(vv[x1][y1+1]==0)y1++;
			else x1++;
			printf("%d %d\n",x1,y1);
		}
	}
}