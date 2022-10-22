#include<bits/stdc++.h>
#define sit set<Seg>::iterator
using namespace std;
const int maxn=510000;
struct Seg
{
	int l,r,id;
	Seg(int L=0,int R=0,int ID=0):l(L),r(R),id(ID){}
	bool operator < (const Seg &a) const
	{
		return r<a.r;
	}
};
int n;
int l[maxn],r[maxn],id[maxn];
int fa[maxn];
set<Seg> s;
int find(int x)
{
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void mer(int u,int v)
{
	u=find(u),v=find(v);
	if(u==v) return;
	fa[u]=v;
	return;
}
int cmp(int a,int b)
{
	return l[a]<l[b];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		id[i]=i;
	}
	sort(id+1,id+n+1,cmp);
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		sit it1=s.lower_bound(Seg(-1,l[id[i]],-1));
		sit it2=s.upper_bound(Seg(-1,r[id[i]],-1));
		for(sit it=it1;it!=it2;it++)
		{
			int u=it->id,v=id[i];
			if(find(u)==find(v)) 
			{
				ans=1;
				break;
			}
			mer(u,v);
			cnt++;
		}
		if(ans) break;
		s.insert(Seg(l[id[i]],r[id[i]],id[i]));
	}
	if(ans) printf("NO\n");
	else
	{
		if(cnt==n-1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}