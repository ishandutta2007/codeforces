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
long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

signed main() {
    int T=read();
    while(T--) {
        int a=read(), b=read(), c=read();
        printf("%lld %lld %lld\n",a+b+c,b+c,c);
    }
    return 0;
}