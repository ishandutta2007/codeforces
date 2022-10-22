#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=100000+5,MaxTr=2000000+5,Limit=(1<<17),Infinity=((1<<30)-1);
struct Vertex
{
	char w;
	int dep,Fa,siz,cnt;
	int Inn,Li,top,bot;
	int Root,Zeta;
	int Alph,Beta;
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
inline void Dfs_Basics(const int u)
{
	int v;
	vt[u].siz=1;
	for(int e=vt[u].head;e;e=ed[e].next)
	{
		if((v=ed[e].v)==vt[u].Fa)
			continue;
		vt[v].dep=(vt[u].dep+1);
		vt[v].Fa=u,Dfs_Basics(v);
		vt[u].siz+=vt[v].siz,++vt[u].cnt;
		if(vt[v].siz>vt[vt[u].Li].siz)
			vt[u].Li=v;
	}
}
int Overall_Inn;
inline void Dfs_Advanced(const int u)
{
	int v;
	vt[u].Inn=(++Overall_Inn);
	if(!vt[u].Li)
		{vt[vt[u].top].bot=u;return;}
	vt[vt[u].Li].top=vt[u].top,Dfs_Advanced(vt[u].Li);
	for(int e=vt[u].head;e;e=ed[e].next)
	{
		if((v=ed[e].v)==vt[u].Fa||v==vt[u].Li)
			continue;
		vt[v].top=v,Dfs_Advanced(v);
	}
}
mt19937 mt_rand(time(NULL));
struct FHQ_Treap
{
	struct Treap_Node
	{
		int Zeta;
		unsigned Rand;
		int siz;
		int ch[2];
	};
	Treap_Node tr[MaxTr];
	int Overall_Tr;
	inline int New_Node(const int Zeta)
	{
		const int x=(++Overall_Tr);
		tr[x].Zeta=Zeta;
		tr[x].Rand=mt_rand();
		tr[x].siz=1;
		return x;
	}
	inline void push_up(const int x)
		{tr[x].siz=((tr[tr[x].ch[0]].siz+tr[tr[x].ch[1]].siz)+1);}
	inline int Merge(const int x,const int y)
	{
		if(!x) return y;
		if(!y) return x;
		if(tr[x].Rand<=tr[y].Rand)
			{tr[x].ch[1]=Merge(tr[x].ch[1],y),push_up(x);return x;}
		else
			{tr[y].ch[0]=Merge(x,tr[y].ch[0]),push_up(y);return y;}
	}
	inline void Split(const int z,const int Zeta,int &x,int &y)
	{
		if(!z){x=y=0;return;}
		if(tr[z].Zeta<=Zeta)
			x=z,Split(tr[x].ch[1],Zeta,tr[x].ch[1],y);
		else
			y=z,Split(tr[y].ch[0],Zeta,x,tr[y].ch[0]);
		push_up(z);
	}
	inline void Insert(int &Root,const int Zeta)
	{
		int x,y;
		Split(Root,Zeta,x,y);
		Root=Merge(Merge(x,New_Node(Zeta)),y);
	}
	inline void Delete(int &Root,const int Zeta)
	{
		int x,y,z;
		Split(Root,Zeta,x,z);
		Split(x,Zeta-1,x,y);
		Root=Merge(Merge(x,(y=Merge(tr[y].ch[0],tr[y].ch[1]))),z);
	}
	inline int Query(const int x,const int Goal)
	{
		if(Goal<=tr[tr[x].ch[0]].siz)
			return Query(tr[x].ch[0],Goal);
		else if(Goal==(tr[tr[x].ch[0]].siz+1))
			return tr[x].Zeta;
		else //if(Goal>=(tr[tr[x].ch[0]].siz+2))
			return Query(tr[x].ch[1],(Goal-(tr[tr[x].ch[0]].siz+1)));
	}
	inline int Query_Bust(const int Root,const int Goal)
	{
		if(Goal<=0)
			return (-Infinity);
		if(Goal>=(tr[Root].siz+1))
			return (+Infinity);
		return Query(Root,Goal);
	}
};
FHQ_Treap Tr;
struct Group_Element
	{int Alph,Beta;};
Group_Element arr[MaxN];
inline Group_Element operator * (const Group_Element Ele_0,const Group_Element Ele_1)
{
	Group_Element Ele_2;
	Ele_2.Alph=min(max(Ele_0.Alph,Ele_1.Alph),Ele_1.Beta);
	Ele_2.Beta=min(max(Ele_0.Beta,Ele_1.Alph),Ele_1.Beta);
	return Ele_2;
}
struct Zkw_Segment_Tree
{
	struct Tree_Node
		{Group_Element Ele;};
	Tree_Node tr[(Limit<<1)|5];
	inline void push_up(const int x)
	{
		const int Lch=(x<<1),Rch=(Lch|1);
		tr[x].Ele=(tr[Rch].Ele*tr[Lch].Ele);
	}
	inline void Initalize(const int n)
	{
		rep(i,0,Limit-1)
			tr[Limit|i].Ele=(Group_Element){(-Infinity),(+Infinity)};
		rep(i,1,n)
			tr[Limit|i].Ele=arr[i];
		dow(i,Limit-1,1)
			push_up(i);
	}
	inline void Modify(const int pos,const Group_Element Ele)
	{
		int x=(Limit|pos);
		tr[x].Ele=Ele;
		while(x>>=1) push_up(x);
	}
	inline Group_Element Query(const int lef,const int rig)
	{
		Group_Element Prefix=(Group_Element){(-Infinity),(+Infinity)};
		Group_Element Suffix=(Group_Element){(-Infinity),(+Infinity)};
		for(int x=(Limit|(lef-1)),y=(Limit|(rig+1));x^y^1;x>>=1,y>>=1)
		{
			if(~x&1) Prefix=(tr[x^1].Ele*Prefix);
			if( y&1) Suffix=(Suffix*tr[y^1].Ele);
		}
		return (Suffix*Prefix);
	}
};
Zkw_Segment_Tree St;
inline void Dfs_Initalize(const int u)
{
	int v;
	if(!vt[u].Li)
	{
		if(vt[u].w=='0')
			vt[u].Alph=vt[u].Beta=vt[u].Zeta=(-Infinity);
		else //if(vt[u].w=='1')
			vt[u].Alph=vt[u].Beta=vt[u].Zeta=(+Infinity);
		arr[vt[u].Inn]=(Group_Element){vt[u].Alph,vt[u].Beta};
		return;
	}
	for(int e=vt[u].head;e;e=ed[e].next)
	{
		if((v=ed[e].v)==vt[u].Fa)
			continue;
		Dfs_Initalize(v),Tr.Insert(vt[u].Root,vt[v].Zeta);
	}
	vt[u].Zeta=(vt[u].cnt+1);
	while(Tr.Query_Bust(vt[u].Root,(((vt[u].cnt-(vt[u].Zeta-2))>>1)+1))<=(vt[u].Zeta-2))
		vt[u].Zeta-=2;
	Tr.Delete(vt[u].Root,vt[vt[u].Li].Zeta);
	vt[u].Alph=(vt[u].cnt+1);
	while(Tr.Query_Bust(vt[u].Root,((vt[u].cnt-(vt[u].Alph-2))>>1))<=(vt[u].Alph-2))
		vt[u].Alph-=2;
	vt[u].Beta=(vt[u].cnt+1);
	while(Tr.Query_Bust(vt[u].Root,(((vt[u].cnt-(vt[u].Beta-2))>>1)+1))<=(vt[u].Beta-2))
		vt[u].Beta-=2;
	arr[vt[u].Inn]=(Group_Element){vt[u].Alph,vt[u].Beta};
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,q,k;
	cin>>n>>k;
	int u,v,w;
	rep(i,2,n)
		cin>>u>>v,Ins_Edge(u,v);
	const int Tree_Root=1;
	vt[Tree_Root].dep=1,Dfs_Basics(Tree_Root);
	vt[Tree_Root].top=Tree_Root,Dfs_Advanced(Tree_Root);
	rep(i,1,n)
		if((cin>>w),(w!=(-1))) vt[i].w=(w?'1':'0');
	Dfs_Initalize(Tree_Root);
	St.Initalize(n);
	cin>>q;
	char cmd;
	while(q--)
	{
		cin>>cmd;
		if(cmd=='1')
		{
			cin>>u,v=vt[u].top;
			const Group_Element Ele=St.Query(vt[u].Inn,vt[vt[v].bot].Inn);
			cout<<((k>=Ele.Alph)?'0':'1')<<'\n';
		}
		else if(cmd=='2')
		{
			cin>>u>>w,vt[u].w=(w?'1':'0');
			if(vt[u].w=='0')
				vt[u].Alph=vt[u].Beta=vt[u].Zeta=(-Infinity);
			else //if(vt[u].w=='1')
				vt[u].Alph=vt[u].Beta=vt[u].Zeta=(+Infinity);
			St.Modify(vt[u].Inn,((Group_Element){vt[u].Alph,vt[u].Beta}));
			const int u_Org=u;
			while(u)
			{
				if((v=vt[u].top)!=Tree_Root)
					Tr.Delete(vt[vt[v].Fa].Root,vt[v].Zeta);
				vt[v].Zeta=St.Query(vt[v].Inn,vt[vt[v].bot].Inn).Alph;
				if(v!=Tree_Root)
				{
					Tr.Insert(vt[vt[v].Fa].Root,vt[v].Zeta);
					if(vt[u_Org].w=='0')
					{
						if(Tr.Query_Bust(vt[vt[v].Fa].Root,
							((vt[vt[v].Fa].cnt-(vt[vt[v].Fa].Alph-2))>>1))<=(vt[vt[v].Fa].Alph-2))
							vt[vt[v].Fa].Alph-=2;
						if(Tr.Query_Bust(vt[vt[v].Fa].Root,
							(((vt[vt[v].Fa].cnt-(vt[vt[v].Fa].Beta-2))>>1)+1))<=(vt[vt[v].Fa].Beta-2))
							vt[vt[v].Fa].Beta-=2;
					}
					else //if(vt[u_Org].w=='1')
					{
						if(!(Tr.Query_Bust(vt[vt[v].Fa].Root,
							((vt[vt[v].Fa].cnt-vt[vt[v].Fa].Alph)>>1))<=vt[vt[v].Fa].Alph))
							vt[vt[v].Fa].Alph+=2;
						if(!(Tr.Query_Bust(vt[vt[v].Fa].Root,
							(((vt[vt[v].Fa].cnt-vt[vt[v].Fa].Beta)>>1)+1))<=vt[vt[v].Fa].Beta))
							vt[vt[v].Fa].Beta+=2;
					}
					St.Modify(vt[vt[v].Fa].Inn,((Group_Element){vt[vt[v].Fa].Alph,vt[vt[v].Fa].Beta}));
				}
				u=vt[v].Fa;
			}
		}
		else //if(cmd=='3')
			cin>>k;
	}
	return 0;
}