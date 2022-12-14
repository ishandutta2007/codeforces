#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
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
using ll = long long;
const int N = 1e3+10,M=1e5+10,mod = 1e9+7;
int a[M];

struct node{
	int l,r;
	int sum,mx;
}tr[M*4];
void pushup(int u)
{
	tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
	tr[u].mx = max(tr[u<<1].mx, tr[u<<1|1].mx);
}
void build(int u,int l,int r)
{
	tr[u] = {l,r};
	if(l==r) 
	{
		tr[u].sum = tr[u].mx = a[l];
		return;
	}
	int mid = l + r >>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u); 
}
void update(int u,int l,int r,int x)
{
	if(tr[u].l>=l&&tr[u].r<=r) 
	{
		tr[u].sum = tr[u].mx = x;
		return;
	}
	int mid = tr[u].l + tr[u].r >>1;
	if(l<=mid) update(u<<1,l,r,x);
	else update(u<<1|1,l,r,x);
	pushup(u);
}
void update1(int u,int l,int r,int x)
{
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		if(tr[u].l==tr[u].r)
        {
            tr[u].sum %= x;
			tr[u].mx = tr[u].sum;
        }else
        {
            int mid = tr[u].l + tr[u].r >>1;
            if(tr[u<<1].mx>=x) update1(u<<1,l,r,x); 
            if(tr[u<<1|1].mx>=x) update1(u<<1|1,l,r,x); 
            pushup(u);
        }
        return;
	}
	int mid = tr[u].l + tr[u].r >>1;
	if(l<=mid) update1(u<<1,l,r,x);
	if(r>mid) update1(u<<1|1,l,r,x);
	pushup(u);
}
int query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r) return tr[u].sum;
	int mid = tr[u].l + tr[u].r >>1;
	int ans = 0;
	if(l<=mid) ans += query(u<<1,l,r);
	if(r>mid) ans += query(u<<1|1,l,r);
	return ans;
}
void solve()
{
	int n,q; cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while(q--)
	{
		int opt; cin>>opt;
		int l,r; cin>>l>>r;
		if(opt==1)
		{
			cout<<query(1,l,r)<<endl;
		}else if(opt==3)
		{
			update(1,l,l,r);
		}else{
			int x; cin>>x;
			update1(1,l,r,x);
		}
//		for(int i=1;i<=n;i++) cout<<query(1,i,i)<<" "; cout<<endl;
	}
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