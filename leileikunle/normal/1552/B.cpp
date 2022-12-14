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
const int maxn = 50000;
const int inf = 0x3f3f3f3f;

int rk[maxn+5][10];

void solve()
{
	int n; scanf("%d",&n);
	rep(i,1,n) rep(j,1,5) scanf("%d",&rk[i][j]);
	int now=1;
	rep(i,2,n)
	{
		int cnt=0;
		rep(j,1,5) cnt+=rk[now][j]<rk[i][j];
		if(cnt<=2) now=i;
	}
	int ok=1;
	rep(i,1,n) if(i!=now) 
	{
		int cnt=0;
		rep(j,1,5) cnt+=rk[now][j]<rk[i][j];
		if(cnt<=2) ok=0;
		if(ok==0) break;
	}
	if(ok) printf("%d\n",now);
	else puts("-1");
}

int main()
{
	int tt=1; scanf("%d",&tt); while(tt--) solve();
	return 0;
}