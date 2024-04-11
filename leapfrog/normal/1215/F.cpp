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
#define p(x,w) (((x)<<1)-w)
#define s(x,w) ((((x)+n+1)<<1)-w)
const int N=2000005;int dfn[N],low[N],cl[N],clt,dt,st[N],tp;char v[N];
int n,m,q1,q2,et,head[N];struct edge{int to,nxt;}e[4000005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void tarjan(int x)
{
	dfn[x]=low[x]=++dt,v[x]=1,st[++tp]=x;
	for(int i=head[x];i;i=e[i].nxt)
		if(!dfn[e[i].to]) tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else if(v[e[i].to]) low[x]=min(dfn[e[i].to],low[x]);
	if(low[x]==dfn[x]) {int y=++clt;do cl[y=st[tp--]]=clt,v[y]=0;while(y^x);}
}
int main()
{
	read(q1),read(n),read(m),read(q2);
	for(int i=1,x,y;i<=q1;i++) read(x),read(y),adde(p(x,0),p(y,1)),adde(p(y,0),p(x,1));
	for(int i=1,l,r;i<=n;i++)
	{
		read(l),read(r);
		adde(p(i,1),s(r,1)),adde(s(r,0),p(i,0));
		adde(p(i,1),s(l-1,0)),adde(s(l-1,1),p(i,0));
	}
	for(int i=1,x,y;i<=q2;i++) read(x),read(y),adde(p(x,1),p(y,0)),adde(p(y,1),p(x,0));
	for(int i=1;i<=m;i++) adde(s(i-1,1),s(i,1)),adde(s(i,0),s(i-1,0));
	for(int i=1,e=(n+m+1)<<1;i<=e;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++) if(cl[p(i,1)]==cl[p(i,0)]) return puts("-1"),0;
	for(int i=0;i<=m;i++) if(cl[s(i,1)]==cl[s(i,0)]) return puts("-1"),0;
	int cnt=0;for(int i=1;i<=n;i++) if(cl[p(i,1)]<cl[p(i,0)]) cnt++;
	printf("%d ",cnt);for(int i=1;i<=m;i++) if(cl[s(i,1)]<cl[s(i,0)]) {printf("%d\n",i);break;};
	for(int i=1;i<=n;i++) if(cl[p(i,1)]<cl[p(i,0)]) printf("%d ",i);
	return putchar('\n'),0;
}