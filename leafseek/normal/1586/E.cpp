#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=700000+5,Bit=20;
struct Vertex
{
	int fa,dep;
	int Anc[Bit+1];
	bool tag;
	int head;
};
Vertex vt[MaxN];
struct Edge
{
	int u;
	int v;
	int next;
};
Edge ed[MaxN<<1];
inline void add_edge(const int u,const int v,const int pos)
{
	ed[pos].u=u;
	ed[pos].v=v;
	ed[pos].next=vt[u].head;
	vt[u].head=pos;
}
struct Connector
{
	int kk[MaxN];
	inline int getf(const int u)
	{
		if(u!=kk[u])
			kk[u]=getf(kk[u]);
		return kk[u];
	}
	inline void Merge(const int u,const int v)
	{
		const int fu=getf(u),fv=getf(v);
		if(fu!=fv)
			kk[fu]=fv;
	}
	inline bool Same(const int u,const int v)
	{
		return (getf(u)==getf(v));
	}
};
Connector Con;
inline void Dfs_Basics(const int u)
{
	vt[u].Anc[0]=vt[u].fa;
	rep(i,1,Bit)
		vt[u].Anc[i]=vt[vt[u].Anc[i-1]].Anc[i-1];
	int v;
	for(int e=vt[u].head;e;e=ed[e].next)
	{
		v=ed[e].v;
		if(v==vt[u].fa)
			continue;
		vt[v].dep=(vt[u].dep+1);
		vt[v].fa=u,Dfs_Basics(v);
	}
}
int xx[MaxN],yy[MaxN];
inline int Lca(int u,int v)
{
	if(vt[u].dep<vt[v].dep)
		return Lca(v,u);
	dow(i,Bit,0)
		if(vt[vt[u].Anc[i]].dep>=vt[v].dep)
			u=vt[u].Anc[i];
	if(u==v) return u;
	dow(i,Bit,0)
		if(vt[u].Anc[i]!=vt[v].Anc[i])
			u=vt[u].Anc[i],v=vt[v].Anc[i];
	return vt[u].fa;
}
int arr[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	rep(i,1,n) Con.kk[i]=i;
	int u,v,tot=0;
	rep(i,1,m)
	{
		cin>>u>>v;
		if(Con.Same(u,v)) continue;
		Con.Merge(u,v),add_edge(u,v,++tot),add_edge(v,u,++tot);
	}
	vt[1].dep=1;
	Dfs_Basics(1);
	int q;
	cin>>q;
	rep(i,1,q)
	{
		cin>>xx[i]>>yy[i];
		vt[xx[i]].tag^=true;
		vt[yy[i]].tag^=true;
	}
	int flag=0;
	rep(i,1,n)
		if(vt[i].tag)
			++flag;
	if(flag)
	{
		cout<<"NO"<<endl;
		cout<<(flag>>1)<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
		rep(i,1,q)
		{
			u=xx[i],v=yy[i];
			const int lca=Lca(u,v);
			const int siz=(vt[u].dep+vt[v].dep-(vt[lca].dep<<1))+1;
			arr[0]=0;
			while(u!=lca)
			{
				arr[++arr[0]]=u;
				u=vt[u].fa;
			}
			arr[++arr[0]]=lca;
			arr[0]=(siz+1);
			while(v!=lca)
			{
				arr[--arr[0]]=v;
				v=vt[v].fa;
			}
			cout<<siz<<'\n';
			rep(i,1,siz)
				cout<<arr[i]<<' ';
			cout<<'\n';
		}
	}
	return 0;
}