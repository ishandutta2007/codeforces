#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10,mod=1e9+7;
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
    template<class T>friend modint operator^(modint a,T b){return a^=b;}
    template<class T>friend modint operator/(modint a,T b){return a/=b;}
    friend modint operator^(modint a,int b){return a^=b;}
    friend bool operator==(modint a,int b){return a.val==b;}
    friend bool operator!=(modint a,int b){return a.val!=b;}
    inline bool operator!(){return !val;}
    inline modint operator-(){return val?mod-val:0;}
    inline modint &operator++(){return *this+=1;}
};
using mi=modint;
inline mi ex_euler(mi x,ll y){
	return x^(y%(mod-1));
}
inline mi calc(int k){
	if(!k)return 1;
	ll n=(1ll<<k)-1;
	return ex_euler(4,n-1);
}
int k;
unordered_map<ll,int>clr;
#define fi first
#define se second
inline void insert(ll p,int t){
	if(!p)return;
	auto it=clr.find(p);
	if(it!=clr.end()){
		if(it->se==7)it->se=t;
		else if(t!=7&&t!=it->se)putchar(48),exit(0);
	}
	else clr[p]=t;
	insert(p>>1,7);
}
unordered_map<ll,mi>f[7];
mi dfs(ll p,int t){
	auto it=f[t].find(p);
	if(it!=f[t].end())return it->se;
	mi ret=0;
	ri hb=63-__builtin_clzll(p),tmp=clr[p];
	if(tmp==7)tmp=t;
	else if(!tmp)return calc(k-hb);
	else if(tmp!=t)return 0;
	if(k==hb+1)return 1;
	for(ri i=1;i<7;++i)
		if(i!=t&&i+t!=7)
			for(ri j=1;j<7;++j)
				if(j!=t&&j+t!=7)
					ret+=dfs(p<<1,i)*dfs(p<<1|1,j);
	return f[t][p]=ret;
}
mi ans;
int id[256],n;
char s[11];
int main(){
	id['w']=1,id['y']=6,id['g']=2,id['b']=5,id['r']=3,id['o']=4;
	scanf("%d%d",&k,&n);
	while(n--){
		ll x;
		scanf("%lld%s",&x,s);
		insert(x,id[*s]);
	}
	for(ri i=1;i<7;++i)ans+=dfs(1,i);
	printf("%d",ans);
	return 0;
}