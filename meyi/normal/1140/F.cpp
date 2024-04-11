#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10,mx=3e5;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
ll ans;
struct undo_dsu{
	int fa[maxn<<1],sizl[maxn<<1],sizr[maxn<<1],tp;
	typedef pair<int,int> pii;
	#define fi first
	#define se second
	pii st[maxn<<1];
	int find(int k){return k==fa[k]?k:find(fa[k]);}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			if(sizl[x]+sizr[x]>sizl[y]+sizr[y])swap(x,y);
			ans+=1ll*sizl[x]*sizr[y]+1ll*sizr[x]*sizl[y];
			fa[x]=y,sizl[y]+=sizl[x],sizr[y]+=sizr[x],st[++tp]={x,y};
		}
	}
	inline void undo(int k){
		while(tp>k){
			ri x=st[tp].fi,y=st[tp].se;
			fa[x]=x,sizl[y]-=sizl[x],sizr[y]-=sizr[x],--tp;
			ans-=1ll*sizl[x]*sizr[y]+1ll*sizr[x]*sizl[y];
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
int x[maxn],y[maxn];
void solve(int p){
	ri tmp=d.tp;
	for(ri i:t[p].v)d.merge(x[i],y[i]);
	if(t[p].l==t[p].r)printf("%lld ",ans);
	else solve(ls(p)),solve(rs(p));
	d.undo(tmp);
}
map<int,int>lst[maxn];
int n;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=mx;++i)d.fa[i]=i,d.sizl[i]=1;
	for(ri i=mx+1;i<=(mx<<1);++i)d.fa[i]=i,d.sizr[i]=1;
	build(1,1,n);
	for(ri i=1;i<=n;++i){
		scanf("%d%d",x+i,y+i);
		y[i]+=mx;
		auto it=lst[x[i]].find(y[i]);
		if(it==lst[x[i]].end())lst[x[i]][y[i]]=i;
		else if(!it->se)it->se=i;
		else modify(1,it->se,i-1,it->se),it->se=0;
	}
	for(ri i=1;i<=mx;++i)
		for(auto &j:lst[i])
			if(j.se)
				modify(1,j.se,n,j.se);
	solve(1);
	return 0;
}