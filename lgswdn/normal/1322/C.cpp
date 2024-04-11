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

const int base=31,N=5e5+9;
int T,n,m,c[N];
ull e[N],p[N];
pair<ull,int>r[N];

signed main() {
    T=read();
    p[0]=1;
    rep(i,1,500001) p[i]=p[i-1]*base;
    while(T--) {
        n=read(), m=read();
        rep(i,1,n) c[i]=read(), e[i]=0;
        rep(i,1,m) {
            int u=read(), v=read();
            e[v]+=p[u];
        }
        rep(i,1,n) r[i]=make_pair(e[i],c[i]);
        int ans=0;
        sort(r+1,r+n+1);
        rep(i,1,n) {
            int p=i,sum=0;
            while(r[p].fi==r[i].fi) sum+=r[p].se, p++; p--;
            if(r[p].fi==0) {i=p; continue;}
            if(ans==0) ans=sum;
            else ans=__gcd(ans,sum);
            i=p;
        }
        printf("%lld\n",ans);
    }
    return 0;
}