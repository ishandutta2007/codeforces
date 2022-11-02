//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[200005];
int n,m,k,s,a[100005],et,head[100005],ds[100005][105];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void bfs(int id)
{
	queue<int>q;for(int i=1;i<=n;i++) ds[i][id]=-1;
	for(int i=1;i<=n;i++) if(a[i]==id) ds[i][id]=0,q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].nxt) if(!~ds[e[i].to][id]) q.push(e[i].to),ds[e[i].to][id]=ds[x][id]+1;
	}
}
int main()
{
	read(n),read(m),read(k),read(s);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,x,y;i<=m;i++) read(x),read(y),adde(x,y),adde(y,x);
	for(int i=1;i<=k;i++) bfs(i);
	for(int i=1;i<=n;i++)
	{
		sort(ds[i]+1,ds[i]+k+1);int sm=0;
		for(int j=1;j<=s;j++) if(~ds[i][j]) sm+=ds[i][j];
		printf("%d%c",sm,i==n?'\n':' ');
	}
	return 0;
}