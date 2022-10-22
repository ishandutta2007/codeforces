#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxk=110,maxn=1e5+10,mod=998244353;
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
mi f[maxn][maxk],sum[maxn];
int k,m,mx[maxk],n;
int main(){
	scanf("%d%d%d",&n,&k,&m);
	sum[0]=1;
	for(ri i=1,x;i<=n;++i){
		scanf("%d",&x);
		for(ri j=1;j<=k;++j){
			if(x==-1||x==j){
				f[i][j]=sum[i-1],++mx[j];
				if(i>=m&&mx[j]>=m)f[i][j]-=sum[i-m]-f[i-m][j];
				sum[i]+=f[i][j];
			}
			else mx[j]=0;
		}
	}
	printf("%d",sum[n]);
	return 0;
}