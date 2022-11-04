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

const int N=2e5+9;
int T,n,m;
vi p[N];

signed main() {
    T=read();
    while(T--) {
        n=read(), m=read();
        bool flag=0;
        int rx=0,ry=0;
        rep(i,1,n) {
            vi a,b;
            rep(i,1,m) a.emplace_back(read());
            p[i]=a;
            rep(i,1,m) b.emplace_back(a[i-1]);
            sort(b.begin(),b.end());
            int x=0,y=0;
            rep(i,0,m-1) {
                if(a[i]!=b[i]) {
                    if(!x) x=i;
                    else if(!y) y=i;
                    else flag=1;
                }
            }
            if(x==0&&y==0) continue;
            if(rx==0&&ry==0) rx=x,ry=y;
            else if(x!=rx||y!=ry) flag=1;
        }
        if(flag) {puts("-1"); continue;}
        rep(i,1,n) swap(p[i][rx],p[i][ry]);
        rep(i,1,n) rep(j,1,m-1) if(p[i][j]<p[i][j-1]) flag=1;
        if(flag) {puts("-1"); continue;}
        else printf("%lld %lld\n",rx+1,ry+1);
    }
    return 0;
}