#include<bits/stdc++.h>
#define endl '\n'
#define int long long
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
#define all(v) begin(v),end(v)
#define lb(a, x) distance(begin(a), lower_bound(all(a), (x)))
#define toset(a) (sort(all(a)), a.erase(unique(all(a)), a.end()), a.size())
#define x first
#define y second
using pii = pair<int,int>;
const int N =6e5+10,inf = 1e9;
struct node1{
	int line,l,r;
}a[N];
vector<int> v; 
vector<pii> g[N];

int find(int x) { return lb(v,x) + 1; }
struct node{
	int l,r;
	pii mx,tag;
}tr[N*4];
void pushup(int u) {  tr[u].mx = max(tr[u<<1].mx,tr[u<<1|1].mx);  }
void pushdown(int u)
{
	if(tr[u].tag.x)
	{
		tr[u<<1].mx = tr[u<<1].tag = tr[u].mx;
		tr[u<<1|1].mx = tr[u<<1|1].tag = tr[u].mx;
		tr[u].tag = {0,0};
	}
}
void build(int u,int l,int r)
{
	tr[u] = {l,r};
	if(l==r) return;
	int mid = l + r >>1;
	build(u<<1,l,mid); build(u<<1|1,mid+1,r);
	pushup(u); 
}
void update(int u,int l,int r,pii k)
{
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		tr[u].mx = k; tr[u].tag = k;
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >>1;
	if(l<=mid) update(u<<1,l,r,k);
	if(r>mid) update(u<<1|1,l,r,k);
	pushup(u);
}
pii query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r) return tr[u].mx;
	pushdown(u);
	int mid = tr[u].l + tr[u].r >>1;
	if(r<=mid) return query(u<<1,l,r);
	if(l>mid) return query(u<<1|1,l,r);
	else return max(query(u<<1,l,r),query(u<<1|1,l,r));
}
int f[N],st[N],ok[N];
void solve() 
{
	int n,m; cin>>n>>m;
	build(1,1,2*m);
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].line>>a[i].l>>a[i].r;
		v.push_back(a[i].l); v.push_back(a[i].r);
	}
	int siz = toset(v);
	for(int i=1;i<=m;i++)
	{
		a[i].l = find(a[i].l); a[i].r = find(a[i].r);
		g[a[i].line].push_back({a[i].l,a[i].r});
	}
	
	for(int i=1;i<=n;i++) if(g[i].size()) sort(all(g[i]));
	for(int i=1;i<=n;i++)
	{
		pii mx = {0,0};
		for(auto t:g[i]) mx = max(mx,query(1,t.x,t.y));
		f[i] = mx.x+1; st[i] = mx.y;
		for(auto t:g[i]) update(1,t.x,t.y,{mx.x+1,i});
	}
	cout<<n-tr[1].mx.x<<endl;
	int now = tr[1].mx.y;
	while(now)
	{
		ok[now] = 1; 
		now = st[now];
	}
	for(int i=1;i<=n;i++) 
	{
		if(!ok[i]) cout<<i<<' ';
	}
	cout<<endl;
}
signed main()
{
	int tt=1;
	while(tt--)
	{
		solve();
	}
}