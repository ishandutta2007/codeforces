#include<cstdio>
#define int long long
const int N=1e6+5;
int p,k,tot;
int last;
int a[N],b[N];
signed main()
{
	register int i;
	scanf("%lld%lld",&p,&k);last=p;
	while(true)
	{
		if(last>=0)
			b[tot]=(-last)/k;
		else
		{
			if(last%k==0)
				b[tot]=(-last)/k;
			else
				b[tot]=(-last)/k+1;
		}
		last=b[tot];
		if(!last)
			break;
		tot++;
	}
	a[0]=k*b[0]+p;
	for(i=1;i<=tot;i++)
		a[i]=k*b[i]+b[i-1];
	printf("%lld\n",tot+1);
	for(i=0;i<=tot;i++)
		printf("%lld ",a[i]);
	putchar('\n');
	return 0;
}