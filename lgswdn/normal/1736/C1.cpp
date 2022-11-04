#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define eb emplace_back
#define y1 yylyylyylyyl
#define pc __builtin_popcount
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

const int N=2e5+9;
int T,a[N],n,b[N];

signed main() {
    T=read();
    while(T--) {
        n=read();
        rep(i,1,n) a[i]=read();
        rep(i,1,n) b[i]=i-a[i]+1;
        int l=1, r=0, ans=0;
        for(;l<=n;l++) {
            while(b[r+1]<=l&&r<n) ++r;
            ans+=r-l+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}