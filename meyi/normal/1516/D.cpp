#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int lg=16,maxn=1e5+10;
int a[maxn],f[maxn][lg+1],lst[maxn],m,n;
vector<int>d[maxn];
struct segment_tree{
	int l,r,v;
}t[maxn<<2];
#define ls(k) (k<<1)
#define rs(k) (k<<1|1)
inline void push_up(int p){
	t[p].v=min(t[ls(p)].v,t[rs(p)].v);
}
inline void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].v=n+1;
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
inline void modify(int p,int k,int v){
	if(t[p].l>k||k>t[p].r)return;
	if(t[p].l==k&&k==t[p].r){
		t[p].v=v;
		return;
	}
	modify(ls(p),k,v);
	modify(rs(p),k,v);
	push_up(p);
}
inline int query(int p,int l,int r){
	if(t[p].l>r||l>t[p].r)return n+1;
	if(l<=t[p].l&&t[p].r<=r)return t[p].v;
	return min(query(ls(p),l,r),query(rs(p),l,r));
}
int main(){
	for(ri i=2;i<=100000;++i)
		for(ri j=i;j<=100000;j+=i)
			d[j].push_back(i);
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	build(1,1,n);
	for(ri i=n;i;--i){
		ri mx=n+1;
		for(ri j=0;j<d[a[i]].size();++j){
			if(lst[d[a[i]][j]])mx=min(mx,lst[d[a[i]][j]]);
			lst[d[a[i]][j]]=i;
		}
		modify(1,i,mx);
		f[i][0]=query(1,i,mx-1);
	}
	for(ri i=0;i<=lg;++i)f[n+1][i]=n+1;
	for(ri j=1;j<=lg;++j)
		for(ri i=1;i<=n;++i)
			f[i][j]=f[f[i][j-1]][j-1];
	while(m--){
		ri ans=0,l,r;
		scanf("%d%d",&l,&r);
		for(ri i=lg;~i;--i)
			if(f[l][i]<=r)
				ans+=(1<<i),l=f[l][i];
		printf("%d\n",ans+1);
	}
	return 0;
}