#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=1000000+5;
struct dsu
{
	int fa[MaxN<<1];
	inline void init(const int n)
	{
		rep(i,1,n) fa[i]=i;
	}
	inline int getf(const int u)
	{
		if(u!=fa[u])
			fa[u]=getf(fa[u]);
		return fa[u];
	}
	inline void merge(const int u,const int v)
	{
		const int fu=getf(u),fv=getf(v);
		if(fu!=fv) fa[fv]=fu;
	}
};
dsu Con;
struct Edge
{
	int u,v;
	int w;
};
Edge ed[MaxN];
int a[MaxN],b[MaxN];
bool S[MaxN],ok[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n,q;
	while(T--)
	{
		cin>>n>>q,Con.init(n<<1);
		int u,v,w;
		rep(i,1,n) a[i]=i;
		rep(i,1,n) b[i]=(n+i);
		rep(i,2,n)
		{
			cin>>u>>v>>w;
			ed[i].u=u,ed[i].v=v;
			ed[i].w=w;
			if(ed[i].w!=(-1))
			{
				if(__builtin_parity(ed[i].w))
				{
					Con.merge(a[u],b[v]);
					Con.merge(b[u],a[v]);
				}
				else
				{
					Con.merge(a[u],a[v]);
					Con.merge(b[u],b[v]);
				}
			}
		}
		while(q--)
		{
			cin>>u>>v>>w;
			if(w)
			{
				Con.merge(a[u],b[v]);
				Con.merge(b[u],a[v]);
			}
			else
			{
				Con.merge(a[u],a[v]);
				Con.merge(b[u],b[v]);
			}
		}
		rep(i,1,n<<1) ok[i]=false;
		bool Flag=true;
		rep(i,1,n)
		{
			if(Con.getf(a[i])==Con.getf(b[i]))
			{
				Flag=false;
				break;
			}
		}
		if(!Flag)
		{
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		rep(i,1,n)
		{
			u=a[i],v=b[i];
			const int x=Con.getf(u),y=Con.getf(v);
			if(ok[x])
				continue;
			ok[x]=true;
			if(ok[y])
			{
				S[x]=(!S[y]);
				continue;
			}
			S[x]=false;
			S[y]=true;
			ok[y]=true;
		}
		rep(i,1,n)
			S[i]=S[Con.getf(i)];
		rep(i,2,n)
		{
			u=ed[i].u,v=ed[i].v,w=ed[i].w;
			if(w==(-1))
				w=(S[u]^S[v]);
			cout<<u<<' '<<v<<' '<<w<<'\n';
		}
	}
	return 0;
}