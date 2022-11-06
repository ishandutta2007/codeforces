#include<bits/stdc++.h>
using namespace std;
#define re register
int n,m,x[2001000],f[200100],p[200100],q[200100],ans[200100],k[200100],pos[200100];
inline bool cmp(re int a,re int b){return x[a]==x[b]?a<b:x[a]>x[b];}
inline bool cmp1(re int a,re int b){return k[a]<k[b];}
void add(re int a)
{
	for(;a<=n;a+=a&-a)f[a]++;
}
int qus(re int a)
{
	re int ans=0;
	for(;a;a-=a&-a)ans+=f[a];
	return ans;
}
int main()
{
	re int x1=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)scanf("%d",&x[i]),p[i]=i;
	sort(p+1,p+n+1,cmp);
	scanf("%d",&m);
	for(re int i=1;i<=m;i++)scanf("%d%d",&k[i],&pos[i]),q[i]=i;
	sort(q+1,q+m+1,cmp1);
	for(re int i=1;i<=m;i++)
	{
		re int xx=q[i];
		while(x1<k[xx])add(p[++x1]);
		re int l=1,r=n,mid;
		for(mid=(l+r)/2;l<r;mid=(l+r)/2)
		{
			if(qus(mid)<pos[xx])l=mid+1;
			else r=mid;
		}
		ans[xx]=x[mid];
	}
	for(re int i=1;i<=m;i++)printf("%d\n",ans[i]);
}