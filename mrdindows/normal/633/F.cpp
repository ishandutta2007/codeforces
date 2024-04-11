#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <cmath>
# include <algorithm>
# include <cstdio>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <deque>
# include <functional>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
using namespace std;

// Let's define unordered map
# ifdef __GNUC__
# if __cplusplus > 199711L
# include <unordered_set>
# include <unordered_map>
# else
# include <tr1/unordered_map>
# include <tr1/unordered_set>
using namespace std::tr1;
# endif
# else
# include <unordered_map>
# include <unordered_set>
# endif

#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
#define DBN1(a)         std::cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)       std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)     std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)   std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e) std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
#define DA(a,n) cout<<#a<<"=["; printarray(a,n); cout<<"]\n"
#define DAR(a,n,s) cout<<#a<<"["<<s<<"-"<<n-1<<"]=["; printarray(a,n,s); cout<<"]\n"

#ifdef _MSC_VER
#define ALIGN(x) __declspec(align(x))
#else
#define ALIGN(x) __attribute__((aligned(x)))
#endif

#define CURTIME() cerr << clock() * 1.0 / CLOCKS_PER_SEC << std::endl
double __begin;
#define DTIME(ccc) __begin = clock(); ccc; std::cerr<<"Time of work = "<<(clock()-__begin)/CLOCKS_PER_SEC<<std::endl;

#define mp make_pair
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

template<typename T1, typename T2, typename T3>
struct triple{ T1 a; T2 b; T3 c; triple(){}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };
#define tri triple<int,int,int>
#define trll triple<ll,ll,ll>
template<typename T1, typename T2, typename T3>
bool operator<(const triple<T1, T2, T3> &t1, const triple<T1, T2, T3> &t2){ if (t1.a != t2.a) return t1.a<t2.a; else if (t1.b != t2.b) return t1.b<t2.b; else return t1.c < t2.c; }
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }

#define FI(n) for(int i=0;i<n;i++)
#define FJ(n) for(int j=0;j<n;j++)
#define all(a) a.begin(), a.end()
//int some_primes[10] = {100271, 500179, 1000003, 2000227, 5000321}

inline int bits_count(int v){ v = v - ((v >> 1) & 0x55555555); v = (v & 0x33333333) + ((v >> 2) & 0x33333333); return((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; }
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
inline int sign(int x){ return x > 0; }
inline bool isPowerOfTwo(int x){ return (x != 0 && (x&(x - 1)) == 0); }
#define checkbit(n,b) ( (n >> b) & 1)
#define reunique(v) v.resize(std::unique(v.begin(), v.end()) - v.begin())

//STL output ********************************
template<typename T1, typename T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p);
template<typename T> inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v);
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v);
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v);
template<typename T1, typename T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){ return os << "(" << p.first << ", " << p.second << ")"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v){ bool first = true; os << "["; for (unsigned int i = 0; i<v.size(); i++){ if (!first)os << ", "; os << v[i]; first = false; }return os << "]"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v){ bool first = true; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v){ bool first = true; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T, typename T2>void printarray(T  a[], T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }

//Pair magic
template<typename T1, typename T2> inline pair<T1, T2> operator+(const pair<T1, T2> &p1 , const pair<T1, T2> &p2) { return pair<T1, T2>(p1.first + p2.first, p1.second + p2.second); }
template<typename T1, typename T2> inline pair<T1, T2> operator-(const pair<T1, T2> &p1 , const pair<T1, T2> &p2) { return pair<T1, T2>(p1.first - p2.first, p1.second - p2.second); }

#define FREIN(FILE) freopen(FILE,"rt",stdin)
#define FREOUT(FILE) freopen(FILE,"wt",stdout)

#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(1.0*(x))
#define pow(x,n) pow(1.0*(x),n)

inline ll mulmod(ll x, ll n, ll _mod){ ll res = 0; while (n){ if (n & 1)res = (res + x) % _mod; x = (x + x) % _mod; n >>= 1; }return res; }
inline ll powmod(ll x, ll n, ll _mod){ ll res = 1; while (n){ if (n & 1)res = (res*x) % _mod; x = (x*x) % _mod; n >>= 1; }return res; }
inline ll gcd(ll a, ll b){ ll t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
inline ll gcd(ll a, ll b, ll c){ return gcd(gcd(a, b), c); }
inline int gcd(int a, int b, int c){ return gcd(gcd(a, b), c); }

template<class T>
inline void getar(T a, int n, int m){ for (int i = 0; i < n; i++) for (int j = 0; j<m; ++j) { scanf("%d", &a[i][j]); } }
inline void getar(int *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d", a + ii); } }
inline void getar(pii *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d%d", &a[ii].first, &a[ii].second); } }
inline void getar(ll *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%I64d", a + ii); } }
template<class T>
inline void cinarr(T &a, int n){ for (int i = 0; i<n; ++i) cin >> a[i]; }
// Useful constants

#define INF         1011111111
#define LLINF       1000111000111000111LL
#define EPS         (double)1e-10
#define mod         1000000007
#define PI          3.14159265358979323
#define link        asaxlaj
#define next        wrwe
//*************************************************************************************

ll dp[101010][5];
// 0 - biggest path down
//
//
//
//
vector<int> v[101010];
vector<int> g[101010];
int a[101010];
bool used[101010];
int n;
void go(int cur) {
//    DBN(cur);
    used[cur] = true;
    for (int to : v[cur]) {
        if (used[to]) continue;
        g[cur].push_back(to);
        go(to);
    }
    
    /* 0 - biggest path down */ {
        dp[cur][0] = 0;
        for (int to : g[cur]) {
            dp[cur][0] = max(dp[cur][0], dp[to][0]);
        }
        dp[cur][0] += a[cur];
    }
//    DBN(cur, dp[cur][0]);
    
    /* 1 - biggest pair of pathes */ {
        ll firstMax = 0;
        ll secondMax = 0;
        dp[cur][1] = dp[cur][0];
        for (int to : g[cur]) {
            dp[cur][1] = max(dp[cur][1], dp[to][1]);
            ll t = dp[to][0];
            if (t > firstMax) {
                secondMax = firstMax;
                firstMax = t;
            } else if (t > secondMax) {
                secondMax = t;
            }
        }
//        DBN(cur, firstMax, secondMax);
        dp[cur][1] = max(dp[cur][1], a[cur] + firstMax + secondMax);
    }
//    DBN(cur, dp[cur][1]);
    
    /* 2 - biggest path down and pair of pathes */ {
        ll firstMax = 0;
        int firstMaxTo = -1;
        ll secondMax = 0;
        int secondMaxTo = -1;
        
        ll firstMax1 = 0;
        int firstMax1To = -1;
        ll secondMax1 = 0;
        ll secondMax1To = -1;
        
        dp[cur][2] = dp[cur][1];
        for (int to : g[cur]) {
            dp[cur][2] = max(dp[cur][2], dp[to][2] + a[cur]);
            ll t = dp[to][0];
            if (t > firstMax) {
                secondMax = firstMax;
                secondMaxTo = firstMaxTo;
                firstMaxTo = to;
                firstMax = t;
            } else if (t > secondMax) {
                secondMax = t;
                secondMaxTo = to;
            }
            
            t = dp[to][1];
            if (t > firstMax1) {
                secondMax1 = firstMax1;
                secondMax1To = firstMax1To;
                firstMax1To = to;
                firstMax1 = t;
            } else if (t > secondMax1) {
                secondMax1 = t;
                secondMax1To = to;
            }
        }
        if (firstMaxTo != -1) {
            dp[cur][2] = max(dp[cur][2], dp[firstMaxTo][1] + a[cur]);
        }
        if (firstMaxTo == -1 || secondMaxTo == -1) goto nextOne;
        
        if (firstMax1To != firstMaxTo) {
            dp[cur][2] = max(dp[cur][2], dp[firstMaxTo][0] + a[cur] + dp[firstMax1To][1]);
        } else {
            dp[cur][2] = max(dp[cur][2], dp[firstMaxTo][0] + a[cur] + dp[secondMax1To][1]);
            dp[cur][2] = max(dp[cur][2], dp[secondMaxTo][0] + a[cur] + dp[firstMax1To][1]);
        }
    }
nextOne:;
    
    /* 3 - biggest pair of pairs of pathes */ {
        ll firstMax2 = 0;
        int firstMax2To = -1;
        ll secondMax2 = 0;
        int secondMax2To = -1;
        
        ll firstMax1 = 0;
        int firstMax1To = -1;
        ll secondMax1 = 0;
        int secondMax1To = -1;
        ll thirdMax1 = 0;
        int thirdMax1To = -1;
        
        ll firstMax0 = 0;
        int firstMax0To = -1;
        ll secondMax0 = 0;
        int secondMax0To = -1;
        ll thirdMax0 = 0;
        int thirdMax0To = -1;
        
        
        dp[cur][3] = dp[cur][2];
        for (int to : g[cur]) {
            dp[cur][3] = max(dp[cur][3], dp[to][3]);
        }
        for (int to : g[cur]) {
            ll t = dp[to][2];
            if (t > firstMax2) {
                secondMax2 = firstMax2;
                secondMax2To = firstMax2To;
                firstMax2To = to;
                firstMax2 = t;
            } else if (t > secondMax2) {
                secondMax2 = t;
                secondMax2To = to;
            }
            
            t = dp[to][0];
            if (t > firstMax0) {
                thirdMax0 = secondMax0;
                thirdMax0To = secondMax0To;
                secondMax0 = firstMax0;
                secondMax0To = firstMax0To;
                firstMax0To = to;
                firstMax0 = t;
            } else if (t > secondMax0) {
                thirdMax0 = secondMax0;
                thirdMax0To = secondMax0To;
                secondMax0 = t;
                secondMax0To = to;
            } else if (t > thirdMax0) {
                thirdMax0 = t;
                thirdMax0To = to;
            }
            
            t = dp[to][1];
            if (t > firstMax1) {
                thirdMax1 = secondMax1;
                thirdMax1To = secondMax1To;
                secondMax1 = firstMax1;
                secondMax1To = firstMax1To;
                firstMax1To = to;
                firstMax1 = t;
            } else if (t > secondMax1) {
                thirdMax1 = secondMax1;
                thirdMax1To = secondMax1To;
                secondMax1 = t;
                secondMax1To = to;
            } else if (t > thirdMax1) {
                thirdMax1 = t;
                thirdMax1To = to;
            }
        }
        int s0[3] = {firstMax0To, secondMax0To, thirdMax0To};
        int s1[3] = {firstMax1To, secondMax1To, thirdMax1To};
        for (int x : s0) {
            for (int y : s0) {
                for (int z : s1) {
                    if (x == y || y == z || z == x) continue;
                    if (x == -1 || y == -1 || z == -1) continue;
                    dp[cur][3] = max(dp[cur][3], dp[x][0] + a[cur] + dp[y][0] + dp[z][1]);
                }
            }
        }
        
        if (firstMax0To == -1 || secondMax0To == -1) return;
        dp[cur][3] = max(dp[cur][3], dp[firstMax1To][1] + dp[secondMax1To][1]);
        
        if (firstMax0To != firstMax2To) {
            dp[cur][3] = max(dp[cur][3], dp[firstMax0To][0] + dp[firstMax2To][2] + a[cur]);
        }
        if (firstMax0To != secondMax2To) {
            dp[cur][3] = max(dp[cur][3], dp[firstMax0To][0] + dp[secondMax2To][2] + a[cur]);
        }
        if (secondMax0To != firstMax2To) {
            dp[cur][3] = max(dp[cur][3], dp[secondMax0To][0] + dp[firstMax2To][2] + a[cur]);
        }
        if (secondMax0To != secondMax2To) {
            dp[cur][3] = max(dp[cur][3], dp[secondMax0To][0] + dp[secondMax2To][2] + a[cur]);
        }
    }
    
}
int main() {
    int n;
    cin >> n;
    FI(n) {
        cin >> a[i];
    }
    FI(n - 1) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    go(0);
    cout << dp[0][3] << endl;
    
//    FI(n) {
//        DBN(i);
//        printarray(dp[i], 4);
//    }
    
    return 0;
}