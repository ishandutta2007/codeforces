#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;
//#define int long long
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
const int N = 1e6+10,mod = 1e9+7,inf = 0x3f3f3f3f;
int dp[82][82][82][2];
int dis[82][82];
void solve()
{
	int n,k,m; cin>>n>>k>>m;
	if(k==1) return void(cout<<0<<endl);
	memset(dp,0x3f,sizeof dp);
	memset(dis,0x3f,sizeof dis);
	while(m--)
	{
		int a,b,c; cin>>a>>b>>c;
		dis[a][b] = min(dis[a][b],c);
	}
	for(int i=1;i<=n;i++) dp[1][0][i][1] = dp[1][i][n+1][0] = 0;
	
	for(int i=1;i<k;i++)
	{
		for(int l=0;l<=n+1;l++)
		{
			for(int r=l;r<=n+1;r++)
			{
				for(int f=0;f<2;f++)
				{
					if(dp[i][l][r][f] != inf)
					{
						int v= (f==0?l:r);
						for(int z=l+1;z<=r-1;z++)
						{
							if(dis[v][z] < inf)
							{
								dp[i+1][l][z][1] = min(dp[i+1][l][z][1],dp[i][l][r][f] + dis[v][z]);
								dp[i+1][z][r][0] = min(dp[i+1][z][r][0],dp[i][l][r][f] + dis[v][z]);
							}
						}
					}
				} 
			}
		}
	}
	
	int ans = inf;
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			ans = min({ans,dp[k][l][r][0],dp[k][l][r][1]});
		}
	}
	if(ans >= inf) cout<<-1<<endl;
	else cout<<ans<<endl;
	
	
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