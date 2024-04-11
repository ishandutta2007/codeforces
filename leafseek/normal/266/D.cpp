#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=200+5,Infinity=((1<<30)-2);
int wei[MaxN][MaxN],Dis[MaxN][MaxN],*the_Dis,arr[MaxN][MaxN],lit[MaxN];
struct Compare_Dis
	{inline bool operator () (const int u,const int v)
		{return (the_Dis[u]<the_Dis[v]);}};
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	rep(i,1,n)
		rep(j,1,n)
			if(j!=i) wei[i][j]=(+Infinity);
	int u,v,x;
	while(m--)
		cin>>u>>v,cin>>wei[u][v],wei[v][u]=(wei[u][v]<<=1);
	rep(i,1,n)
		rep(j,1,n)
			Dis[i][j]=wei[i][j];
	rep(i,1,n)
		rep(u,1,n)
			rep(v,1,n)
				Dis[u][v]=min(Dis[u][v],(Dis[u][i]+Dis[i][v]));
	rep(i,1,n)
	{
		the_Dis=Dis[i];
		rep(j,1,n) arr[i][j]=j;
		sort(arr[i]+1,arr[i]+n+1,Compare_Dis());
	}
	int Answer=(+Infinity);
	rep(u,1,n)
		rep(v,1,n)
		{
			if((u==v)||(wei[u][v]==(+Infinity)))
				continue;
			lit[0]=0;
			rep(i,1,n)
			{
				x=arr[u][i];
				while(lit[0]&&(Dis[v][x]>=Dis[v][lit[lit[0]]]))
					--lit[0];
				lit[++lit[0]]=x;
			}
			Answer=min(Answer,min(Dis[u][lit[lit[0]]],Dis[v][lit[1]]));
			rep(i,1,lit[0]-1)
			{
				Answer=min(Answer,((wei[u][v]+(Dis[u][lit[i]]+Dis[v][lit[i+1]]))>>1));
				Answer=min(Answer,((wei[u][v]+(Dis[u][lit[i+1]]+Dis[v][lit[i]]))>>1));
			}
		}
	cout<<(Answer>>1)<<'.'<<((Answer&1)?'5':'0')<<'\n';
	return 0;
}