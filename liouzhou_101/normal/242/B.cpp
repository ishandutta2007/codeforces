#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=100010;

int n,sx=2000000000,sy=0;
int x[MaxN],y[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&x[i],&y[i]);
		sx=min(sx,x[i]);
		sy=max(sy,y[i]);
	}
	for (int i=1;i<=n;++i)
		if (sx==x[i]&&sy==y[i])
		{
			printf("%d\n",i);
			return 0;
		}
	puts("-1");
	return 0;
}