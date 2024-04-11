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

const int N=2e5+9;
int n,a[N],ans=0x3f3f3f3f3f3f3f3f,b[N];

signed main() {
    n=read();
    rep(i,1,n) a[i]=read();
    rep(i,1,n) b[i]=(a[i]+1)/2;
    sort(b+1,b+n+1);
    ans=min(ans,b[1]+b[2]);
    rep(i,2,n-1) {
        if(a[i-1]%2==0&&a[i+1]%2==0) ans=min(ans,a[i-1]/2+a[i+1]/2);
        else ans=min(ans,a[i-1]/2+a[i+1]/2+1);
    }
    rep(i,1,n-1) {
        int x=a[i], y=a[i+1];
        if(x>=2*y||y>=2*x) ans=min(ans,max((x+1)/2,(y+1)/2));
        else {
            int u=(2*x-y)/3; ans=min(ans,u+max(x-2*u,(y-u+1)/2));
            u++; ans=min(ans,u+max(x-2*u,(y-u+1)/2));
        }
    }
    printf("%lld\n",ans);
    return 0;
}