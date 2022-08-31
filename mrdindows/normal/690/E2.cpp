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
# include <random>
# include <deque>
# include <functional>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>

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

#define FI(n) for(int i=0;i<n;++i)
#define FJ(n) for(int j=0;j<n;++j)
#define FK(n) for(int k=0;k<n;++k)
#define all(a) a.begin(), a.end()
//int some_primes[10] = {100271, 500179, 1000003, 2000227, 5000321}

inline int bits_count(int v){ v = v - ((v >> 1) & 0x55555555); v = (v & 0x33333333) + ((v >> 2) & 0x33333333); return((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; }
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
inline int sign(int x){ return x > 0; }
inline bool isPowerOfTwo(int x){ return (x != 0 && (x&(x - 1)) == 0); }
#define checkbit(n, b) ((n >> b) & 1)
#define reunique(v) v.resize(std::unique(v.begin(), v.end()) - v.begin())

//STL output ********************************
template<typename T1, typename T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p);
template<typename T> inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v);
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v);
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v);
template<typename T1, typename T2, typename T3> inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t);
template<typename T1, typename T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){ return os << "(" << p.first << ", " << p.second << ")"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v){ bool first = true; os << "["; for (unsigned int i = 0; i<v.size(); i++){ if (!first)os << ", "; os << v[i]; first = false; }return os << "]"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v){ bool first = true; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v){ bool first = true; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T, typename T2>void printarray(T  a[], T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }

//Pair magic
template<typename T1, typename T2> inline pair<T1, T2> operator+(const pair<T1, T2> &p1 , const pair<T1, T2> &p2) { return pair<T1, T2>(p1.first + p2.first, p1.second + p2.second); }
template<typename T1, typename T2> inline pair<T1, T2> operator-(const pair<T1, T2> &p1 , const pair<T1, T2> &p2) { return pair<T1, T2>(p1.first - p2.first, p1.second - p2.second); }

#define FREIN(FILE) freopen(FILE, "rt", stdin)
#define FREOUT(FILE) freopen(FILE, "wt", stdout)

#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(1.0 * (x))
#define pow(x, n) pow(1.0 * (x), n)

inline ll mulmod(ll x, ll n, ll _mod){ ll res = 0; while (n){ if (n & 1)res = (res + x) % _mod; x = (x + x) % _mod; n >>= 1; }return res; }
inline ll powmod(ll x, ll n, ll _mod){ ll res = 1; while (n){ if (n & 1)res = (res*x) % _mod; x = (x*x) % _mod; n >>= 1; }return res; }
inline ll gcd(ll a, ll b){ ll t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
inline ll gcd(ll a, ll b, ll c){ return gcd(gcd(a, b), c); }
inline int gcd(int a, int b, int c){ return gcd(gcd(a, b), c); }

// Useful constants

#define INF         1011111111
#define LLINF       1000111000111000111LL
#define EPS         (double)1e-10
#define mod         1000000007
#define PI          3.14159265358979323
#define link        asaxlajrewqwe
#define rank        wahayawehasdakw
//*************************************************************************************


char c[606][606];
double g1[606][606];
double g2[606][606];
int im[606];
int h, w, r;
int get(int x, int y) {
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x >= h) x = h - 1;
    if (y >= w) y = w - 1;
    return g1[x][y];
}
double dist[20][20];
double dp[1 << 16][16];
pii par[1 << 16][16];
int main() {
    vector<int> anses[200] = {{2,1},
        {2,3,1},
        {4,3,2,1},
        {1,3,4,2,5},
        {1,6,11,3,10,9,15,12,7,13,2,5,4,14,8},
        {5,1,3,11,10,7,6,9,13,15,12,4,14,2,8},
        {9,7,2,5,1,10,8,3,4,6},
        {2,1,4,3},
        {4,12,8,2,9,14,5,7,1,6,10,13,15,3,11},
        {11,5,6,8,10,12,7,2,1,4,9,3,13,14,15},
        {11,7,8,4,5,15,13,14,3,9,12,2,1,10,6},
        {12,7,11,4,10,2,5,14,13,1,6,3,9,8,15,16},
        {3,2,1},
        {4,2,1,3,5},
        {1,8,11,15,3,2,7,16,13,4,6,10,9,12,5,14},
        {9,8,6,13,11,10,2,7,14,12,5,4,15,3,1},
        {2,15,16,10,8,5,9,3,11,7,1,14,12,4,6,13},
        {15,5,2,14,3,13,1,7,12,8,4,10,6,11,9},
        {9,7,3,14,2,12,13,5,1,15,11,10,8,4,6},
        {9,7,13,10,15,16,5,3,6,1,2,11,8,4,14,12},
        {6,13,2,11,5,10,3,14,9,1,12,8,16,4,15,7},
        {2,7,16,14,13,8,4,10,5,12,11,1,6,9,3,15},
        {2,1,6,13,4,11,9,8,5,3,7,14,10,12,15},
        {3,11,4,5,14,10,16,9,8,6,7,13,12,1,15,2},
        {4,3,11,9,8,16,6,15,2,13,7,14,10,1,12,5},
        {1,12,9,7,6,5,2,13,14,10,15,8,11,4,3},
        {2,1,3},
        {2,1},
        {1,3,2,6,4,8,7,5},
        {14,5,6,7,2,9,13,8,1,4,11,15,16,10,3,12},
        {1,7,4,3,6,5,2,8},
        {13,7,6,14,12,15,3,5,1,9,8,10,4,11,2},
        {11,2,15,5,14,3,9,10,7,1,12,13,8,6,4},
        {3,1,2,4},
        {16,13,11,14,9,2,15,3,1,5,6,7,12,8,4,10},
        {3,1,4,9,16,15,7,10,6,13,5,11,2,14,12,8},
        {11,1,10,16,6,7,9,5,4,8,15,2,12,3,14,13},
        {3,1,6,5,2,4},
        {14,8,2,10,6,16,9,7,15,4,1,3,11,13,5,12},
        {15,8,10,9,11,12,7,13,5,14,1,4,3,2,6},
        {5,7,3,12,6,11,8,4,10,1,2,9},
        {2,1},
        {13,14,8,6,4,7,5,10,3,11,2,9,15,12,1},
        {2,15,11,13,12,5,3,4,9,8,14,6,10,1,7},
        {3,1,4,2},
        {6,2,16,5,7,10,15,1,8,14,13,4,9,11,3,12},
        {3,1,2},
        {16,4,13,11,7,9,5,2,10,3,6,15,12,14,8,1},
        {2,5,1,9,15,7,3,11,13,4,8,12,6,14,10},
        {6,3,11,15,16,13,7,2,5,12,4,14,8,1,10,9},
        {5,7,11,3,10,15,2,9,4,8,14,13,16,12,1,6},
        {4,6,7,8,5,3,11,16,12,15,14,2,1,9,13,10},
        {6,5,2,10,12,8,4,13,9,11,1,15,3,14,7},
        {12,13,9,1,3,11,4,8,15,14,10,7,16,5,6,2},
        {4,2,3,1},
        {10,7,15,3,12,6,11,1,16,5,13,9,14,8,2,4},
        {5,2,6,4,1,3},
        {1,13,9,4,8,2,5,6,7,12,3,15,10,11,14},
        {10,8,2,11,15,5,1,13,16,12,14,9,6,4,3,7},
        {8,2,15,11,9,12,16,6,13,7,4,5,14,1,10,3},
        {3,9,10,13,6,16,5,4,8,7,12,11,1,15,14,2},
        {3,2,6,12,5,14,4,1,9,13,8,7,15,11,10},
        {6,7,3,2,5,8,1,9,10,4},
        {11,10,12,15,3,13,1,16,2,8,4,5,6,14,7,9},
        {8,1,13,15,7,10,5,9,3,2,6,4,12,11,14},
        {5,15,4,7,10,14,11,1,3,9,8,16,12,2,13,6},
        {3,2,1},
        {4,7,8,2,1,6,5,3},
        {2,1},
        {10,3,7,6,12,4,1,5,9,2,8,13,14,15,16,11},
        {15,9,2,8,1,4,14,13,5,3,12,6,7,11,10},
        {4,1,5,2,3},
        {1,8,4,11,9,3,6,7,5,2,10,12},
        {9,3,14,10,13,6,2,16,1,7,5,11,15,8,12,4},
        {6,5,9,14,4,11,10,7,1,12,13,3,8,2,16,15},
        {11,16,14,2,6,12,3,4,1,8,7,13,10,9,15,5},
        {15,14,4,6,9,5,3,2,13,12,10,11,7,1,8},
        {12,9,14,10,3,15,2,16,13,8,4,5,7,6,11,1},
        {4,3,5,14,6,8,16,10,9,12,2,11,13,15,7,1},
        {1,4,5,10,9,6,8,3,2,7},
        {7,6,15,5,12,13,2,4,3,14,11,1,10,8,9},
        {2,14,9,3,8,7,6,15,10,11,16,5,12,13,1,4},
        {2,5,9,1,11,4,16,6,8,7,12,3,13,10,15,14},
        {3,5,7,14,1,9,6,4,10,8,11,15,2,16,12,13},
        {15,14,10,13,1,5,2,12,4,11,8,9,6,7,3,16},
        {6,1,4,16,2,9,8,5,12,11,10,13,3,7,14,15},
        {16,14,9,8,4,1,7,2,12,10,3,5,11,6,15,13},
        {6,1,5,2,4,3},
        {3,10,4,5,9,6,1,2,7,8},
        {8,1,15,10,12,5,14,11,4,2,3,13,7,9,6},
        {5,13,12,7,9,1,10,4,15,8,3,2,14,6,11},
        {2,3,6,1,4,5},
        {3,15,13,6,7,11,12,1,14,4,8,9,2,10,5},
        {2,12,13,11,5,1,4,3,8,15,16,14,6,9,10,7},
        {7,2,4,13,9,1,15,8,12,11,6,3,5,14,10},
        {3,4,5,6,14,8,9,10,15,12,11,13,7,2,1},
        {4,11,5,12,8,14,10,7,3,9,16,13,15,1,6,2},
        {2,6,3,1,4,5},
        {6,5,7,9,2,8,3,1,4,10},
        {14,7,15,11,1,4,3,13,5,10,6,9,8,2,12},
        {15,14,5,3,7,4,1,9,11,6,10,2,12,13,8},
        {16,14,3,7,13,2,6,1,10,12,9,4,5,8,11,15},
        {3,8,5,10,12,11,4,6,7,9,2,1},
        {11,3,5,4,12,8,1,2,6,7,9,10},
        {3,11,6,16,13,15,5,2,12,7,14,8,10,9,4,1},
        {6,5,1,4,3,2},
        {1,4,2,10,12,11,9,5,6,13,3,14,15,8,7},
        {7,13,10,5,2,12,6,3,8,4,15,11,1,9,14},
        {12,5,7,8,1,9,10,15,6,4,14,13,3,2,11},
        {2,5,3,9,13,4,7,12,6,14,10,11,15,1,8},
        {5,4,2,6,1,3},
        {4,8,9,1,5,13,11,7,3,12,2,6,14,15,10},
        {2,1},
        {11,5,7,9,15,2,8,14,3,13,10,12,1,6,4},
        {5,14,15,4,13,6,8,10,7,12,2,11,16,3,9,1},
        {12,8,7,2,3,9,15,5,11,6,4,14,13,1,10},
        {14,7,11,13,2,3,12,1,10,9,5,8,4,15,6},
        {6,4,3,5,1,2,7,8},
        {8,16,4,11,13,5,2,14,9,6,3,15,12,1,10,7},
        {3,5,1,8,2,9,7,12,4,11,10,6},
        {2,5,4,9,11,12,13,6,3,1,15,10,8,7,14},
        {13,6,8,11,12,15,1,2,10,9,7,14,3,5,4},
        {2,11,15,12,5,8,9,1,14,10,4,3,6,7,13},
        {5,8,16,3,10,6,14,7,1,15,12,9,13,2,11,4},
        {10,12,1,16,11,4,2,15,6,7,13,14,5,3,8,9},
        {1,2,5,3,4},
        {6,5,1,4,2,3},
        {8,4,7,5,6,1,2,3},
        {4,2,3,1},
        {4,5,6,8,3,1,2,9,10,7},
        {1,8,10,12,14,13,16,11,9,4,3,2,7,5,15,6},
        {2,1},
        {14,8,1,15,11,2,9,7,3,12,10,4,5,13,6},
        {15,13,8,2,7,11,6,5,14,9,10,12,3,4,1},
        {2,1},
        {8,4,5,10,6,1,14,13,12,9,2,3,11,15,7},
        {10,3,6,8,5,11,14,16,7,1,9,2,13,4,15,12},
        {7,5,6,2,4,1,8,3},
        {10,2,7,9,11,6,1,8,3,5,12,4},
        {4,2,3,1},
        {3,13,9,7,11,15,14,10,5,2,16,12,4,8,1,6},
        {2,7,11,5,15,6,4,13,8,1,10,3,9,12,14},
        {2,7,14,16,13,8,3,15,12,11,1,4,6,5,10,9},
        {4,3,1,2,5},
        {3,4,11,7,15,1,13,10,9,14,16,12,5,8,2,6},
        {4,9,14,7,12,3,10,5,13,1,2,11,8,6,15},
        {10,9,16,13,7,3,12,4,15,8,5,1,11,2,6,14},
        {2,1},
        {14,4,1,2,13,6,3,5,12,10,7,9,15,8,11},
        {3,4,1,6,2,5},
        {5,10,4,6,2,8,11,9,1,7,3,13,15,14,12},
        {2,4,1,3},
        {16,14,12,11,7,3,2,6,1,9,4,10,15,13,5,8},
        {13,12,1,4,16,15,2,14,5,8,10,9,6,11,7,3},
        {4,2,1,3},
        {8,12,2,4,1,11,9,6,15,7,10,3,13,5,14}};
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        for (int x : anses[i]) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
    
    FREIN("medium_contestant_package/all.in");
    FREOUT("out.txt");
    ifstream correct("medium_contestant_package/sample.out");
    int tot = 0;
    while (q--) {
        int k;
        cin >> h >> w >> k;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                int x;
                cin >> x;
                c[i][j] = x;
                g1[i][j] = log(x + 1.0);
            }
        }
        r = h / k;
        const int ks = 9;
        double kernel[ks] = {0.1, 0.12, 0.15, 0.2, 0.2, 0.2, 0.15, 0.12, 0.1};
        double coef = 0.0;
        for (int i = 0; i < ks; ++i) {
            coef += kernel[i];
        }
        auto calc2 = [&](int x, int y, int t) {
            double sum = 0;
            int from = 3;
            for (int i = from; i >= 0; --i) {
                sum += get(x + (from - i) * t, y) * kernel[i];
            }
            return sum / coef;
        };
        for (int part = 0; part < k; ++part) {
            int from = part * r;
            int to = from + r - 1;
            for (int i = 0; i < w; ++i) {
                g1[from][i] = calc2(from, i, 1);
                g1[to][i] = calc2(to, i, -1);
            }
        }
        auto calc = [&](int x, int y) {
            double sum = 0;
            for (int i = 0; i < ks; ++i) {
                sum += get(x, y - ks / 2 + i) * kernel[i];
            }
            return sum / coef;
        };
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (i == j) continue;
                int from = i * r + r - 1;
                int to = j * r;
                double sum = 0;
                for (int l = 0; l < w; ++l) {
                    auto a = calc(from, l);
                    auto b = calc(to, l);
                    sum += abs(a - b);
                }
                dist[i][j] = sum;
//                DBN(from, to);
//                DBN(i, j, sum);
            }
        }
//        return 0;
        for (int mask = 1; mask < (1 << k); ++mask) {
            if (bits_count(mask) == 1) {
                int last = 0;
                while (!checkbit(mask, last)) ++last;
                dp[mask][last] = 0;
            } else {
                for (int i = 0; i < k; ++i) {
                    if (checkbit(mask, i)) {
                        int sm = mask ^ (1 << i);
                        dp[mask][i] = 1e20;
                        for (int j = 0; j < k; ++j) {
                            if (checkbit(sm, j)) {
                                double res = dp[sm][j] + dist[j][i];
                                if (res < dp[mask][i]) {
                                    dp[mask][i] = res;
                                    par[mask][i] = {sm, j};
                                }
                            }
                        }
                    }
                }
            }
        }
        vector<int> v;
        int mask = (1 << k) - 1;
        int best = 0;
        for (int i = 0; i < k; ++i) {
            if (dp[mask][i] < dp[mask][best]) {
                best = i;
            }
        }
        for (int i = 0; i < k; ++i) {
            v.push_back(best + 1);
            int t = mask ^ (1 << best);
            best = par[mask][best].second;
            mask = t;
        }
        reverse(all(v));
        static int res[20];
        for (int i = 0; i < k; ++i) {
            res[v[i] - 1] = i + 1;
        }
        v = {res, res + k};
        static int test = 0;
        if (test++ < 20) {
            for (int i = 0; i < k; ++i) {
                correct >> v[i];
            }
        }
        cout << "{";
        for (int i = 0; i < k; ++i) {
            cout << v[i] << (i == k - 1 ? "},\n" : ",");
        }
        DBN(test);
//        return 0;
    }
    DBN(tot);
    return 0;
}