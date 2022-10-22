#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100000;
int n,m;
int a[maxn+5];
int suma[maxn+5],sumb[maxn+5];
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	a[n+1]=m;
	n++;
	for(int i=1;i<=n;i++) 
	{
		suma[i]=suma[i-1];
		sumb[i]=sumb[i-1];
		if(i&1) suma[i]+=a[i]-a[i-1];
		else sumb[i]+=a[i]-a[i-1];
	}
	int ans=suma[n],id=-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i-1]+1) continue;
		int pos,sum=0;
		if(i&1)
		{
			pos=a[i]-1;
			sum=suma[i-1]+(sumb[n]-sumb[i]);
			sum+=pos-a[i-1];
		}
		else
		{
			pos=a[i-1]+1;
			sum=suma[i-1]+(sumb[n]-sumb[i]);
			sum+=a[i]-pos;			
		}
		if(sum>ans)
		{
			ans=sum;
			id=pos;
		}
	}
	printf("%lld\n",ans);
	return 0;
}