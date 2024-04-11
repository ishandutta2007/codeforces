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

const int N=5009;
int T,n,a[N],p[N][N],c[N],f[N];

signed main() {
    T=read();
    while(T--) {
        n=read();
        rep(i,1,n) a[i]=read();
        rep(l,1,n) {
            int mx=0;
            rep(i,1,n) c[i]=0;
            rep(r,l,n) {
                c[a[r]]++; mx=max(mx,c[a[r]]);
                if(mx*2<=(r-l+1)&&(r-l+1)%2==0) p[l][r]=1;
                else p[l][r]=0;
            }
        }
        int ans=0;
        rep(i,1,n) {
            if(i==1||p[1][i-1]) f[i]=1;
            else f[i]=-n;
            rep(j,1,i-1) if(a[i]==a[j]) {
                if(j+1==i||p[j+1][i-1]) f[i]=max(f[i],f[j]+1);
            }
            if(i==n||p[i+1][n]) ans=max(ans,f[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}