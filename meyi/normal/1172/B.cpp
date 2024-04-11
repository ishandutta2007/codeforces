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
mi fac[maxn],ifac[maxn];
inline void init(int sz){
	fac[0]=1;
	for(ri i=1;i<=sz;++i)fac[i]=fac[i-1]*i;
	ifac[sz]=1/fac[sz];
	for(ri i=sz;i;--i)ifac[i-1]=ifac[i]*i;
}
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v=1){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
mi f[maxn];
int deg[maxn],siz[maxn];
void dfs1(int p,int fa){
	deg[p]=!!fa;
	f[p]=siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=fa){
			++deg[p];
			dfs1(e[i].to,p);
			f[p]*=f[e[i].to];
			siz[p]+=siz[e[i].to];
		}
	f[p]*=fac[deg[p]];
}
mi ans;
int n;
int main(){
	scanf("%d",&n);
	init(n);
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	dfs1(1,0);
	printf("%d",f[1]*n);
	return 0;
}