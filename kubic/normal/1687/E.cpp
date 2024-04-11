#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define pb push_back
const int INF=1e9;
int n,a[N],w[N],p[N],vs[N],mn1[N],mn2[N],ps1[N],ps2[N];
int x1,x2,ans,cnt[N],st[N];bool fl,vs1[N];vector<int> vc[N];
void sieve(int n)
{
	for(int i=2;i<=n;++i)
	{
		if(!vs[i]) p[vs[i]=++p[0]]=i;
		for(int j=1;i*p[j]<=n;++j)
		{vs[i*p[j]]=j;if(!(i%p[j])) break;}
	}
}
void ins(int x,int y,int w,bool fl=1)
{
	if(w<mn1[x]) mn2[x]=mn1[x],ps2[x]=ps1[x],mn1[x]=w,ps1[x]=y;
	else if(w<mn2[x]) mn2[x]=w,ps2[x]=y;if(fl) vc[x].pb(y);
}
int main()
{
	scanf("%d",&n);sieve(1e6);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=p[0];++i) mn1[i]=mn2[i]=INF;
	for(int i=1,lst=0,nw=0;i<=n;++i,lst=nw=0)
	{
		for(int j=a[i];j>1;j/=p[vs[j]])
		{if(vs[j]!=lst) ins(lst,i,nw),lst=vs[j],nw=0,++w[i];++nw;}
		ins(lst,i,nw);
	}
	for(int i=1;i<=p[0];++i) for(int j=1,t=0;j<=n;++j)
	{
		while(t<vc[i].size() && vc[i][t]<j) ++t;
		if(t==vc[i].size() || j!=vc[i][t]) ins(i,j,0,0);
		if(!mn2[i]) break;
	}
	for(int i=1;i<=p[0];++i)
	{
		if(mn1[i]) {x1=ps1[i];x2=ps2[i];break;}else if(mn2[i])
		{if(x1 && x1!=ps2[i]) {x2=ps2[i];break;}else x1=ps2[i];}
	}if(!x1) {printf("0\n");return 0;}
	if(!x2)
	{
		if(w[x1]<7) {for(int i=1;i<=n;++i) if(i!=x1) {x2=i;break;}}
		else for(int i=1;i<=n;++i) if(w[i]<7) {x2=i;break;}
	}vs1[x1]=vs1[x2]=1;
	for(int i=a[x1],lst=0;i>1;i/=p[vs[i]])
		if(vs[i]!=lst) ++cnt[vs[i]],lst=vs[i];
	for(int i=a[x2],lst=0;i>1;i/=p[vs[i]])
		if(vs[i]!=lst) ++cnt[vs[i]],lst=vs[i];
	for(int i=1;i<=p[0];++i)
	{
		if(cnt[i]>1) {vs1[ps1[i]]=vs1[ps2[i]]=1;continue;}
		if(cnt[i])
		{
			if(mn2[i]) vs1[ps2[i]]=1;
			else vs1[ps2[i]==x1 || ps2[i]==x2?ps1[i]:ps2[i]]=1;
		}
	}for(int i=1;i<=n;++i) if(vs1[i]) st[++st[0]]=i;
	for(int i=1,t;i<1<<st[0];++i)
	{t=__builtin_popcount(i);if(t>2) ans+=t-2;}ans+=st[0];
	printf("%d\n",ans);
	for(int i=1,t;i<1<<st[0];++i)
	{
		t=__builtin_popcount(i);
		for(int j=1;j<t-1;++j)
		{
			printf("%d %d ",t&1,t);
			for(int k=1;k<=st[0];++k) if(i>>k-1&1)
				printf("%d ",st[k]);putchar('\n');
		}
	}for(int i=1;i<=st[0];++i) printf("%d %d %d\n",0,1,st[i]);
	return 0;
}