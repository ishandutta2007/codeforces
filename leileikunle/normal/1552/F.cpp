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

template<class T> struct BIT
{
    int n;
    T a[maxn+5];
    void init(int _n)
    {
        n=_n;
        rep(i,1,n) a[i]=0;
    }
    void add(int i,T x)
    {
        for(;i<=n;i+=i&-i) a[i]=(a[i]+x)%mod;
    }
    T ask(int i)
    {
        T ans=0;
        for(;i;i-=i&-i) ans=(ans+a[i])%mod;
        return ans;
    }
    void add(int l,int r,T x) {add(l,x); add(r+1,-x);}
    T ask(int l,int r) {return (ask(r)-ask(l-1)+mod)%mod;}
};
BIT<int> bit;

int x[maxn+5],y[maxn+5],s[maxn+5];
int dp[maxn+5];

void solve()
{
    int n; scanf("%d",&n);
    bit.init(n);
    rep(i,1,n) scanf("%d%d%d",&x[i],&y[i],&s[i]);
    rep(i,1,n) 
    {
        int id=lower_bound(x+1,x+n+1,y[i])-x;
        if(id==i) dp[i]=(1ll*x[i]-x[i-1]+x[i]-y[i])%mod;
        else
        {
            dp[i]=(2ll*(x[i]-x[i-1])+bit.ask(id,i-1)-(y[i]-x[id-1]))%mod;
            dp[i]=(dp[i]+mod)%mod;
        }
        bit.add(i,dp[i]);
    }
    int ans=1;
    rep(i,1,n)
    {
        if(s[i]==0) ans=(ans+x[i]-x[i-1])%mod;
        else ans=(ans+dp[i])%mod;
    }
    printf("%d\n",ans);
}

int main()
{
	int tt=1; //scanf("%d",&tt); 
    while(tt--) solve();
	return 0;
}