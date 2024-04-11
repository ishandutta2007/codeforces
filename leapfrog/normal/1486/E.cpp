//
#include<bits/stdc++.h>
#define int long long
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct edge{int to,w;};vector<edge>v[100005];
struct node{int x,l,ds;bool operator<(node b) const {return ds>b.ds;}};
int n,m,ds[100005][55];char vs[100005][55];priority_queue<node>q;
signed main()
{
	read(n),read(m),memset(ds,0x3f,sizeof(ds)),ds[1][0]=0,q.push((node){1,0,0});
	for(int i=1,x,y,w;i<=m;i++) read(x),read(y),read(w),v[x].push_back((edge){y,w}),v[y].push_back((edge){x,w});
	while(!q.empty())
	{
		node t=q.top();q.pop();int x=t.x;if(vs[x][t.l]) continue;else vs[x][t.l]=1;
		if(t.l) {for(auto y:v[x]) if(ds[y.to][0]>t.ds+(t.l+y.w)*(t.l+y.w)) ds[y.to][0]=t.ds+(t.l+y.w)*(t.l+y.w),q.push((node){y.to,0,ds[y.to][0]});}
		else for(auto y:v[x]) if(ds[y.to][y.w]>t.ds) ds[y.to][y.w]=t.ds,q.push((node){y.to,y.w,t.ds});
	}
	for(int i=1;i<=n;i++) printf("%lld%c",ds[i][0]>1e18?-1:ds[i][0],i==n?'\n':' ');
	return 0;
}