#include<cstdio>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)
typedef pair<int,int> pii;
#define fi first
#define se second

const int N=2e5+5,M=1e6+5;
int n,m,p[N],ip[N];
int stk[N],top,ch[N][2];
#define lc ch[x][0]
#define rc ch[x][1]
vector<int> fac[N];
struct Line {int l,r,v;};
vector<Line> buc[N];
vector<pii> qr[N]; ll ans[M];
void dfs(int x,int l,int r) {
	for(auto d:fac[p[x]]) {
		int i=ip[d],j=ip[p[x]/d];
		if(l<=i&&i<j&&j<=r) {
			buc[min(i,x)].push_back(Line{max(j,x),r,1});
			buc[l-1].push_back(Line{max(j,x),r,-1});
			//cout<<l<<' '<<min(i,x)<<' '<<max(j,x)<<' '<<r<<endl;
		}
	}
	if(lc) dfs(lc,l,x-1);
	if(rc) dfs(rc,x+1,r);
}
#undef lc
#undef rc

int cnt[N<<2],seg[N<<2],len[N<<2];
ll sum[N<<2],tag[N<<2],tag2[N<<2];
#define lc (k<<1)
#define rc (lc|1)
#define left lc,l,mid
#define right rc,mid+1,r
void pushup(int k) {seg[k]=cnt[k]?len[k]:seg[lc]+seg[rc];}
void puttag2(int k,ll v) {tag2[k]+=v,sum[k]+=len[k]*v;}
void puttag(int k,ll v) {
	if(cnt[k]) puttag2(k,v);
	else tag[k]+=v,sum[k]+=seg[k]*v;
}
void pushdown(int k) {
	if(tag2[k]) puttag2(lc,tag2[k]),puttag2(rc,tag2[k]),tag2[k]=0;
	if(tag[k]) puttag(lc,tag[k]),puttag(rc,tag[k]),tag[k]=0;
}

void build(int k,int l,int r) {
	len[k]=r-l+1;
	if(l==r) return;
	int mid=l+r>>1;
	build(left),build(right);
}
void change(int k,int l,int r,int x,int y,int v) {
	if(x<=l&&r<=y) {
		cnt[k]+=v;
		if(l==r) seg[k]=cnt[k]?1:0;
		else pushup(k);
		return;
	}
	int mid=l+r>>1; pushdown(k);
	if(x<=mid) change(left,x,y,v);
	if(y>mid) change(right,x,y,v);
	pushup(k);
}
ll query(int k,int l,int r,int x,int y) {
	if(x<=l&&r<=y) return sum[k];
	int mid=l+r>>1; ll z=0; pushdown(k);
	if(x<=mid) z=query(left,x,y);
	if(y>mid) z+=query(right,x,y);
	return z;
}
int main() {
	n=read(),m=read();
	fr(i,1,n) {
		ip[p[i]=read()]=i;
		while(top&&p[stk[top]]<p[i]) ch[i][0]=stk[top--];
		ch[stk[top]][1]=i;
		stk[++top]=i;
	}
	fr(i,1,n) for(int j=i;j<=n;j+=i) fac[j].push_back(i);
	dfs(ch[0][1],1,n);
	fr(i,1,m) {
		int l=read();
		int r=read();
		qr[l].push_back(pii(r,i));
	}
	build(1,1,n);
	rf(i,n,1) {
		for(auto x:buc[i]) change(1,1,n,x.l,x.r,x.v);
		puttag(1,1);
		for(auto x:qr[i]) ans[x.se]=query(1,1,n,1,x.fi);
	}
	fr(i,1,m) printf("%lld\n",ans[i]);
	return 0;
}

inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}