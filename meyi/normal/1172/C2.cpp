#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10,mod=998244353;
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
mi f[3001][3001],g[3001][3001],inv[6001];
int a[maxn],b[maxn],m,n,sum[3];
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d",b+i);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		sum[b[i]]+=a[i];
		sum[2]+=a[i];
	}
	for(ri i=max(0,m-sum[0]);i<=2*m;++i)inv[i]=mi(1)/(sum[2]+i-m);
	for(ri i=m;~i;--i){
		f[i][m-i]=g[i][m-i]=1;
		for(ri j=min(m-i-1,sum[0]);~j;--j){
			f[i][j]=((sum[1]+i+1)*f[i+1][j]+(sum[0]-j)*f[i][j+1])*inv[i-j+m];
			g[i][j]=((sum[1]+i)*g[i+1][j]+(sum[0]-j-1)*g[i][j+1])*inv[i-j+m];
		}
	}
	for(ri x=1;x<=n;++x)printf("%d\n",a[x]*(b[x]?f[0][0]:g[0][0]));
	return 0;
}
//f[i][j][k]  i  j k 