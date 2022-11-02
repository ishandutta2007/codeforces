//
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,w,nxt;}e[600005];
int n,m,et,head[300005],ls[300005],rs[300005];char in[300005];ll d[300005];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void dij(int s)
{
	memset(d,0x3f,sizeof(d)),d[s]=0,q.push(make_pair(d[s],s));
	while(!q.empty())
	{
		int x=q.top().second;ll wei=q.top().first;q.pop();
		// printf("%d , %lld\n",x,wei);
		if(in[x]) continue;else in[x]=1;
		for(int i=head[x];i;i=e[i].nxt) if(d[e[i].to]>=wei+e[i].w)
		{
			d[e[i].to]=wei+e[i].w,ls[e[i].to]=i;
			if(!in[e[i].to]) q.push(make_pair(d[e[i].to],e[i].to));
		}
	}
}
int main()
{
	read(n),read(m);
	for(int i=1,x,y,w;i<=m;i++) read(x),read(y),read(w),adde(x,y,w),adde(y,x,w);
	int st;read(st),dij(st);ll res=0;
	for(int i=1;i<=n;i++) if(i!=st) res+=e[ls[i]].w;
	printf("%lld\n",res);for(int i=1;i<=n;i++) if(i^st) printf("%d ",(ls[i]+1)>>1);
	return !putchar('\n');
}