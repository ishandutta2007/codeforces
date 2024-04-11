#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int n;
struct SGT{
	struct segment_tree{
		int ls,rs;
		ll sum;
	}t[maxn<<6];
	int cnt,st[maxn],tp;
	#define new_node (tp?st[tp--]:++cnt)
	void insert(int &p,int l,int r,int k,int v){
		if(!p)p=new_node;
		t[p].sum+=v;
		if(l<r){
			ri mid=l+r>>1;
			if(k<=mid)insert(t[p].ls,l,mid,k,v);
			else insert(t[p].rs,mid+1,r,k,v);
		}
		if(!t[p].sum)st[++tp]=p,p=0;
	}
	ll query(vector<int>p1,vector<int>p2,int l,int r,int k){
		if(l==r){
			ll ret=0;
			for(ri &i:p1)ret-=t[i].sum;
			for(ri &i:p2)ret+=t[i].sum;
			return ret;
		}
		ri mid=l+r>>1;
		if(k<=mid){
			for(ri &i:p1)i=t[i].ls;
			for(ri &i:p2)i=t[i].ls;
			return query(p1,p2,l,mid,k);
		}
		else{
			ll ret=0;
			for(ri &i:p1)ret-=t[t[i].ls].sum,i=t[i].rs;
			for(ri &i:p2)ret+=t[t[i].ls].sum,i=t[i].rs;
			return ret+query(p1,p2,mid+1,r,k);
		}
	}
	int rt[maxn];
	#define lowbit(k) (k&-k)
	inline void modify(int p,int k,int v){
		for(ri i=p;i<=n;i+=lowbit(i))insert(rt[i],0,n+1,k,v);
	}
}t[2];
inline ll query_nxt(int l,int r){
	vector<int>p1;
	for(ri i=l-1;i;i^=lowbit(i))p1.push_back(t[0].rt[i]);
	vector<int>p2;
	for(ri i=r;i;i^=lowbit(i))p2.push_back(t[0].rt[i]);
	return t[0].query(p1,p2,0,n+1,n+1)-t[0].query(p1,p2,0,n+1,r);
}
inline ll query_pre(int l,int r){
	vector<int>p1;
	for(ri i=l-1;i;i^=lowbit(i))p1.push_back(t[1].rt[i]);
	vector<int>p2;
	for(ri i=r;i;i^=lowbit(i))p2.push_back(t[1].rt[i]);
	return t[1].query(p1,p2,0,n+1,l-1);
}
int a[maxn],m,nxt[maxn],pre[maxn];
set<int>pos[maxn];
inline void calc_nxt(int p){
	if(p<1||p>n)return;
	if(~nxt[p])t[0].modify(p,nxt[p],-p);
	nxt[p]=*pos[a[p]].upper_bound(p);
	t[0].modify(p,nxt[p],p);
}
inline void calc_pre(int p){
	if(p<1||p>n)return;
	if(~pre[p])t[1].modify(p,pre[p],p);
	pre[p]=*--pos[a[p]].lower_bound(p);
	t[1].modify(p,pre[p],-p);
}
inline void update(int p,int v){
	if(a[p]){
		pos[a[p]].erase(p);
		calc_pre(nxt[p]);
		calc_nxt(pre[p]);
	}
	a[p]=v;
	pos[a[p]].insert(p);
	calc_nxt(p);
	calc_pre(p);
	calc_pre(nxt[p]);
	calc_nxt(pre[p]);
}
signed main(){
	scanf("%d%d",&n,&m);
	clear(nxt,n,-1),clear(pre,n,-1);
	for(ri i=1;i<=n;++i)pos[i].insert(0),pos[i].insert(n+1);
	for(ri i=1,x;i<=n;++i)scanf("%d",&x),update(i,x);
	while(m--){
		ri op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op&1)update(x,y);
		else printf("%lld\n",query_nxt(x,y)+query_pre(x,y));
	}
	return 0;
}