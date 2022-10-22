#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxm=37,maxn=4e5+10,mod=998244353,inv2=(mod+1)>>1;
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
int len;
inline void fwt_xor(mi *f,int val){
	for(ri k=1,kk=2;kk<=len;k<<=1,kk<<=1)
		for(ri i=0;i<len;i+=kk)
			for(ri j=0;j<k;++j){
				mi x=f[i|j],y=f[i|j|k];
				f[i|j]=(x+y)*val,f[i|j|k]=(x-y)*val;
			}
}
int m,mid,n;
struct LB{
	int cnt;
	ll f[maxm];
	inline void insert(ll x){
		for(ri i=m-1;~i;--i)
			if((x>>i)&1){
				if(f[i])x^=f[i];
				else{
					++cnt;
					f[i]=x;
					return;
				}
			}
	}
}lb;
int b;
mi ans[maxm],f[((maxm+1)>>1)+1][1<<((maxm+1)>>1)],g[1<<((maxm+1)>>1)];
#define pop __builtin_popcount
void dfs1(int p,ll xsum){
	if(p<mid){
		++f[pop(xsum>>mid)][xsum&b];
		return;
	}
	dfs1(p-1,xsum);
	if(lb.f[p])dfs1(p-1,xsum^lb.f[p]);
}
void dfs2(int p,ll xsum){
	if(p>=mid){
		++g[xsum];
		return;
	}
	dfs2(p+1,xsum);
	if(lb.f[p])dfs2(p+1,xsum^lb.f[p]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i){
		ll x;
		scanf("%lld",&x);
		lb.insert(x);
	}
	mid=(m+1)>>1,len=1<<mid,b=len-1;
	dfs1(m-1,0);
	dfs2(0,0);
	fwt_xor(g,1);
	for(ri i=0;i<=m-mid;++i){
		fwt_xor(f[i],1);
		for(ri j=0;j<len;++j)f[i][j]*=g[j];
		fwt_xor(f[i],inv2);
		for(ri j=0;j<len;++j)ans[i+pop(j)]+=f[i][j];
	}
	mi mul=mi(2)^(n-lb.cnt);
	for(ri i=0;i<=m;++i)printf("%d ",ans[i]*mul);
	return 0;
}