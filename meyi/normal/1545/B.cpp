#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10,mod=998244353;
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
    inline modint &operator++(int){return *this+=1;}
};
using mi=modint;
mi fac[maxn],ifac[maxn];
inline mi C(int x,int y){
	return fac[x]*ifac[y]*ifac[x-y];
}
int n,t_case;
char s[maxn];
int main(){
	fac[0]=1;
	for(ri i=1;i<100001;++i)fac[i]=fac[i-1]*i;
	ifac[100000]=1/fac[100000];
	for(ri i=100000;i;--i)ifac[i-1]=ifac[i]*i;
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&n,s+1);
		ri cnt1=0,cnt2=0;
		for(ri i=1;i<=n;++i)
			if(s[i]=='1'){
				ri j=i+1;
				for(;j<=n&&s[j]=='1';++j);
				ri len=j-i;
				cnt1+=len/2,cnt2+=len%2;
				i=j;
			}
		printf("%d\n",C(n-cnt1-cnt2,cnt1));
	}
}