#include<cstdio>
signed main()
{
	long long i,j,n,a,b;
	scanf("%I64d%I64d%I64d",&n,&a,&b);
	for(i=0;a*i<=n;i++)
		if((n-a*i)%b==0)
			return printf("YES\n%I64d %I64d\n",i,(n-a*i)/b),0;
	puts("NO");
	return 0;
}