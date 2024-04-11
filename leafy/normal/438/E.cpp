// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ntt NTT
const int N=1e6+5,P=998244353,G=3,Gi=332748118;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=(s*10+ch-'0')%P,ch=getchar();
	return s*f;
}
int n,m,k,bit=1;
int rev[N<<2];
ll a[N<<2],b[N<<2],c[N<<2],d[N<<2],e[N<<2];
ll f[N<<2],g[N<<2];
/*inline void get_rev(int n){
	bit=1;
	while(bit<=(n<<1)) bit<<=1;
	for(int i=0;i<bit;i++) rev[i]=(rev[i>>1]>>1)|(bit>>1)*(i&1);
}*/
inline ll qpow(ll a,int b){
	ll res=1;
	for(;b;b>>=1,a=a*a%P) if(b&1) res=res*a%P;
	return res;
}
inline void NTT(ll *a,int dft,int len){
	bit=1;
	while(bit<len) bit<<=1;
	for(int i=0;i<bit;i++) rev[i]=(rev[i>>1]>>1)|(bit>>1)*(i&1);
	for(int i=0;i<bit;i++)
		if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=1;i<bit;i<<=1){
		ll W=qpow(dft==1?G:Gi,(P-1)/(i<<1));
		for(int j=0;j<bit;j+=(i<<1)){
			ll w=1;
			for(int k=j;k<i+j;k++,w=w*W%P){
				ll x=a[k],y=w*a[k+i]%P;
				a[k]=(x+y)%P,a[k+i]=(x-y+P)%P;
			}
		}
	}
	if(dft==-1) {
		ll inv=qpow(bit,P-2);
		for(int i=0;i<bit;i++) a[i]=a[i]*inv%P;
	}
}
inline void get_inv(ll *a,ll *b,int n){
	if(n==1){
		b[0]=qpow(a[0],P-2);
		return;
	}
	get_inv(a,b,n>>1);
	for(int i=0;i<n;i++) c[i]=a[i];
	for(int i=n;i<bit;i++) c[i]=0;
	NTT(c,1,n<<1);NTT(b,1,n<<1);
	for(int i=0;i<bit;i++) b[i]=((2-b[i]*c[i]%P+P)%P*b[i])%P;
	NTT(b,-1,n<<1);
	for(int i=n;i<bit;i++) b[i]=0;
}
inline void der(ll *a,ll *b,int n){
	for(int i=1;i<n;i++) b[i-1]=i*a[i]%P;b[n-1]=0;
}
inline void inter(ll *a,ll *b,int n){
	for(int i=1;i<n;i++) b[i]=a[i-1]*qpow(i,P-2)%P;b[0]=0;
}
inline void get_ln(ll *f,ll *g,int n){
	der(f,a,n);get_inv(f,b,n);
	ntt(a,1,n<<1),ntt(b,1,n<<1);
	for(int i=0;i<bit;i++) a[i]=a[i]*b[i]%P;
	ntt(a,-1,n<<1);inter(a,g,n);
	for(int i=0;i<(n<<1);i++) a[i]=b[i]=0;
}
inline void exp(ll *f,ll *g,int n){ //not accepted yet
	if(n==1) {
		g[0]=1;return;
	} 
	exp(f,g,n>>1);get_ln(g,d,n);
	d[0]=(f[0]+1-d[0]+P)%P;
	for(int i=1;i<n;i++) d[i]=(f[i]-d[i]+P)%P;
	ntt(d,1,n<<1);ntt(g,1,n<<1);
	for(int i=0;i<bit;i++) g[i]=g[i]*d[i]%P;
	ntt(g,-1,n<<1);
	for(int i=n;i<bit;i++) d[i]=g[i]=0;
}
inline void poly_sqrt(ll *a,ll *b,int n){
	get_ln(a,e,n);
	for(int i=0;i<n;i++) e[i]=e[i]*qpow(2,P-2)%P;
	exp(e,b,n);
}
inline void poly_qpow(ll *a,ll *b,int k,int n){
	get_ln(a,e,n);
	for(int i=0;i<n;i++) e[i]=e[i]*k%P;
	exp(e,b,n);
}
int main(){
	/*n=read(),k=read();
	for(int i=0;i<n;i++) f[i]=read();
	while(bit<=n) bit<<=1;
	qpow(f,g,k,bit);
	for(int i=0;i<n;i++) printf("%lld ",g[i]);*/
	n=read(),m=read();
	for(int i=1;i<=n;i++) g[read()]++;
	//while(bit<=m) bit<<=1;
	for(int i=1;i<=m;i++) g[i]=(-4*g[i]%P+P)%P;
	g[0]=1;m++;
	while(bit<=m) bit<<=1;
	int len=bit;
	poly_sqrt(g,f,len);
	f[0]=(f[0]+1)%P;
	memset(g,0,sizeof(g));
	get_inv(f,g,len);
	for(int i=1;i<m;i++) printf("%I64d\n",g[i]*2%P);
    return 0;
}