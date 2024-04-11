#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
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
#define all(v) begin(v),end(v)
const int N = 4e4+10,inf = 1e9;
int dp[N][105];
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
		int t = tr[u].tag;
		tr[u<<1].mi += t, tr[u<<1].tag += t;
		tr[u<<1|1].mi += t, tr[u<<1|1].tag += t;
		tr[u].tag = 0;
	}
}
void build(int u,int l,int r)
{
	tr[u] = {l,r,0,0};
	if(l==r) return;
	int mid = l + r >>1;
	build(u<<1,l,mid); build(u<<1|1,mid+1,r);
	pushup(u);
}
void update(int u,int l,int r,int k)
{
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		tr[u].mi += k; tr[u].tag += k;
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >>1;
	if(l<=mid) update(u<<1,l,r,k);
	if(r>mid) update(u<<1|1,l,r,k);
	pushup(u);
}
int query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r) return tr[u].mi;
	pushdown(u);
	int mid = tr[u].l + tr[u].r >>1;
	int ans = inf;
	if(l<=mid) ans = min(ans,query(u<<1,l,r));
	if(r>mid) ans = min(ans,query(u<<1|1,l,r));
	return ans;
}
int pos[N],a[N],last[N];
void solve()
{
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pos[i] = last[a[i]];
		last[a[i]] = i;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][1] = dp[i-1][1] + (pos[i] == 0 ? 0 : i - pos[i]);
	}
	for(int j=2;j<=k;j++)
	{
		build(1,1,n);
		for(int i=1;i<=n;i++) update(1,i,i,dp[i][j-1]);
		for(int i=1;i<j;i++)  dp[i][j] = inf;
		for(int i=j;i<=n;i++)
		{
			if(pos[i]) update(1,1,pos[i]-1,i-pos[i]);
			dp[i][j] = query(1,1,i-1);
		}
	}
	cout<<dp[n][k];	
}
signed main()
{
	int tt=1;
	while(tt--)
	{
		solve();
	}
}