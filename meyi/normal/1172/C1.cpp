#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=51,mod=998244353;
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
mi f[51][101][51],inv[2551];
inline void init(int k){
	inv[1]=1;
	for(ri i=2;i<=k;++i)inv[i]=(mod-mod/i)*inv[mod%i];
}
int a[maxn],b[maxn],m,n,s1,s2;
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d",b+i);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		s1+=a[i];
		if(b[i])s2+=a[i];
	}
	init(s1+m);
	for(ri x=1;x<=n;++x){
		memset(f,0,sizeof f);
		f[0][a[x]][0]=1;
		if(b[x]){
			for(ri i=0;i<m;++i)
				for(ri j=a[x];j<=a[x]+i;++j)
					for(ri k=0;k<=i;++k)
						if(f[i][j][k].val){
							ri fav=s2+k,sum=s1+k-(i-k);
							f[i+1][j+1][k+1]+=f[i][j][k]*j*inv[sum];
							f[i+1][j][k+1]+=f[i][j][k]*(fav-j)*inv[sum];
							f[i+1][j][k]+=f[i][j][k]*(sum-fav)*inv[sum];
						}
			mi ans=0;
			for(ri j=a[x];j<=a[x]+m;++j){
				mi sum=0;
				for(ri k=0;k<=m;++k)sum+=f[m][j][k];
				ans+=j*sum;
			}
			printf("%d\n",ans);
		}
		else{
			for(ri i=0;i<m;++i)
				for(ri j=max(a[x]-i,0);j<=a[x];++j)
					for(ri k=0;k<=i;++k)
						if(f[i][j][k].val){
							ri fav=s2+k,sum=s1+k-(i-k);
							f[i+1][j-1][k]+=f[i][j][k]*j*inv[sum];
							f[i+1][j][k+1]+=f[i][j][k]*fav*inv[sum];
							f[i+1][j][k]+=f[i][j][k]*(sum-fav-j)*inv[sum];
						}
			mi ans=0;
			for(ri j=max(a[x]-m,0);j<=a[x];++j){
				mi sum=0;
				for(ri k=0;k<=m;++k)sum+=f[m][j][k];
				ans+=j*sum;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
//f[i][j][k]  i  j k 