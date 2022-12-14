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
const int maxn = 10;
const int inf = 0x3f3f3f3f;

int a[maxn+5];

bool dfs(int dep,int cnt,int sum)
{
    if(dep==0) return cnt>0 && sum==0;
    if(dfs(dep-1,cnt,sum)) return 1;
    if(dfs(dep-1,cnt+1,sum+a[dep])) return 1;
    if(dfs(dep-1,cnt+1,sum-a[dep])) return 1;
    return 0;
}

void solve()
{
	int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]),a[i]=abs(a[i]);
    rep(i,1,n) if(a[i]==0) {puts("YES"); return;}
    puts(dfs(n,0,0)?"YES":"NO");
}

int main()
{
	int tt=1; scanf("%d",&tt); while(tt--) solve();
	return 0;
}