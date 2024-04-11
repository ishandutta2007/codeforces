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

const int N=109;
int T,n,c[2],a[N],b[N];

signed main() {
    T=read();
    while(T--) {
        n=read();
        rep(i,0,1) c[i]=0;
        rep(i,1,n) c[a[i]=read()]++;
        rep(i,1,n) c[b[i]=read()]--;
        int res=0;
        rep(i,1,n) res+=(a[i]!=b[i]);
        printf("%lld\n",min(1+abs(c[1]),res));
    }
    return 0;
}