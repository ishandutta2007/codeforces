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
const int N = 1e6+10,mod = 1e9+7,inf = 1e18;
inline int quick(int a, int b) { a%=mod; int res = 1;  while(b) { if(b & 1) res = res * a % mod; a = a * a % mod;  b >>= 1; } return res; }

struct edge{
	int from;
	int to;
	bool exist;
}e[N];
int d[N],f[N];
int calc(int x) { return f[x] - (d[x]+1)/2; }

void solve()
{
	int n,m; cin>>n>>m;
	for(int i=1,u,v;i<=m;i++)
	{
		cin>>u>>v;
		d[u]++; d[v]++;
		e[i] = {u,v};
	}
	for(int i=1;i<=n;i++) f[i] = d[i];
	sort(e+1,e+m+1,[&](edge a,edge b){
		return min(calc(a.from),calc(a.to)) > min(calc(b.from),calc(b.to));
	});
    int now = m,pos = m,limit = (n+m+1)/2;
    while(now>limit)
    {
		int u = e[1].from,v = e[1].to;
		f[u]--; f[v]--;
		if(calc(u)>=0 && calc(v)>=0) now--,e[1].exist = 1;
		else f[u]++,f[v]++;
		swap(e[1],e[pos]);
		pos--;
	}
	cout<<now<<endl;
	for(int i=1;i<=m;i++)
	{
		if(!e[i].exist) cout<<e[i].from<<" "<<e[i].to<<endl;
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