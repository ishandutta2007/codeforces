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
#define sz(A) (int)A.size()
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

#ifdef CF_DEBUG
 #define debug(...) { cout << "debug : [ "; cout << #__VA_ARGS__; cout << " ] = [ "; W(__VA_ARGS__); cout<<"\b\b ]\n"; }
#else
 #define debug(...) (0)
#endif

const int mod = 1000000007;
const int maxn = 600000;
const int inf = 0x3f3f3f3f;

int a[maxn+5];
pii seg[maxn+5];
int ps[maxn+5];

ll dp[maxn+5][2];

void solve()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    rep(i,1,m) scanf("%d%d",&seg[i].FI,&seg[i].SE);
    vi vec; 
    rep(i,1,n) vec.pb(a[i]);
    rep(i,1,m) vec.pb(seg[i].FI),vec.pb(seg[i].SE);
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    int N=sz(vec);
    auto getid=[&](int x) {return lower_bound(vec.begin(),vec.end(),x)-vec.begin()+1;};
    rep(i,1,N) ps[i]=0;
    rep(i,1,n) ps[getid(a[i])]++; 
    rep(i,1,N) ps[i]+=ps[i-1];
    int ptr=0;
    rep(i,1,m)
    {
        int lid=getid(seg[i].FI);
        int rid=getid(seg[i].SE);
        int cnt=ps[rid]-ps[lid-1];
        if(cnt==0) seg[++ptr]=seg[i];
    }
    m=ptr;
    sort(seg+1,seg+m+1,[](pii a,pii b) {
        if(a.FI==b.FI) return a.SE>b.SE;
        return a.FI<b.FI;
    });
    ptr=0;
    rep(i,1,m) 
    {
        while(ptr && seg[i].SE<=seg[ptr].SE) ptr--;
        seg[++ptr]=seg[i];
    }
    m=ptr;
//puts("fuck");
//rep(i,1,n) printf("? %d\n",a[i]);
//rep(i,1,m) printf("! %d %d\n",seg[i].FI,seg[i].SE);

    dp[0][0]=dp[0][1]=0;
    ptr=1;
    rep(i,1,n+1)
    {
        ll x=i==1?-1ll<<50:a[i-1];
        ll y=i==n+1?1ll<<50:a[i];
        int j=ptr;
        while(j<=m && seg[j].FI<y) j++;
        // segs in [ptr, j-1]
        int L=ptr,R=j-1;
        //printf("?? %d: %d %d\n",i,L,R);
        dp[i][0]=dp[i][1]=1ll<<60;
        rep(r,0,1) rep(s,0,1)
        {
            ll fac1=r==0?2:1;
            ll fac2=s==0?1:2;
            
            if(L>R) chmin(dp[i][s],dp[i-1][r]);
            else
            {
                chmin(dp[i][s],dp[i-1][r]+fac2*(y-seg[L].SE));
                chmin(dp[i][s],dp[i-1][r]+fac1*(seg[R].FI-x));
                rep(k,L,R-1) chmin(dp[i][s],dp[i-1][r]+fac1*(seg[k].FI-x)+fac2*(y-seg[k+1].SE));
            }
        }
        //printf("!!! %d: %lld %lld\n",i,dp[i][0],dp[i][1]);
        ptr=j;
    }
    printf("%lld\n",dp[n+1][0]);
}

int main()
{
	int tt=1; scanf("%d",&tt); 
	while(tt--) solve();
	return 0;
}