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

const int N=200009;
int T,n,m,a[N];
vp ans;

signed main() {
    T=read();
    while(T--) {
        n=read();
        rep(i,1,n) a[i]=read();
        if(n%2==1) {
            puts("-1");
            continue;
        }
        ans.clear(); ans.shrink_to_fit();
        rep(i,1,n) if(i%2==1) {
            if(a[i]==a[i+1]) ans.eb(pii(i,i+1));
            else ans.eb(pii(i,i)), ans.eb(pii(i+1,i+1));
        }
        int sz=ans.size();
        printf("%lld\n",sz);
        for(auto pp:ans) printf("%lld %lld\n",pp.fi,pp.se);
    }
    return 0;
}