#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10,mod=1e9+7;
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
mi ans,ilen[maxn],len[maxn],p[maxn],q[maxn],sum;
int l[maxn],n,r[maxn];
inline mi calc(int m){
	assert(m+1<=n);
	ri L=max({l[m-1],l[m],l[m+1]}),R=min({r[m-1],r[m],r[m+1]});
	return 1-p[m]-p[m+1]+max(0,R-L+1)*ilen[m-1]*ilen[m]*ilen[m+1];
}
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",l+i);
	ilen[0]=1;
	for(ri i=1;i<=n;++i){
		scanf("%d",r+i);
		len[i]=r[i]-l[i]+1;
		ilen[i]=1/len[i];
		p[i]=max(0,min(r[i-1],r[i])-max(l[i-1],l[i])+1)*ilen[i-1]*ilen[i];
		q[i]=1-p[i];
		sum+=q[i];
	}
	ans=sum;
	for(ri i=1;i<=n;++i){
		ans+=(sum-q[i-1]-q[i]-q[i+1])*q[i];
		if(i>1)ans+=calc(i-1);
		if(i<n)ans+=calc(i);
	}
	printf("%d",ans);
	return 0;
}