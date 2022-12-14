#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
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
#define x first
#define y second
const int N = 3e5+10;
using pii = pair<int,int>;
pii a[N];
int cnt;
void dfs(int l,int r,int ll,int rr,int k,int w,int num) 
{
	if(ll<=l && r<=rr) 
	{
		int low = w;
		int cun = 1<<(num+1);
		int high = cun-1+low;
		a[++cnt] = make_pair(low,high);
		return;
	}
	int mid = l + r >> 1;
	int s = (k>>num)&1;
	if(ll<=mid) dfs(l,mid,ll,rr,k,(w|(s<<num)),num-1);
	if(rr>mid) dfs(mid+1,r,ll,rr,k,(w|((!s)<<num)),num-1);
	return;
}
pii res;
void solve()
{
	int n,m; cin>>n>>m;
	cnt = 0;
	int end = (1<<30)-1;
	dfs(0,end,0,m,n,0,29);
	sort(a+1,a+1+cnt);
	int ans = 0;
	for2(i,1,cnt)
	{
		res = a[i];
		if(ans<res.x) break;
		else ans=res.y+1;
	}
	cout<<ans<<endl;
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