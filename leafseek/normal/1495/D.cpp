#include<bits/stdc++.h> 
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=400+5,Mod=998244353,Inf=(1<<30)-1;
int dis[MaxN][MaxN],cnt[MaxN];
vector<int> adj[MaxN];
bool tag[MaxN];
long long Mul[MaxN][MaxN];
inline bool Inevitable(const register int stt,const register int ter,const register int pos)
	{return ((dis[stt][ter]==dis[stt][pos]+dis[pos][ter])?true:false);}
int main()
{
	register int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n)
		adj[i].push_back(0);
	rep(i,1,n)
		rep(j,1,n)
			dis[i][j]=Inf;
	rep(i,1,n)
		dis[i][i]=0;
	while(m--)
	{
		register int u,v;
		scanf("%d%d",&u,&v);
		++adj[u][0],adj[u].push_back(v);
		++adj[v][0],adj[v].push_back(u);
		dis[u][v]=min(dis[u][v],1);
		dis[v][u]=min(dis[v][u],1);
	}
	rep(a,1,n)
		rep(b,1,n)
			rep(c,1,n)
				dis[b][c]=min(dis[b][c],dis[b][a]+dis[a][c]);
	rep(s,1,n)
		rep(t,1,n)
		{
			Mul[s][t]=1;
			register int Sum,Max=0;
			rep(u,1,n)
			{
				if(!Inevitable(s,t,u))
					continue;
				++cnt[dis[s][u]];
				Max=max(Max,dis[s][u]);
			}
			register bool flag=true;
			rep(i,0,Max)
				if(cnt[i]!=1)
					{flag=false;break;}
			rep(i,0,Max)
				cnt[i]=0;
			if(!flag)
				{Mul[s][t]=0;continue;}
			rep(u,1,n)
			{
				Sum=0;
				if(Inevitable(s,t,u))
					continue;
				rep(i,1,adj[u][0])
				{
					register int v=adj[u][i];
					if(Inevitable(s,u,v)&&Inevitable(t,u,v))
						++Sum;
				}
				Mul[s][t]=(Mul[s][t]*Sum)%Mod;
			}
		}
	rep(i,1,n)
	{
		rep(j,1,n)
			printf("%lld ",Mul[i][j]);
		printf("\n");
	}
	return 0;
}