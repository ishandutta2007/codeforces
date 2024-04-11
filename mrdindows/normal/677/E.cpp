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

//
//bool used[303][303][303];
//int d[303][303][303];
//int dp[303][303];
//int code(int x, int y, int z) {
//    int r = z;
//    r = r * 303 + y;
//    r = r * 303 + x;
//    return r;
//}
//void decode(int& x, int& y, int& z, int code) {
//    x = code % 303;
//    code /= 303;
//    y = code % 303;
//    code /= 303;
//    z = code;
//}
//int q[303*303*303];
//int a[303][303];
//int n, m, p;
//int gett(int i, int j) {
//    if (i < 0 || j < 0 || i >= n || j >= m) {
//        return 0;
//    }
//    return a[i][j];
//}
///*
//2 2 4
// 1 2
// 4 3
// */
// 
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin >> n >> m >> p;
//    int zx = 0, zy = 0;
//    FI(n) {
//        FJ(m) {
//            int x;
//            cin >> x;
//            a[i][j] = x;
//            if (x == p) {
//                zx = i;
//                zy = j;
//            }
//        }
//    }
//    int qc = 0;
//    int qs = 0;
//    
//    q[qs++] = code(0, 0, a[0][0] == 1);
//    int dx[4] = {0, 1, 0, -1};
//    int dy[4] = {1, 0, -1, 0};
//    while (qc < qs) {
//        auto curt = q[qc++];
//        int x, y, z;
//        decode(x, y, z, curt);
//        int curd = d[x][y][z];
////        DBN(x, y, z, curd);
//        for (int dir = 0; dir < 4; ++dir) {
//            int tox = x + dx[dir];
//            int toy = y + dy[dir];
//            int t = gett(tox, toy);
//            if (t == 0) continue;
//            if (t != z + 1) {
//                t = z;
//            }
//            if (used[tox][toy][t]) {
//                continue;
//            }
//            used[tox][toy][t] = true;
//            d[tox][toy][t] = curd + 1;
//            q[qs++] = code(tox, toy, t);
//        }
//    }
////    for (int i = 1; i <= p; ++i) {
////        dp[i].resize(w[i].size());
////    }
//    cout << d[zx][zy][p] << endl;
//    return 0;
//}




int a[1011][1010];
pii val[1010][1010];
int n;
int z[1011][1010];
int f[1010][1010];
pii prefi[1010][1010];
pii prefj[1010][1010];
pii prefr[1010][1010];
pii prefd[1010][1010];
pii sum(const pii& p1, const pii& p2) {
    return {p1.first + p2.first, p1.second + p2.second};
}
pii dif(const pii& p1, const pii &p2) {
    return {p1.first - p2.first, p1.second - p2.second};
}
pii simple(int x, int y, int d) {
    pii res(0, 0);
    res = dif(prefi[x + d - 1][y], prefi[x - d][y]);
    res = sum(res, dif(prefj[x][y + d - 1], prefj[x][y - d]));
    res = dif(res, val[x][y]);
    return res;
}
pii rotated(int x, int y, int d) {
    pii res(0, 0);
    res = dif(prefd[x + d - 1][y + d - 1], prefd[x - d][y - d]);
    res = sum(res, dif(prefr[x + d - 1][y - d + 1], prefr[x - d][y + d]));
    res = dif(res, val[x][y]);
    return res;
}
int cmp23(int x, int y) {
    return x * logl(2) > y * logl(3);
}
pii max(pii a, pii b) {
    int p2 = a.first - b.first;
    int p3 = a.second - b.second;
    if (p2 >= 0 && p3 >= 0) {
        return a;
    } else if (p2 <= 0 && p3 <= 0) {
        return b;
    } else {
        return cmp23(p2, -p3) ? a : b;
    }
}
int main() {
    cin >> n;
    bool nz = false;
    FI(n) {
        char s[1010];
        cin >> s;
        FJ(n) {
            a[i + 1][j + 1] = s[j] - '0';
            
            if (a[i + 1][j + 1]) {
                nz = true;
            }
        }
    }
    if (!nz) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j]) {
                z[i][j] = min(i, n - i + 1);
                f[i][j] = min(j, n - j + 1);
                if (a[i][j] == 2) {
                    val[i][j] = {1, 0};
                } else if (a[i][j] == 3) {
                    val[i][j] = {0, 1};
                }
            } else {
                z[i][j] = 0;
                f[i][j] = 0;
            }
            prefi[i][j] = sum(prefi[i - 1][j], val[i][j]);
            prefj[i][j] = sum(prefj[i][j - 1], val[i][j]);
            prefd[i][j] = sum(prefd[i - 1][j - 1], val[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = n; j > 0; --j) {
            prefr[i][j] = sum(prefr[i - 1][j + 1], val[i][j]);
        }
    }
    pii ans(0, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[i][j] = min(f[i][j], f[i][j - 1] + 1);
            z[i][j] = min(z[i][j], z[i - 1][j] + 1);
        }
    }
    for (int i = n; i > 0; --i) {
        for (int j = n; j > 0; --j) {
            f[i][j] = min(f[i][j], f[i][j + 1] + 1);
            z[i][j] = min(z[i][j], z[i + 1][j] + 1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            z[i][j] = min(z[i][j], f[i][j]);
            if (z[i][j]) {
//                DBN(i, j, z[i][j]);
                ans = max(ans, simple(i, j, z[i][j]));
            }
        }
    }
//    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j]) {
                z[i][j] = min({i, j, n - i + 1, n - j + 1});
                f[i][j] = z[i][j];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            z[i][j] = min(z[i][j], z[i - 1][j - 1] + 1);
        }
    }
    for (int i = n; i >= 1; --i) {
        for (int j = n; j >= 1; --j) {
            z[i][j] = min(z[i][j], z[i + 1][j + 1] + 1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= 1; --j) {
            f[i][j] = min(f[i][j], f[i - 1][j + 1] + 1);
        }
    }
    for (int i = n; i >= 1; --i) {
        for (int j = n; j >= 1; --j) {
            f[i][j] = min(f[i][j], f[i + 1][j - 1] + 1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            z[i][j] = min(z[i][j], f[i][j]);
            if (z[i][j]) {
                //DBN(i, j, z[i][j]);
                ans = max(ans, rotated(i, j, z[i][j]));
            }
        }
    }
    
    cout << powmod(2, ans.first, mod) * powmod(3, ans.second, mod) % mod << endl;
    
    return 0;
}