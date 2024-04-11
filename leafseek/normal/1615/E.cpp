#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=400000+5;
struct Vertex
{
	int dep,Fa;
	int Li,Hei;
	bool is_Leaf;
	int head;
};
Vertex vt[MaxN];
bitset<MaxN> Bitset;
struct Edge
{
	int u,v;
	int next;
};
Edge ed[MaxN<<1];
int Overall_Ed=1;
inline void Ins_edge(const int u,const int v)
{
	const int Ed=(++Overall_Ed);
	ed[Ed].u=u,ed[Ed].v=v;
	ed[Ed].next=vt[u].head;
	vt[u].head=Ed;
}
inline void Ins_Edge(const int u,const int v)
	{Ins_edge(u,v),Ins_edge(v,u);}
inline void Dfs_Basics(const int u)
{
	int v;
	vt[u].is_Leaf=true;
	for(int e=vt[u].head;e;e=ed[e].next)
	{
		if((v=ed[e].v)==vt[u].Fa)
			continue;
		vt[v].dep=(vt[u].dep+1);
		vt[v].Fa=u,Dfs_Basics(v);
		vt[u].is_Leaf=false;
		if(vt[vt[v].Li].dep>vt[vt[u].Li].dep)
			vt[u].Li=vt[v].Li;
	}
	if(vt[u].is_Leaf)
		vt[u].Li=u;
	vt[u].Hei=(vt[vt[u].Li].dep-vt[u].dep+1);
}
struct Temporary_Node
{
	int u;
	inline bool operator < (const Temporary_Node other) const
		{return (vt[u].Hei<vt[other.u].Hei);}
};
priority_queue<Temporary_Node> Pri;
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	const int Limit=(n>>1);
	int u,v;
	rep(i,2,n)
		cin>>u>>v,Ins_Edge(u,v);
	const int Tree_Root=1;
	vt[Tree_Root].dep=1,Dfs_Basics(Tree_Root);
	int Cum_Leaf=0;
	rep(i,1,n) if(vt[i].is_Leaf)
		++Cum_Leaf;
	long long Answer;
	if(Cum_Leaf<=m)
	{
		if(Limit<=Cum_Leaf)
			Answer=((long long)(n-Cum_Leaf)*Cum_Leaf);
		else if(Limit<=m)
			Answer=((long long)(n-Limit)*Limit);
		else
			Answer=((long long)(n-m)*m);
	}
	else
	{
		int Record=0;
		Bitset[0]=true,Pri.push((Temporary_Node){Tree_Root});
		rep(I,1,m)
		{
			const int x=Pri.top().u;
			Record+=vt[x].Hei,u=vt[x].Li,Pri.pop();
			while(!Bitset[u])
			{
				Bitset[u]=true;
				for(int e=vt[u].head;e;e=ed[e].next)
				{
					if((v=ed[e].v)==vt[u].Fa)
						continue;
					if(!Bitset[v])
						Pri.push((Temporary_Node){v});
				}
				u=vt[u].Fa;
			}
		}
		Record=min(Limit,(n-Record));
		Answer=((long long)((n-m)-Record)*(m-Record));
	}
	cout<<Answer<<'\n';
	return 0;
}