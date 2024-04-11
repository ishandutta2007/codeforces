//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
template<int N,int M>struct Edge//{{{
{
	struct edge{int to,nxt;}e[M<<1];int et,head[N];
	inline void Adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
	inline void adde(int x,int y) {Adde(x,y),Adde(y,x);}
	inline void clear() {et=0,memset(head,0,sizeof(head));}
#define Go(A,x,v) for(int Ed=A.head[x],v=A.e[Ed].to;Ed;v=A.e[Ed=A.e[Ed].nxt].to)
};Edge<2505,5005>E;Edge<5005,5005>Tr;
const int N=3755;int n,m,tt,f[N],dfn[N],low[N],dt,dp[N][N][4],sz[N];
inline void tarjan(int x,int fa)
{
	f[x]=fa,dfn[x]=low[x]=++dt;
	Go(E,x,y)
	{
		if(!dfn[y]) tarjan(y,x),low[x]=min(low[x],low[y]);
		else if(y!=fa) low[x]=min(low[x],dfn[y]);
		if(low[y]>dfn[x]) Tr.adde(x,y);
	}
	Go(E,x,y) if(f[y]!=x&&dfn[y]>dfn[x])
	{
		tt++,Tr.adde(tt,x);
		for(int u=y;u^x;u=f[u]) Tr.adde(tt,u);
	}
}//}}}
inline void chkmx(int &a,int b) {a=max(a,b);}
int debug[N][4],tmp[N][4];
inline void solve(int x,int fa)
{//dp k  1  2 
	Go(Tr,x,y) if(y!=fa) solve(y,x);
	if(x<=n)
	{
		sz[x]=1,memset(dp[x],~0x3f,sizeof(dp[x])),memset(dp[x][0],0,sizeof(dp[x][0]));
		Go(Tr,x,y) if(y!=fa)
		{
			int od=sz[x];sz[x]+=sz[y];
			for(int i=0;i<=od;i++) memcpy(debug[i],dp[x][i],sizeof(debug[i]));
			for(int i=od;i>=0;i--) for(int a=3;~a;a--)
				for(int j=sz[y];j>=0;j--) for(int b=3;~b;b--)
					chkmx(dp[x][i+j][a|b],debug[i][a]+dp[y][j][b]);
//printf("f**k %d : ",x);for(int i=0;i<=sz[x];i++) printf("<%d,%d,%d,%d>%c",dp[x][i][0],dp[x][i][1],dp[x][i][2],dp[x][i][3],i==sz[x]?'\n':' ');
		}
		for(int i=0;i<=sz[x];i++) memcpy(debug[i],dp[x][i],sizeof(debug[i])),memset(dp[x][i],~0x3f,sizeof(dp[x][i]));
		for(int i=0;i<=sz[x];i++)
		{
			for(int a=0;a<4;a++) if(i+(a==1)<=sz[x]) chkmx(dp[x][i+(a==1)][a],debug[i][0]+(a==2));
			chkmx(dp[x][i][0],debug[i][1]);if(i^sz[x]) chkmx(dp[x][i+1][1],debug[i][1]);
			chkmx(dp[x][i][0],debug[i][2]);chkmx(dp[x][i][2],debug[i][2]+1);
			chkmx(dp[x][i][0],debug[i][3]);
		}
	}else
	{
		Go(Tr,x,y) if(y!=fa) sz[x]+=sz[y];
		memset(dp[x],~0x3f,sizeof(dp[x]));
		for(int bit=0;bit<3;bit++)
		{
			char fg=0;int Sz=1;memset(tmp,~0x3f,sizeof(tmp));
			Go(Tr,x,y) if(y!=fa)
			{
				if(!fg)
				{
					for(int i=0;i<=sz[y];i++) tmp[i][bit]=dp[y][i][bit];
					Sz+=sz[y],fg=1;continue;
				}
				else
				{
					for(int i=0;i<=Sz;i++) memcpy(debug[i],tmp[i],sizeof(debug[i]));
					for(int i=Sz;i>=0;i--) for(int j=sz[y];j>=0;j--)
					{
						for(int a=0;a<3;a++) chkmx(tmp[i+j][0],debug[i][a]+dp[y][j][0]);
						chkmx(tmp[i+j][1],max(debug[i][0],debug[i][1])+dp[y][j][1]);
						chkmx(tmp[i+j][2],max(debug[i][0],debug[i][2])+dp[y][j][2]);
					}
					Sz+=sz[y];
				}
			}
//printf("f**k %d : ",x);for(int i=0;i<=sz[x];i++) printf("<%d,%d,%d,%d>%c",tmp[i][0],tmp[i][1],tmp[i][2],tmp[i][3],i==sz[x]?'\n':' ');
			for(int i=0;i<=sz[x];i++)
			{
				chkmx(dp[x][i][bit],tmp[i][0]);
				chkmx(dp[x][i][bit|1],tmp[i][1]);
				chkmx(dp[x][i][bit|2],tmp[i][2]);
			}
		}
	}
//printf("res %d : ",x);for(int i=0;i<=sz[x];i++) printf("<%d,%d,%d,%d>%c",dp[x][i][0],dp[x][i][1],dp[x][i][2],dp[x][i][3],i==sz[x]?'\n':' ');
}
int main()
{
	read(n,m);for(int i=1,x,y;i<=m;i++) read(x,y),E.adde(x,y);
	tt=n,tarjan(1,0),solve(1,0);
	for(int i=0;i<=n;i++) printf("%d%c",max(max(dp[1][i][0],dp[1][i][1]),max(dp[1][i][2],dp[1][i][3])),i==n?'\n':' ');
	return 0;
}