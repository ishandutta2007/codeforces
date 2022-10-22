#pragma GCC optimize("Ofast")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define set(a,v) memset(a,v,sizeof(a))
#define RG register
int n,aL,aR,L=1,R,G,ds[N],sz[N],mx[N],z[N],dst[N],st[N];bool vs[N];struct Ans {int u,v;}ans;
int cntE,hd[N];struct Edge {int v,w,nxt;}e[N<<1];struct Seg {int v;}sg[N<<2];
int min(int x,int y) {return x<y?x:y;}
int max(int x,int y) {return x>y?x:y;}
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=getchar();
	while(isdigit(c)) res=(res<<1)+(res<<3)+(c&15),c=getchar();return res;
} 
void addE(int u,int v,int w) {e[++cntE]=(Edge) {v,w,hd[u]};hd[u]=cntE;}
Seg merge(Seg tL,Seg tR)
{
	Seg res;
	if(!tL.v) res.v=tR.v;else if(!tR.v) res.v=tL.v;else res.v=z[tL.v]<z[tR.v]?tR.v:tL.v;return res;
}
void pu(int p) {sg[p]=merge(sg[p<<1],sg[p<<1|1]);}
void build(int p,int l,int r) {sg[p].v=0;if(l==r) return;int mid=l+r>>1;build(p<<1,l,mid);build(p<<1|1,mid+1,r);}
void upd(int p,int l,int r,int x,int v)
{
	if(l==r) {if(!v || !sg[p].v || z[v]>z[sg[p].v]) sg[p].v=v;return;}int mid=l+r>>1;
	if(x<=mid) upd(p<<1,l,mid,x,v);else upd(p<<1|1,mid+1,r,x,v);pu(p);
}
Seg qMx(int p,int l,int r,int qL,int qR)
{
	if(l>=qL && r<=qR) return sg[p];int mid=l+r>>1;Seg tL,tR;
	if(qL<=mid) tL=qMx(p<<1,l,mid,qL,qR);if(qR>mid) tR=qMx(p<<1|1,mid+1,r,qL,qR);
	if(qL<=mid && qR>mid) return merge(tL,tR);else if(qL<=mid) return tL;return tR;
}
void getG(int u,int f,int x)
{
	sz[u]=1;mx[u]=0;
	for(RG int i=hd[u],v;~i;i=e[i].nxt) {v=e[i].v;if(v!=f && !vs[v]) getG(v,u,x),sz[u]+=sz[v],mx[u]=max(mx[u],sz[v]);}
	mx[u]=max(mx[u],x-sz[u]);if(!G || mx[u]<mx[G]) G=u;
}
void dfs(int u,int f,int gl,int nw)
{
	if(dst[u]>aR) return;st[++st[0]]=u;z[u]=nw;
	for(RG int i=hd[u],v,w;~i;i=e[i].nxt) {v=e[i].v;w=e[i].w<gl;if(v!=f && !vs[v]) dst[v]=dst[u]+1,dfs(v,u,gl,nw+1-(w<<1));}
}
Ans slv(int u,int f,int x,int gl)
{
	if(x<=aL) return (Ans) {0,0};G=0;getG(u,f,x);u=G;vs[u]=1;
	for(RG int i=hd[u],v,w,lst=0;~i;i=e[i].nxt)
	{
		v=e[i].v;w=e[i].w<gl;if(v==f || vs[v]) continue;dst[v]=1;dfs(v,u,gl,1-(w<<1));
		for(RG int j=lst+1,t;j<=st[0];++j)
		{
			if(dst[st[j]]>=aL && z[st[j]]>=0) return (Ans) {u,st[j]};
			t=qMx(1,0,n,max(aL-dst[st[j]],0),aR-dst[st[j]]).v;if(t && z[t]>=-z[st[j]]) return (Ans) {t,st[j]};
		}for(RG int j=lst+1;j<=st[0];++j) upd(1,0,n,dst[st[j]],st[j]);lst=st[0];
	}while(st[0]) upd(1,0,n,dst[st[st[0]--]],0);
	for(RG int i=hd[u],v;~i;i=e[i].nxt) {Ans t;v=e[i].v;if(v!=f && !vs[v]) {t=slv(v,u,sz[v],gl);if(t.u) return t;}}
	return (Ans) {0,0};
}
int main()
{
	set(hd,-1);n=rd();aL=rd();aR=rd();
	for(RG int i=1,u,v,w;i<n;++i) u=rd(),v=rd(),w=rd(),addE(u,v,w),addE(v,u,w),ds[++ds[0]]=w;
	sort(ds+1,ds+ds[0]+1);R=ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	while(L<=R) {int mid=L+R>>1;Ans t;st[0]=0;set(vs,0);build(1,0,n);t=slv(1,0,n,ds[mid]);if(t.u) ans=t,L=mid+1;else R=mid-1;}
	printf("%d %d\n",ans.u,ans.v);return 0;
}