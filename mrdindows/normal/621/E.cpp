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
#define EPS         (double)1e-10
#define mod         1000000007
#define PI          3.14159265358979323
#define link        asaxlaj
//*************************************************************************************



struct Matrix {
    long long a[101][101];
    int n, m;
    Matrix(int nn = 100, int mm = 100) {
        n = nn;
        m = mm;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = 0;
            }
        }
    }
    ll* operator[](int idx) {
        return a[idx];
    }
    const ll* operator[](int idx) const {
        return a[idx];
    }
    Matrix operator*(const Matrix& other) const {
        Matrix res(this->n, other.m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < other.m; ++j) {
                for (int k = 0; k < m; ++k) {
                    res[i][j] = (res[i][j] + a[i][k] * other[k][j]) % mod;
                }
            }
        }
        return res;
    }
    Matrix power(int p) {
        Matrix res(this->n, this->m);
        if (p == 0) {
            for (int j = 0; j < n; ++j) {
                res[j][j] = 1;
            }
            return res;
        } else if (p == 1) {
            return *this;
        } else {
            Matrix t = this->power(p / 2);
            t *= t;
            if (p % 2) {
                t *= *this;
            }
            return t;
        }
    }
    Matrix& operator*=(const Matrix& other) {
        Matrix res(this->n, other.m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < other.m; ++j) {
                res[i][j] = 0;
                for (int k = 0; k < m; ++k) {
                    res[i][j] = (res[i][j] + a[i][k] * other[k][j]) % mod;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < other.m; ++j) {
                a[i][j] = res[i][j];
            }
        }
        return *this;
    }
    void print() {
        for (int i = 0; i < n; ++i) {
            cout << (i == 0 ?  "[[" : " [");
            for (int j = 0; j < m; ++j) {
                cout << a[i][j] << (j == m - 1 ? (i == n - 1 ? "]]\n" : "]\n") : ", ");
            }
        }
    }
};

int a[101010];
int c[11];
int phi(int x) {
    int res = x;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
            }
            res = res * (i - 1) / i;
        }
    }
    if (x > 1) {
        res = res * (x - 1) / x;
    }
    return res;
}
const int F = 522;
Matrix ms[F + 10];
ll dp[1001][101];

int main() {
//    FREIN("in.txt");
    int n, b, k, x;
    cin >> n >> b >> k >> x;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        c[t]++;
    }

    int per = phi(x);
    int ten = 1;
    for (int mi = 0; mi <= F; ++mi) {
        ms[mi] = Matrix(x, x);
        for (int i = 0; i < x; ++i) {
            for (int c = 1; c <= 9; ++c) {
                int o = c * ten % x;
                ms[mi][(i - o + x) % x][i] += ::c[c];
            }
        }
        ten = ten * 10 % x;
    }
    
    
//    dp[0][0] = 1;
//    ten = 1;
//    for (int j = 0; j < 1000; ++j) {
//        for (int c = 1; c <= 9; ++c) {
//            int o = c * ten % x;
//            for (int i = 0; i < x; ++i) {
//                dp[j + 1][i] = (dp[j + 1][i] + ::c[c] * dp[j][(i - o + x) % x]) % mod;
//            }
//        }
//        ten = ten * 10 % x;
//    }
//    DBN(dp[b][k]);
    
    
//    ms[0].print();
    Matrix ans(1, x);
    ans[0][0] = 1;
//    ans.print();

    if (b < 200) {
        for (int i = 0; i < b; ++i) {
            ans = ans * ms[i];
//            ans.print();
//            ms[i].print();
        }
    } else {
        int ten = 1;
        
        const int K = 30;
        
        for (int i = 0; i < K; ++i) {
            ans *= ms[i];
            --b;
            ten = ten * 10 % x;
        }
//        --per;
        int ptr = K;
        while (b % per) {
            ans *= ms[ptr++];
            --b;
            ten = ten * 10 % x;
        }
        
        for (int j = 0; j <= per; ++j) {
            for (int i = 0; i <= x; ++i) {
                dp[j][i] = 0;
            }
        }
        dp[0][0] = 1;
        for (int j = 0; j < 1000; ++j) {
            for (int c = 1; c <= 9; ++c) {
                int o = c * ten % x;
                for (int i = 0; i < x; ++i) {
                    dp[j + 1][i] = (dp[j + 1][i] + ::c[c] * dp[j][(i - o + x) % x]) % mod;
                }
            }
            ten = ten * 10 % x;
        }
        
        Matrix t(x, x);
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < x; ++j) {
                int d = i - j;
                if (d < 0) {
                    d += x;
                }
                t[j][i] = dp[per][d];
            }
        }
        ans *= t.power(b / per);;
    }
    cout << ans[0][k] << endl;
    
    return 0;
}