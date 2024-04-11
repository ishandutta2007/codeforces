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
const int N = 1e6+10;
#define fi first
#define se second
int a[N];
int mp[505][505];
void solve()
{
	int n,m,x,y; cin>>n>>m>>x>>y;
	string s; cin>>s;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			mp[i][j] = 0;
	mp[x][y] = 1;
	cout<<1<<" ";
	int ans = 1;
	int sz = s.size();
	for(int i=0;i<sz-1;i++)
	{
		if(s[i]=='U'&&x>=2) x--;
		else if(s[i]=='D'&&x<=n-1) x++;
		else if(s[i]=='L'&&y>=2) y--;
		else if(s[i]=='R'&&y<=m-1) y++;
		if(mp[x][y]) cout<<"0 ";
		else cout<<"1 ",ans++;
		mp[x][y] = 1;
	}
	cout<<n*m-ans<<endl;
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