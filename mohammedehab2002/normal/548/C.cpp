#include <iostream>
#include <string.h>
using namespace std;
long long m,h[2],g[2],x[2],y[2],t;
bool vis[1000005];
void move()
{
	for (int i=0;i<2;i++)
	h[i]=(h[i]*x[i]+y[i])%m;
	t++;
}
int main()
{
	cin >> m;
	for (int i=0;i<2;i++)
	cin >> h[i] >> g[i] >> x[i] >> y[i];
	while (h[0]!=g[0])
	{
		if (vis[h[0]])
		{
			printf("-1");
			return 0;
		}
		vis[h[0]]=1;
		move();
	}
	if (h[0]==g[0] && h[1]==g[1])
	{
		printf("%I64d",t);
		return 0;
	}
	long long tmp=1,a=x[1],b=y[1];
	move();
	memset(vis,0,sizeof(vis));
	while (h[0]!=g[0])
	{
		if (vis[h[0]])
		{
			printf("-1");
			return 0;
		}
		vis[h[0]]=1;
		move();
		tmp++;
		a=(a*x[1])%m;
		b=(b*x[1]+y[1])%m;
	}
	memset(vis,0,sizeof(vis));
	while (h[1]!=g[1])
	{
		if (vis[h[1]])
		{
			printf("-1");
			return 0;
		}
		vis[h[1]]=1;
		h[1]=(a*h[1]+b)%m;
		t+=tmp;
	}
	printf("%I64d",t);
}