#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=18,bs1=2333,bs2=2337,mod=1e9+7;
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
char s[1<<maxn];
struct hsh{
	mi x,y;
	inline hsh operator+(const hsh &k)const{return {x+k.x,y+k.y};}
	inline hsh operator*(const hsh &k)const{return {x*k.x,y*k.y};}
	inline bool operator==(const hsh &k)const{return x.val==k.x.val&&y.val==k.y.val;}
}f[maxn+1][1<<maxn];
int ans,n;
inline bool check(int x,int y){
	if(f[n][x]==f[n][y])return false;
	for(ri i=n-1;~i;--i)
		if(f[i][x]==f[i][y])
			x^=1<<i,y^=1<<i;
	return s[x]<s[y];
}
int main(){
	scanf("%d%s",&n,s);
	for(ri i=0;i<1<<n;++i)f[0][i]={s[i],s[i]};
	hsh b={bs1,bs2};
	for(ri i=0;i<n;++i){
		for(ri j=0;j<1<<n;++j)
			f[i+1][j]=f[i][j]*b+f[i][j^(1<<i)];
		b=b*b;
	}
	for(ri i=1;i<1<<n;++i)
		if(check(i,ans))
			ans=i;
	for(ri i=0;i<1<<n;++i)putchar(s[i^ans]);
	return 0;
}