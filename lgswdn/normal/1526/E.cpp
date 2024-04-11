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
typedef unsigned long long ull;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=4e5+9,mod=998244353;
int n,k,a[N],p[N],ans,fac[N],inv[N],ifac[N];
int ksm(int x,int y,int res=1) {
    for(;y;y>>=1,x=x*x%mod) if(y%2==1) res=res*x%mod;
    return res;
}
void pre(int n) {
    inv[0]=inv[1]=fac[0]=ifac[0]=1;
    rep(i,1,n) fac[i]=fac[i-1]*i%mod;
    ifac[n]=ksm(fac[n],mod-2);
    per(i,n-1,1) ifac[i]=ifac[i+1]*(i+1)%mod;
    rep(i,2,n) inv[i]=ifac[i]*fac[i-1]%mod;
}
int C(int x,int y) {
    if(x<0||y<0||x<y) return 0;
    else return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

signed main() {
    n=read(), k=read();
    pre(n+k);
    rep(i,1,n) p[i]=read()+1, a[p[i]]=i; a[n+1]=-1;
    rep(i,2,n) if(a[p[i]+1]>a[p[i-1]+1]) ++k;
    printf("%lld\n",C(k,n));
    return 0;
}