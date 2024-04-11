#include <iostream>
using namespace std;
#define MX 1000000
long long sum[2*MX+5],ans=(1LL<<60);
int cnt[2*MX+5];
int main()
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	while (n--)
	{
		int a;
		scanf("%d",&a);
		cnt[a]++;
		sum[a]+=a;
	}
	for (int i=1;i<=2*MX;i++)
	{
		cnt[i]+=cnt[i-1];
		sum[i]+=sum[i-1];
	}
	for (int i=2;i<=MX;i++)
	{
		long long cur=0;
		for (int j=i;j<=2*MX;j+=i)
		{
			long long all=cnt[j]-cnt[j-i],f=j-min(i,x/y+1),inc=cnt[j]-cnt[f];
			cur+=(inc*j-(sum[j]-sum[f]))*y+(all-inc)*x;
		}
		ans=min(ans,cur);
	}
	printf("%I64d",ans);
}