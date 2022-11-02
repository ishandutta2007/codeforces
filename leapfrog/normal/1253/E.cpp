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
struct edge{int to,w,nxt;}e[10000005];
int n,m,s,t,et,head[200005],dis[200005],w[85],b[85];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline int dijk(int s,int t)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	memset(dis,0x3f,sizeof(dis)),dis[s]=0,q.push(make_pair(dis[s],s));
	while(!q.empty())
	{
		int x=q.top().second,w=q.top().first;q.pop();if(w!=dis[x]) continue;else if(x==t) return w;
		for(int i=head[x];i;i=e[i].nxt) if(dis[e[i].to]>w+e[i].w) dis[e[i].to]=w+e[i].w,q.push(make_pair(dis[e[i].to],e[i].to));
	}
	return 0;
}
int main()
{
	read(n),read(m),s=1,t=m+1;
	for(int i=1;i<=n;i++) read(w[i]),read(b[i]);
	for(int i=1;i<=m;i++) adde(i,i+1,1),adde(i+1,i,0);
	for(int i=1;i<=n;i++)
	{
		int len=0,le=max(1,w[i]-b[i]),ri=min(w[i]+b[i]+1,m+1);
		while(le>=1&&ri<=m+1) adde(le=max(le,1),ri=min(ri,m+1),len++),--le,++ri;
	}
	return printf("%d\n",dijk(s,t)),0;
}