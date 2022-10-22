#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=51,maxm=2e4+10;
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
int a[maxn][maxm],f[maxm],k,m,n,pre[maxn][maxm];
struct segment_tree{
	int l,r,v,tag;
}t[maxm<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].v=max(t[ls(p)].v,t[rs(p)].v);
}
void build(int p,int l,int r,int id){
	t[p].l=l,t[p].r=r,t[p].tag=0;
	if(l==r){
		t[p].v=f[l]-max(pre[id+1][k]-pre[id+1][l-1],0);
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid,id);
	build(rs(p),mid+1,r,id);
	push_up(p);
}
inline void add_tag(int p,int v){
	t[p].v+=v,t[p].tag+=v;
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
int main(){
	n=qr(),m=qr(),k=qr();
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=m;++j)
			pre[i][j]=pre[i][j-1]+(a[i][j]=qr());
	for(ri i=1;i+k-1<=m;++i)f[i]=pre[n][i+k-1]-pre[n][i-1];
	for(ri i=n-1;i;--i){
		build(1,1,m-k+1,i);
		for(ri j=1;j<=m-k+1;++j){
			f[j]=t[1].v+pre[i][j+k-1]-pre[i][j-1]+pre[i+1][j+k-1]-pre[i+1][j-1];
			modify(1,max(j-k+1,1),j,a[i+1][j]);
			if(j+1<=m-k+1)modify(1,j+1,min(j+k,m-k+1),-a[i+1][j+k]);
		}
	}
	printf("%d",*max_element(f+1,f+m-k+2));
	return 0;
}