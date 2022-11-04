// LUOGU_RID: 90799256
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

const int N=1e6+9;
int n,m,b,g,gg,cnt;
vi B[N],G[N];
map<int,int>d,mp,yp,zp;

void exgcd(int a,int b,int &x,int &y) {
    if(a==1&&b==0) {x=1, y=0; return;}
    if(a<b) swap(a,b);
    exgcd(b,a%b,x,y);
    int t=y; y=x-a/b*y, x=t;
}

int work(int n,int m,vi b,vi g) {
    if(b.size()==0&&g.size()==0) return -1;
    yp.clear(), zp.clear();
    if(n>m) swap(n,m), swap(b,g);
    int k=m-n, ans=0;
    vp p,q;
    int tmp=0, ik=0; exgcd(m,k,tmp,ik); ik=(ik%m+m)%m;
    for(auto x:b) p.eb(pii(x,x)), zp[x*ik%m]=1;
    for(auto x:g) p.eb(pii(x,x)), yp[x*ik%m]=1;
    for(auto pp:p) {
        int x=pp.fi, dis=pp.se;
        int pos=x*ik%m, lst=(pos+1)%m;
        if(x>=n) zp[x*ik%m]=1;
        q.eb(pii(pos,dis)), q.eb(pii(lst,m*n));
    }
    sort(q.begin(),q.end());
    int sz=q.size();
    d.clear();
    for(auto x:q) {
        if(!d.count(x.fi)) d[x.fi]=x.se;
        else d[x.fi]=min(d[x.fi],x.se);
    }
    rep(i,0,2*sz-1) {
        int x=q[i%sz].fi, y=q[(i+1)%sz].fi;
        d[x]=min(d[x],d[y]+(y-x+m)%m*n);
    }
    for(auto x:q) if(!yp[x.fi]||!zp[x.fi]) ans=max(ans,d[x.fi]);
    return ans;
}

signed main() {
    n=read(), m=read(), gg=__gcd(n,m);
    if(gg>1000000) return puts("-1"), 0;
    b=read();
    rep(i,1,b) {
        int x=read();
        B[x%gg].eb(x/gg);
    }
    g=read();
    rep(i,1,g) {
        int x=read();
        G[x%gg].eb(x/gg);
    }
    int ans=0;
    rep(i,0,gg-1) {
        int res=work(n/gg,m/gg,B[i],G[i]);
        if(res==-1) {ans=-1; break;}
        if(B[i].size()<n/gg||G[i].size()<m/gg) ans=max(ans,res*gg+i);
    }
    printf("%lld\n",ans);
    return 0;
}