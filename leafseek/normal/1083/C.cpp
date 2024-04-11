#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=200000+5,Log_Limit=18,Limit=(1<<Log_Limit),Infinity=((1<<30)-1);
struct Vertex
{
	int wei;
	int dep,Fa;
	int Inn,Out;
	int head;
};
Vertex vt[MaxN];
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
int Euler[MaxN<<1];
inline void Dfs_Basics(const int u)
{
	int v;
	Euler[vt[u].Inn=vt[u].Out=(++Euler[0])]=u;
	for(int e=vt[u].head;e;e=ed[e].next)
	{
		if((v=ed[e].v)==vt[u].Fa)
			continue;
		vt[v].dep=(vt[u].dep+1);
		vt[v].Fa=u,Dfs_Basics(v);
		Euler[vt[u].Out=(++Euler[0])]=u;
	}
}
inline bool Is_Ancestor(const int u,const int v)
	{return ((vt[u].Inn<=vt[v].Inn)&&(vt[v].Out<=vt[u].Out));}
inline int Compare_0(const int u,const int v)
	{return ((vt[u].dep<=vt[v].dep)?u:v);}
inline int Compare_1(const int u,const int v)
	{return ((vt[u].dep>=vt[v].dep)?u:v);}
struct Sparse_Table_List
{
	int Log_2[MaxN<<1],Min[Log_Limit+1][MaxN<<1];
	inline void Initalize(const int Len)
	{
		Log_2[0]=(-1);
		rep(i,1,Len)
			Log_2[i]=(Log_2[i>>1]+1);
		rep(i,1,Len)
			Min[0][i]=Euler[i];
		rep(Lvl,1,Log_Limit)
			rep(i,1,Len-(1<<Lvl)+1)
				Min[Lvl][i]=Compare_0(Min[Lvl-1][i],Min[Lvl-1][i+(1<<(Lvl-1))]);
	}
	inline int Query(const int beg,const int end)
	{
		const int Lvl=Log_2[end-beg+1];
		return Compare_0(Min[Lvl][beg],Min[Lvl][end-(1<<Lvl)+1]);
	}
};
Sparse_Table_List List;
inline int Get_Lca(const int u,const int v)
{
	if(vt[u].Inn<=vt[v].Inn)
		return List.Query(vt[u].Inn,vt[v].Inn);
	else
		return List.Query(vt[v].Inn,vt[u].Inn);
}
struct Group_Element
{
	char Flag;
	int u,v,Lca;
};
inline Group_Element operator * (const Group_Element &Ele_0,const Group_Element &Ele_1)
{
	if(Ele_0.Flag=='E'||Ele_1.Flag=='.')
		return Ele_1;
	if(Ele_0.Flag=='.'||Ele_1.Flag=='E')
		return Ele_0;
	if(Ele_0.Flag=='0'&&Ele_1.Flag=='0')
	{
		if(Is_Ancestor(Ele_0.v,Ele_1.v))
			return (Group_Element){'0',Compare_0(Ele_0.u,Ele_1.u),Ele_1.v,0};
		if(Is_Ancestor(Ele_1.v,Ele_0.v))
			return (Group_Element){'0',Compare_0(Ele_0.u,Ele_1.u),Ele_0.v,0};
		const int Lca_u=Get_Lca(Ele_0.u,Ele_1.u),Lca_v=Get_Lca(Ele_0.v,Ele_1.v);
		if(Is_Ancestor(Ele_0.u,vt[Lca_v].Fa)||Is_Ancestor(Ele_1.u,vt[Lca_v].Fa))
			return (Group_Element){'.',0,0,0};
		return (Group_Element){'1',Ele_0.v,Ele_1.v,Lca_u};
	}
	else if(Ele_0.Flag=='0'&&Ele_1.Flag=='1')
	{
		if(!Is_Ancestor(Ele_1.Lca,Ele_0.u))
			return (Group_Element){'.',0,0,0};
		if(Is_Ancestor(Ele_0.v,Ele_1.u)||Is_Ancestor(Ele_1.u,Ele_0.v))
			return (Group_Element){'1',Compare_1(Ele_0.v,Ele_1.u),Ele_1.v,Ele_1.Lca};
		else if(Is_Ancestor(Ele_0.v,Ele_1.v)||Is_Ancestor(Ele_1.v,Ele_0.v))
			return (Group_Element){'1',Ele_1.u,Compare_1(Ele_0.v,Ele_1.v),Ele_1.Lca};
		return (Group_Element){'.',0,0,0};
	}
	else if(Ele_0.Flag=='1'&&Ele_1.Flag=='0')
	{
		if(!Is_Ancestor(Ele_0.Lca,Ele_1.u))
			return (Group_Element){'.',0,0,0};
		if(Is_Ancestor(Ele_0.u,Ele_1.v)||Is_Ancestor(Ele_1.v,Ele_0.u))
			return (Group_Element){'1',Compare_1(Ele_0.u,Ele_1.v),Ele_0.v,Ele_0.Lca};
		else if(Is_Ancestor(Ele_0.v,Ele_1.v)||Is_Ancestor(Ele_1.v,Ele_0.v))
			return (Group_Element){'1',Ele_0.u,Compare_1(Ele_0.v,Ele_1.v),Ele_0.Lca};
		return (Group_Element){'.',0,0,0};
	}
	else //if(Ele_0.Flag=='1'&&Ele_1.Flag=='1')
	{
		if(Ele_0.Lca!=Ele_1.Lca)
			return (Group_Element){'.',0,0,0};
		if((Is_Ancestor(Ele_0.u,Ele_1.u)||Is_Ancestor(Ele_1.u,Ele_0.u))&&
			(Is_Ancestor(Ele_0.v,Ele_1.v)||Is_Ancestor(Ele_1.v,Ele_0.v)))
			return (Group_Element){'1',Compare_1(Ele_0.u,Ele_1.u),Compare_1(Ele_0.v,Ele_1.v),Ele_0.Lca};
		else if((Is_Ancestor(Ele_0.u,Ele_1.v)||Is_Ancestor(Ele_1.v,Ele_0.u))&&
			(Is_Ancestor(Ele_0.v,Ele_1.u)||Is_Ancestor(Ele_1.u,Ele_0.v)))
			return (Group_Element){'1',Compare_1(Ele_0.u,Ele_1.v),Compare_1(Ele_0.v,Ele_1.u),Ele_0.Lca};
		return (Group_Element){'.',0,0,0};
	}
}
int arr[MaxN];
struct Zkw_Segment_Tree
{
	struct Tree_Node
		{Group_Element Ele;};
	Tree_Node tr[(Limit<<1)|5];
	inline void push_up(const int x)
	{
		const int Lch=(x<<1),Rch=(Lch|1);
		tr[x].Ele=(tr[Lch].Ele*tr[Rch].Ele);
	}
	inline void Initalize(const int n)
	{
		rep(i,1,(Limit<<1)-1)
			tr[i].Ele.Flag='.';
		rep(i,1,n)
		{
			const int u=arr[i];
			tr[Limit|i].Ele=(Group_Element){'0',u,u,u};
		}
		dow(i,Limit-1,1) push_up(i);
	}
	inline void Update(const int pos)
	{
		int x=(Limit|pos);
		while(x>>=1) push_up(x);
	}
	inline void Modify(const int pos,const int u)
	{
		const int x=(Limit|pos);
		tr[x].Ele=(Group_Element){'0',u,u,u};
		Update(pos);
	}
	inline int Locate(const int pos)
	{
		Group_Element Ele_0=(Group_Element){'E',0,0,0},Ele_1;
		for(int x=(Limit|(pos-1));x;x>>=1)
		{
			if(x&1) continue;
			Ele_1=(Ele_0*tr[x^1].Ele);
			if(Ele_1.Flag=='.')
			{
				x^=1;while(!(x&Limit))
				{
					const int Lch=(x<<1),Rch=(Lch|1);
					Ele_1=(Ele_0*tr[Lch].Ele);
					((Ele_1.Flag=='.')?(x=Lch):(Ele_0=Ele_1,x=Rch));
				}
				return ((x^Limit)-1);
			}
			else Ele_0=Ele_1;
		}
	}
};
Zkw_Segment_Tree St;
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,q;
	cin>>n;
	rep(i,1,n)
		cin>>vt[i].wei,arr[++vt[i].wei]=i;
	int u,v;
	rep(i,2,n)
		cin>>u,Ins_Edge(u,i);
	vt[0].Inn=(-Infinity),vt[0].Out=(+Infinity);
	const int Tree_Root=1;
	Dfs_Basics(Tree_Root);
	List.Initalize(Euler[0]);
	St.Initalize(n);
	cin>>q;
	char cmd;
	while(q--)
	{
		cin>>cmd;
		if(cmd=='1')
		{
			cin>>u>>v;
			swap(vt[u].wei,vt[v].wei);
			St.Modify(vt[u].wei,u);
			St.Modify(vt[v].wei,v);
		}
		else //if(cmd=='2')
			cout<<St.Locate(1)<<'\n';
	}
	return 0;
}