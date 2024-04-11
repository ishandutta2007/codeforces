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
struct edge{int to,nxt;}e[4000005];int n,m,et=1,head[200005];
int v[4000005],cn,deg[200005];vector<int>q;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et,deg[x]++;}
inline void dfs(int x)
{
	for(int &i=head[x];i;i=e[i].nxt) if(!v[i])
	{
		v[i]=v[i^1]=1;int a=x,b=e[i].to;dfs(b);
		if((++cn)&1) printf("%d %d\n",a,b);else printf("%d %d\n",b,a);
	}
}
int main()
{
	read(n),read(m);for(int i=1,x,y;i<=m;i++) read(x),read(y),adde(x,y),adde(y,x);
	for(int i=1;i<=n;i++) if(deg[i]&1) q.push_back(i);
	for(int i=1;i<(int)q.size();i+=2) adde(q[i],q[i-1]),adde(q[i-1],q[i]),m++;
	return m&1?m++,adde(1,1),adde(1,1):void(),printf("%d\n",m),dfs(1),0;
}