#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
map<int,int>e[maxn];
int m,n,x[maxn],y[maxn];
typedef pair<int,int> pii;
#define fi first
#define se second
struct undo_dsu{
	int fa[maxn<<1],siz[maxn<<1],tp;
	pii st[maxn<<1];
	inline void init(int k){for(ri i=1;i<=k;++i)fa[i]=i,siz[i]=1;}
	int find(int k){return k==fa[k]?k:find(fa[k]);}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			if(siz[x]>siz[y])swap(x,y);
			fa[x]=y,siz[y]+=siz[x],st[++tp]={x,y};
		}
	}
	inline void undo(int k){
		while(tp>k){
			fa[st[tp].fi]=st[tp].fi;
			siz[st[tp].se]-=siz[st[tp].fi];
			--tp;
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
void solve(int p){
	ri tmp=d.tp;
	for(ri i:t[p].v){
		d.merge(x[i],y[i]+n),d.merge(x[i]+n,y[i]);
		if(d.find(x[i])==d.find(x[i]+n)||d.find(y[i])==d.find(y[i]+n)){
			for(ri j=t[p].l;j<=t[p].r;++j)puts("NO");
			goto skip;
		}
	}
	if(t[p].l==t[p].r)puts("YES");
	else solve(ls(p)),solve(rs(p));
	skip:;
	d.undo(tmp);
}
int main(){
	scanf("%d%d",&n,&m);
	build(1,1,m);
	d.init(n<<1);
	for(ri i=1;i<=m;++i){
		scanf("%d%d",x+i,y+i);
		auto it=e[x[i]].find(y[i]);
		if(it==e[x[i]].end())e[x[i]][y[i]]=i;
		else if(!it->se)it->se=i;
		else modify(1,it->se,i-1,it->se),it->se=0;
	}
	for(ri i=1;i<=n;++i)
		for(auto &j:e[i])
			if(j.se)
				modify(1,j.se,m,j.se);
	solve(1);
	return 0;
}