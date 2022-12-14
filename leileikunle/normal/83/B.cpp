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
inline char nextchar() {
	static char buf[1 << 20], *p = buf, *q = buf;
	return p == q && (q = (p = buf) + fread(buf, 1, 1 << 20, stdin), p == q) ? EOF : *p++;
}

template<typename T>
inline void read(T& x) {
	x = 0;
	char c = nextchar();
	for (; !isdigit(c); c = nextchar()) ;
	for (;  isdigit(c); c = nextchar()) x = x * 10 + c - '0';
}

template<typename T, typename... other>
inline void read(T& x, other&... y) {
	read(x);
	read(y...);
}
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
#define all(a) a.begin(),a.end()
#define lb(a, x) distance(begin(a), lower_bound(all(a), (x)))
#define toset(a) (sort(all(a)), a.erase(unique(all(a)), a.end()), a.size())
using pii = pair<int,int>;
const int N = 4e5+10,mod = 998244353,inf = 0x3f3f3f3f;
int a[N];
void solve() 
{
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int sum = accumulate(a+1,a+n+1,0ll);
    if(sum<k) return void(cout<<-1);
    else if(sum==k) return void(cout<<endl);
    if(!k) 
    {
		for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;
		return;
	}
    int l = 1,r = 1e9;
    auto check = [&](int x) -> bool{
		int cnt = 0;	
		for(int i=1;i<=n;i++) cnt += min(x,a[i]);
		if(cnt<k) return true;
		else return false;
	};
	while(l<=r)
    {
		int mid = l + r >>1;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	int res = 0,last;
	for(int i=1;i<=n;i++) res += min(a[i],l-1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=l) res++;
		if(res==k) 
		{
			last = i; 
			break;
		}
	}
	vector<int> ans;
	for(int i=last+1;i<=n;i++) if(a[i]>=l) ans.push_back(i);
	for(int i=1;i<=last;i++) if(a[i]>l) ans.push_back(i);
	for(auto i:ans) cout<<i<<" "; cout<<endl;
}
signed main() 
{
    int tt = 1;
    //  cin>>tt;
    while (tt--) 
	{
        solve();
    }
}