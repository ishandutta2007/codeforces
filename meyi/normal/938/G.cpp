#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=4e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
struct LB{
	int b[30];
	inline LB(){memset(b,0,sizeof b);}
	inline void insert(int k){
		for(ri i=29;~i;--i)
			if(k&(1<<i)){
				if(!b[i]){b[i]=k;return;}
				else k^=b[i];
			}
	}
	inline int query(int k){
		for(ri i=29;~i;--i)ckmin(k,k^b[i]);
		return k;
	}
};
struct undo_dsu{
	int fa[maxn],siz[maxn],tp,val[maxn];
	typedef pair<int,int> pii;
	#define fi first
	#define se second
	pii st[maxn];
	inline void init(int k){for(ri i=1;i<=k;++i)fa[i]=i,siz[i]=1;}
	int find(int k){return k==fa[k]?k:find(fa[k]);}
	int find_val(int k){return val[k]^(k==fa[k]?0:find_val(fa[k]));}
	inline void merge(int x,int y,int z,LB &b){
		ri fx=find(x),fy=find(y);
		z^=find_val(x)^find_val(y);
		if(fx==fy)b.insert(z);
		else{
			if(siz[fx]>siz[fy])swap(fx,fy);
			fa[fx]=fy,siz[fy]+=siz[fx],st[++tp]={fx,fy},val[fx]=z;
		}
	}
	inline void undo(int k){
		while(tp>k){
			ri x=st[tp].fi,y=st[tp].se;
			fa[x]=x,siz[y]-=siz[x],--tp,val[x]=0;
		}
	}
}d;
struct segment_tree{
	int l,r;
	vector<int>v;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r)return;
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
}
void modify(int p,int l,int r,int v){
	if(t[p].l>r||l>t[p].r)return;
	if(l<=t[p].l&&t[p].r<=r){
		t[p].v.push_back(v);
		return;
	}
	modify(ls(p),l,r,v);
	modify(rs(p),l,r,v);
}
int op[maxn],x[maxn],y[maxn],z[maxn];
void solve(int p,LB b){
	ri tmp=d.tp;
	for(ri &i:t[p].v)d.merge(x[i],y[i],z[i],b);
	if(t[p].l==t[p].r){
		if(op[t[p].l]==3)printf("%d\n",b.query(d.find_val(x[t[p].l])^d.find_val(y[t[p].l])));
	}
	else solve(ls(p),b),solve(rs(p),b);
	d.undo(tmp);
}
map<int,int>lst[maxn];
int m,n,q;
int main(){
	scanf("%d%d",&n,&m);
	d.init(n);
	for(ri i=1;i<=m;++i){
		scanf("%d%d%d",x+i,y+i,z+i);
		lst[x[i]][y[i]]=i;
	}
	scanf("%d",&q);
	build(1,1,m+q);
	for(ri i=m+1;i<=m+q;++i){
		scanf("%d%d%d",op+i,x+i,y+i);
		if(op[i]==1){
			scanf("%d",z+i);
			lst[x[i]][y[i]]=i;
		}
		else if(op[i]==2){
			auto it=lst[x[i]].find(y[i]);
			modify(1,it->se,i-1,it->se);
			it->se=0;
		}
	}
	for(ri i=1;i<=n;++i)
		for(auto &j:lst[i])
			if(j.se)
				modify(1,j.se,m+q,j.se);
	solve(1,LB());
	return 0;
}