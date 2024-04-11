#include<bits/stdc++.h>
using namespace std;
const int magic=2000;
int n,m,q,x,y,a[111111],b[111111],id[111111],deg[111111],cnt,aa[111111],val[111111],cur,cnr,ncnr;
int head[111111],nxt[222222],to[222222];
int nhead[111111],nnxt[222222],nto[222222];
long long ans;
set<pair<int,int> > s[222];
set<pair<int,int> >::iterator it;
void addedge(int x,int y)
{
	++cnr;to[cnr]=y;
	nxt[cnr]=head[x];head[x]=cnr;
}
void addedgen(int x,int y)
{
	++ncnr;nto[ncnr]=y;
	nnxt[ncnr]=nhead[x];nhead[x]=ncnr;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y);addedge(y,x);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=head[i];j;j=nxt[j])
		{
			if (to[j]>i) a[i]++;
			else b[i]++;
		}
	}
	for (int i=1;i<=n;i++) val[i]=i;
	for (int i=1;i<=n;i++)
	{
		ans+=(1ll*a[i]*b[i]);
		for (int j=head[i];j;j=nxt[j]) deg[i]++;
	}
	for (int i=1;i<=n;i++)
	{
		if (deg[i]>=magic)
		{
			for (int j=head[i];j;j=nxt[j])
			{
				if (deg[to[j]]>=magic) addedgen(i,to[j]);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (deg[i]>=magic) 
		{
			++cnt;
			aa[cnt]=i;
			id[i]=cnt;
			for (int j=head[i];j;j=nxt[j])
			{
				s[cnt].insert(make_pair(-to[j],to[j]));
			}
		}
	}
	scanf("%d",&q);cur=n;
	printf("%lld\n",ans);
	while(q--)
	{
		scanf("%d",&x);cur++;
		ans-=(1ll*a[x]*b[x]);
		a[x]=0;b[x]=deg[x];
		if (deg[x]<magic)
		{
			for (int j=head[x];j;j=nxt[j])
			{
				if (val[to[j]]>val[x])
				{
					ans+=(b[to[j]]-a[to[j]]-1);
					a[to[j]]++;b[to[j]]--;
				}
				if (deg[to[j]]>=magic)
				{
					s[id[to[j]]].erase(s[id[to[j]]].find(make_pair(-val[x],x)));
					s[id[to[j]]].insert(make_pair(-cur,x));
				}
			}
		}
		else
		{
			int idd=id[x];
			for (it=s[idd].begin();it!=s[idd].end();it++)
			{
				if (-(it->first)<val[x]) break;
				int to=it->second;
				ans+=(b[to]-a[to]-1);
				a[to]++;b[to]--;
			}
			for (int j=nhead[x];j;j=nnxt[j])
			{
				s[id[nto[j]]].erase(s[id[nto[j]]].find(make_pair(-val[x],x)));
				s[id[nto[j]]].insert(make_pair(-cur,x));
			}
		}
		val[x]=cur;
		printf("%lld\n",ans);
	}
	return 0;
}