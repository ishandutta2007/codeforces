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
const int maxn = 100000;
const int inf = 0x3f3f3f3f;

vi pool[100+5];
struct seg{int l,r,c;};
int cnt[maxn+5],OK[maxn+5];
pii ans[maxn+5];

void solve()
{
    int n=30,k=4; scanf("%d%d",&n,&k);
    rep(i,1,n) pool[i].clear();
    rep(i,1,n) OK[i]=0;
    rep(i,1,n*k) cnt[i]=0;
    vi a;
    rep(i,1,n) rep(j,1,k) a.pb(i);
    random_shuffle(a.begin(),a.end());
    rep(i,1,n*k)
    {
        int c=a[i-1]; scanf("%d",&c);
        pool[c].pb(i);
    }
    vector<seg> A;
    rep(c,1,n) rep(i,1,k-1) A.pb(seg{pool[c][i-1],pool[c][i],c});
    sort(A.begin(),A.end(),[](seg &a,seg &b) {return a.r<b.r;});
    int thr=(n+k-2)/(k-1);
    for(auto [l,r,c]: A) if(OK[c]==0)
    {
        int ok=1;
        rep(i,l,r) if(cnt[i]>=thr) ok=0;
        if(ok) 
        {
            OK[c]=1;
            rep(i,l,r) cnt[i]++;
            ans[c]={l,r};
        }
    }
    
    rep(i,1,n) if(OK[i]==0)
    {
        for(auto x: a) printf("%d ",x);
        puts("");
        assert(0);
    }
    //puts("ok");
    
    rep(i,1,n) printf("%d %d\n",ans[i].FI,ans[i].SE);
}

int main()
{
    srand(time(NULL));
	int tt=1; //scanf("%d",&tt); 
    while(tt--) solve();
	return 0;
}