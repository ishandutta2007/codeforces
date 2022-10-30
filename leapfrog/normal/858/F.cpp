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
int dfn[200005],dt;char v[200005];struct node{int a,b,c;};vector<node>rs;
struct edge{int to,nxt;}e[400005];int n,m,et,head[200005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline char dfs(int x,int fa)
{
	dfn[x]=++dt,v[x]=1;vector<int>sn;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
	{
		if(!v[e[i].to]&&dfs(e[i].to,x)) sn.push_back(e[i].to);
		else if(dfn[e[i].to]<dfn[x]) sn.push_back(e[i].to);
	}
	for(int i=1;i<(int)sn.size();i+=2) rs.push_back((node){sn[i],x,sn[i-1]});
	if(sn.size()%2==0) return 1;else if(fa) return rs.push_back((node){fa,x,sn[sn.size()-1]}),0;else return 0;
}
int main()
{
	read(n),read(m);for(int i=1,x,y;i<=m;i++) read(x),read(y),adde(x,y),adde(y,x);
	for(int i=1;i<=n;i++) if(!v[i]) dfs(i,0);
	printf("%d\n",(int)rs.size());for(auto x:rs) printf("%d %d %d\n",x.a,x.b,x.c);
	return 0;
}