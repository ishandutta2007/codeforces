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
#define all(v) begin(v),end(v)
const int N = 3e5+10,inf = 1e9;
using pii = pair<int,int>;

vector<int> edge1[N],edge2[N];
int ans,cnt,cur;
set<pii> s;
int st[N],en[N];
void dfsb(int u)
{
	st[u] = ++cnt;
	for(auto i:edge2[u]) dfsb(i);
	en[u] = ++cnt;
}
bool is_ancestor(int u,int v)
{
	return st[u]<st[v] && en[v]<en[u];
}
void dfs(int u)
{
	int res = cur;
	auto it = s.lower_bound({st[u],0});
	if(it!=s.end()) cur += (1-is_ancestor(u,it->second));
	if(it!=s.begin())
	{
		auto tmp = it; tmp--;
		if(it!=s.end()) cur -= (1-is_ancestor(tmp->second,it->second));
		cur += (1-is_ancestor(tmp->second,u));
	}
	ans = max(ans,cur);
	s.insert({st[u],u});
	for(auto i:edge1[u]) dfs(i);
	s.erase(s.find({st[u],u}));
	cur = res;	
}
void solve() 
{
	int n; cin>>n;
	for(int i=1;i<=n;i++) edge1[i].clear(),edge2[i].clear();
	for(int i=2;i<=n;i++) 
	{
		int x; cin>>x;
		edge1[x].push_back(i);
	}
	for(int i=2;i<=n;i++) 
	{
		int x; cin>>x;
		edge2[x].push_back(i);
	}
	cnt = 0; ans = 0; cur = 1; s.clear();
	dfsb(1);
	dfs(1);
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