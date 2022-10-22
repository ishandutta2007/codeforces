#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=101,mod=1e9+7,inv2=(mod+1)>>1;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct modint{
	int val;
	inline modint(int val_=0):val((val_%mod+mod)%mod){}
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
typedef mi mat[maxn][maxn];
int m;
inline void mul(mat a,mat b){
	mat ret;
	memset(ret,0,sizeof ret);
	for(ri i=0;i<=m;++i)
		for(ri j=0;j<=m;++j)
			for(ri k=0;k<=m;++k)
				ret[i][j]+=a[i][k]*b[k][j];
	memcpy(a,ret,sizeof ret);
}
inline void qpow(mat a,int b){
	mat ret;
	memset(ret,0,sizeof ret);
	for(ri i=0;i<=m;++i)ret[i][i]=1;
	for(;b;mul(a,a),b>>=1)if(b&1)mul(ret,a);
	memcpy(a,ret,sizeof ret);
}
int a[maxn],cnt,k,n;
mi sum;
mat f,t;
signed main(){
	scanf("%d%d",&n,&k);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		if(!a[i])++m;
	}
	for(ri i=1;i<=m;++i)
		if(!a[i])
			++cnt;
	f[0][cnt]=1;
	for(ri i=0;i<=m;++i){
		if(i)t[i][i-1]=mi(i)*mi(n-2*m+i);
		t[i][i]=mi(n)*mi(n-1)*inv2-mi(m-i)*mi(m-i)-mi(i)*mi(n-2*m+i);
		if(i<m)t[i][i+1]=mi(m-i)*mi(m-i);
	}
	qpow(t,k);
	mul(f,t);
	for(ri i=0;i<=m;++i)sum+=f[0][i];
	printf("%d",f[0][m]/sum);
	return 0;
}
/*
n m0
m i0 m-i1
n-m  m-i0 n-2m+i1
f[i]mi0 
f[i]*(m-i)*(m-i) -> f[i+1]
f[i]*i*(n-2m+i) -> f[i-1]
f[i]*(n*(n-1)/2-(m-i)*(m-i)-i*(n-2m+i)) -> f[i] 
 f[m]/sum(f[i]) 
*/