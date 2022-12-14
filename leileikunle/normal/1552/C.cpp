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
const int maxn = 200;
const int inf = 0x3f3f3f3f;

pii chord[maxn+5];
bool mark[maxn+5];

void solve()
{
	int n,k; scanf("%d%d",&n,&k);
    rep(i,1,n*2) mark[i]=1;
    rep(i,1,k)
    {
        int x,y; scanf("%d%d",&x,&y);
        chord[i]={x,y};
        mark[x]=0;
        mark[y]=0;
    }
    vi tmp;
    rep(i,1,n*2) if(mark[i]==1) tmp.pb(i);
    rep(i,1,n-k) chord[k+i]={tmp[i-1],tmp[i-1+n-k]};
    int ans=0;
    rep(i,1,n)
    {
        auto [x1,y1]=chord[i];
        if(x1>y1) swap(x1,y1);
        rep(j,i+1,n)
        {
            auto [x2,y2]=chord[j];
            int in1=x1<=x2 && x2<=y1;
            int in2=x1<=y2 && y2<=y1;
            ans+=in1^in2;
        }
    }
    printf("%d\n",ans);
}

int main()
{
	int tt=1; scanf("%d",&tt); while(tt--) solve();
	return 0;
}