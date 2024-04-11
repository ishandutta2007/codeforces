//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,m,K,et,head[300005],rs[300005],rst,ls[300005];ll ds[300005];struct edge{int to,w,nxt;}e[600005];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
int main()
{
	read(n),read(m),read(K);
	for(int i=1,x,y,w;i<=m;i++) read(x),read(y),read(w),adde(x,y,w),adde(y,x,w);
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
	for(memset(ds,0x3f,sizeof(ds)),q.push(make_pair(ds[1]=0,1));!q.empty();)
	{
		int x=q.top().second;ll w=q.top().first;q.pop();if(ds[x]^w) continue;else if(x^1) rs[++rst]=(ls[x]+1)>>1;
		for(int i=head[x];i;i=e[i].nxt) if(w+e[i].w<ds[e[i].to]) ds[e[i].to]=w+e[i].w,ls[e[i].to]=i,q.push(make_pair(ds[e[i].to],e[i].to));
	}
	printf("%d\n",min(rst,K));for(int i=1;i<=rst&&i<=K;i++) printf("%d%c",rs[i],i==rst||i==K?'\n':' ');
	return 0;
}