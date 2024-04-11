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
const int N = 1e6+10,mod = 1e9;
#define fi first
#define se second
int a[N],pos[N];
int cost[N],sum[N];
struct node{
	int l,r;
	int mi,tag;
}tr[N*4];
void pushup(int u) 
{
	tr[u].mi = min(tr[u<<1].mi,tr[u<<1|1].mi);
}
void pushdown(int u)
{
	if(tr[u].tag)
	{
		tr[u<<1].mi += tr[u].tag; tr[u<<1].tag += tr[u].tag;
		tr[u<<1|1].mi += tr[u].tag; tr[u<<1|1].tag += tr[u].tag;
		tr[u].tag = 0;
	}
}
void build(int u,int l,int r)
{
	tr[u] = {l,r};
	if(l==r) 
	{
		tr[u].mi = sum[l];
		debug(sum[l]);
		return;
	};
	int mid = tr[u].l + tr[u].r >>1;
	build(u<<1,l,mid); 
	build(u<<1|1,mid+1,r);
	pushup(u);
}
void update(int u,int l,int r,int k)
{
	if(l>r) return;
	if(tr[u].l>=l&&tr[u].r<=r) 
	{
		tr[u].mi += k; tr[u].tag += k; return; 
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >>1;
	if(l<=mid) update(u<<1,l,r,k);
	if(r>mid) update(u<<1|1,l,r,k);
	pushup(u);
}
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],pos[a[i]]=i;
	for(int i=1;i<=n;i++)
	{
		cin>>cost[i];
		sum[i] = sum[i-1] + cost[i];
	}
	build(1,1,n-1);
	int ans = tr[1].mi;
	for(int i=1;i<=n;i++)
	{
		update(1,1,pos[i]-1,cost[pos[i]]);
		update(1,pos[i],n-1,-cost[pos[i]]);
		ans = min(ans,tr[1].mi);
		debug(ans);
	}
	cout<<ans<<endl;
	
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