//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct edge{int to,nxt;}e[2000005];char avd[1000005];int len[1000005];
int n,et,head[1000005],mx,mxw,sn[1000005],r[1000005];vector<int>v[1000005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs1(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
	{
		dfs1(e[i].to,x),len[x]=max(len[x],len[e[i].to]+1);
		if(len[e[i].to]>=len[sn[x]]) sn[x]=e[i].to;
	}
}
inline void solve(int x,int fa)
{
	if(!sn[x]) return(void)(v[x].push_back(1),r[x]=0);else solve(sn[x],x),swap(v[x],v[sn[x]]);
	r[x]=r[sn[x]],v[x].push_back(1);if(v[x][r[x]]==1) r[x]=len[x];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa&&e[i].to!=sn[x])
	{
		solve(e[i].to,x);
		for(int j=len[e[i].to];j>=0;j--)
		{
			int w=j+len[x]-len[e[i].to]-1;v[x][w]+=v[e[i].to][j];
			if(v[x][w]>v[x][r[x]]||(v[x][w]==v[x][r[x]]&&w>r[x])) r[x]=w;
		}
	}
}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	dfs1(1,0),solve(1,0);for(int i=1;i<=n;i++) printf("%d\n",len[i]-r[i]);
	return 0;
}