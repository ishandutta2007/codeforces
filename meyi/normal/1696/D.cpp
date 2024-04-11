#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int inf=0x3f3f3f3f,maxn=2.5e5+10;
struct SGT{
	struct segment_tree{
		int l,r,v;
	}t[maxn<<2];
	#define ls(p) (p<<1)
	#define rs(p) (p<<1|1)
	inline void push_up(int p){
		t[p].v=min(t[ls(p)].v,t[rs(p)].v);
	}
	void build(int p,int l,int r){
		t[p].l=l,t[p].r=r,t[p].v=inf;
		if(l==r)return;
		ri mid=l+r>>1;
		build(ls(p),l,mid);
		build(rs(p),mid+1,r);
	}
	#define no_intersection (t[p].l>r||l>t[p].r)
	#define is_subseg (l<=t[p].l&&t[p].r<=r)
	void modify(int p,int l,int r,int v){
		if(no_intersection)return;
		if(is_subseg){
			t[p].v=v;
			return;
		}
		modify(ls(p),l,r,v);
		modify(rs(p),l,r,v);
		push_up(p);
	}
	int query(int p,int l,int r){
		if(no_intersection)return inf;
		if(is_subseg)return t[p].v;
		return min(query(ls(p),l,r),query(rs(p),l,r));
	}
}t[2];
int a[maxn],f[maxn],m,n,st1[maxn],st2[maxn],tp1,tp2,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		t[0].build(1,1,n);
		t[1].build(1,1,n);
		memset(f,0x3f,n+1<<2);
		f[1]=0;
		t[0].modify(1,1,1,0);
		t[1].modify(1,1,1,0);
		tp1=tp2=0;
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			vector<int>tmp1,tmp2;
			while(tp1&&a[i]>a[st1[tp1]])tmp1.push_back(st1[tp1--]);
			while(tp2&&a[i]<a[st2[tp2]])tmp2.push_back(st2[tp2--]);
			if(i>1){
//				printf("! %d %d %d\n",i,st1[tp1]+1,st2[tp2]+1);
				f[i]=min(t[1].query(1,st1[tp1]+1,i-1),t[0].query(1,st2[tp2]+1,i-1))+1;
				for(ri j:tmp1)t[0].modify(1,j,j,inf);
				for(ri j:tmp2)t[1].modify(1,j,j,inf);
				t[0].modify(1,i,i,f[i]);
				t[1].modify(1,i,i,f[i]);
			}
			st1[++tp1]=i,st2[++tp2]=i;
		}
		printf("%d\n",f[n]);
	}
	return 0;
}