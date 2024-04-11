#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;
#define int long long
#define endl '\n'
using namespace std;
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
template<class T> void _W(const T &x) { cout << x; }
template<class T> void _W(T &x) { cout << x; }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.first); putchar(' '); _W(x.second);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) cout<<' '; }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); cout<<", "; W(tail...); }
#ifdef CF_DEBUG
 #define debug(...) { cout << "debug : [ "; cout << #__VA_ARGS__; cout << " ] = [ "; W(__VA_ARGS__); cout<<"\b\b ]\n"; }
#else
 #define debug(...) (0)
#endif
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
#define all(a) a.begin(),a.end()
#define lb(a, x) distance(begin(a), lower_bound(all(a), (x)))
#define toset(a) (sort(all(a)), a.erase(unique(all(a)), a.end()), a.size())
using pii = pair<int,int>;
const int N = 5e6+10,mod = 998244353,inf = 1e18;
inline int quick(int a, int b) { a%=mod; int res = 1;  while(b) { if(b & 1) res = res * a % mod; a = a * a % mod;  b >>= 1; } return res; }
int son[N][2], cnt, pre[N];
int sz[N];
int num[40][2]; // ij 
void insert(int x)
{
    int p = 0;
    for(int i=30;~i;i--)
    {
        int now = (x>>i)&1;
        if(!son[p][now]) son[p][now] = ++cnt;
        if(son[p][now^1]) num[i][now] += sz[son[p][now^1]];
        p = son[p][now];
        sz[p]++;
    }
}
int ans1,ans2;
void solve()
{
	int n; cin>>n;
	for(int i=1,x;i<=n;i++) cin>>x,insert(x);
	for(int i=30;~i;i--)
	{
		ans1 += min(num[i][0],num[i][1]);
		if(num[i][1] < num[i][0]) ans2 += 1<<i; 
	}
	cout<<ans1<<" "<<ans2<<endl; 
}

signed main()
{
	int tt = 1;
//	cin>>tt;
	while(tt--)
	{
		solve();
	}
}
/*
__ __ __ __ __ __ __
*/