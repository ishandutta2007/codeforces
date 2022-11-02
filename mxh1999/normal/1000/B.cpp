#include<bits/stdc++.h>
using namespace std;

const int maxn=100010;
int a[maxn];
int ans;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=2;i<=n+1;i++)
		scanf("%d",&a[i]);
	a[1]=0;
	a[n+2]=m;
	n+=2;
	for (int i=2;i<=n;i+=2)
		ans+=a[i]-a[i-1];
	int now=ans;
	for (int i=n;i>=2;i--)
	{
		int ha=a[i]-a[i-1];
		if (ha!=1)
		{
			if (i&1)	ans=max(ans,now+ha-1);else ans=max(ans,now-1);
		}
		if (i&1)	now+=ha;else now-=ha;
	}
	printf("%d\n",ans);
	return 0;
}