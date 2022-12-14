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
const int N = 5e5+10,mod = 1e9+7,inf = 1e18;
int a[N];
int mp[200][200],dis[200][200];
void solve()
{
	int n; cin>>n;
	int cnt = 0;
	for(int i=1;i<=n;i++) 
	{
		int x; cin>>x;
		if(x) cnt++,a[cnt] = x;
	}
	if(cnt>150) return cout<<3,void(0);
	n = cnt;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j && (a[i]&a[j]))  dis[i][j] = mp[i][j] = 1;
			else dis[i][j] = mp[i][j] = inf;
		}
	}
	int ans = inf;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)
		{
			for(int j=i+1;j<k;j++)
			{
				ans = min(ans,mp[i][k]+mp[k][j]+dis[i][j]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dis[i][k]!=inf && dis[k][j]!=inf)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	cout<< (ans >= inf ? -1 : ans)<<endl;
	
	
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