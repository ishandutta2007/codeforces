#include<bits/stdc++.h>
using namespace std;
int n,p[444444],pos[444444],l,r,mid,sz;
long long bit1[444444],bit2[444444],ans1,ans2;
void update(int p,int x,long long bit[])
{
	while(p<=sz)
	{
		bit[p]+=x;
		p+=p&(-p);
	}
}
long long query(int p,long long bit[])
{
	long long res=0;
	while(p>=1)
	{
		res+=bit[p];
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++) pos[p[i]]=i;
	sz=1;
	while(sz<=n) sz<<=1;
	for (int i=1;i<=n;i++)
	{
		int ps=pos[i];
		ans1+=(query(n,bit1)-query(ps,bit1));
		update(ps,1,bit1);
		update(ps,ps,bit2);
		l=1;r=n;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if (query(mid,bit1)<(i+1)/2) l=mid+1;
			else r=mid-1;
		}
		int xx=query(l-1,bit1),yy=query(n,bit1)-query(l,bit1);
		ans2=1ll*l*xx-query(l-1,bit2)-1ll*xx*(xx+1)/2+query(n,bit2)-query(l,bit2)-1ll*l*yy-1ll*yy*(yy+1)/2;
		printf("%lld ",ans1+ans2);
	}
	printf("\n");
	return 0;
}