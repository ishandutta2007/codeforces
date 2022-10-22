#include<bits/stdc++.h>
#define int long long
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=1000000+5,Mod=998244353;
bitset<MaxN> Is_pri;
vector<pair<int,int>> arr[MaxN];
int Inv[MaxN],pri[MaxN];
inline void Initalize(const int n,int &m)
{
	rep(i,1,n) arr[i].push_back(make_pair(0,0));
	rep(i,2,n) Is_pri[i]=true;
	rep(i,2,n)
	{
		if(!Is_pri[i]) continue;
		pri[++m]=i;
		for(int j=i;j<=n;j+=i)
		{
			Is_pri[j]=false;
			++arr[j][0].first;
			int o=0,h=j;
			while(!(h%i)) ++o,h/=i;
			arr[j].push_back(make_pair(m,o));
		}
		Is_pri[i]=true;
	}
	Inv[1]=1;
	rep(i,2,n) Inv[i]=((long long)(Mod-(Mod/i))*Inv[Mod%i])%Mod;
}
struct Vertex
{
	int Fa;
	int dep;
	int head;
};
Vertex vt[MaxN];
struct Edge
{
	int u,v;
	int x,y;
	int next;
};
Edge ed[MaxN<<1];
int Overall_Ed=1;
inline void Ins_edge(const int u,const int v,const int x,const int y)
{
	const int Ed=(++Overall_Ed);
	ed[Ed].u=u,ed[Ed].v=v;
	ed[Ed].x=x,ed[Ed].y=y;
	ed[Ed].next=vt[u].head;
	vt[u].head=Ed;
}
inline void Ins_Edge(const int u,const int v,const int x,const int y)
{
	Ins_edge(u,v,x,y),Ins_edge(v,u,y,x);
}
int cnt[MaxN],Max[MaxN];
inline void Dfs(const int u)
{
	int v,x,y,w;
	for(int e=vt[u].head;e;e=ed[e].next)
	{
		if((v=ed[e].v)==vt[u].Fa)
			continue;
		x=ed[e].x,y=ed[e].y;
		w=((long long)x*Inv[y])%Mod;
		vt[v].dep=((long long)vt[u].dep*w)%Mod;
		rep(i,1,arr[x][0].first)
		{
			const int I=arr[x][i].first,O=arr[x][i].second;
			cnt[I]-=O;
		}
		rep(i,1,arr[y][0].first)
		{
			const int I=arr[y][i].first,O=arr[y][i].second;
			cnt[I]+=O,Max[I]=max(Max[I],cnt[I]);
		}
		vt[v].Fa=u,Dfs(v);
		rep(i,1,arr[x][0].first)
		{
			const int I=arr[x][i].first,O=arr[x][i].second;
			cnt[I]+=O;
		}
		rep(i,1,arr[y][0].first)
		{
			const int I=arr[y][i].first,O=arr[y][i].second;
			cnt[I]-=O;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	const int N=400000;
	int M=0;
	Initalize(N,M);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n,Overall_Ed=1;
		m=1; while(pri[m+1]<=n) ++m;
		rep(i,1,n) vt[i].head=0,Max[i]=0,cnt[i]=0;
		int u,v,x,y;
		rep(i,2,n)
		{
			cin>>u>>v>>x>>y,swap(x,y);
			Ins_Edge(u,v,x,y);
		}
		const int R=n;
		vt[R].dep=1,vt[R].Fa=0;
		Dfs(R);
		int S=1;
		rep(i,1,m) while(Max[i]--) S=((long long)S*pri[i])%Mod;
		long long C=0;
		rep(i,1,n) C+=vt[i].dep;
		const int Ans=((C%Mod)*S)%Mod;
		cout<<Ans<<'\n';
	}
	return 0;
}