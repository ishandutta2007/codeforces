#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10,mod=1e9+7;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
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
mi pw2[maxn];
int cnt[maxn],d[maxn][21];
inline void insert(int id,int k){
	for(ri i=20;~i;--i)
		if((k>>i)&1){
			if(!d[id][i]){
				++cnt[id];
				d[id][i]=k;
				return;
			}
			else k^=d[id][i];
		}
}
inline bool check(int id,int k){
	ri ret=0;
	for(ri i=20;~i;--i)
		if(((ret>>i)&1)^((k>>i)&1))
			ret^=d[id][i];
	return ret==k;
}
int a[maxn],m,n;
signed main(){
	pw2[0]=1;
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)pw2[i]=pw2[i-1]+pw2[i-1];
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		cnt[i]=cnt[i-1];
		memcpy(d[i],d[i-1],sizeof d[i-1]);
		insert(i,a[i]);
	}
	while(m--){
		ri x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",check(x,y)?pw2[x-cnt[x]]:0);
	}
	return 0;
}