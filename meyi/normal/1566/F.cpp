#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
const ll inf=0x3f3f3f3f3f3f3f3fll;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
vector<ll>tmp;
struct SGT{
	struct segment_tree{
		int l,r;
		ll v;
	}t[maxn<<2];
	#define ls(p) (p<<1)
	#define rs(p) (p<<1|1)
	inline void push_up(int p){
		t[p].v=min(t[ls(p)].v,t[rs(p)].v);
	}
	void build(int p,int l,int r){
		if(l>r)return;
		t[p].l=l,t[p].r=r;
		if(l==r){
			t[p].v=tmp[t[p].l];
			return;
		}
		ri mid=l+r>>1;
		build(ls(p),l,mid);
		build(rs(p),mid+1,r);
		push_up(p);
	}
	#define no_intersection (t[p].l>r||l>t[p].r)
	#define is_subset (l<=t[p].l&&t[p].r<=r)
	inline ll query(int p,int l,int r){
		if(l>r||no_intersection)return inf;
		if(is_subset)return t[p].v;
		return min(query(ls(p),l,r),query(rs(p),l,r));
	}
}t1,t2;
int a[maxn],m,n,t_case;
vector<int>dis;
vector<ll>f[maxn];
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>v[maxn];
template<class T>
inline void my_resize(vector<T> &arr,int siz,T val){
	arr=vector<T>(siz,val);
}
signed main(){
	a[0]=-1e9;
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		v[0].clear();
		for(ri i=1;i<=n;++i)scanf("%d",a+i),v[i].clear();
		sort(a+1,a+n+1);
		for(ri i=1,l,r;i<=m;++i){
			scanf("%d%d",&l,&r);
			ri pl=lower_bound(a+1,a+n+1,l)-a,pr=upper_bound(a+1,a+n+1,r)-a;
			if(pl!=pr)continue;
			v[pl-1].emplace_back(l,r);
		}
		for(ri i=0;i<=n;++i){
			v[i].emplace_back(a[i],a[i]);
			sort(v[i].begin(),v[i].end());
			my_resize(f[i],v[i].size(),inf);
		}
		f[0][0]=0;
		for(ri i=1;i<=n;++i){
			my_resize(dis,f[i-1].size()+1,0);
			if(v[i-1].size()){
				for(ri j=f[i-1].size()-1;~j;--j)
					dis[j]=max(dis[j+1],a[i]-v[i-1][j].se);
				tmp=f[i-1];
				for(ri j=0;j<f[i-1].size();++j)tmp[j]+=dis[j+1];
				t1.build(1,0,tmp.size()-1);
				for(ri j=0;j<f[i-1].size();++j)tmp[j]+=dis[j+1];
				t2.build(1,0,tmp.size()-1);
		 	}
			for(ri j=0;j<v[i].size();++j){
				ll d=v[i][j].fi-a[i];
				ri pos=lower_bound(dis.begin(),dis.end(),d,greater<int>())-dis.begin()-1;
				f[i][j]=min(t1.query(1,0,pos-1)+2*d,t2.query(1,pos,dis.size()-1)+d);
			}
		}
		printf("%lld\n",f[n].back());
	}
	return 0;
}