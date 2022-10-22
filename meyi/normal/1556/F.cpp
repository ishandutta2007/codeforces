#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=15,mod=1e9+7;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
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
mi a[maxn],ans,f[1<<maxn],p[maxn][maxn];
int n;
inline mi calc(int U,int S){
	vector<int>x,y;
	for(ri i=0;i<n;++i)
		if(U&(1<<i))
			((S&(1<<i))?x:y).push_back(i);
	mi mul=1;
	for(auto i:x)
		for(auto j:y)
			mul*=p[i][j];
	return mul;
}
int main(){
	scanf("%d",&n);
	for(ri i=0;i<n;++i)scanf("%d",a+i);
	for(ri i=0;i<n;++i)
		for(ri j=0;j<n;++j)
			if(i!=j)
				p[i][j]=a[i]/(a[i]+a[j]);
	ri all=(1<<n)-1;
	for(ri i=1;i<=all;++i){
		f[i]=1;
		for(ri j=i&(i-1);j;j=i&(j-1))f[i]-=calc(i,j)*f[j];
		ans+=calc(all,i)*f[i]*__builtin_popcount(i);
	}
	printf("%d",ans);
	return 0;
}