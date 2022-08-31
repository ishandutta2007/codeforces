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
template<typename T1, typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){ return os << "(" << p.first << ", " << p.second << ")"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v){ bool first = true; os << "["; for (unsigned int i = 0; i<v.size(); i++){ if (!first)os << ", "; os << v[i]; first = false; }return os << "]"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v){ bool first = true; os << "["; for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v){ bool first = true; os << "["; for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T, typename T2>void printarray(T  a[], T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }

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

#define INF         1011111111
#define LLINF       1000111000111000111LL
#define EPS         ((double)1e-10)
#define mod         1000000007
#define PI          3.14159265358979323
#define link        asaxlaj
//*************************************************************************************


int dp[102][102][102];
char s[101][101][101];
bool used[101][101][101];
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    dp[1][1][1] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> s[i][j];
            for (int l = 0; l < k; ++l) {
                dp[i + 1][j + 1][l + 1] = s[i][j][l] == '1';
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int l = 1; l <= k; ++l) {
                if (dp[i][j][l]) {
                    if (dp[i - 1][j][l] && dp[i + 1][j][l]) used[i][j][l] = true;
                    if (dp[i][j - 1][l] && dp[i][j + 1][l]) used[i][j][l] = true;
                    if (dp[i][j][l - 1] && dp[i][j][l + 1]) used[i][j][l] = true;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int l = 1; l <= k; ++l) {
                if (dp[i][j][l] && dp[i + 1][j + 1][l]) {
                    int k = dp[i + 1][j][l] + dp[i][j + 1][l];
                    if (k == 1) {
                        used[i + 1][j][l] = used[i][j + 1][l] = true;
                    }
                }
                if (dp[i][j][l] && dp[i][j + 1][l + 1]) {
                    int k = dp[i][j][l + 1] + dp[i][j + 1][l];
                    if (k == 1) {
                        used[i][j][l + 1] = used[i][j + 1][l] = true;
                    }
                }
                if (dp[i][j][l] && dp[i + 1][j][l + 1]) {
                    int k = dp[i + 1][j][l] + dp[i][j][l + 1];
                    if (k == 1) {
                        used[i + 1][j][l] = used[i][j][l + 1] = true;
                    }
                }
            }
        }
    }
    
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int l = 1; l <= k; ++l) {
                if (dp[i][j][l] && dp[i + 1][j + 1][l + 1]) {
                    int w[3][3][3] = {};
                    w[1][1][1] = 1;
                    for (int x = 1; x <= 2; ++x) {
                        for (int y = 1; y <= 2; ++y) {
                            for (int z = 1; z <= 2; ++z) {
                                w[x][y][z] += w[x - 1][y][z] + w[x][y - 1][z] + w[x][y][z - 1];
                                if (!dp[i + x - 1][j + y - 1][z + l - 1]) {
                                    w[x][y][z] = 0;
                                }
                            }
                        }
                    }
                    int r[3][3][3] = {};
                    r[1][1][1] = 1;
                    for (int x = 1; x >= 0; --x) {
                        for (int y = 1; y >= 0; --y) {
                            for (int z = 1; z >= 0; --z) {
                                r[x][y][z] += r[x + 1][y][z] + r[x][y + 1][z] + r[x][y][z + 1];
                                if (!dp[i + x][j + y][z + l]) {
                                    r[x][y][z] = 0;
                                }
                            }
                        }
                    }
                    if (w[2][2][2] == 2) {
                        if (w[2][2][1] == 2)
                            used[i + 1][j + 1][l] = true;
                        if (w[1][2][2] == 2)
                            used[i][j + 1][l + 1] = true;
                        if (w[2][1][2] == 2)
                            used[i + 1][j][l + 1] = true;
                    }
                    if (r[0][0][0] == 2) {
                        if (r[1][0][0] == 2)
                            used[i + 1][j][l] = true;
                        if (r[0][1][0] == 2)
                            used[i][j + 1][l] = true;
                        if (r[0][0][1] == 2)
                            used[i][j][l + 1] = true;
                    }
                    
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int l = 1; l <= k; ++l) {
                if (dp[i][j][l] && used[i][j][l]) {
                    ++ans;
                }
                //                cout << used[i][j][l];
            }
            //            cout << endl;
        }
        //        cout << endl;
    }
    
    cout << ans << endl;
    
    return 0;
}