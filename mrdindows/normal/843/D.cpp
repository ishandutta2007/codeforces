//#pragma comment(linker, "/stack:20000000")
//#pragma GCC optimize("Ofast")
////#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//
//#define _CRT_SECURE_NO_WARNINGS
//# include <iostream>
//# include <cmath>
//# include <algorithm>
//# include <stdio.h>
//# include <cstring>
//# include <string>
//# include <cstdlib>
//# include <vector>
//# include <bitset>
//# include <map>
//# include <queue>
//# include <ctime>
//# include <stack>
//# include <set>
//# include <list>
//# include <random>
//# include <deque>
//# include <functional>
//# include <iomanip>
//# include <sstream>
//# include <fstream>
//# include <complex>
//# include <numeric>
//# include <immintrin.h>
//# include <cassert>
//# include <array>
//
//using namespace std;
//
//// Let's define unordered map
//# ifdef __GNUC__
//# if __cplusplus > 199711L
//# include <unordered_set>
//# include <unordered_map>
//# else
//# include <tr1/unordered_map>
//# include <tr1/unordered_set>
//using namespace tr1;
//# endif
//# else
//# include <unordered_map>
//# include <unordered_set>
//# endif
//
//#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 6,5,4,3,2,1))
//#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
//#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,_6,N,...) N
//#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
//#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
//#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
//#define macro_dispatcher___(macro, nargs) macro ## nargs
//#define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
//#define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
//#define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
//#define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
//#define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
//#define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
//#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
//#define DA(a,n) cerr<<#a<<"=["; printarray(a,n); cerr<<"]\n"
//#define DAR(a,n,s) cerr<<#a<<"["<<s<<"-"<<n-1<<"]=["; printarray(a,n,s); cerr<<"]\n"
//
//#ifdef _MSC_VER
//#define ALIGN(x) __declspec(align(x))
//#define PREFETCH(ptr, rw, level) ((void)0)
//#else
//#define ALIGN(x) __attribute__((aligned(x)))
//#define PREFETCH(ptr, rw, level) __builtin_prefetch(ptr, rw, level)
//#endif
//
//#ifdef LOCAL
//#define CURTIME() cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl
//#else
//#define CURTIME() ;
//#endif
//double __begin;
//#define DTIME(ccc) __begin = clock(); ccc; cerr<<"Time of work = "<<(clock()-__begin)/CLOCKS_PER_SEC<<endl;
//
//#define mp make_pair
//typedef long long ll;
//typedef unsigned int uint;
//typedef unsigned long long ull;
//typedef pair<int, int> pii;
//typedef pair<long long, long long> pll;
//typedef vector<int> vi;
//typedef vector<long long> vll;
//typedef int itn;
//
//template<class T1, class T2, class T3>
//struct triple{ T1 a; T2 b; T3 c; triple() : a(T1()), b(T2()), c(T3()) {}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };
//template<class T1, class T2, class T3>
//bool operator<(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a<t2.a;else if(t1.b!=t2.b)return t1.b<t2.b;else return t1.c<t2.c;}
//template<class T1, class T2, class T3>
//bool operator>(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a>t2.a;else if(t1.b!=t2.b)return t1.b>t2.b;else return t1.c>t2.c;}
//#define tri triple<int,int,int>
//#define trll triple<ll,ll,ll>
//
//#define FI(n) for(int i=0;i<n;++i)
//#define FJ(n) for(int j=0;j<n;++j)
//#define FK(n) for(int k=0;k<n;++k)
//#define FL(n) for(int l=0;l<n;++l)
//#define FQ(n) for(int q=0;q<n;++q)
//#define FOR(i,a,b) for(int i = (a), __e = (int) (b); i < __e; ++i)
//#define all(a) std::begin(a), std::end(a)
//#define reunique(v) v.resize(unique(v.begin(), v.end()) - v.begin())
//
//#define sqr(x) ((x) * (x))
//#define sqrt(x) sqrt(1.0 * (x))
//#define pow(x, n) pow(1.0 * (x), n)
//
//#define COMPARE(obj) [&](const std::decay<decltype(obj)>::type& a, const std::decay<decltype(obj)>::type& b)
//#define COMPARE_BY(obj, field) [&](const std::decay<decltype(obj)>::type& a, const std::decay<decltype(obj)>::type& b) { return a.field < b.field; }
//
//#define checkbit(n, b) (((n) >> (b)) & 1)
//#define setbit(n, b) ((n) | (static_cast<std::decay<decltype(n)>::type>(1) << (b)))
//#define removebit(n, b) ((n) & ~(static_cast<std::decay<decltype(n)>::type>(1) << (b)))
//#define flipbit(n, b) ((n) ^ (static_cast<std::decay<decltype(n)>::type>(1) << (b)))
//inline int bits_count(int v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
//inline int bits_count(ll v){int t=v>>32;int p=(v& ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
//unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
//template<class T>
//inline int sign(T x){ return x > 0 ? 1 : x < 0 ? -1 : 0; }
//inline bool isPowerOfTwo(int x){ return (x != 0 && (x&(x - 1)) == 0); }
//template<class T1, class T2, class T3> T1 inline clamp(T1 x, const T2& a, const T3& b) { if (x < a) return a; else if (x > b) return b; else return x; }
//unsigned long long rdtsc() {
//#ifdef _MSC_VER
//    return 0;
//#else
//    unsigned long long ret;
//    __asm__ __volatile__("rdtsc" : "=A" (ret) : :);
//    return ret;
//#endif
//}
//// Fast IO ********************************************************************************************************
//template<class T = int> T read_int() {
//    const int B = 4096;
//    static char b[B + 16], *e = b + B, *i = e;
//    auto c = [&]() { if (i == e) memset(b, 0, B), cin.read(b, B), i = b; };
//    c();
//    while (*i && (*i < '0' || *i > '9') && *i != '-') ++i;
//    c();
//    bool m = false;
//    if (*i == '-') ++i, c(), m = true;
//    T r = 0;
//    while (*i >= '0' && *i <= '9') r = r * 10 + *i - '0', ++i, c();
//    ++i;
//    return m ? -r : r;
//}
//template<class T>
//void write_int(T x, char endc = '\n') {
//    const int B = 4096;
//    static char b[B + 20], *i = b, *e = b + B;
//    if (x < 0) *i++ = '-', x = -x;
//    if (x == 0) *i++ = '0';
//    char* s = i;
//    while (x) {
//        T t = x / 10;
//        char c = x - 10 * t + '0';
//        *i++ = c;
//        x = t;
//    }
//    char* f = i - 1;
//    while (s < f) swap(*s, *f), ++s, --f;
//    if (i > e) cout.write(b, i - b), i = b;
//    *i++ = endc;
//    struct F { ~F() { if (i != b) cout.write(b, i - b); } };
//    static F flush;
//}
//
////STL output *****************************************************************************************************
//#define TT1 template<class T>
//#define TT1T2 template<class T1, class T2>
//#define TT1T2T3 template<class T1, class T2, class T3>
//TT1T2 ostream& operator << (ostream& os, const pair<T1, T2>& p);
//TT1 ostream& operator << (ostream& os, const vector<T>& v);
//TT1T2 ostream& operator << (ostream& os, const set<T1, T2>&v);
//TT1T2 ostream& operator << (ostream& os, const multiset<T1, T2>&v);
//TT1T2 ostream& operator << (ostream& os, priority_queue<T1, T2> v);
//TT1T2T3 ostream& operator << (ostream& os, const map<T1, T2, T3>& v);
//TT1T2T3 ostream& operator << (ostream& os, const multimap<T1, T2, T3>& v);
//TT1T2T3 ostream& operator << (ostream& os, const triple<T1, T2, T3>& t);
//TT1T2 ostream& operator << (ostream& os, const pair<T1, T2>& p){ return os <<"("<<p.first<<", "<< p.second<<")"; }
//TT1 ostream& operator << (ostream& os, const vector<T>& v){       bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
//TT1T2 ostream& operator << (ostream& os, const set<T1, T2>&v){    bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
//TT1T2 ostream& operator << (ostream& os, const multiset<T1,T2>&v){bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
//TT1T2T3 ostream& operator << (ostream& os, const map<T1,T2,T3>& v){ bool f = 1; os << "["; for (auto& ii : v) { if (!f)os << ", "; os << "(" << ii.first << " -> " << ii.second << ") "; f = 0; }return os << "]"; }
//TT1T2 ostream& operator << (ostream& os, const multimap<T1, T2>& v){ bool f = 1; os << "["; for (auto& ii : v) { if (!f)os << ", "; os << "(" << ii.first << " -> " << ii.second << ") "; f = 0; }return os << "]"; }
//TT1T2 ostream& operator << (ostream& os, priority_queue<T1, T2> v) { bool f = 1; os << "["; while (!v.empty()) { auto x = v.top(); v.pop(); if (!f) os << ", "; f = 0; os << x; } return os << "]"; }
//TT1T2T3 ostream& operator << (ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }
//TT1T2 void printarray(T1 a, T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }
//
////STL input *****************************************************************************************************
//TT1T2T3 inline istream& operator >> (istream& os, triple<T1, T2, T3>& t);
//TT1T2 inline istream& operator >> (istream& os, pair<T1, T2>& p) { return os >> p.first >> p.second; }
//TT1 inline istream& operator >> (istream& os, vector<T>& v) {
//    if (v.size()) for (T& t : v) os >> t; else {
//        string s; T obj; while (s.empty()) {getline(os, s); if (!os) return os;}
//        stringstream ss(s); while (ss >> obj) v.push_back(obj);
//    }
//    return os;
//}
//TT1T2T3 inline istream& operator >> (istream& os, triple<T1, T2, T3>& t) { return os >> t.a >> t.b >> t.c; }
//
////Pair magic *****************************************************************************************************
//#define PT1T2 pair<T1, T2>
//TT1T2 inline PT1T2 operator+(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first + p2.first, p1.second + p2.second); }
//TT1T2 inline PT1T2 operator-(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first - p2.first, p1.second - p2.second); }
//
//#undef TT1
//#undef TT1T2
//#undef TT1T2T3
//
//#define FREIN(FILE) freopen(FILE, "rt", stdin)
//#define FREOUT(FILE) freopen(FILE, "wt", stdout)
//
//template<class T> inline void normmod(T &x, T m) { x %= m; if (x < 0) x += m; }
//template<class T1, class T2> inline T2 summodfast(T1 x, T1 y, T2 m) { T2 res = x + y; if (res >= m) res -= m; return res; }
//template<class T1, class T2, class T3> inline void addmodfast(T1 &x, T2 y, T3 m) { x += y; if (x >= m) x -= m; }
//template<class T1, class T2, class T3> inline void submodfast(T1 &x, T2 y, T3 m) { x -= y; if (x < 0) x += m; }
//inline ll mulmod(ll x, ll n, ll m){ ll r = 0; normmod(x, m); normmod(n, m); while (n) { if (n & 1) addmodfast(r, x, m); addmodfast(x, x, m); n /= 2; } return r; }
//inline ll mulmodfast(ll x, ll n, ll m){ ll r = 0; while (n){ if (n & 1) addmodfast(r, x, m); addmodfast(x, x, m); n /= 2; } return r; }
//inline ll powmod(ll x, ll n, ll m){ ll r = 1; normmod(x, m); while (n){ if (n & 1)r = (r*x) % m; x = (x*x) % m; n /= 2; }return r; }
//inline ll powmulmod(ll x, ll n, ll m) { ll res = 1; normmod(x, m); while (n){ if (n & 1)res = mulmod(res, x, m); x = mulmod(x, x, m); n /= 2; } return res; }
//template<class T> inline T gcd(T a, T b) { while (b) { a %= b; T t = a; a = b; b = t; } return a; }
//inline ll lcm(ll a, ll b){ return a / gcd(a, b) * b; }
//template<class T> inline T gcd(T a, T b, T c){ return gcd(gcd(a, b), c); }
//ll gcdex(ll a, ll b, ll& x, ll& y) {
//    if (!a) { x = 0; y = 1; return b; }
//    ll y1; ll d = gcdex(b % a, a, y, y1); x = y1 - (b / a) * y;
//    return d;
//}
//template<class T> bool isPrime(T x) { if (x < 2) return 0; for (T i = 2; i * i <= x; ++i) if (x % i == 0) return 0; return 1; }
//bool millerRabin(long long n) {
//    if (n <= 2) return n == 2;
//    long long s = n - 1; int t = 0; while (s % 2 == 0) s /= 2, ++t;
//    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) { if (a >= n) return a == n;
//        long long f = powmulmod(a, s, n); if (f == 1 || f == n - 1) continue;
//        for (int i = 1; i < t; ++i) if ((f = mulmodfast(f, f, n)) == n - 1) goto nextp;
//        return false; nextp:;
//    } return true;
//}
//
//// Useful constants
//
////int some_primes[7] = {24443, 100271, 1000003, 1000333, 5000321, 98765431, 1000000123};
//#define INF         1011111111
//#define LLINF       1000111000111000111LL
//#define EPS         (double)1e-10
//#define mod         1000000007
//#define PI          3.14159265358979323
//#define link        asaxlajrewqwe
//#define rank        wahayawehasdakw
////*************************************************************************************

#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
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
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>

using namespace std;

// #define _GLIBCXX_DEBUG
// #define DEBUG 1

// #define err(...) fprintf(stderr, "%.2f : ", 1. * clock() / CLOCKS_PER_SEC), fprintf(stderr, __VA_ARGS__), fflush(stderr)

//#define DEBUG

/** Begin fast allocation */
// const int MAX_MEM = 1e8;
// int mpos = 0;
// char mem[MAX_MEM];
// inline void * operator new ( size_t n ) {
// 	assert((mpos += n) <= MAX_MEM);
// 	return (void *)(mem + mpos - n);
// }
// inline void operator delete ( void * ) { } // must have!
/** End fast allocation */

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1e18;

// int cnt1 = 0, cnt2 = 0;

inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x );
inline void writeWord( const char *s );

const int MAX = 1e6 + 10;


struct Qelem {
    int next;
    int v;
};
int pos, qhead[MAX]; //, qnext[MAX], qhead[MAX], qv[MAX];
Qelem q[MAX];

struct Edge {
    int to;
    int w;
    int next;
};

Edge edges[101011];
int head[101013];
int res[102345];
ll d[120193];

int main() {
    int n, m, queries;
#ifdef DEBUG
    n = 0.5e5, m = 1e5, queries = 2000;
#else
    n = readInt();
    m = readInt();
    queries = readInt();
#endif
    
    memset(head, -1, sizeof(head));
    // puts("start");
    forn(i, m) {
#ifdef DEBUG
        int a = rand() % n, b = rand() % n, c = rand() % 10000;
#else
        int a = readInt();
        int b = readInt();
        int c = readInt();
        a--, b--;
#endif
        edges[i].to = b;
        edges[i].w = c;
        edges[i].next = head[a];
        head[a] = i;
    }
    auto Dijkstra = [&]() {
        set<pii> s;
        fill(d, d + n, INF);
        s.insert(pii(d[0] = 0, 0));
        while (s.size()) {
            int v = s.begin()->second;
            s.erase(s.begin());
            for (int i = head[v]; i != -1; i = edges[i].next) {
                int to = edges[i].to;
                int w = edges[i].w;
                if (d[to] > d[v] + w) {
                    s.erase(pii(d[to], to));
                    s.insert(pii(d[to] = d[v] + w, to));
                }
            }
        }
    };
    // puts("0 OK");
    Dijkstra();
    // puts("1 OK");
    // err("=)\n");
    
    int k = 0;
    // puts("!");
    auto bfs = [&]() {
    };
    
    while (queries--) {
        int type;
#ifdef DEBUG
        type = 2;
#else
        type = readInt();
#endif
        if (type == 1) {
            int v = readInt();
            if (d[v - 1] == INF)
                puts("-1");
            else {
                if (k > 0) {
                    // puts("bfs!");
                    memset(qhead, -1, sizeof(qhead[0]) * (k + 1));
                    pos = 0;
                    fill(res, res + n, 1e9);
                    res[0] = 0;
                    auto addq = [&]( int i, int v ) {
                        q[pos].next = qhead[i], q[pos].v = v, qhead[i] = pos++;
                    };
                    addq(0, 0);
                    // int cnt1 = 0, cnt2 = 0;
                    // printf("k = %d\n", k);
                    forn(dist, k + 1)
                    while (qhead[dist] != -1) {
                        int p = qhead[dist];
                        int v = q[p].v;
                        qhead[dist] = q[p].next;
                        if (res[v] != dist)
                            continue;
                        auto dv = d[v];
                        int resv = res[v];
                        for (int i = head[v]; i != -1; i = edges[i].next) {
                            int to = edges[i].to;
                            int w = edges[i].w;
                            int tmp = int(dv + resv + w - d[to]);
                            if (res[to] > tmp) {
                                if (tmp > k) continue;
                                res[to] = tmp, addq(tmp, to);
                            }
                        }
                    }
                    // forn(i, n)
                    // 	printf("%d ", res[i]);
                    // puts("");
                    forn(i, n)
                    if (d[i] != INF)
                        d[i] += res[i];
                    k = 0;
                }
                printf("%lld\n", d[v - 1]);
            }
        } else {
            int cnt, i;
#ifdef DEBUG
            cnt = 2000;
#else
            cnt = readInt();
#endif
            forn(_, cnt) {
#ifdef DEBUG
                i = rand() % m;
#else
                i = readInt() - 1;
#endif
                edges[i].w++;
            }
            k += cnt;
            // Dijkstra();
            // continue;
//             bfs();
//            k = 0;
        }
    }
    cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    // err("cnt1 = %g\n", (double)cnt1);
    // err("cnt2 = %g\n", (double)cnt2);
}

/** Read */

static const int buf_size = 4096;

inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len)
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    if (pos == len)
        return -1;
    return buf[pos++];
}

inline int readChar() {
    int c = getChar();
    while (c <= 32)
        c = getChar();
    return c;
}

template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}

template <class T> 
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;
    
    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}

inline void writeWord( const char *s ) {
    while (*s)
        writeChar(*s++);
}

struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;