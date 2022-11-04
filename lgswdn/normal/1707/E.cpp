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

const int N=1e5+9;
int n,q,a[N],mn[N][19],mx[N][19],fl[N][19],fr[N][19],mnl[N][19][19],mxr[N][19][19],lg2[N];

int qmin(int l,int r) {
    int len=r-l+1; int p=lg2[len];
    return min(mn[l][p],mn[r-(1<<p)+1][p]);
}
int qmax(int l,int r) {
    int len=r-l+1; int p=lg2[len];
    return max(mx[l][p],mx[r-(1<<p)+1][p]);
}

pii f2k(int l,int r,int k) {
    r--; int len=r-l+1; int p=lg2[len];
    //cout<<" "<<l<<" "<<r<<' '<<k<<" "<<p<<" "<<mnl[l][k][p]<<" "<<mnl[r-(1<<p)+1][k][p]<<endl;
    return pii(min(mnl[l][k][p],mnl[r-(1<<p)+1][k][p]),max(mxr[l][k][p],mxr[r-(1<<p)+1][k][p]));
}
pii f(int l,int r,int k) {
    pii res(l,r);
    per(h,17,0) if((1<<h)&k) res=f2k(res.fi,res.se,h);
    return res;
}

signed main() {
    n=read(), q=read();
    rep(i,1,n) a[i]=read();
    rep(i,2,2*n) lg2[i]=lg2[i/2]+1;
    per(i,n,1) {
        mn[i][0]=a[i];
        rep(h,1,17) mn[i][h]=min(mn[i][h-1],i+(1<<h-1)<=n?mn[i+(1<<h-1)][h-1]:n+1);
        mx[i][0]=a[i];
        rep(h,1,17) mx[i][h]=max(mx[i][h-1],i+(1<<h-1)<=n?mx[i+(1<<h-1)][h-1]:0);
    }
    rep(i,1,n-1) fl[i][0]=min(a[i],a[i+1]), fr[i][0]=max(a[i],a[i+1]);
    per(i,n-1,1) {
        mnl[i][0][0]=fl[i][0];
        rep(h,1,17) mnl[i][0][h]=min(mnl[i][0][h-1],i+(1<<h-1)<=n-1?mnl[i+(1<<h-1)][0][h-1]:n+1);
        mxr[i][0][0]=fr[i][0];
        rep(h,1,17) mxr[i][0][h]=max(mxr[i][0][h-1],i+(1<<h-1)<=n-1?mxr[i+(1<<h-1)][0][h-1]:0);
    }
    rep(k,1,17) {
        per(i,n-1,1) {
            pii p=f2k(fl[i][k-1],fr[i][k-1],k-1);
            fl[i][k]=p.fi, fr[i][k]=p.se;
            //cout<<i<<" "<<k<<" "<<fl[i][k-1]<<" "<<fr[i][k-1]<<" "<<p.fi<<' '<<p.se<<endl;
            mnl[i][k][0]=fl[i][k];
            rep(h,1,17) mnl[i][k][h]=min(mnl[i][k][h-1],i+(1<<h-1)<=n-1?mnl[i+(1<<h-1)][k][h-1]:n+1);
            mxr[i][k][0]=fr[i][k];
            rep(h,1,17) mxr[i][k][h]=max(mxr[i][k][h-1],i+(1<<h-1)<=n-1?mxr[i+(1<<h-1)][k][h-1]:0);
        }
    }
    while(q--) {
        int x=read(), y=read();
        if(x==1&&y==n) {puts("0"); continue;}
        if(x==y) {puts("-1"); continue;}
        int l=0, r=2*n, ans=-1;
        while(l<=r) {
            int mid=l+r>>1;
            pii p=f(x,y,mid);
            if(p.fi==1&&p.se==n) ans=mid, r=mid-1;
            else l=mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}