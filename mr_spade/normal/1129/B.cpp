#include<cstdio>
const int N=2005;
int n,k;
int a[N];
signed main()
{
	register int i;
	scanf("%d",&k);k++;
	n=(k+999998)/999999+1;
	for(i=n;i>=2;i--)
		if(k<=999999)
			a[i]=k+1,k=0;
		else
			a[i]=1000000,k-=999999;
	a[1]=-1;
	printf("%d\n",n);
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	putchar('\n');
	return 0;
}