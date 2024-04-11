#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=4e6+10,mod=51123987,inv2=(mod+1)>>1;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int n,nn,p[maxn];
char s[maxn];
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
mi pre[maxn],suf[maxn],sum;
int main(){
	scanf("%d%s",&n,s+1);
	s[0]='?';
	for(ri i=n;~i;--i)s[i<<1]=s[i],s[i<<1|1]='#';
	nn=n<<1|1;
	for(ri i=1,mid=1,mx=1;i<=nn;++i){
		if(i<mx)p[i]=min(mx-i,p[(mid<<1)-i]);
		else p[i]=1;
		while(s[i-p[i]]==s[i+p[i]])++p[i];
		if(i+p[i]>mx)mid=i,mx=i+p[i];
		if(i&1){
			ri len=(p[i]-1)>>1;
			pre[(i-1)>>1]+=1,pre[((i-1)>>1)-len]-=1;
			suf[(i+1)>>1]+=1,suf[((i+1)>>1)+len]-=1;
			sum+=len;
		}
		else{
			ri len=p[i]>>1;
			pre[i>>1]+=1,pre[(i>>1)-len]-=1;
			suf[i>>1]+=1,suf[(i>>1)+len]-=1;
			sum+=len;
		}
	}
	sum*=(sum-1)*inv2;
	for(ri i=n;i;--i)pre[i]+=pre[i+1];
	for(ri i=1;i<=n;++i)suf[i]+=suf[i-1];
	for(ri i=1;i<n;++i){
		suf[i]+=suf[i-1];
		sum-=suf[i]*pre[i+1];
	}
	printf("%d",sum);
	return 0;
}