#include<iostream>
#include<cstdio>
using namespace std;
int n,m,p[101],minnum,k;
int main()
{
	scanf("%d%d",&n,&m);
	minnum=n+1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&k);
		if(k<minnum)
		{
			for(int i=k;i<minnum;i++)
				p[i]=n-k;
			minnum=k;
		}
	}
	for(int i=1;i<n;i++)
		printf("%d ",n-p[i]);
	printf("%d\n",n-p[n]);
	return 0;
}