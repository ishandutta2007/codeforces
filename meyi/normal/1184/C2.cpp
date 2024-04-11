#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=3e5+10,maxv=4e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline int qr(){
	ri in=0;bool f=false;char ch;
	while(!isdigit(ch=getchar()))f|=(ch=='-');
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return f?-in:in;
}
int mx[maxv<<2],tag[maxv<<2];
void modify(int p,int l,int r,int ql,int qr,int v){
	if(ql<=l&&r<=qr){
		mx[p]+=v,tag[p]+=v;
		return;
	}
	mx[p<<1]+=tag[p],tag[p<<1]+=tag[p];
	mx[p<<1|1]+=tag[p],tag[p<<1|1]+=tag[p];
	tag[p]=0;
	ri mid=l+r>>1;
	if(ql<=mid)modify(p<<1,l,mid,ql,qr,v);
	if(qr>mid)modify(p<<1|1,mid+1,r,ql,qr,v);
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
int ans,id[maxn],lim,n,x[maxn],y[maxn];
int main(){
	n=qr(),lim=qr();
	for(ri i=1;i<=n;++i){
		id[i]=i;
		*x=qr()+1000000,*y=qr()+1000000;
		x[i]=*x+*y,y[i]=*x+2000000-*y;
	}
	sort(id+1,id+n+1,[&](int u,int v){return x[u]<x[v];});
	for(ri i=0,jj=1,kk=1;i<=4000000;++i){
		ri j=id[jj];
		while(jj<=n&&x[j]<=i+lim)modify(1,0,4000000,max(y[j]-lim,0),min(y[j]+lim,4000000),1),j=id[++jj];
		ri k=id[kk];
		while(kk<=n&&x[k]<i-lim)modify(1,0,4000000,max(y[k]-lim,0),min(y[k]+lim,4000000),-1),k=id[++kk];
		ckmax(ans,mx[1]);
	}
	printf("%d",ans);
	return 0;
}