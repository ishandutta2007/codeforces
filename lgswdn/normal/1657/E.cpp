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
typedef bitset<509> bset;
typedef pair<bset,bset> v2;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=259,mod=998244353;
int n,k,c[N][N],f[N][N];

int ksm(int x,int y,int r=1) {
    for(;y;y>>=1,x=x*x%mod) if(y%2==1) r=r*x%mod;
    return r;
}

signed main() {
    n=read(), k=read();
    rep(i,0,n) c[i][0]=1;
    rep(i,1,n) rep(j,1,n) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    int ans=0;
    f[0][0]=1;
     rep(j,0,k) rep(i,0,n-1){
        rep(l,0,n-1-i) {
            f[i+l][j+1]=(f[i+l][j+1]+f[i][j]*c[n-i-1][l]%mod*ksm(k-j,i*l+l*(l-1)/2))%mod;
        }
    }
    printf("%lld\n",f[n-1][k]);
    return 0;
}