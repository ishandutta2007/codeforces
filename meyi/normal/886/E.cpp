#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e6+10,mod=1e9+7;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
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
    template<class T>friend modint operator/(modint a,T b){return a/=b;}
    friend modint operator^(modint a,int b){return a^=b;}
    friend bool operator==(modint a,int b){return a.val==b;}
    friend bool operator!=(modint a,int b){return a.val!=b;}
    inline bool operator!(){return !val;}
    inline modint operator-(){return val?mod-val:0;}
    inline modint &operator++(){return *this+=1;}
};
using mi=modint;
mi fac[maxn],ifac[maxn],inv[maxn];
int k,n;
inline void init(){
	fac[0]=1;
	for(ri i=1;i<=n;++i)fac[i]=fac[i-1]*i;
	ifac[n]=1/fac[n];
	for(ri i=n;i;--i)ifac[i-1]=ifac[i]*i;
	inv[1]=1;
	for(ri i=2;i<=n;++i)inv[i]=(mod-mod/i)*inv[mod%i];
}
mi g[maxn],pre[maxn];
inline mi getsum(int l,int r){
	return l<1?pre[r]:pre[r]-pre[l-1];
}
int main(){
	scanf("%d%d",&n,&k);
	init();
	g[0]=pre[0]=1;
	for(ri i=1;i<=n;++i){
		g[i]=getsum(i-k,i-1)*inv[i];
		pre[i]=pre[i-1]+g[i];
	}
	printf("%d",fac[n]-pre[n-1]*fac[n-1]);
	return 0;
}