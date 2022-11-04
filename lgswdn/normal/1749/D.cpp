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

const int N=3e5+9,mod=998244353;
int n,m,f[N][2],vst[N];

signed main() {
    n=read(), m=read();
    vst[1]=1;
    rep(i,2,n) rep(j,2,n/i) vst[i*j]=1;
    int ss=1;
    f[0][0]=1; 
    rep(i,1,n) {
        if(ss<=m&&!vst[i]) ss*=i;
        f[i][0]=(m/ss)%mod*f[i-1][0]%mod;
        f[i][1]=((m-m/ss)%mod*f[i-1][0]%mod+m%mod*f[i-1][1])%mod;
    }
    int ans=0;
    rep(i,1,n) ans=(ans+f[i][1])%mod;
    printf("%lld\n",ans);
    return 0;
}