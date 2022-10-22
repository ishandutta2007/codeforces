#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int mod=1e9+7;
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
mi ans,f[1<<20],pw2[1<<20];
int m,n;
inline void fwt_and(){
	for(ri k=1,kk=2;kk<=1<<m;k<<=1,kk<<=1)
		for(ri i=0;i<1<<m;i+=kk)
			for(ri j=0;j<k;++j)
				f[i|j]+=f[i|j|k];
}
int main(){
	scanf("%d",&n);
	pw2[0]=1;
	for(ri i=1,x;i<=n;++i){
		scanf("%d",&x);
		++f[x];
		ckmax(m,x);
		pw2[i]=pw2[i-1]+pw2[i-1];
	}
	if(m)m=__lg(m)+1;
	fwt_and();
	for(ri i=0;i<1<<m;++i)ans+=(__builtin_parity(i)?mod-1:1)*(pw2[f[i].val]-1);
	printf("%d",ans);
	return 0;
}