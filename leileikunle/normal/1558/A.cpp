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

vi ans;

void cal(int a,int b)
{
	int N=a+b,y=N/2,x=N-y;
	int up=min(a,x)+min(b,y);
	int m=min(min(a,x),min(b,y));
	rep(i,0,m) ans.pb(up-i*2);
}

void solve()
{
	int a,b; scanf("%d%d",&a,&b);
	ans.clear();
	cal(a,b);
	cal(b,a);
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	int N=ans.size();
	printf("%d\n",N);
	rep(i,0,N-1) printf("%d%c",ans[i]," \n"[i==N-1]);
}

int main()
{
	int tt=1; scanf("%d",&tt); 
	while(tt--) solve();
	return 0;
}