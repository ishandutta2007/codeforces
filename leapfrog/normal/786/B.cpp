//
#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct node{int id,ls,rs;}t[3000005];
struct edge{int to,w,nxt;}e[3000005];
int n,q,s,rt1,rt2,et,head[1600005],tc,ec,dis[1600005],qaq[1600005],qwq[1600005];
inline void adde(int x,int y,int w,int g) {if(g) swap(x,y);e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void build(int &x,int l,int r,int id)
{
	x=++tc,t[x]=(node){tc,0,0};if(l==r) return;
	build(t[x].ls,l,(l+r)>>1,id),build(t[x].rs,((l+r)>>1)+1,r,id);
	adde(t[x].id,t[t[x].ls].id,0,!id),adde(t[x].id,t[t[x].rs].id,0,!id);
}
inline int getid(int x,int l,int r,int dw)
{
	if(l==r) return t[x].id;
	if(dw<=((l+r)>>1)) return getid(t[x].ls,l,(l+r)>>1,dw);
	else return getid(t[x].rs,((l+r)>>1)+1,r,dw);
}
inline void chng(int x,int l,int r,int dl,int dr,int dt,int id,int w)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return adde(t[x].id,dt,w,id);
	chng(t[x].ls,l,(l+r)>>1,dl,dr,dt,id,w),chng(t[x].rs,((l+r)>>1)+1,r,dl,dr,dt,id,w);
}
inline void dijk(int s)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	memset(dis,0x3f,sizeof(dis)),dis[s]=0,q.push(make_pair(dis[s],s));
	while(!q.empty())
	{
		int x=q.top().second,w=q.top().first;q.pop();if(w!=dis[x]) continue;
		for(int i=head[x];i;i=e[i].nxt) if(dis[e[i].to]>dis[x]+e[i].w) dis[e[i].to]=dis[x]+e[i].w,q.push(make_pair(dis[e[i].to],e[i].to));
	}
}
signed main()
{
	read(n),read(q),read(s),rt1=rt2=tc=0,build(rt1,1,n,0),build(rt2,1,n,1);
	for(int i=1;i<=n;i++) qaq[i]=getid(rt1,1,n,i),qwq[i]=getid(rt2,1,n,i),adde(qaq[i],qwq[i],0,1);
	for(int fg,v,l,r,w;q--;)
	{
		read(fg),read(v),read(l),read(r);
		if(fg==1) adde(getid(rt1,1,n,v),getid(rt2,1,n,l),r,0);
		if(fg==2) read(w),chng(rt2,1,n,l,r,getid(rt1,1,n,v),1,w);
		if(fg==3) read(w),chng(rt1,1,n,l,r,getid(rt2,1,n,v),0,w);
	}
	dijk(getid(rt2,1,n,s));
	for(int i=1,g;i<=n;i++)
	{
		g=dis[getid(rt1,1,n,i)];
		if(g>=1e15) printf("-1 ");else printf("%lld ",g);
	}
	return putchar('\n'),0;
}