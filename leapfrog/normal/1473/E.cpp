//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
struct edge{int to;ll w;int nxt;}e[400005];int et,head[200005];
struct node{int x;ll w;int a,b;bool operator<(node b) const {return w>b.w;}};
int n,m;ll d[200005][2][2];priority_queue<node>q;
inline void adde(int x,int y,ll w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void dijk(int s)
{
	q.push((node){s,0,0,0}),memset(d,0x3f,sizeof(d)),d[s][0][0]=0;
	while(!q.empty())
	{
		node w=q.top();int x=w.x;q.pop();if(d[x][w.a][w.b]^w.w) continue;
		for(int i=head[x];i;i=e[i].nxt)
		{
			if(d[e[i].to][w.a][w.b]>w.w+e[i].w)
				d[e[i].to][w.a][w.b]=w.w+e[i].w,q.push((node){e[i].to,d[e[i].to][w.a][w.b],w.a,w.b});
			if(!w.a&&d[e[i].to][1][w.b]>w.w+(e[i].w<<1))
				d[e[i].to][1][w.b]=w.w+(e[i].w<<1),q.push((node){e[i].to,d[e[i].to][1][w.b],1,w.b});
			if(!w.b&&d[e[i].to][w.a][1]>w.w)
				d[e[i].to][w.a][1]=w.w,q.push((node){e[i].to,d[e[i].to][w.a][1],w.a,1});
			if(!w.a&&!w.b&&d[e[i].to][1][1]>w.w+e[i].w)
				d[e[i].to][1][1]=w.w+e[i].w,q.push((node){e[i].to,d[e[i].to][1][1],1,1});
		}
	}
}
int main()
{
	read(n),read(m);for(int i=1,x,y,w;i<=m;i++) read(x),read(y),read(w),adde(x,y,w),adde(y,x,w);
	dijk(1);for(int i=2;i<=n;i++) printf("%lld%c",d[i][1][1],i==n?'\n':' ');
	return 0;
}