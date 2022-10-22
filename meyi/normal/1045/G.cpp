#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline int qr(){
	int in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
struct node{int f,r,L,R,x;}a[maxn];
ll ans;
int b[maxn*3],c[maxn*3],bl,k,n;
#define lowbit(k) (k&-k)
inline void add(int k,int v){
	for(ri i=k;i<=bl;i+=lowbit(i))c[i]+=v;
}
inline int query(int l,int r){
	ri ret=0;
	for(ri i=r;i;i^=lowbit(i))ret+=c[i];
	for(ri i=l-1;i;i^=lowbit(i))ret-=c[i];
	return ret;
}
void solve(int l,int r){
	if(l==r)return;
	ri mid=l+r>>1;
	solve(l,mid),solve(mid+1,r);
	sort(a+l,a+mid+1,[&](const node &u,const node &v){return u.f<v.f;});
	sort(a+mid+1,a+r+1,[&](const node &u,const node &v){return u.f<v.f;});
	ri i1=l,i2=l,j=mid+1;
	while(j<=r){
		while(i1<=mid&&a[j].f-a[i1].f>=-k)add(a[i1].x,1),++i1;
		while(i2<i1&&a[j].f-a[i2].f>k)add(a[i2].x,-1),++i2;
		ans+=query(a[j].L,a[j].R),++j;
	}
	while(i1>i2)--i1,add(a[i1].x,-1);
}
int main(){
	n=qr(),k=qr();
	for(ri i=1;i<=n;++i){
		b[++bl]=a[i].x=qr();
		a[i].r=qr();
		b[++bl]=a[i].L=max(a[i].x-a[i].r,0);
		b[++bl]=a[i].R=min(a[i].x+a[i].r,(int)1e9);
		a[i].f=qr();
	}
	sort(b+1,b+bl+1);
	bl=unique(b+1,b+bl+1)-b-1;
	for(ri i=1;i<=n;++i){
		a[i].x=lower_bound(b+1,b+bl+1,a[i].x)-b;
		a[i].L=lower_bound(b+1,b+bl+1,a[i].L)-b;
		a[i].R=lower_bound(b+1,b+bl+1,a[i].R)-b;
	}
	sort(a+1,a+n+1,[&](const node &u,const node &v){return u.r!=v.r?u.r>v.r:u.f<v.f;});
	solve(1,n);
	printf("%lld",ans);
	return 0;
}