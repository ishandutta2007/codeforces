#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10,mod=1e9+7;
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
mi ans;
bool flag;
int b,c,q,r,t_case,y,z;
inline mi calc(int p){
	if(1ll*p*q/__gcd(p,q)!=r)return 0;
	if(b>c-r||b+1ll*q*(y-1)<c+1ll*r*(z-1)+r){
		flag=true;
		return 0;
	}
	return mi(r/p)*mi(r/p);
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d%d%d%d",&b,&q,&y,&c,&r,&z);
		if(r%q||b>c||b+1ll*q*(y-1)<c+1ll*r*(z-1)||(b%q+q)%q!=(c%q+q)%q){
			puts("0");
			continue;
		}
		ans=flag=0;
		for(ri p=1,pp=sqrt(r);p<=pp;++p)
			if(r%p==0){
				ans+=calc(p);
				if(p*p!=r)ans+=calc(r/p);
			}
		if(flag)puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}