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

int T,n,k,a[N];

map<int,int>cnt;

namespace SegT {
    int ls[N],rs[N],tot=1,sm[N],tp[N];
    void build(int p,int l,int r) {
        sm[p]=tp[p]=0;
        if(l==r) return; int mid=l+r>>1;
        build(ls[p]=++tot,l,mid), build(rs[p]=++tot,mid+1,r);
    }
    void add(int p,int l,int r,int x,int y) {
        if(l==r) {sm[p]+=x*y, tp[p]+=y; return;} int mid=l+r>>1;
        if(x<=mid) add(ls[p],l,mid,x,y); else add(rs[p],mid+1,r,x,y);
        sm[p]=sm[ls[p]]+sm[rs[p]], tp[p]=tp[ls[p]]+tp[rs[p]];
    }
    int qry(int p,int l,int r,int k) {
        if(l==r) return tp[p]-k/l; int mid=l+r>>1;
        if(sm[ls[p]]<k) return qry(rs[p],mid+1,r,k-sm[ls[p]]);
        else return tp[rs[p]]+qry(ls[p],l,mid,k);
    }
}

signed main() {
    T=read();
    while(T--) {
        n=read(), k=read();
        cnt.clear();
        SegT::tot=1;
        SegT::build(1,1,n);
        rep(i,1,n) a[i]=read(), cnt[a[i]]++;
        for(auto p:cnt) SegT::add(1,1,n,p.se,1);
        int cc=0,ans=n+1;
        rep(mx,0,n) {
            if(cnt[mx]) {
                SegT::add(1,1,n,cnt[mx],-1);
            }
            if(mx) {
                if(!cnt[mx-1]) cc++;
            }
            if(cc>k) break;
            ans=min(ans,SegT::qry(1,1,n,k));
        }
        printf("%lld\n",ans);
    }
    return 0;
}