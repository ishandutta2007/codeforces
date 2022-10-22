#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int m=1e3,maxn=2e5+10,mod=998244353;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;register char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
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
mi ans[maxn],fac[maxn],ifac[maxn],mul[maxn],sum;
inline void init(int sz){
	fac[0]=1;
	for(ri i=1;i<=sz;++i)fac[i]=fac[i-1]*i;
	ifac[sz]=1/fac[sz];
	for(ri i=sz;i;--i)ifac[i-1]=ifac[i]*i;
}
int bel[maxn];
struct qry{
	int l,r,id;
	inline bool operator<(const qry &k)const{
		return bel[l]!=bel[k.l]?l<k.l:(bel[l]&1)?r<k.r:r>k.r;
	}
};
vector<qry>q[maxn];
int a[maxn],b,clr,cnt[maxn],n,ql,t,tot[maxn];
inline void add(int k){
	sum*=fac[tot[k]-cnt[k]];
	++cnt[k];
	sum*=ifac[tot[k]-cnt[k]];
}
inline void del(int k){
	sum*=fac[tot[k]-cnt[k]];
	--cnt[k];
	sum*=ifac[tot[k]-cnt[k]];
}
int main(){
	init(200000);
	n=qr(),clr=qr(),t=qr();
	for(ri i=1;i<=n;++i){
		a[i]=qr();
		++tot[a[i]];
		if(i%m==1)++b;
		bel[i]=b;
	}
	for(ri i=1,x,y,z;i<=t;++i){
		x=qr(),y=qr(),z=qr();
		q[z].push_back({x,y,i});
	}
	for(ri i=0;i<=100000;++i)
		if(q[i].size()){
			sort(q[i].begin(),q[i].end());
			mul[0]=sum=1;
			for(ri j=1;j<=clr;++j){
				cnt[j]=0;
				tot[j]+=i;
				mul[0]*=fac[tot[j]];
				sum*=ifac[tot[j]];
			}
			for(ri j=1,k=(1ll*i*clr+1)%mod;j<=n;++j,++k)mul[j]=mul[j-1]*k;
			ri pl=1,pr=0;
			for(auto j:q[i]){
				while(pl>j.l)add(a[--pl]);
				while(pr<j.r)add(a[++pr]);
				while(pl<j.l)del(a[pl++]);
				while(pr>j.r)del(a[pr--]);
				ans[j.id]=mul[n-(j.r-j.l+1)]*sum;
			}
			for(ri j=1;j<=clr;++j)tot[j]-=i;
		}
	for(ri i=1;i<=t;++i)qw(ans[i].val),putchar(10);
	return 0;
}