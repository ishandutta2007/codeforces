#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

#define int long long
int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2e5+5,M=1e6+5;
int n,m,P;
struct Node {
	int a,c;
} p[N],q[N];
struct Point {
	int x,y,z;
} a[N];

int arr[M],S=1e6+1;
int seg[M<<2],tag[M<<2];
#define lc (k<<1)
#define rc (lc|1)
#define left lc,l,mid
#define right rc,mid+1,r
void pushup(int k) {seg[k]=max(seg[lc],seg[rc]);}
void puttag(int k,int v) {seg[k]+=v; tag[k]+=v;}
void pushdown(int k) {if(tag[k]) puttag(lc,tag[k]),puttag(rc,tag[k]),tag[k]=0;}
void build(int k,int l,int r) {
	tag[k]=0;
	if(l==r) return seg[k]=arr[l],void();
	int mid=l+r>>1;
	build(left); build(right); pushup(k);
}
void change(int k,int l,int r,int x,int y,int v) {
	if(x<=l&&r<=y)
		return puttag(k,v);
	int mid=l+r>>1; pushdown(k);
	if(x<=mid) change(left,x,y,v);
	if(y>mid) change(right,x,y,v);
	pushup(k);
}
signed main() {
	scanf("%lld%lld%lld",&n,&m,&P);
	fr(i,1,n) scanf("%lld%lld",&p[i].a,&p[i].c);
	memset(arr,-0x3f,sizeof arr);
	fr(i,1,m) {
		scanf("%lld%lld",&q[i].a,&q[i].c);
		arr[q[i].a]=max(arr[q[i].a],-q[i].c);
	}
	build(1,1,S);
	fr(i,1,P) scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
	sort(p+1,p+n+1,[](const Node &a,const Node &b) {
		return a.a<b.a;
	});
	sort(a+1,a+P+1,[](const Point &a,const Point &b) {
		return a.x<b.x;
	});
	int cur=1; int ans=-2e9;
	fr(i,1,n) {
		while(cur<=P&&a[cur].x<p[i].a) {
			change(1,1,S,a[cur].y+1,S,a[cur].z);
			++cur;
		}
		ans=max(ans,seg[1]-p[i].c);
	}
	printf("%lld\n",ans);
	return 0;
}