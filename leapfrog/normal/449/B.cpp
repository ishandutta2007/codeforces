#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=100005;char fg[N],vs[N];ll ds[N];
struct edge{int to,w,nxt;}e[600005];int n,m,K,cn[N],et,head[N];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
int main()
{
	read(n,m,K);for(int i=1,x,y,w;i<=m;i++) read(x,y,w),adde(x,y,w),adde(y,x,w);
	memset(ds,0x3f,sizeof(ds)),ds[1]=0;priority_queue<pair<ll,int> >q;
	for(int i=1,s;i<=K;i++) {ll w;read(s,w),ds[s]=min(ds[s],w),fg[s]=1;}
	for(int i=1;i<=n;i++) if(ds[i]<=1e9) q.push(make_pair(-ds[i],i));
	while(!q.empty())
	{
		int x=q.top().second;q.pop();if(vs[x]) continue;else vs[x]=1;
		for(int i=head[x];i;i=e[i].nxt) if(ds[e[i].to]>=ds[x]+e[i].w)
		{
			fg[e[i].to]=0,ds[e[i].to]=ds[x]+e[i].w;
			q.push(make_pair(-ds[e[i].to],e[i].to));
		}
	}
	int tot=K;for(int i=1;i<=n;i++) tot-=fg[i];
	return printf("%d\n",tot),0;
}