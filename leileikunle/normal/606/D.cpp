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
int a[N],vis[N];
struct node{
	int w,flag,id;
};
vector<node> edge; 
vector<pii> ans;
void solve()
{
	int n,m; cin>>n>>m;
	ans.resize(m+10);
	for(int i=1;i<=m;i++)
	{
		int w,flag; cin>>w>>flag;
		edge.push_back({w,flag,i});
	}
	sort(all(edge),[](node a,node b)
	{
		if(a.w == b.w) return a.flag > b.flag;
		else return a.w < b.w;
	});
	int l,r; l = r = 2;
	int ri = 2;
	for(int i=0;i<m;i++)
	{
		if(!edge[i].flag)
		{
			if(l==r) r++,l=2;
			if(!vis[r]) return void(cout<<-1<<endl);
			ans[edge[i].id] = {l,r};
			l++;
		}else{
			ans[edge[i].id] = {1,ri};
			vis[ri] = 1; ri++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
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