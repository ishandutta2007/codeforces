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

const int N=1e5+9;
int T,n,m,a[N],b[N];

signed main() {
    T=read();
    while(T--) {
        n=read(), m=read();
        rep(i,1,m) a[i]=read();
        sort(a+1,a+m+1);
        rep(i,1,m) {
            int j=i+1;
            if(i!=m) b[i]=a[j]-a[i]-1;
            else b[i]=n-a[m]+a[1]-1;
        }
        sort(b+1,b+m+1,greater<int>());
        int ans=0;
        rep(i,1,m) {
            if(b[i]-(i-1)*4==1) ans++;
            else ans=ans+max(0ll,b[i]-i*4+3);
        }
        printf("%lld\n",n-ans);
    }
    return 0;
}