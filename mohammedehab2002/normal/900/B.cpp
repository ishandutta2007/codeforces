#include <iostream>
using namespace std;
bool vis[100005];
int main()
{
	int a,b,c,ans=0;
	scanf("%d%d%d",&a,&b,&c);
	while (1)
	{
		ans++;
		int cur=a*10/b;
		if (vis[a])
		{
			printf("-1");
			return 0;
		}
		vis[a]=1;
		if (cur==c)
		{
			printf("%d",ans);
			return 0;
		}
		a=a*10-cur*b;
	}
}