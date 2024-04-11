#include <bits/stdc++.h>
using namespace std;
int n;
int r=n-1;
int h;
int a[2001];
int g[2001];
int gcd(int x,int y)
{
	int p,q;
	while(y!=0)
	{
		p=x/y;
		q=x-p*y;
		x=y;
		y=q;
	}
	return x;
}
int main()
{
	int x,y;
	/*while(true)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",gcd(x,y));
	}*/
	scanf("%d",&n);
	r=n-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		g[i]=a[i];
	}
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<n-j;i++)
		{
			if(g[i]==1) h++;
		}
		if(h>0)
		{
			if(j==0) printf("%d\n",n-h);
			else printf("%d\n",r+j);
			return 0;
		}
		for(int i=0;i<n-j-1;i++)
		{
			g[i]=gcd(g[i],a[i+j+1]);
		}
	}
	printf("-1");
	/*for(int i=0;i<n-j;i++)
	{
		if(g[i]==1)
		{
			printf("%d",r+i);
			return 0;
		}
	}*/
	return 0;
}