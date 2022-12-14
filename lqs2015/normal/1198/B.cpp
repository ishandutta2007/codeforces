#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,a[222222],b[222222],mx[222222],q,x,y,z,tp,lst[222222],val[222222],cnt,pos[222222],pp;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&q);
	for (int i=1;i<=n;i++) val[i]=a[i];
	for (int i=1;i<=q;i++)
	{
		scanf("%d",&tp);
		if (tp==1)
		{
			scanf("%d%d",&x,&y);
			lst[x]=i;val[x]=y;
		}
		else
		{
			scanf("%d",&x);cnt++;
			pos[cnt]=i;b[cnt]=x;
		}
	}
	for (int i=cnt;i>=1;i--) mx[i]=max(mx[i+1],b[i]);
	for (int i=1;i<=n;i++)
	{
		pp=lower_bound(pos+1,pos+cnt+1,lst[i])-pos;
		printf("%d ",max(mx[pp],val[i]));
	}
	printf("\n");
	return Accepted;
}