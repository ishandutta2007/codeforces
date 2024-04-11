#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=210,mod=1e9+7;
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
mi ans,f[maxn][maxn],inv2=(mod+1)>>1;
int dis[maxn][maxn],n;
int main(){
	scanf("%d",&n);
	memset(dis,0x3f,sizeof dis);
	for(ri i=1;i<=n;++i)dis[i][i]=0;
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		dis[x][y]=dis[y][x]=1;
	}
	for(ri k=1;k<=n;++k)
		for(ri i=1;i<=n;++i)
			for(ri j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(ri i=1;i<=n;++i)f[i][0]=1;
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=n;++j)
			f[i][j]=(f[i-1][j]+f[i][j-1])*inv2;
	for(ri i=1;i<n;++i)
		for(ri j=i+1;j<=n;++j)
			for(ri k=1;k<=n;++k){
				if(dis[k][i]+dis[i][j]==dis[k][j])ans+=0;
				else if(dis[k][j]+dis[j][i]==dis[k][i])ans+=1;
				else{
					ri tmp=(dis[k][i]+dis[k][j]-dis[i][j])>>1;
					ans+=f[dis[k][i]-tmp][dis[k][j]-tmp];
				}
			}
	printf("%d",ans/n);
	return 0;
}