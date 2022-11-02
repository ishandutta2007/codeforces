//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+9;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[400005];
struct node{int x,y;}a[400005];
int T,n,m,et,head[200005],at,deg[200005],dt=0,pc[200005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et,++deg[y];}
int main()
{
	for(read(T);T--;)
	{
		read(n),read(m),et=at=dt=0,memset(head,0,sizeof(head)),memset(deg,0,sizeof(deg));
		for(int i=1,f,x,y;i<=m;i++) {read(f),read(x),read(y),a[++at]=(node){x,y};if(f) adde(x,y);}
		queue<int>q;for(int i=1;i<=n;i++) if(!deg[i]) q.push(i);
		while(!q.empty())
		{
			int x=q.front();q.pop(),pc[x]=++dt;
			for(int i=head[x];i;i=e[i].nxt) {--deg[e[i].to];if(!deg[e[i].to]) q.push(e[i].to);}
		}
		if(dt!=n) {puts("NO");continue;}else puts("YES");
		for(int i=1;i<=m;i++) {if(pc[a[i].x]>pc[a[i].y]) swap(a[i].x,a[i].y);printf("%d %d\n",a[i].x,a[i].y);}
	}
	return 0;
}