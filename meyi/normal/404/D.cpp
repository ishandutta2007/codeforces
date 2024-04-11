#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e6+10,mod=1e9+7;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
enum{E=0,E1=1,M1=2,M2=3,M=4};
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
mi f[maxn][5];
int n;
char s[maxn];
signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	f[1][E]=(s[1]=='0'||s[1]=='?');
	f[1][E1]=(s[1]=='1'||s[1]=='?');
	f[1][M]=(s[1]=='*'||s[1]=='?');
	for(ri i=2;i<=n;++i){
		if(s[i]=='0'||s[i]=='?')f[i][E]=f[i-1][E]+f[i-1][M1];
		if(s[i]=='1'||s[i]=='?')f[i][E1]=f[i-1][E]+f[i-1][M1],f[i][M1]=f[i-1][M];
		if(s[i]=='2'||s[i]=='?')f[i][M2]=f[i-1][M];
		if(s[i]=='*'||s[i]=='?')f[i][M]=f[i-1][E1]+f[i-1][M2]+f[i-1][M];
	}
	printf("%d",f[n][E]+f[n][M1]+f[n][M]);
	return 0;
}