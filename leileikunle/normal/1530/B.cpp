#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
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

const int mod = 1e9+7;

// double time=clock();  printf("%lf\n",clock()-time);


const int N = 2e5+10;

char mp[25][25];
void solve()
{
    int n,m; cin>>n>>m;
    memset(mp,0,sizeof mp);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) mp[i][j]='0';
    for(int i=1;i<=m;i+=2) mp[1][i]='1';
    for(int i=m;i>=1;i-=2) mp[n][i]='1';
    for(int i=3;i<=n-2;i+=2) mp[i][1]='1';
    for(int i=n;i>=3;i-=2) mp[i][m]='1';
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
		{
			cout<<mp[i][j];
		}cout<<endl;
	}
	cout<<endl;
}
signed main()
{
	int tt=1;
	cin>>tt;
	while(tt--)
	{
		solve();
	}



}