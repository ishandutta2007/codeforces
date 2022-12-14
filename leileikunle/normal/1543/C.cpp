#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
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
const double tru = 1.0;
double a,b,c,d;
double dfs(double a,double b,double c)
{
	if(a<=1e-7) if(b<=1e-7) return tru; 
	double res=0;
	if(a>=1e-7)
	{
		if(a<d)
		{
			double cun = a/2;
			if(b<=1e-7) res=res+(dfs(0,0,1)+1) * a;
			else res=res+a*(dfs(0,cun+b,c+cun)+1);
		}
		else
		{
			double cun = a-d,q = d/2;;
			if(b<=1e-7)  res=res+a*(dfs(cun,0,c+d)+1);
			else res=res+a*(dfs(cun,b+q,c+q)+1);
		}
	}
	if(b>=1e-7)
	{
		if(b<d)
		{
			double cun = b/2;
			if(a<=1e-7) res=res+(dfs(0,0,1)+1)*b;
			else res=res+(dfs(a+cun,0,c+cun)+1)*b;
		}
		else
		{
			double cun = b-d;
			if(a<=1e-7) res=res+(dfs(0,cun,c+d)+1)*b;
			else res=res+(dfs(a+(d/2),cun,c+(d/2))+1)*b;
		}
	}
	return res+=c;
}
void solve()
{
	cin>>a>>b>>c>>d;
	printf("%.15f",dfs(a,b,c));
	cout<<endl;
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