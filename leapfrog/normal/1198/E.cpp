//
#include<bits/stdc++.h>
using namespace std;typedef int ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x,1:1;
}
const ll INF=1e9+5;struct edge{int to;ll w;int nxt;}e[7505005];
int s,t,et,head[6005],cur[6005],d[6005];
inline void ADDE(int x,int y,ll w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void adde(int x,int y,ll w) {ADDE(x,y,w),ADDE(y,x,0);}
inline char bfs(int s,int t)
{
	queue<int>q;q.push(s),memset(d,0,sizeof(d)),d[s]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].nxt) if(!d[e[i].to]&&e[i].w) q.push(e[i].to),d[e[i].to]=d[x]+1;
	}
	return !!d[t];
}
#define rev(x) ((((x)&1)?1:-1)+(x))
inline ll dfs(int x,int t,ll lim=INF)
{
	ll f=lim;if(x==t) return lim;
	for(int &i=cur[x];i;i=e[i].nxt) if(d[e[i].to]==d[x]+1&&e[i].w)
		{ll g=dfs(e[i].to,t,min(f,e[i].w));e[i].w-=g,e[rev(i)].w+=g,f-=g;if(!f) break;}
	return lim-f;
}
inline ll dinic(int s,int t) {ll r=0;while(bfs(s,t)) memcpy(cur,head,sizeof(cur)),r+=dfs(s,t);return r;}
int n,m,X1[55],Y1[55],X2[55],Y2[55],Tx[105],Ty[105],Txc=0,Tyc=0;char c[105][105];
int main()
{
	read(n),read(m);
	for(int i=1;i<=m;i++) read(X1[i]),read(Y1[i]),read(X2[i]),read(Y2[i]);
	for(int i=1;i<=m;i++) Tx[++Txc]=X1[i],Tx[++Txc]=++X2[i],Ty[++Tyc]=Y1[i],Ty[++Tyc]=++Y2[i];
	Tx[++Txc]=1,Ty[++Tyc]=1,Tx[++Txc]=n+1,Ty[++Tyc]=n+1,sort(Tx+1,Tx+Txc+1),sort(Ty+1,Ty+Tyc+1);
	Txc=unique(Tx+1,Tx+Txc+1)-Tx-1,Tyc=unique(Ty+1,Ty+Tyc+1)-Ty-1,s=Txc+Tyc+1,t=s+1;
	for(int i=1;i<Txc;i++) adde(s,i,Tx[i+1]-Tx[i]);
	for(int i=1;i<Tyc;i++) adde(i+Txc,t,Ty[i+1]-Ty[i]);
	//for(int i=1;i<Txc;i++) printf("[%d,%d]%c",Tx[i],Tx[i+1]-1,i==Txc-1?'\n':' ');
	//for(int i=1;i<Tyc;i++) printf("[%d,%d]%c",Ty[i],Ty[i+1]-1,i==Tyc-1?'\n':' ');
	for(int i=1;i<=m;i++)
	{
		X1[i]=lower_bound(Tx+1,Tx+Txc+1,X1[i])-Tx,X2[i]=upper_bound(Tx+1,Tx+Txc+1,X2[i]-1)-Tx-1;
		Y1[i]=lower_bound(Ty+1,Ty+Tyc+1,Y1[i])-Ty,Y2[i]=upper_bound(Ty+1,Ty+Tyc+1,Y2[i]-1)-Ty-1;
		//printf("%d ~ %d ; %d ~ %d\n",X1[i],X2[i],Y1[i],Y2[i]);
		for(int x=X1[i];x<=X2[i];x++) for(int y=Y1[i];y<=Y2[i];y++) c[x][y]=1;
	}
	//for(int i=1;i<Txc;i++) for(int j=1;j<Tyc;j++) printf("%d%c",c[i][j],j==Tyc-1?'\n':' ');
	for(int i=1;i<Txc;i++) for(int j=1;j<Tyc;j++) if(c[i][j]) adde(i,j+Txc,INF);
	return printf("%d\n",dinic(s,t)),0;
}