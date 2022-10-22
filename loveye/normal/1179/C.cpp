#include<cstdio>
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

const int N=1e6+5,A=N-5;
int n,a[N],b[N],q,m;
int mn[N<<2],tag[N<<2];
#define lc (k<<1)
#define rc (lc|1)
#define left lc,l,mid
#define right rc,mid+1,r
void puttag(int k,int v) {mn[k]+=v; tag[k]+=v;}
void pushdown(int k) {if(tag[k]) puttag(lc,tag[k]),puttag(rc,tag[k]),tag[k]=0;}
void pushup(int k) {mn[k]=min(mn[lc],mn[rc]);}
void change(int k,int l,int r,int x,int v) {
	if(r<=x) return puttag(k,v);
	int mid=l+r>>1; pushdown(k);
	if(x>mid) change(right,x,v);
	change(left,x,v);
	pushup(k);
}
int query(int k,int l,int r) {
	if(l==r) return l;
	int mid=l+r>>1; pushdown(k);
	return mn[rc]<0?query(right):query(left);
}
int main() {
	cin>>n>>m;
	fr(i,1,n) cin>>a[i],change(1,1,A,a[i],-1);
	fr(i,1,m) cin>>b[i],change(1,1,A,b[i],1);
	cin>>q;
	while(q--) {
		static int i,x,op;
		cin>>op>>i>>x;
		if(op==1) {
			change(1,1,A,a[i],1);
			change(1,1,A,a[i]=x,-1);
		} else {
			change(1,1,A,b[i],-1);
			change(1,1,A,b[i]=x,1);
		}
		printf("%d\n",mn[1]<0?query(1,1,A):-1);
	}
	return 0;
}