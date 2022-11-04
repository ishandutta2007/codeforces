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
int T,n,a[N],c[2],p[N];
char s[N];

signed main() {
    T=read();
    while(T--) {
        n=read(); scanf("%s",s+1);
        rep(i,1,2*n) a[i]=s[i]-'0';
        c[0]=c[1]=0;
        rep(i,1,2*n) c[a[i]]++;
        if(c[0]%2==1) {puts("-1"); continue;}
        int cnt=0;
        rep(i,1,n) if(a[i*2-1]!=a[i*2]) {
            if(a[i*2-1]==cnt%2) p[++cnt]=i*2-1;
            else p[++cnt]=i*2;
        }
        printf("%lld ",cnt);
        rep(i,1,cnt) printf("%lld ",p[i]);
        puts("");
        rep(i,1,n) printf("%lld ",2*i-1);
        puts("");
    }
    return 0;
}