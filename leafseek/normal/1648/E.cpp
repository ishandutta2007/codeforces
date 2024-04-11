#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=400000+5,MaxM=400000+5,Bit=18;
struct ConnectionSet
{
	int Fa[MaxN];
	inline void Initalize(const int n)
	{
		rep(i,1,n) Fa[i]=i;
	}
	inline int getf(const int u)
	{
		if(u!=Fa[u])
			Fa[u]=getf(Fa[u]);
		return Fa[u];
	}
	inline bool Merge(const int u,const int v)
	{
		const int Fu=getf(u),Fv=getf(v);
		if(Fu==Fv) return false;
		return ((Fa[Fv]=Fu),true);
	}
};
ConnectionSet Con_0,Con_1;
struct Vertex
{
	int dep;
	int Fa,Rev;
	int Anc[Bit+1];
	int Max[Bit+1];
	vector<int> vec;
	int head;
};
Vertex vt[MaxN];
vector<int> Lit[MaxN];
struct Edge
{
	int u,v;
	int w;
	int next;
};
Edge ed[MaxN<<1];
int Overall_Ed=1;
inline void Ins_edge(const int u,const int v,const int w)
{
	const int Ed=(++Overall_Ed);
	ed[Ed].u=u,ed[Ed].v=v,ed[Ed].w=w;
	ed[Ed].next=vt[u].head,vt[u].head=Ed;
}
inline void Ins_Edge(const int u,const int v,const int w)
{
	Ins_edge(u,v,w),Ins_edge(v,u,w);
}
struct Link
{
	int idx;
	int u,v;
	int w;
	inline bool operator < (const Link &other) const
	{
		return (w<other.w);
	}
};
Link li[MaxM];
inline void Merge(vector<int> &t_0,vector<int> &t_1)
{
	if(t_0[0]<t_1[0]) swap(t_0,t_1);
	rep(i,1,t_1[0])
		++t_0[0],t_0.push_back(t_1[i]);
	t_1.clear(),t_1.push_back(0);
}
inline void Dfs(const int u)
{
	vt[u].Anc[0]=vt[u].Fa,vt[u].Max[0]=vt[u].Rev;
	rep(I,1,Bit)
	{
		vt[u].Anc[I]=vt[vt[u].Anc[I-1]].Anc[I-1];
		vt[u].Max[I]=max(vt[u].Max[I-1],vt[vt[u].Anc[I-1]].Max[I-1]);
	}
	int v,w;
	for(int e=vt[u].head;e;e=ed[e].next)
	{
		v=ed[e].v,w=ed[e].w;
		if(v==vt[u].Fa) continue;
		vt[v].dep=(vt[u].dep+1);
		vt[v].Fa=u,vt[v].Rev=w,Dfs(v);
	}
}
inline int Query(int u,int v)
{
	if(vt[u].dep<vt[v].dep) swap(u,v);
	int Max=0;
	dow(I,Bit,0)
		if(vt[vt[u].Anc[I]].dep>=vt[v].dep)
			Max=max(Max,vt[u].Max[I]),u=vt[u].Anc[I];
	if(u==v) return Max;
	dow(I,Bit,0)
		if(vt[u].Anc[I]!=vt[v].Anc[I])
		{
			Max=max(Max,vt[u].Max[I]),u=vt[u].Anc[I];
			Max=max(Max,vt[v].Max[I]),v=vt[v].Anc[I];
		}
	return max(Max,max(vt[u].Rev,vt[v].Rev));
}
set<pair<int,int>> Set;
int Answer[MaxN],Next[MaxN],arr[MaxN],arr2[MaxN];
vector<int> new_vec;
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m,Con_0.Initalize(n),Overall_Ed=1;
		rep(i,1,n) vt[i].vec.clear(),vt[i].vec.push_back(0),vt[i].head=0;
		rep(i,1,n) Lit[i].clear(),Lit[i].push_back(0);
		rep(i,1,n)
		{
			++vt[i].vec[0],vt[i].vec.push_back(i);
			++Lit[i][0],Lit[i].push_back(i);
		}
		Set.clear();
		int u,v,w;
		rep(i,1,m)
		{
			li[i].idx=i,cin>>u>>v>>w,li[i].u=u,li[i].v=v,li[i].w=w;
			Set.insert(make_pair(u,v)),Set.insert(make_pair(v,u));
		}
		sort(li+1,li+m+1);
		rep(I,1,m)
		{
			u=li[I].u,v=li[I].v,w=li[I].w;
			const int Fu=Con_0.getf(u),Fv=Con_0.getf(v);
			//if(I==2)
			//	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
			if(Fu==Fv) continue;
			Con_0.Fa[Fv]=Fu;
			Con_1.Initalize(vt[Fu].vec[0]+vt[Fv].vec[0]);
			arr[0]=0; rep(i,1,vt[Fv].vec[0]) arr[++arr[0]]=i;
			rep(i,1,vt[Fu].vec[0])
			{
				const int idx_i=vt[Fu].vec[i];
				bool Flag_1=true;
				arr2[0]=0;
				int Miu;
				rep(J,1,arr[0])
				{
					const int j=arr[J];
					const int idx_j=vt[Fv].vec[j];
					bool Flag=false;
					rep(p,1,Lit[idx_i][0])
					{
						const int U=Lit[idx_i][p];
						rep(q,1,Lit[idx_j][0])
						{
							const int V=Lit[idx_j][q];
							if(Set.find(make_pair(U,V))==Set.end())
								{Flag=true;break;}
						}
						if(Flag) break;
					}
					if(Flag)
					{
						if(Flag_1)
							Miu=arr2[++arr2[0]]=j,Flag_1=false;
						else
							Merge(Lit[vt[Fv].vec[Miu]],Lit[idx_j]);
						Con_1.Merge(i,j+vt[Fu].vec[0]);
					}
					else arr2[++arr2[0]]=j;
				}
				swap(arr[0],arr2[0]);
				rep(y,1,arr2[0]) arr[y]=arr2[y];
			}
			rep(i,1,vt[Fu].vec[0]+vt[Fv].vec[0])
			{
				if(Con_1.getf(i)==i) continue;
				const int F=Con_1.getf(i),G=i;
				const int FF=((F<=vt[Fu].vec[0])?vt[Fu].vec[F]:vt[Fv].vec[F-vt[Fu].vec[0]]);
				const int GG=((G<=vt[Fu].vec[0])?vt[Fu].vec[G]:vt[Fv].vec[G-vt[Fu].vec[0]]);
				Ins_Edge(FF,GG,w),Merge(Lit[FF],Lit[GG]);
				//printf("Ins_Edge (%2d , %2d) with [%3d]\n",FF,GG,w);
			}
			new_vec.clear(),new_vec.push_back(0);
			rep(i,1,vt[Fu].vec[0]+vt[Fv].vec[0])
			{
				if(Con_1.getf(i)!=i) continue;
				const int II=((i<=vt[Fu].vec[0])?vt[Fu].vec[i]:vt[Fv].vec[i-vt[Fu].vec[0]]);
				++new_vec[0],new_vec.push_back(II);
			}
			vt[Fu].vec=new_vec,vt[Fv].vec.clear(),vt[Fv].vec.push_back(0);
		}
		const int R=1;
		vt[R].dep=1,Dfs(R);
		rep(i,1,m)
		{
			u=li[i].u,v=li[i].v;
			Answer[li[i].idx]=Query(u,v);
		}
		rep(i,1,n) vt[i].vec.clear(),vt[i].vec.push_back(0),vt[i].head=0;
		rep(i,1,n) Lit[i].clear(),Lit[i].push_back(0);
		rep(i,1,m) cout<<Answer[i]<<' '; cout<<'\n';
	}
	return 0;
}