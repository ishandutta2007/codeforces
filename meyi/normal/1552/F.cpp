#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=1e6+10,mod=998244353;
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
struct node{
	int fr,to;
	bool v;
}e[maxn];
mi ans,f[maxn],pre[maxn];
int b[maxn],bl,m,n,rev[maxn],t_case;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d%d%d",&e[i].fr,&e[i].to,&e[i].v);
		b[++bl]=e[i].fr,b[++bl]=e[i].to;
	}
	sort(b+1,b+bl+1);
	bl=unique(b+1,b+bl+1)-b-1;
	ans=(b[bl]+1)%mod;
	for(ri i=1;i<=n;++i){
		e[i].fr=lower_bound(b+1,b+bl+1,e[i].fr)-b;
		e[i].to=lower_bound(b+1,b+bl+1,e[i].to)-b;
		rev[e[i].fr]=i;
	}
	for(ri i=1;i<=bl;++i){
		if(rev[i]){
			f[i]=b[i]-b[e[rev[i]].to]+pre[i-1]-pre[e[rev[i]].to-1];
			if(e[rev[i]].v)ans+=f[i];
		}
		pre[i]=pre[i-1]+f[i];
	}
	printf("%d",ans);
	return 0;
}