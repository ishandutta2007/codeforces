#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
struct segment_tree{
	int l,r,mn,sum,tag;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].mn=min(t[ls(p)].mn,t[rs(p)].mn);
	t[p].sum=(t[ls(p)].mn==t[p].mn?t[ls(p)].sum:0)+(t[rs(p)].mn==t[p].mn?t[rs(p)].sum:0);
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r,t[p].sum=r-l+1;
	if(l==r)return;
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
}
inline void add_tag(int p,int v){
	t[p].mn+=v,t[p].tag+=v;
}
inline void push_down(int p){
	if(!t[p].tag)return;
	add_tag(ls(p),t[p].tag);
	add_tag(rs(p),t[p].tag);
	t[p].tag=0;
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subseg (l<=t[p].l&&t[p].r<=r)
void modify(int p,int l,int r,int v){
	if(no_intersection)return;
	if(is_subseg){
		add_tag(p,v);
		return;
	}
	push_down(p);
	modify(ls(p),l,r,v);
	modify(rs(p),l,r,v);
	push_up(p);
}
int a[maxn],lst[30],n,st[maxn],tp;
ll ans;
int main(){
	n=qr();
	build(1,1,n);
	for(ri i=1;i<=n;++i){
		a[i]=qr();
		for(ri j=0;j<30;++j)
			if(a[i]&(1<<j))
				modify(1,lst[j]+1,i,1<<j),lst[j]=i;
		while(tp&&a[i]>=a[st[tp]]){
			modify(1,st[tp-1]+1,st[tp],a[st[tp]]);
			--tp;
		}
		modify(1,st[tp]+1,i,-a[i]);
		st[++tp]=i;
		ans+=i-(t[1].sum-(n-i));
	}
	printf("%lld",ans);
	return 0;
}