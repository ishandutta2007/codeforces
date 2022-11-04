#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define eb emplace_back
#define y1 yylyylyylyyl
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

const int mod=998244353;

int ksm(int x,int y,int r=1) {
    for(;y;y>>=1,x=x*x%mod) if(y%2) r=r*x%mod;
    return r;
}

const int N=1e6+9;
int n,a[N],c,f[N];

signed main() {
    int T=read();
    while(T--) {
        n=read(); c=0;
        rep(i,1,n) a[i]=read(), c+=(a[i]==0);
        int xx=0, x=(n*(n-1)/2)%mod;
        rep(i,1,c) xx+=(a[i]==0);
        f[c]=0;
        per(i,c,xx) {
            int r=1+(c-i)*(c-i)%mod*ksm(x,mod-2)%mod*f[i+1]%mod;
            int s=((c-i)*(c-i)%mod)*ksm(x,mod-2)%mod;
            s=ksm(s,mod-2);
            f[i]=(r*s)%mod;
        }
        printf("%lld\n",f[xx]);
    }
    return 0;
}