//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,id,nxt;}e[200005];
int n,et,head[100005],deg[100005],rs[100005];
inline void adde(int x,int y,int id) {e[++et]=(edge){y,id,head[x]},head[x]=et,++deg[x];}
int main()
{
	read(n);int tag=0,qwq=0;memset(rs,-1,sizeof(rs));
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y,i),adde(y,x,i);
	for(int i=1;i<=n;i++) if(deg[i]>=3) {tag=i;break;}
	if(tag==0) {for(int i=0;i<n-1;i++) printf("%d\n",i);return 0;}
	for(int i=head[tag];i;i=e[i].nxt) rs[e[i].id]=qwq++;
	for(int i=1;i<n;i++) if(rs[i]==-1) rs[i]=qwq++;
	for(int i=1;i<n;i++) printf("%d\n",rs[i]);
	return 0;
}