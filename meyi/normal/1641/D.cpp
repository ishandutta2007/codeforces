#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef unsigned long long ll;
const int maxn=1e5+10;
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
struct edge{
	int to,nxt;
}e[maxn*5];
int cnt[maxn*5],hd[1<<20],len,n;
ll msk[maxn*5];
inline int insert(int x){
	ri k=x&1048575;
	for(ri i=hd[k];i;i=e[i].nxt)
		if(e[i].to==x){
			if(++cnt[i]==n)printf("-1"),exit(0);
			return i;
		}
	++len;
	cnt[len]=1;
	e[len]={x,hd[k]};
	hd[k]=len;
	msk[len]=~0ull;
	return len;
}
struct node{
	int v[5],w;
	inline bool operator<(const node &k)const{return w<k.w;}
}a[maxn];
int ans=INT_MAX,m;
int main(){
	n=qr(),m=qr();
	for(ri i=1;i<=n;++i){
		for(ri j=0;j<m;++j)a[i].v[j]=insert(qr());
		a[i].w=qr();
	}
	sort(a+1,a+n+1);
	for(ri i=1;i<=n;i+=64){
		if(a[1].w+a[i].w>=ans)break;
		ri nxt=min(i+63,n);
		for(ri j=i;j<=nxt;++j)
			for(ri k=0;k<m;++k)
				msk[a[j].v[k]]^=1ull<<(63-j+i);
		for(ri j=1,jj=lower_bound(a+1,a+nxt,node{0,0,0,0,0,ans-a[i].w})-a;j<jj;++j){
			ll bit=~0ull;
			for(ri k=0;bit&&k<m;++k)bit&=msk[a[j].v[k]];
			if(bit){
				ri pos=i+__builtin_clzll(bit);
				if(pos<=n){
					if(a[j].w+a[pos].w<ans){
						ans=a[j].w+a[pos].w;
						jj=lower_bound(a+1,a+nxt,node{0,0,0,0,0,ans-a[i].w})-a;
					}
					if(pos==i)break;
				}
			}
		}
		for(ri j=i;j<=nxt;++j)
			for(ri k=0;k<m;++k)
				msk[a[j].v[k]]^=1ull<<(63-j+i);
	}
	printf("%d",ans==INT_MAX?-1:ans);
	return 0;
}