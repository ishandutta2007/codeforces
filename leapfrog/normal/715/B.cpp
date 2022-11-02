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
struct edge{int to,w,f,nxt;}e[20005];int n,m,L,s,t,et=1,head[1005],ds[1005][2];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,max(w,1),!w,head[x]},head[x]=et;}
inline void dijk(int s,int t,int fg)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push(make_pair(ds[s][fg]=0,s));for(int i=0;i<n;i++) ds[i][fg]=(i!=s)*1019260817;
	for(;!q.empty();)
	{
		int x=q.top().second,w=q.top().first;q.pop();if(w^ds[x][fg]) continue;
		for(int i=head[x],y;i;i=e[i].nxt)
		{
			y=e[i].to;if(fg&&e[i].f) e[i].w=e[i^1].w=max(e[i].w,ds[y][0]+L-ds[t][0]-ds[x][1]);
			if(ds[y][fg]>ds[x][fg]+e[i].w) q.push(make_pair(ds[y][fg]=ds[x][fg]+e[i].w,y));
		}
	}
}
int main()
{
	read(n),read(m),read(L),read(s),read(t);
	for(int i=1,x,y,w;i<=m;i++) read(x),read(y),read(w),adde(x,y,w),adde(y,x,w);
	dijk(s,t,0);if(ds[t][0]>L) return puts("NO"),0;else dijk(s,t,1);
	//printf("%d %d %d\n",ds[t][0],L,ds[t][1]);
	if(ds[t][1]^L) return puts("NO"),0;else puts("YES");
	for(int i=2;i<=et;i+=2) printf("%d %d %d\n",e[i+1].to,e[i].to,e[i].w);
	return 0;
}