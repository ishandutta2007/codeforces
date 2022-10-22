#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define ll long long
#define pb push_back
int T,n,m,a[N],st[N],ds[N],cnt[N];ll ans;
map<int,int> vs[N];vector<int> vc[N];
void slv()
{
	scanf("%d %d",&n,&m);ans=ds[0]=st[0]=0;
	for(int i=1;i<=n;++i)
		vc[i].clear(),scanf("%d",&a[i]),ds[++ds[0]]=a[i];
	sort(ds+1,ds+ds[0]+1);ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	for(int i=1;i<=ds[0];++i) cnt[i]=0;
	for(int i=1;i<=n;++i)
	{
		a[i]=lower_bound(ds+1,ds+ds[0]+1,a[i])-ds;
		vs[a[i]].clear();vs[a[i]][a[i]]=1;++cnt[a[i]];
	}
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d %d",&u,&v);
		u=lower_bound(ds+1,ds+ds[0]+1,u)-ds;
		v=lower_bound(ds+1,ds+ds[0]+1,v)-ds;
		vs[u][v]=vs[v][u]=1;
	}for(int i=1;i<=ds[0];++i) if(cnt[i]) vc[cnt[i]].pb(i);
	for(int i=1;i<=n;++i) if(vc[i].size()) st[++st[0]]=i;
	for(int i=1;i<=st[0];++i)
	{
		reverse(vc[st[i]].begin(),vc[st[i]].end());
		for(auto j:vc[st[i]]) for(int i1=1;i1<=i;++i1)
			for(auto j1:vc[st[i1]]) if(!vs[j][j1])
			{ans=max(ans,1ll*(st[i]+st[i1])*(ds[j]+ds[j1]));break;}
	}printf("%lld\n",ans);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}