#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define LIM 1000005
#define ll unsigned long long
#define pb push_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
const ll INF=1e18;char *P1,*P2,buf[LIM];
int n,m,c,a1[N],ps[N],dg[N],ord[N],id[N],s[N],R[N];ll ans,a[N],dst[N],ans1[N];
bool vs[N];struct Edge {int v,w;};vector<Edge> e[N];
struct Point {int u;ll w;bool operator < (Point t) const {return w>t.w;}}b[N];
struct Node {int l,x;ll w;bool operator < (Node t) const {return l<t.l;}};
vector<int> vc[N];priority_queue<Point> q;set<Node> z1,z2;
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+(c-48),c=gc();return res;
}
void print(ll x) {if(x<10) {putchar(x+48);return;}print(x/10);putchar(x%10+48);}
bool cmp(int x,int y) {return dst[x]<dst[y];}
void Dijkstra(int S)
{
	for(int i=1;i<=n;++i) dst[i]=INF;q.push((Point) {S,dst[S]=0});
	while(!q.empty())
	{
		Point t=q.top();q.pop();int u=t.u;if(vs[u]) continue;vs[u]=1;
		for(auto i:e[u]) if(dst[u]+i.w<dst[i.v])
			q.push((Point) {i.v,dst[i.v]=dst[u]+i.w});
	}
}
int qry1(int l,int r,int x)
{
	l=lower_bound(vc[x].begin(),vc[x].end(),l)-vc[x].begin();
	r=upper_bound(vc[x].begin(),vc[x].end(),r)-vc[x].begin();return r-l;
}
ll qry(int l,int r,int x1,int x2,ll w1,ll w2)
{return w1*(s[r]-s[l-1])+(w2-w1)*qry1(l,r,x1);}
void upd2(int l,int r,int x,int x1,int x2,ll w1,ll w2)
{
	Node t;set<Node>::iterator it=--z2.upper_bound((Node) {l,0,0});t=*it;
	if(t.w<a[x]) return;if(l>t.l) z2.insert((Node) {l,t.x,t.w});
	it=z2.lower_bound((Node) {r+1,0,0});
	if(r+1<it->l) t=*--it,z2.insert((Node) {r+1,t.x,t.w});
	while(1)
	{
		it=z2.lower_bound((Node) {l,0,0});t=*it;
		if(t.l>r || t.w<a[x]) break;++it;z2.erase(t);
		ans+=qry(t.l,it->l-1,x2,x,w2,a[x])-qry(t.l,it->l-1,x1,t.x,w1,t.w);
	}z2.insert((Node) {l,x,a[x]});
}
void upd1(int l,int r,int x)
{
	Node t;set<Node>::iterator it=--z1.upper_bound((Node) {l,0,0});t=*it;
	if(t.w<a[x]) {upd2(l,r,x,t.x,t.x,t.w,t.w);return;}
	if(l>t.l) z1.insert((Node) {l,t.x,t.w});
	it=z2.lower_bound((Node) {r+1,0,0});
	if(r+1<it->l) t=*--it,z2.insert((Node) {r+1,t.x,t.w});
	while(1)
	{
		it=z1.lower_bound((Node) {l,0,0});t=*it;
		if(t.l>r || t.w<a[x]) break;++it;z1.erase(t);
		if(x!=t.x) upd2(t.l,it->l-1,t.x,t.x,x,t.w,a[x]);
		else ans+=(a[x]-t.w)*(s[it->l-1]-s[t.l-1]-qry1(t.l,it->l-1,t.x));
	}z1.insert((Node) {l,x,a[x]});if(t.l<=r) upd2(t.l,r,x,t.x,t.x,t.w,t.w);
}
int main()
{
	n=rd();m=rd();c=rd();for(int i=1;i<=n;++i) ord[i]=i,a1[i]=rd();
	for(int i=1,u,v,w;i<=m;++i)
		u=rd(),v=rd(),w=rd(),e[u].pb((Edge) {v,w}),e[v].pb((Edge) {u,w});
	Dijkstra(1);sort(ord+1,ord+n+1,cmp);dg[1]=2;a[0]=INF;
	for(int i=1;i<=n;++i) for(auto j:e[i])
		if(dst[i]+j.w==dst[j.v]) {++dg[j.v];if(i>1) ps[j.v]=i;}
	for(int i=1;i<=n;++i) id[ord[i]]=i,a[i]=a1[ord[i]];
	for(int i=1;i<=c;++i) b[i].u=id[rd()],b[i].w=rd(),a[b[i].u]+=b[i].w;
	for(int i=1;i<=n;++i)
	{s[i]=s[i-1];if(dg[ord[i]]<2) vc[id[ps[ord[i]]]].pb(i),++s[i];}
	for(int i=n,t=n;i;--i) {if(dst[ord[i]]<dst[ord[i+1]]) t=i;R[i]=t+1;}
	for(int i=1,t=1,x1=0,x2=0;i<=n;++i)
	{
		while(R[t]<=i) {if(a[t]<a[x1]) x2=x1,x1=t;else if(a[t]<a[x2]) x2=t;++t;}
		if(dg[ord[i]]<2) ans+=a[x1==id[ps[ord[i]]]?x2:x1];
		z1.insert((Node) {i,x1,a[x1]});z2.insert((Node) {i,x2,a[x2]});
	}z1.insert((Node) {n+1,0,0});z2.insert((Node) {n+1,0,0});
	for(int i=c;i;--i) ans1[i]=ans,a[b[i].u]-=b[i].w,upd1(R[b[i].u],n,b[i].u);
	ans1[0]=ans;for(int i=0;i<=c;++i) print(ans1[i]),putchar('\n');return 0;
}