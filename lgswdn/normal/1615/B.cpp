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

const int N=1e6+9;
int T,n,s[30][N];

signed main() {
    int p=200000;
    rep(k,0,20) {
        rep(i,1,p) {
            s[k][i]=s[k][i-1]+(!(i&(1<<k)));
        }
    }
    T=read();
    while(T--) {
        int l=read(), r=read();
        int ans=r-l+1;
        rep(i,0,20) {
            ans=min(ans,s[i][r]-s[i][l-1]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}