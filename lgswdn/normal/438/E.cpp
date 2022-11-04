#include<bits/stdc++.h>
#define int long long 
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=4e5+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,c[N],g[N],tmp[N],f[N];

namespace Poly {
    const int mod=998244353,gg=3,ig=332748118;
    int lim,r[N],a[N],b[N],c[N],d[N],e[N],h[N];
    void init(int n) {
        int l=0;
        for(lim=1;lim<=n;lim<<=1,l++);
        rep(i,0,lim) r[i]=(r[i>>1]>>1)|((i&1)<<l-1);
    }
    int pls(int x,int y) {return x+=y,x>=mod?x-mod:x;}
    int mns(int x,int y) {return x-=y,x<0?x+=mod:x;}
    int ksm(int x,int y,int ret=1) {
        while(y) {
            if(y%2) ret=ret*x%mod;
            x=x*x%mod, y>>=1;
        }
        return ret;
    }
    inline void ntt(int *f,int lim,int t) {
        rep(i,0,lim-1) if(i<r[i]) swap(f[i],f[r[i]]);
        for(int len=1;len<lim;len<<=1) {
            int dw=ksm(t>0?gg:ig,(mod-1)/(len*2));
            for(int i=0;i<lim;i+=len*2) {
                int w=1;
                for(int j=0;j<len;j++,w=w*dw%mod) {
                    int x=f[i+j], y=w*f[i+j+len]%mod;
                    f[i+j]=pls(x,y), f[i+j+len]=mns(x,y);
                }
            }
        }
        if(t==-1) {
            int iv=ksm(lim,mod-2);
            rep(i,0,lim) f[i]=f[i]*iv%mod;
        }
    }
    
    void _inv(int *f,int *g,int len) {
        if(len==1) {f[0]=ksm(g[0],mod-2); return;}
        _inv(f,g,(len+1)/2);
        init(len*2);
        rep(i,0,len-1) c[i]=g[i]; rep(i,len,lim) c[i]=0;
        ntt(c,lim,1), ntt(f,lim,1);
        rep(i,0,lim-1) f[i]=mns(2,f[i]*c[i]%mod)*f[i]%mod;
        ntt(f,lim,-1);
        rep(i,len,lim-1) f[i]=0;
    }
    void _sqrt(int *f,int *g,int len) {
        if(len==1) {f[0]=1; return;}
        _sqrt(f,g,(len+1)/2);
        init(len*2);
        rep(i,0,lim) d[i]=e[i]=0;
        _inv(e,f,len);
        rep(i,0,len-1) d[i]=g[i];
        ntt(f,lim,1), ntt(d,lim,1), ntt(e,lim,1);
        rep(i,0,lim-1) f[i]=(d[i]+f[i]*f[i]%mod)%mod*e[i]%mod*ksm(2,mod-2)%mod;
        ntt(f,lim,-1); rep(i,len,lim-1) f[i]=0;
    }
}

using Poly::mod;

signed main() {
	n=read(), m=read();
	rep(i,1,n) c[i]=read(), g[c[i]]=-4;
	g[0]=1;
	Poly::_sqrt(tmp,g,m+1);
	tmp[0]++;
	Poly::_inv(f,tmp,m+1);
	rep(i,0,m) f[i]=f[i]*2%mod;
	rep(i,1,m) printf("%lld\n",f[i]);
	return 0;
} //