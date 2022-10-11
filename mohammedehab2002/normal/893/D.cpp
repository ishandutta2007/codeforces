#include <iostream>
using namespace std;
int cur[100005],suf[100005];
bool b[100005];
int main()
{
	int n,d;
	scanf("%d%d",&n,&d);
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		cur[i]=cur[i-1]+a;
		b[i]=!a;
	}
	suf[n+1]=-(1<<30);
	for (int i=n;i>0;i--)
	suf[i]=max(suf[i+1],cur[i]);
	int add=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		if (cur[i]+add>d)
		{
			printf("-1");
			return 0;
		}
		if (b[i] && cur[i]+add<0)
		{
			int tmp=d-(suf[i]+add);
			add+=tmp;
			if (cur[i]+add<0)
			{
				printf("-1");
				return 0;
			}
			ans++;
		}
	}
	printf("%d",ans);
}