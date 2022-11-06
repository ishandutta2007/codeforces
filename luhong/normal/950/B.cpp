#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int x[100100],y[100100];
int main()
{
	int n,m;scanf("%d%d",&n,&m);long long sum1=0,sum2=0;
	for(int i=1;i<=n;i++)scanf("%d",&x[i]);
	for(int i=1;i<=m;i++)scanf("%d",&y[i]);
	int i=0,j=0,ans=0;
	sum1=x[++i],sum2=y[++j];
	while(i<=n&&j<=m)
	{
		while(sum1<sum2)sum1+=x[++i];
		while(sum2<sum1)sum2+=y[++j];
		if(sum1==sum2)ans++,sum1=x[++i],sum2=y[++j];
	}
	printf("%d",ans);
	return 0;
}