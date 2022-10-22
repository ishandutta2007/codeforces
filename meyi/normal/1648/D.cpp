#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int inf=0x3f3f3f3f,maxn=5e5+10;
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
int a[3][maxn],m,n;
ll f[maxn],pre[2][maxn],tmp[maxn];
struct node{int l,r,k;};
void solve(vector<node>q,int l,int r,int k){
	if(l==r){
		for(const node &i:q)ckmin(k,i.k);
		if(k!=inf)ckmax(f[l],max(pre[0][l],f[l-1])+a[1][l]-k);
		return;
	}
	ri mid=l+r>>1;
	vector<node>ql,qr;
	for(node &i:q){
		ckmax(i.l,l),ckmin(i.r,r);
		if(i.l==l&&i.r==r){ckmin(k,i.k);continue;}
		if(i.l<=mid)ql.push_back(i);
		if(i.r>mid)qr.push_back(i);
	}
	solve(ql,l,mid,k);
	for(ri i=l;i<=r;++i)tmp[i]=f[0];
	tmp[mid]=f[mid]-pre[1][mid];
	for(ri i=mid;i>=l;--i)ckmax(tmp[i],max({tmp[i+1],f[i-1]-pre[1][i-1],pre[0][i]-pre[1][i-1]}));
	if(k!=inf)tmp[r]=tmp[l]+pre[1][r]-k;
	for(const node &i:q)
		if(i.l<=mid&&i.r>mid)
			ckmax(tmp[i.r],tmp[i.l]+pre[1][i.r]-i.k);
	ckmax(f[r],tmp[r]);
	for(ri i=r-1;i>mid;--i){
		ckmax(tmp[i],tmp[i+1]-a[1][i+1]);
		ckmax(f[i],tmp[i]);
	}
	solve(qr,mid+1,r,k);
}
int main(){
	n=qr(),m=qr();
	for(ri i=0;i<3;++i)
		for(ri j=1;j<=n;++j)
			a[i][j]=qr();
	for(ri i=0;i<2;++i)
		for(ri j=1;j<=n;++j)
			pre[i][j]=pre[i][j-1]+a[i][j];
	vector<node>q(m);
	for(node &i:q)i.l=qr(),i.r=qr(),i.k=qr();
	clear(f,n,-0x3f);
	solve(q,1,n,inf);
	ll ans=f[0],suf=0;
	for(ri i=n;i;--i){
		suf+=a[2][i];
		ckmax(ans,f[i]+suf);
	}
	printf("%lld",ans);
	return 0;
}