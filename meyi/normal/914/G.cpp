#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e6+10,mod=1e9+7,inv2=(mod+1)>>1;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct modint{
    int val;
    inline modint(int val_=0):val(val_){}
    inline modint &operator=(int val_){return val=val_,*this;}
    inline modint &operator+=(const modint &k){return val=val+k.val>=mod?val+k.val-mod:val+k.val,*this;}
    inline modint &operator-=(const modint &k){return val=val-k.val<0?val-k.val+mod:val-k.val,*this;}
    inline modint &operator*=(const modint &k){return val=1ll*val*k.val%mod,*this;}
    inline modint &operator^=(int k){
        modint ret=1,tmp=*this;
        for(;k;k>>=1,tmp*=tmp)if(k&1)ret*=tmp;
        return val=ret.val,*this;
    }
    inline modint &operator/=(modint k){return *this*=(k^=mod-2);}
    inline modint &operator+=(int k){return val=val+k>=mod?val+k-mod:val+k,*this;}
    inline modint &operator-=(int k){return val=val<k?val-k+mod:val-k,*this;}
    inline modint &operator*=(int k){return val=1ll*val*k%mod,*this;}
    inline modint &operator/=(int k){return *this*=((modint(k))^=mod-2);}
    template<class T>friend modint operator+(modint a,T b){return a+=b;}
    template<class T>friend modint operator-(modint a,T b){return a-=b;}
    template<class T>friend modint operator*(modint a,T b){return a*=b;}
    template<class T>friend modint operator^(modint a,T b){return a/=b;}
    template<class T>friend modint operator/(modint a,T b){return a/=b;}
    friend modint operator^(modint a,int b){return a^=b;}
    friend bool operator==(modint a,int b){return a.val==b;}
    friend bool operator!=(modint a,int b){return a.val!=b;}
    inline bool operator!(){return !val;}
    inline modint operator-(){return val?mod-val:0;}
    inline modint &operator++(){return *this+=1;}
};
using mi=modint;
const int all=1<<17;
inline void fwt_and(mi *f,int v){
	for(ri k=1,kk=2;kk<=all;k<<=1,kk<<=1)
		for(ri i=0;i<all;i+=kk)
			for(ri j=0;j<k;++j)
				f[i|j]+=f[i|j|k]*v; 
}
inline void fwt_or(mi *f,int v){
	for(ri k=1,kk=2;kk<=all;k<<=1,kk<<=1)
		for(ri i=0;i<all;i+=kk)
			for(ri j=0;j<k;++j)
				f[i|j|k]+=f[i|j]*v; 
}
inline void fwt_xor(mi *f,int v){
	for(ri k=1,kk=2;kk<=all;k<<=1,kk<<=1)
		for(ri i=0;i<all;i+=kk)
			for(ri j=0;j<k;++j){
				mi x=f[i|j],y=f[i|j|k];
				f[i|j]=(x+y)*v,f[i|j|k]=(x-y)*v;
			}
}
int a[maxn],n;
mi ans[all],A[all],B[all],C[all],f[18][all],fib[all],g[all],sum;
int main(){
	fib[1]=fib[2]=1;
	for(ri i=3;i<all;++i)fib[i]=fib[i-1]+fib[i-2];
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		++B[a[i]],++C[a[i]],++f[__builtin_popcount(a[i])][a[i]];
	}
	for(ri i=0;i<18;++i){
		fwt_or(f[i],1);
		memset(g,0,sizeof g);
		for(ri j=0;j<=i;++j)
			for(ri k=0;k<all;++k)
				g[k]+=f[j][k]*f[i-j][k];
		fwt_or(g,mod-1);
		for(ri j=0;j<all;++j)
			if(__builtin_popcount(j)==i)
				A[j]+=g[j];
	}
	fwt_xor(C,1);
	for(ri i=0;i<all;++i)C[i]*=C[i];
	fwt_xor(C,inv2);
	for(ri i=0;i<all;++i)A[i]*=fib[i],B[i]*=fib[i],C[i]*=fib[i];
	fwt_and(A,1),fwt_and(B,1),fwt_and(C,1);
	for(ri i=0;i<all;++i)ans[i]=A[i]*B[i]*C[i];
	fwt_and(ans,mod-1);
	for(ri i=1;i<all;i<<=1)sum+=ans[i];
	printf("%d",sum);
	return 0;
}