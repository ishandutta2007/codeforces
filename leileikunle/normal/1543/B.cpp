#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#define pb push_back 	#define po pop_back
#define YES cout<<"YES\n" 	#define Yes cout<<"Yes\n"   #define NO cout<<"NO\n"	 #define No cout<<"No\n"
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
#define cn change_number_tostring    #define cs change_string_tonumber   #define pri init_prime_distance
#define all(a) begin(a), end(a)
#define SUM(a) accumulate(all(a), 0LL)
#define MIN(a) (*min_element(all(a)))
#define MAX(a) (*max_element(all(a)))
#define lb(a, x) distance(begin(a), lower_bound(all(a), (x)))
#define ub(a, x) distance(begin(a), upper_bound(all(a), (x)))
#define gcd __gcd
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

const int mod = 1e9+7;
const int sp = 1e9;
const int ma = 1e5+10;

//int f[ma];
//inline int find(int k) { return f[k]==k? k : f[k]=find(f[k]);} // f[find(j)] = find(k);

inline int digit(int i) { stringstream ss; ss<<i; return ss.str().size(); }
inline string change_number_tostring(int i) {  stringstream ss; ss<<i; return ss.str();  }
inline int change_string_tonumber(string s) {  int num; stringstream ss(s);  ss>>num; return num;  }
inline int quick(int a, int b) { a%=mod; int res = 1;  while(b) { if(b & 1) res = res * a % mod; a = a * a % mod;  b >>= 1; } return res; }
inline int C(int n, int m) { int resdw1 = 1; for2(i, 1, n) resdw1 = resdw1 * i % mod; int resdw2 = 1; for2(i, 1, m - n) resdw2 = resdw2 * i % mod;  int resup = 1;  for2(i, 1, m) resup = resup * i % mod;     return resup * quick(resdw1, mod - 2) % mod * quick(resdw2, mod - 2) % mod; }

inline void read(int &x) {   int f = 1; x = 0; char op = getchar(); while(op < '0' || op > '9') {  if(op == '-') f = -1; op = getchar(); } while(op >= '0' && op <= '9') { x = x * 10 + op - '0'; op = getchar(); } x *= f;	}
inline void print(int x) {   if(x < 0) putchar('-'), x = -x; if(x > 9) print(x / 10); putchar(x % 10 + '0');  }

const int man=1e7+5;
bool vis[man]={0};
int prime[man];
inline void init_prime_distance()  {int cnt= 0; for (int i=2;i<=man;i++) { if (!vis[i])  prime[cnt++]=i; for(int j=0;j<cnt&&i*prime[j]<=man;j++) { vis[i*prime[j]] = 1; if (i%prime[j]== 0) break; } } }

// double time=clock();  printf("%lf\n",clock()-time);


const int N = 2e5+10;
int a[N];
void solve()
{
	int n; cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	int t = sum/n;
	int q = sum%n;
	cout<<q*(n-q)<<endl;
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