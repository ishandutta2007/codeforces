#include<cstdio>
#include<cmath>
typedef unsigned long long ull;
ull n,m;
signed main()
{
	scanf("%I64d%I64d",&n,&m);
	if(m>n)
		return printf("%I64d\n",n),0;
	ull x=ull((sqrt((n-m<<3)+1)-1)/2);
	while(x*(x+1)<n-m<<1)
		x++;
	printf("%I64d\n",x+m);
	return 0;
}