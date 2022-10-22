#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
int ans[maxn],id[maxn],m,n,rk[maxn],x[maxn],y[maxn],z[maxn];
struct undo_dsu{
	int cnt,fa[maxn],siz[maxn],tp;
	typedef pair<int,int> pii;
	#define fi first
	#define se second
	pii st[maxn];
	inline void init(int k){cnt=k;for(ri i=1;i<=k;++i)fa[i]=i,siz[i]=1;}
	int find(int k){return k==fa[k]?k:find(fa[k]);}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			if(siz[x]>siz[y])swap(x,y);
			cnt-=siz[x]&1,cnt-=siz[y]&1;
			fa[x]=y,siz[y]+=siz[x],st[++tp]={x,y};
			cnt+=siz[y]&1;
		}
	}
	inline void undo(int k){
		while(tp>k){
			ri x=st[tp].fi,y=st[tp].se;
			cnt-=siz[y]&1;
			fa[x]=x,siz[y]-=siz[x],--tp;
			cnt+=siz[x]&1,cnt+=siz[y]&1;
		}
	}
}d;
void solve(int l,int r,int L,int R){
	if(l>r||L>R)return;
	ri mid=l+r>>1,tmp=d.tp;
	for(ri i=l;i<=mid;++i)
		if(rk[i]<L)
			d.merge(x[i],y[i]);
	for(ri i=L;i<=R;++i)
		if(id[i]<=mid){
			d.merge(x[id[i]],y[id[i]]);
			if(!d.cnt){
				ans[mid]=i;
				break;
			}
		}
	d.undo(tmp);
	if(ans[mid]){
		tmp=d.tp;
		for(ri i=L;i<ans[mid];++i)
			if(id[i]<l)
				d.merge(x[id[i]],y[id[i]]);
		solve(l,mid-1,ans[mid],R);
		d.undo(tmp);
	}
	tmp=d.tp;
	for(ri i=l;i<=mid;++i)
		if(rk[i]<L)
			d.merge(x[i],y[i]);
	solve(mid+1,r,L,ans[mid]?ans[mid]:R);
	d.undo(tmp);
}
int main(){
	scanf("%d%d",&n,&m);
	d.init(n);
	z[0]=-1;
	for(ri i=1;i<=m;++i)id[i]=i,scanf("%d%d%d",x+i,y+i,z+i);
	sort(id+1,id+m+1,[&](int x,int y){return z[x]<z[y];});
	for(ri i=1;i<=m;++i)rk[id[i]]=i;
	solve(1,m,1,m);
	for(ri i=1;i<=m;++i)printf("%d\n",z[id[ans[i]]]);
	return 0;
}