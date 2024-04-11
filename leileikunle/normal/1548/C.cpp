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

const int mod = 1000000007;
const int maxn = 3000100;
const int inf = 0x3f3f3f3f;

ll fac[maxn+5],ifac[maxn+5],inv[maxn+5];
ll ans[maxn+5];


void solve()
{
    inv[1]=fac[0]=ifac[0]=1;
    rep(i,2,maxn) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,maxn) fac[i]=fac[i-1]*i%mod;
    rep(i,1,maxn) ifac[i]=ifac[i-1]*inv[i]%mod;

    auto binom=[](int n,int m) {
        if(m<0 || n<m) return 0ll;
        return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
    };

	int n,q; scanf("%d%d",&n,&q);
    rep(i,1,n) ans[1]=(ans[1]+binom(i*3,1))%mod;
    rep(i,1,n) ans[2]=(ans[2]+binom(i*3,2))%mod;
    rep(i,3,n*3) ans[i]=(binom(n*3+3,i+1)-binom(3,i+1)-ans[i-2]-ans[i-1]*3+5ll*mod)%mod*inv[3]%mod;
    while(q--)
    {
        int x; scanf("%d",&x);
        printf("%lld\n",ans[x]);
    }
}  

int main()
{
	int tt=1; //scanf("%d",&tt); 
	while(tt--) solve();
	return 0;
}