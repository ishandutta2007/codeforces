#include <bits/stdc++.h>
using namespace std;
#define N 505
#define pb push_back
int n,m,w,ans,q[N],dst[N],pr[N],st[N];
bool vs[N];vector<int> e[N];
void slv(int x,int y)
{
	int t[2]={(y-x+m)/2,(x-y+m)/2};printf("? ",x,y);
	for(int i=1;i<=n;++i) if(t[vs[i]])
		--t[vs[i]],vs[i]^=1,printf("%d ",i);
	fflush(stdout);scanf("%d",&w),ans^=w;
}
int main()
{
	scanf("%d %d",&n,&m);q[0]=q[1]=2;
	for(int i=1;i<=n;++i) dst[i]=-1;
	for(int i=0;i<=n;++i)
		for(int j=max(m-n+i,0);j<=min(m,i);++j)
			e[i].pb(m+i-j*2);
	while(q[0]<=q[1])
	{
		int u=q[q[0]++];
		for(auto v:e[u]) if(dst[v]==-1)
			q[++q[1]]=v,dst[v]=dst[u]+1,pr[v]=u;
	}if(dst[n]==-1) {puts("-1");return 0;}
	for(int i=n;i;i=pr[i]) st[++st[0]]=i;
	slv(0,st[st[0]]);
	for(int i=st[0];i>1;--i) slv(st[i],st[i-1]);
	printf("! %d\n",ans);return 0;
}