#include<bits/stdc++.h>
using namespace std;
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define rep(i,a,b) for(auto i=a; i<=b; i++)
#define per(i,a,b) for(auto i=b; i>=a; i--)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
template<class T> void _W(const T &x) {cout << x;}
template<class T> void _W(T &x) {cout << x;}
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.first); putchar(' '); _W(x.second);}
template<class T> void _W(const vector<T> &x) {for (auto i = x.begin(); i != x.end(); _W(*i++)) cout<<' ';}
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) {_W(head); cout<<", "; W(tail...);}

#define pb push_back
#define mp make_pair
#define FI first
#define SE second
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

#ifdef CF_DEBUG
 #define debug(...) { cout << "debug : [ "; cout << #__VA_ARGS__; cout << " ] = [ "; W(__VA_ARGS__); cout<<"\b\b ]\n"; }
#else
 #define debug(...) (0)
#endif

const int mod = 998244353;
const int maxn = 200000;
const int inf = 0x3f3f3f3f;

void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
void chsub(int &x,int y) {x-=y; if(x<0) x+=mod;}

int a[maxn+5],b[maxn+5];

template<class T> struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<T,maxn*4+5> a;
    void pu(int i) {a[i]=a[ls]+a[rs];}
    void build(int i,int l,int r)
    {
        if(l==r) a[i]=1;
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            pu(i);
        }
    }
    void add(int i,int l,int r,int ql,int qr,T x)
    {
        if(ql<=l && r<=qr)
        {
            a[i]+=x;
            return;
        }
        if(qr<l || r<ql) return;
        int mid=(l+r)>>1;
        add(ls,l,mid,ql,qr,x);
        add(rs,mid+1,r,ql,qr,x);
        pu(i);
    }
    int lb(int i,int l,int r,int x) // find the minimum index i such that a[1]+...+a[i]>=x
    {
        if(l==r) return l;
        int mid=(l+r)>>1;
        if(x<=a[ls]) return lb(ls,l,mid,x);
        else return lb(rs,mid+1,r,x-a[ls]);
    }
    #undef ls
    #undef rs
};
Segtree<int> seg;
int x[maxn+5],y[maxn+5];


ll fac[maxn*3+5],ifac[maxn*3+5],inv[maxn*3+5];
ll binom(int n,int m)
{
    if(m<0 || n-m<0) return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

int mark[maxn+5];

void solve()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m) scanf("%d%d",&x[i],&y[i]);
    
    vi er,mk; int cnt=0;
    per(i,1,m)
    {
        int to_erase=seg.lb(1,1,maxn,y[i]);
        int pos=seg.lb(1,1,maxn,y[i]+1);
        //printf("? %d %d\n",to_erase,pos);
        er.pb(to_erase);
        mk.pb(pos);
        cnt+=mark[pos]==0;
        mark[pos]=1;
        seg.add(1,1,maxn,to_erase,to_erase,-1);
    }
    for(auto x: er) seg.add(1,1,maxn,x,x,1);
    for(auto x: mk) mark[x]=0;
    //printf("??? %d\n",cnt);
    printf("%lld\n",binom(n+n-1-cnt,n));
}


int main()
{
	int tt=1; scanf("%d",&tt); 
    inv[1]=fac[0]=ifac[0]=1;
    rep(i,2,maxn*3) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,maxn*3) fac[i]=fac[i-1]*i%mod;
    rep(i,1,maxn*3) ifac[i]=ifac[i-1]*inv[i]%mod;

    seg.build(1,1,maxn);
	
    while(tt--) solve();
	return 0;
}