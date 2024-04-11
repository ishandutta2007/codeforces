#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=110;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int mod;
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
mi C[maxn][maxn];
inline void init(int sz){
	C[0][0]=1;
	for(ri i=1;i<=sz;++i){
		C[i][0]=C[i][i]=1;
		for(ri j=1;j<i;++j)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
}
mi f[maxn][maxn][maxn];
int k,m,n;
bool vis[maxn][maxn][maxn];
mi dfs(int x,int y,int z){
	if(x+1<(z<<1)||x<z||(y>m&&z)||(y==m&&z>1))return 0;
	if(!x)return !z;
	if(vis[x][y][z])return f[x][y][z];
	vis[x][y][z]=true;
	ri lim=z-(y==m);
	for(ri i=0;i<x;++i)
		for(ri j=0;j<=lim;++j)
			f[x][y][z]+=C[x-1][i]*dfs(i,y+1,j)*dfs(x-1-i,y+1,lim-j);
	return f[x][y][z];
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&mod);
	init(n);
	printf("%d",dfs(n,1,k));
	return 0;
}