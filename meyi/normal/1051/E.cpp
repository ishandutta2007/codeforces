#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef int ll;
const int base=2333,hmod=1e9+7,maxn=1e6+10,mod=998244353;
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
mi pre[maxn];
inline void build(char *s,int &n,ll *h){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(ri i=1;i<=n;++i)h[i]=(1ll*h[i-1]*base+s[i])%hmod;
}
char a[maxn],L[maxn],R[maxn];
int n,nL,nR;
ll bs[maxn],h[maxn],hL[maxn],hR[maxn];
inline ll get_hsh(int l,int r){return (h[r]+hmod-1ll*h[l-1]*bs[r-l+1]%hmod)%hmod;}
inline ll lcp(int pos,int r,ll *h){
	ri l=1,ret=0;
	ckmin(r,n-pos+1);
	while(l<=r){
		ri mid=l+r>>1;
		if(get_hsh(pos,pos+mid-1)==h[mid])ret=mid,l=mid+1;
		else r=mid-1;
	}
	return ret;
}
signed main(){
	build(a,n,h),build(L,nL,hL),build(R,nR,hR);
	bs[0]=1;
	for(ri i=1;i<=n;++i)bs[i]=1ll*bs[i-1]*base%hmod;
	pre[0]=1,pre[1]=mod-1;
	for(ri i=1;i<=n;++i){
		pre[i]+=pre[i-1];
		if(i+nL-1>n)continue;
		if(a[i]==48){
			if(nL==1&&L[1]==48)pre[i]+=pre[i-1],pre[i+1]-=pre[i-1];
			continue;
		}
		ri limL=i+nL-1,limR=i+nR-1;
		ri pL=lcp(i,nL,hL);
		if(pL<nL&&i+pL<=n&&L[pL+1]>a[i+pL])++limL;
		if(limR>n)limR=n;
		else{
			ri pR=lcp(i,nR,hR);
			if(pR<nR&&i+pR<=n&&R[pR+1]<a[i+pR])--limR;
		}
		if(limL<=limR)pre[limL]+=pre[i-1],pre[limR+1]-=pre[i-1];
	}
	printf("%d",pre[n]);
	return 0;
}