#include<bits/stdc++.h>
const int S=1<<21; char ibuf[S],*iS,*iT,obuf[S],*oS=obuf,*oT=oS+S-1;
#define getchar() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,S,stdin),(iS==iT?EOF:*iS++)):*iS++)
#define i64 long long
#define i128 __int128
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
const int N=1<<21,p=490019;
const long long mod=4179340454199820289;
int n,m,c,lim=1,ans,k,a[N],b[N],g[N],f[N],rev[N];
long long F[N],G[N],w[N];
inline int fpow(int a,int b,int p){int s=1;for(;b;b>>=1,a=(i64)a*a%p)if(b&1)s=(i64)s*a%p;return s;}
inline i64 fpow(i64 a,i64 b,i64 p){i64 s=1;for(;b;b>>=1,a=(i128)a*a%p)if(b&1)s=(i128)s*a%p;return s;}
void DFT(i64 *a){
	for(int i=0;i<lim;i++)if(i<rev[i])std::swap(a[i],a[rev[i]]);
	for(int len=1;len<lim;len<<=1)
		for(int i=0;i<lim;i+=(len<<1))
			for(int j=0;j<len;j++){
				i64 x=a[i+j],y=(i128)a[i+j+len]*w[j+len]%mod;
				a[i+j]=x+y,a[i+j+len]=x-y;
				if(a[i+j]>=mod)a[i+j]-=mod;
				if(a[i+j+len]<0)a[i+j+len]+=mod;
			}	
}
int main(){
#ifdef memset0
	// freopen("1.in","r",stdin);
	freopen("comp/data.in","r",stdin);
#endif
	read(n),read(m),read(c);
	for(int i=0;i<n;i++)read(a[i]);
	for(int i=0;i<m;i++)read(b[i]);
	for(int i=0;i<m;i++)F[fpow(i,3,p-1)]+=b[i];
	f[0]=F[0],g[0]=1,g[1]=2;
	for(int i=1;i<p-1;i++)g[i]=(i64)g[i-1]*g[1]%p;
	for(int i=0;i<p-1;i++)F[i]=F[i]%p*g[(p-1-(i64)i*(i-1)/2%(p-1))%(p-1)]%p;
	for(int i=0;i<(p<<1)-1;i++)G[i]=g[(i64)i*(i-1)/2%(p-1)];
	std::reverse(F,F+p-1);
	while(lim<=(p*3-3))lim<<=1,++k;
	for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	for(int len=1;len<lim;len<<=1){
		i64 wn=fpow(3ll,(mod-1)/(len<<1),mod); w[len]=1;
		for(int i=1;i<len;i++)w[i+len]=(i128)w[i+len-1]*wn%mod;
	}
	DFT(F),DFT(G);
	for(int i=0;i<lim;i++)F[i]=(i128)F[i]*G[i]%mod;
	std::reverse(F+1,F+lim),DFT(F);
	i64 invlim=fpow((i64)lim,mod-2,mod);
	for(int i=0;i<lim;i++)F[i]=(i128)F[i]*invlim%mod;
	for(int i=0;i<p-1;i++)f[g[i]]=F[i+p-2]%p*g[(p-1-(i64)i*(i-1)/2%(p-1))%(p-1)]%p;
	for(int i=0;i<n;i++)ans=(ans+(i64)a[i]*f[fpow(fpow(c,i,p),i,p)])%p;
	printf("%d\n",ans);
}