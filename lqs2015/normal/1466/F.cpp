#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int mod=1e9+7;
int test,n,m,val[555555],pa[555555],ans,cnt,arr[555555],k,x,y,rx,ry;
int root(int x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) pa[i]=i;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if (k==1)
		{
			scanf("%d",&x);
			rx=root(x);
			if (val[rx]<1)
			{
				val[rx]++;
				arr[++cnt]=i;
			}
		}
		else
		{
			scanf("%d%d",&x,&y);
			rx=root(x);ry=root(y);
			if (rx==ry || val[rx]+val[ry]>1) continue;
			pa[rx]=ry;val[ry]+=val[rx];
			arr[++cnt]=i;
		}
	}
	ans=1;
	for (int i=1;i<=cnt;i++) ans=(ans+ans)%mod;
	printf("%d %d\n",ans,cnt);
	for (int i=1;i<=cnt;i++) printf("%d ",arr[i]);
	printf("\n");
	return Accepted;
}