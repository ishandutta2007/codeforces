#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxm=1e5+10,maxn=61,mod=998244353;
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
mi ans,f[maxn][maxm],pre[maxm];
int l[maxn],m,n,r[maxn];
bool vis[maxm];
vector<int>fac[maxm];
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d%d",l+i,r+i);
	for(ri i=2;i<=m;++i)
		if(!fac[i].size())
			for(ri j=i;j<=m;j+=i){
				fac[j].push_back(i);
				if((j/i)%i==0)vis[j]=true;
			}
	for(ri i=1;i*n<=m;++i)
		if(!vis[i]){
			f[0][0]=pre[0]=1;
			for(ri j=i;j<=m;j+=i)pre[j]=1;
			for(ri j=1;j<=n;++j){
				ri L=((l[j]+i-1)/i)*i,R=(r[j]/i)*i;
				for(ri k=0;k<L;k+=i)f[j][k]=0;
				for(ri k=L;k<=m;k+=i)f[j][k]=pre[k-L]-(k-R-i>=0?pre[k-R-i]:0);
				pre[0]=f[j][0];
				for(ri k=i;k<=m;k+=i)pre[k]=pre[k-i]+f[j][k];
			}
			mi sum=0;
			for(ri j=0;j<=m;j+=i)sum+=f[n][j];
			ans+=((fac[i].size()&1)?mod-1:1)*sum;
		}
	printf("%d",ans);
	return 0;
}