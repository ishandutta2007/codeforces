#include <iostream>
using namespace std;
double len[100005],cnt[100005];
int main()
{
	int n,p;
	scanf("%d%d",&n,&p);
	for (int i=0;i<n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		len[i]=r-l+1;
		cnt[i]=(int)r/p-(int)(l-1)/p;
	}
	double ans=0.0;
	for (int i=0;i<n;i++)
	{
		int j=(i+1)%n;
		ans+=(cnt[i]/len[i]+cnt[j]/len[j]-cnt[i]*cnt[j]/(len[i]*len[j]))*2000.0;
	}
	printf("%.9lf",ans);
}