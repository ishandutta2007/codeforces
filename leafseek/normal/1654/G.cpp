#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=200000+5,Infinity=((1<<30)-1);
struct Vertex
{
	bool cmd;
	int hei;
	bool Flag;
	int Min,dis;
	int dis_Org;
	bool Okay;
	vector<int> adj;
	int adj_Tot;
};
Vertex vt[MaxN];
inline void Ins_edge(const int u,const int v)
	{++vt[u].adj_Tot,vt[u].adj.push_back(v);}
inline void Ins_Edge(const int u,const int v)
	{Ins_edge(u,v),Ins_edge(v,u);}
int que[MaxN];
inline void BFS_01_Height(const int n)
{
	int que_Beg=1,que_End=0;
	rep(i,1,n)
	{
		if(vt[i].cmd)
			vt[i].hei=0,que[++que_End]=i;
		else
			vt[i].hei=(+Infinity);
	}
	while(que_Beg<=que_End)
	{
		const int u=que[que_Beg++];
		rep(I,1,vt[u].adj_Tot)
		{
			const int v=vt[u].adj[I];
			if(vt[v].hei!=(+Infinity))
				continue;
			vt[v].hei=(vt[u].hei+1),que[++que_End]=v;
		}
	}
}
vector<int> arr[MaxN],Lit[MaxN];
int arr_Tot[MaxN],Lit_Tot[MaxN];
bitset<MaxN> Bitset;
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n;
	cin>>n;
	rep(i,1,n)
		cin>>vt[i].cmd,vt[i].Min=(+Infinity),vt[i].adj.push_back(0);
	rep(i,0,n-1)
		arr[i].push_back(0),Lit[i].push_back(0);
	int u,v;
	rep(i,2,n)
		cin>>u>>v,Ins_Edge(u,v);
	BFS_01_Height(n);
	rep(i,1,n)
	{
		++arr_Tot[vt[i].hei],arr[vt[i].hei].push_back(i);
		rep(I,1,vt[i].adj_Tot)
		{
			u=vt[i].adj[I];
			if(vt[i].hei==vt[u].hei)
				vt[i].Flag=true;
		}
		if(vt[i].Flag)
			Bitset[vt[i].hei]=true;
	}
	rep(x,0,n-1)
	{
		if(!Bitset[x]) continue;
		rep(i,1,n)
			vt[i].dis=((vt[i].Flag&&(vt[i].hei==x))?0:(+Infinity));
		rep(y,x+1,n-1)
		{
			int dis_Min=(+Infinity);
			rep(I,1,arr_Tot[y])
			{
				u=arr[y][I];
				rep(J,1,vt[u].adj_Tot)
				{
					v=vt[u].adj[J];
					if(vt[v].hei==(y-1))
						vt[u].dis=min(vt[u].dis,max(vt[v].dis-1,0));
				}
				dis_Min=min(dis_Min,vt[u].dis_Org=vt[u].dis);
			}
			int que_Beg=1,que_End=0;
			rep(I,1,arr_Tot[y])
			{
				u=arr[y][I];
				if(vt[u].dis>=(+(Infinity>>1)))
					continue;
				++Lit_Tot[vt[u].dis],Lit[vt[u].dis].push_back(u);
				if(vt[u].dis==dis_Min)
					que[++que_End]=u;
			}
			int dis_Last=dis_Min;
			while(que_Beg<=que_End)
			{
				const int u=que[que_Beg++];
				if(vt[u].dis!=dis_Last)
				{
					dis_Last=vt[u].dis;
					rep(I,1,Lit_Tot[vt[u].dis])
					{
						v=Lit[vt[u].dis][I];
						if(vt[v].dis==vt[v].dis_Org)
							que[++que_End]=v;
					}
				}
				rep(I,1,vt[u].adj_Tot)
				{
					v=vt[u].adj[I];
					if(vt[v].hei!=y) continue;
					if((vt[u].dis+1)<vt[v].dis)
						vt[v].dis=(vt[u].dis+1),que[++que_End]=v;
				}
			}
			rep(I,1,arr_Tot[y])
			{
				u=arr[y][I];
				if(vt[u].dis>=(+(Infinity>>1)))
					continue;
				Lit_Tot[vt[u].dis]=0,Lit[vt[u].dis].clear();
				Lit[vt[u].dis].push_back(0);
			}
		}
		rep(i,1,n)
			if((!vt[i].dis)&&(vt[i].Min==(+Infinity)))
				vt[i].Min=x;
	}
	rep(i,1,n)
		cout<<((vt[i].hei<<1)-min(vt[i].Min,vt[i].hei))<<' ';
	cout<<'\n';
	return 0;
}