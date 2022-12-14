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
const int maxn = 200000;
const int inf = 0x3f3f3f3f;

template<class T> struct SparseTable
{
    #define LG 20
    int lg[maxn+5];
    T st[LG][maxn+5];
    T ask(int l,int r)
    {
        if(l>r) return 0;
        int k=lg[r-l+1];
        return gcd(st[k][l],st[k][r-(1<<k)+1]);
    }
    void init(int n,T a[]) // index starts from 1.
    {
        rep(i,2,n) lg[i]=lg[i>>1]+1;
        rep(i,1,n) st[0][i]=a[i];
        rep(i,1,lg[n]) rep(j,1,n-(1<<i)+1) st[i][j]=gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    }
    #undef LG
};

SparseTable<ll> st;

ll a[maxn+5],b[maxn+5];

void solve()
{
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%lld",&a[i]);
    if(n==1) {puts("1"); return;}
    rep(i,1,n-1) b[i]=abs(a[i+1]-a[i]);
    st.init(n-1,b);
    int ptr=1; 
    int ans=0;
    rep(i,1,n-1)
    {
        while(ptr<n && st.ask(i,ptr)!=1) ptr++;
        chmax(ans,ptr-i);
    }
    printf("%d\n",ans+1);
}  

int main()
{
	int tt=1; scanf("%d",&tt); 
	while(tt--) solve();
	return 0;
}