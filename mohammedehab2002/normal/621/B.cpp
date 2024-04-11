#include <iostream>
using namespace std;
long long cnt[3005][2];
int main()
{
	int n;
	scanf("%d",&n);
	while (n--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		cnt[b-a+1000][0]++;
		cnt[b+a+1000][1]++;
	}
	long long ans=0;
	for (int i=0;i<3005;i++)
	{
		for (int x=0;x<2;x++)
		ans+=cnt[i][x]*(cnt[i][x]-1)/2LL;
	}
	printf("%I64d",ans);
}