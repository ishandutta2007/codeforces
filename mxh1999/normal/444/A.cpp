#include<cstdio>
#include<iostream>
using namespace std;

int n,m;
int x[1010];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)	scanf("%d",&x[i]);
	double ans=0;
	for (int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		ans=max(ans,(double)(x[a]+x[b])/c);
	}
	printf("%.15lf\n",ans);
	return 0;
}