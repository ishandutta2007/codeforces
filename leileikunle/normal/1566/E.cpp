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
const int maxn = 200000;
const int inf = 0x3f3f3f3f;

vi e[maxn+5];
int leaf[maxn+5];

void dfs(int now,int fa)
{
    int cnt=0;
    for(auto v: e[now]) if(v!=fa)
    {
        dfs(v,now);
        cnt+=leaf[v];
    }
    leaf[now]=cnt==0;
}

void solve()
{
    int n; scanf("%d",&n);
    rep(i,1,n) e[i].clear();
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1,0);
    int ans=0;
    rep(i,2,n) if(leaf[i]) ans++; else ans--;
    int root_leaf=0;
    for(auto v: e[1]) if(leaf[v]) root_leaf=1;
    if(root_leaf==0) ans++;
    printf("%d\n",ans);
}

int main()
{
	int tt=1; scanf("%d",&tt); 
	while(tt--) solve();
	return 0;
}