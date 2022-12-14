#include<bits/stdc++.h>
using namespace std;
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define rep(i,a,b) for(auto i=a; i<=b; i++)
#define per(i,a,b) for(auto i=a; i>=b; i--)
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
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

#ifdef CF_DEBUG
 #define debug(...) { cout << "debug : [ "; cout << #__VA_ARGS__; cout << " ] = [ "; W(__VA_ARGS__); cout<<"\b\b ]\n"; }
#else
 #define debug(...) (0)
#endif

const int mod = 1000000007;
const int maxn = 100005;
const int inf = 0x3f3f3f3f;

ll A[maxn+5],B[maxn+5];

struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<ll,maxn*4+5> mn,mx;
    void pu(int i) 
    {
        mn[i]=min(mn[ls],mn[rs]);
        mx[i]=max(mx[ls],mx[rs]);
    }
    void build(int i,int l,int r)
    {
        if(l==r) mn[i]=mx[i]=A[l];
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            pu(i);
        }
    }
    pair<ll,ll> ask(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr) return mp(mn[i],mx[i]);
        if(qr<l || r<ql) return mp(1ll<<60,-(1ll<<60));
        int mid=(l+r)>>1;
        auto [ml,Ml]=ask(ls,l,mid,ql,qr);
        auto [mr,Mr]=ask(rs,mid+1,r,ql,qr);
        return mp(min(ml,mr),max(Ml,Mr));
    }
    #undef ls
    #undef rs
}seg;

void solve()
{
	int n,q; scanf("%d%d",&n,&q);
    rep(i,1,n) scanf("%lld",&A[i]);
    rep(i,1,n) scanf("%lld",&B[i]);
    rep(i,1,n) A[i]=B[i]-A[i];
    rep(i,1,n) A[i]+=A[i-1];
    seg.build(1,0,n);
    while(q--)
    {
        int l,r; scanf("%d%d",&l,&r); l--;
        //printf("? %lld %lld\n",A[l],A[r]);
        if(A[l]!=A[r]) puts("-1");
        else
        {
            auto [mn,mx]=seg.ask(1,0,n,l,r);
            //printf(" - %lld %lld\n",mn,mx);
            if(mn<A[l]) puts("-1");
            else printf("%lld\n",mx-A[l]);
        }
    }
}

int main()
{
	int tt=1; //scanf("%d",&tt); 
	while(tt--) solve();
	return 0;
}