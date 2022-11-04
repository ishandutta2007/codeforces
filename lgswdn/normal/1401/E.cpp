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
typedef unsigned long long ull;
typedef bitset<509> bset;
typedef pair<bset,bset> v2;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=1e6+9,lim=1e6;

namespace SegT {
    int ls[N<<1],rs[N<<1],tot=1,s[N<<1];
    void build(int p,int l,int r) {
        int mid=l+r>>1; if(l==r) return;
        build(ls[p]=++tot,l,mid), build(rs[p]=++tot,mid+1,r);
    }
    void mdf(int p,int l,int r,int x,int y) {
        if(l==r) {s[p]+=y; return;} int mid=l+r>>1;
        if(x<=mid) mdf(ls[p],l,mid,x,y); else mdf(rs[p],mid+1,r,x,y);
        s[p]=s[ls[p]]+s[rs[p]];
    }
    int qry(int p,int l,int r,int x,int y) {
        if(l==x&&r==y) return s[p]; int mid=l+r>>1;
        if(y<=mid) return qry(ls[p],l,mid,x,y);
        else if(x>mid) return qry(rs[p],mid+1,r,x,y);
        else return qry(ls[p],l,mid,x,mid)+qry(rs[p],mid+1,r,mid+1,y);
    }
}

int n,m,ans=1;

vp p[N],q[N];

signed main() {
    n=read(), m=read();
    rep(i,1,n) {
        int y=read(), l=read(), r=read();
        q[y].emplace_back(pii(l,r));
        if(l==0&&r==lim) ans++;
    }
    rep(i,1,m) {
        int x=read(), l=read(), r=read();
        p[l].emplace_back(pii(x,1));
        p[r+1].emplace_back(pii(x,-1));
        if(l==0&&r==lim) ans++;
    }
    SegT::build(1,0,lim);
    rep(i,0,lim) {
        for(auto r:p[i]) SegT::mdf(1,0,lim,r.fi,r.se);
        for(auto r:q[i]) ans+=SegT::qry(1,0,lim,r.fi,r.se);
    }
    printf("%lld\n",ans);
    return 0;
}