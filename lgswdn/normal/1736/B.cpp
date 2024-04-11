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

const int N=1e5+9;

int n,a[N],b[N],T;

signed main() {
    T=read();
    while(T--) {
        n=read();
        rep(i,1,n) a[i]=read();
        b[1]=a[1], b[n+1]=a[n];
        rep(i,2,n) b[i]=a[i]*a[i-1]/__gcd(a[i],a[i-1]);
        bool flag=1;
        rep(i,1,n) if(a[i]!=__gcd(b[i],b[i+1])) {flag=0; break;}
        if(flag==0) puts("NO");
        else puts("YES");
    }
    return 0;
}