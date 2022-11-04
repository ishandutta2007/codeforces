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

const int N=2e5+9,mod=998244353;
int T,n,ans,s,a[N],b[N],c[N],d[N];

signed main() {
    T=read();
    while(T--) {
        n=read(), s=read(); ans=1;
        rep(i,1,n) a[i]=b[i]=c[i]=d[i]=0;
        rep(i,1,n) a[i]=read();
        rep(i,1,n) b[i]=read();
        rep(i,1,n) c[i]=max(1ll,a[i]-s);
        rep(i,1,n) if(b[i]!=-1&&b[i]<c[i]) ans=0;
        rep(i,1,n) if(b[i]!=-1) c[i]=-1;
        rep(i,1,n) if(b[i]!=-1) d[b[i]]++;
        per(i,n-1,1) d[i]+=d[i+1];
        sort(c+1,c+n+1,greater<int>());
        rep(i,1,n) if(c[i]!=-1) ans=(ans*(n-c[i]-d[c[i]]-i+2))%mod;
        printf("%lld\n",ans);
    }
    return 0;
}