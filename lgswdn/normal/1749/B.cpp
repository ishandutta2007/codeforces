#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define eb emplace_back
#define y1 yylyylyylyyl
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
int T,n,a[N],b[N],sum,mx;

signed main() {
    T=read();
    while(T--) {
        n=read(), sum=0, mx=0;
        rep(i,1,n) a[i]=read(), sum+=a[i];
        rep(i,1,n) b[i]=read(), sum+=b[i], mx=max(mx,b[i]);
        printf("%lld\n",sum-mx);
    }
    return 0;
}