#include <iostream>
#include <cstdio>
int a[1000005];
int n;
int d[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=a[1];
	int p,q,r;
	p=0;
	q=0;
	d[0]=0;
	for(int i=1;i<=n;i++)
	{
		while(a[i]-a[p]>=90) p++;
		if(p!=0) p--;
		while(a[i]-a[q]>=1440) q++;
		if(q!=0) q--;
		d[i]=d[i-1]+20;
		if(d[i]>d[p]+50) d[i]=d[p]+50;
		if(d[i]>d[q]+120) d[i]=d[q]+120;
		//printf("%d ",d[i]);
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",d[i]-sum);
		sum=d[i];
	}
	return 0;
}