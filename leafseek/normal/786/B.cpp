#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5,MaxVt=800000+5,MaxEd=2000000+5,Empty=0,SegRoot=1;
const long long Inf=(1LL<<60)-1; 
struct GraphVertex
{
	bool conf;
	long long dis;
	int head;
};
GraphVertex vt[MaxVt];
struct GraphEdge
{
	int u;
	int v;
	int w;
	int next;
};
GraphEdge ed[MaxEd];
inline void add_edge(const register int u,const register int v,const register int w,const register int pos)
{
	ed[pos].u=u;
	ed[pos].v=v;
	ed[pos].w=w;
	ed[pos].next=vt[u].head;
	vt[u].head=pos;
}
struct CalculationNode
{
	int idx;
	long long dis;
	inline bool operator < (const CalculationNode& other) const
		{return (dis>other.dis);}
};
priority_queue<CalculationNode> pq;
inline void Dijkstra(const register int Class,const register int Source)
{
	rep(i,1,Class)
		vt[i].dis=((i==Source)?0:Inf);
	pq.push((CalculationNode){Source,vt[Source].dis});
	CalculationNode Now;
	register int u,v,w;
	while(!pq.empty())
	{
		Now=pq.top(),pq.pop();
		u=Now.idx;
		if(vt[u].conf)
			continue;
		vt[u].conf=true;
		for(register int e=vt[u].head;e;e=ed[e].next)
		{
			v=ed[e].v;
			w=ed[e].w;
			if((vt[u].dis+w)<vt[v].dis)
			{
				vt[v].dis=(vt[u].dis+w);
				pq.push((CalculationNode){v,vt[v].dis});
			}
		}
	}
}
struct SegmentTreeVertex
{
	int inn,out;
	int beg,end;
};
SegmentTreeVertex tr[MaxN<<2];
int OverallLen,Leaf[MaxN];
struct FunctionalSegmentTree
{
	int OverallDfn,OverallTot;
	inline int ls(const register int idx){return idx<<1;}
	inline int rs(const register int idx){return idx<<1|1;}
	inline void Build(const register int idx=SegRoot,const register int beg=1,const register int end=OverallLen)
	{
		tr[idx].beg=beg,tr[idx].end=end;
		if(beg==end)
		{
			Leaf[beg]=++OverallDfn;
			tr[idx].inn=tr[idx].out=Leaf[beg];
			return;
		}
		tr[idx].inn=++OverallDfn;
		tr[idx].out=++OverallDfn;
		add_edge(tr[idx].inn,tr[idx].out,Empty,++OverallTot);
		register int mid=(beg+end)>>1;
		Build(ls(idx),beg,mid);
		Build(rs(idx),mid+1,end);
		add_edge(tr[idx].inn,tr[ls(idx)].inn,Empty,++OverallTot);
		add_edge(tr[idx].inn,tr[rs(idx)].inn,Empty,++OverallTot);
		add_edge(tr[ls(idx)].out,tr[idx].out,Empty,++OverallTot);
		add_edge(tr[rs(idx)].out,tr[idx].out,Empty,++OverallTot);
	}
	inline void Initalize(const register int len)
		{OverallLen=len,Build();}
	inline void Connect(const register int from,const register int to,const register int wei)
		{add_edge(Leaf[from],Leaf[to],wei,++OverallTot);}
	inline void UpdateInner(const register int pit,const register int wei,
		const register int lef,const register int rig,const register int idx=SegRoot)
	{
		register int beg=tr[idx].beg,end=tr[idx].end;
		if(lef<=beg&&end<=rig)
		{
			add_edge(Leaf[pit],tr[idx].inn,wei,++OverallTot);
			return;
		}
		register int mid=(beg+end)>>1;
		if(lef<=mid)
			UpdateInner(pit,wei,lef,rig,ls(idx));
		if(rig>mid)
			UpdateInner(pit,wei,lef,rig,rs(idx));
	}
	inline void UpdateOuter(const register int pit,const register int wei,
		const register int lef,const register int rig,const register int idx=SegRoot)
	{
		register int beg=tr[idx].beg,end=tr[idx].end;
		if(lef<=beg&&end<=rig)
		{
			add_edge(tr[idx].out,Leaf[pit],wei,++OverallTot);
			return;
		}
		register int mid=(beg+end)>>1;
		if(lef<=mid)
			UpdateOuter(pit,wei,lef,rig,ls(idx));
		if(rig>mid)
			UpdateOuter(pit,wei,lef,rig,rs(idx));
	}
};
FunctionalSegmentTree St;
int main()
{
	register int n,m,Source;
	scanf("%d%d%d",&n,&m,&Source);
	St.Initalize(n);
	register int cmd,u,v,lef,rig,wei;
	while(m--)
	{
		scanf("%d",&cmd);
		if(cmd==1)
		{
			scanf("%d%d%d",&u,&v,&wei);
			St.Connect(u,v,wei);
		}
		else if(cmd==2)
		{
			scanf("%d%d%d%d",&u,&lef,&rig,&wei);
			St.UpdateInner(u,wei,lef,rig);
		}
		else //if(cmd==3)
		{
			scanf("%d%d%d%d",&u,&lef,&rig,&wei);
			St.UpdateOuter(u,wei,lef,rig);
		}
	}
	Dijkstra(St.OverallDfn,Leaf[Source]);
	rep(i,1,n)
	{
		if(vt[Leaf[i]].dis==Inf)
			printf("-1 ");
		else
			printf("%lld ",vt[Leaf[i]].dis);
	}
	printf("\n");
	return 0;
}