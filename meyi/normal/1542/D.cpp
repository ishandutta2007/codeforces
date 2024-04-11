#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=510,mod=998244353;
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
    inline modint &operator++(int){return *this+=1;}
};
using mi=modint;
mi ans,f[maxn][maxn];
int a[maxn],n;
char op[5];
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%s",op);
		if(*op=='+')scanf("%d",a+i);
	}
	for(ri i=1;i<=n;++i){
		f[0][0]=1;
		for(ri j=1;j<i;++j){
			for(ri k=0;k<=n;++k)f[j][k]=f[j-1][k];
			if(!a[j]){f[j][0]+=f[j-1][0];for(ri k=0;k<n;++k)f[j][k]+=f[j-1][k+1];}
			else if(a[j]<=a[i])for(ri k=1;k<=n;++k)f[j][k]+=f[j-1][k-1];
			else for(ri k=0;k<=n;++k)f[j][k]+=f[j-1][k];
		}
		for(ri j=0;j<=n;++j)f[i][j]=f[i-1][j];
		for(ri j=i+1;j<=n;++j){
			for(ri k=0;k<=n;++k)f[j][k]=f[j-1][k];
			if(!a[j])for(ri k=0;k<n;++k)f[j][k]+=f[j-1][k+1];
			else if(a[j]<a[i])for(ri k=1;k<=n;++k)f[j][k]+=f[j-1][k-1];
			else for(ri k=0;k<=n;++k)f[j][k]+=f[j-1][k];
		}
		for(ri j=0;j<=n;++j)ans+=a[i]*f[n][j];
	}
	printf("%d",ans);
	return 0;
}