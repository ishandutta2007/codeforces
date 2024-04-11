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

const int N=3e5+9;

int T,n,m,b[N];
vi c[N];

signed main() {
    T=read();
    while(T--) {
        n=read(), m=read();
        rep(i,1,n) b[i]=0;
        rep(i,1,n) {
            c[i].clear(); c[i].shrink_to_fit(); c[i].resize(m+1);
            rep(j,1,m) {
                c[i][j]=read(); c[i][j]+=c[i][j-1];
                b[i]+=c[i][j];
            }
        }
        int cnt=0, x=1;
        rep(i,1,n) if(b[i]!=b[1]) cnt++, x=i;
        if(cnt==n-1) x=1;
        if(x==1) printf("%lld %lld\n",1ll,b[2]-b[1]);
        else printf("%lld %lld\n",x,b[1]-b[x]);
    }
    return 0;
}