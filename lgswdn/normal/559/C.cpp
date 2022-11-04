#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=2009,M=2e5+9,mod=1e9+7;

int h,w,n,f[N];
pii a[N];
int fac[M],inv[M],ifac[M];

void pre(int n) {
    inv[0]=inv[1]=fac[0]=ifac[0]=1;
    rep(i,1,n) fac[i]=fac[i-1]*i%mod;
    rep(i,2,n) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,n) ifac[i]=ifac[i-1]*inv[i]%mod;
}
int C(int x,int y) {
    if(x<0||y<0||x<y) return 0;
    else return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int d(int i,int j) {
    return C(a[j].fi+a[j].se-a[i].fi-a[i].se,a[j].fi-a[i].fi);
}

signed main() {
    h=read(), w=read(), n=read();
    rep(i,1,n) a[i].fi=read(), a[i].se=read();
    sort(a+1,a+n+1);
    a[n+1].fi=h, a[n+1].se=w, a[0].fi=1, a[0].se=1;
    pre(h+w);
    rep(i,1,n+1) {
        f[i]=d(0,i);
        rep(j,1,i-1) f[i]=(f[i]+mod-f[j]*d(j,i)%mod)%mod;
    }
    printf("%lld\n",f[n+1]);
    return 0;
}