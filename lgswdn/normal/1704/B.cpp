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
int T,n,a[N],x;

signed main() {
    T=read();
    while(T--) {
        n=read(), x=read();
        rep(i,1,n) a[i]=read();
        int mn=1000000009, mx=0, cnt=0;
        rep(i,1,n) {
            mn=min(mn,a[i]+x), mx=max(mx,a[i]-x);
            if(mn<mx) {
                cnt++;
                mn=a[i]+x, mx=a[i]-x;
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}