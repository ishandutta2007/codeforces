#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	long long sum=0;
	for(int i=1;i<=m;i++)
	{
		int x,d;scanf("%d%d",&x,&d);
		if(d>0)sum+=1ll*n*x+1ll*d*n*(n-1)/2;
		else sum+=1ll*n*x+1ll*d*(1ll*(1+n/2)*(n/2)+(n&1?0:-n/2));
	}
	printf("%.15lf",(double)sum/n);return 0;
}