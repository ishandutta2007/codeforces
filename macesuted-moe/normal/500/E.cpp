#include<bits/stdc++.h>
#define fre(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1;c=getchar(); }
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
	return x*f;
}
const int N=4e5+5;
vector<pair<int,int>>vt[N];
#define fi first
#define se second
int n,m,p[N],h[N],b[N<<1],tot,v[N<<1],ans[N];
int l[N],r[N];
struct Tree{
	#define pl p<<1
	#define pr p<<1|1
	int dat[N<<2],tag[N<<2];
	inline void build(int p,int l,int r){
		if(l==r) return dat[p]=v[l],void();
		int mid=(l+r)>>1;
		build(pl,l,mid);
		build(pr,mid+1,r);
		dat[p]=dat[pl]+dat[pr];
	}
	inline void change(int p,int l,int r,int L,int R){
		if(tag[p]) return;
		if(l>=L&&r<=R) return tag[p]=1,dat[p]=0,void();
		int mid=(l+r)>>1;
		if(L<=mid) change(pl,l,mid,L,R);
		if(R>mid) change(pr,mid+1,r,L,R);
		dat[p]=dat[pl]+dat[pr];
		if(!dat[p]) tag[p]=1;
	}
	inline int query(int p,int l,int r,int L,int R){
		if(tag[p]) return 0;
		if(l>=L&&r<=R) return dat[p];
		int mid=(l+r)>>1,res=0;
		if(L<=mid) res+=query(pl,l,mid,L,R);
		if(R>mid) res+=query(pr,mid+1,r,L,R);
		return res;
	}
}T;
signed main(){
	n=read();
	for(int i=1;i<=n;i++) p[i]=read(),h[i]=read();
	for(int i=1;i<=n;i++) b[++tot]=p[i],b[++tot]=p[i]+h[i];
	sort(b+1,b+tot+1);
	tot=unique(b+1,b+tot+1)-b-1;
	for(int i=1;i<tot;i++) v[i]=b[i+1]-b[i];
	T.build(1,1,tot);
	for(int i=1;i<=n;i++){
		l[i]=lower_bound(b+1,b+tot+1,p[i])-b;
		r[i]=lower_bound(b+1,b+tot+1,p[i]+h[i])-b;
	}
	m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		vt[x].push_back(make_pair(y,i));
	}
	for(int i=n;i>=1;i--){
		T.change(1,1,tot,l[i],r[i]-1);
		for(auto u:vt[i]) ans[u.se]=T.query(1,1,tot,l[i],l[u.fi]-1);
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}