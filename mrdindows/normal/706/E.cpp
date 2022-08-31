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
typedef int itn;

template<typename T1, typename T2, typename T3>
struct triple{ T1 a; T2 b; T3 c; triple() : a(T1()), b(T2()), c(T3()) {}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };
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

const int BUSFIZE = 4096;
int read_int() {
    static char inbuf[BUSFIZE + 16];
    static char* inp = inbuf;
    static char* linp = inbuf + BUSFIZE;
    if (*inp == 0) {
        cin.read(inbuf, BUSFIZE);
        inp = inbuf;
    }
    while (*inp && (*inp < '0' || *inp > '9'))
        ++inp;
    int res = 0;
    while (*inp >= '0' && *inp <= '9') {
        res = res * 10 + *inp - '0';
        ++inp;
        if (inp == linp) {
            cin.read(inbuf, BUSFIZE);
            inp = inbuf;
        }
    }
    ++inp;
    return res;
}
static char outbuf[BUSFIZE + 16];
static char *outptr = outbuf;
static char *loutp = outbuf + BUSFIZE;
void write_int(int x) {
    char* begp = outptr;
    while (x) {
        int t = x / 10;
        char c = x - 10 * t + '0';
        *outptr++ = c;
        x = t;
    }
    char* endp = outptr - 1;
    while (begp < endp) {
        swap(*begp, *endp);
        ++begp;
        --endp;
    }
    if (outptr > loutp) {
        cout.write(outbuf, outptr - outbuf);
        outptr = outbuf;
    }
    *outptr++ = ' ';
}

int x[1008][1008];
void swap(char *a, char *b, int n) {
    int t = n % 64;
    if (t) {
        char buffer[64];
        memcpy(buffer, a, t);
        memcpy(a, b, t);
        memcpy(b, buffer, t);
        a += t;
        b += t;
    }
    n /= 64;
    typedef __m128i* Ptr;
    Ptr ptra = (Ptr)a;
    Ptr ptrb = (Ptr)b;
    char buffer[3008];
    auto buff = (Ptr) buffer;
    t = n;
    while (t--) {
        _mm_storeu_si128(buff + 0, _mm_loadu_si128(ptrb + 0));
        _mm_storeu_si128(buff + 1, _mm_loadu_si128(ptrb + 1));
        _mm_storeu_si128(buff + 2, _mm_loadu_si128(ptrb + 2));
        _mm_storeu_si128(buff + 3, _mm_loadu_si128(ptrb + 3));
        buff += 4;
        ptrb += 4;
    }
    t = n;
    ptrb = (Ptr)b;
    while (t--) {
        _mm_storeu_si128(ptrb + 0, _mm_loadu_si128(ptra + 0));
        _mm_storeu_si128(ptrb + 1, _mm_loadu_si128(ptra + 1));
        _mm_storeu_si128(ptrb + 2, _mm_loadu_si128(ptra + 2));
        _mm_storeu_si128(ptrb + 3, _mm_loadu_si128(ptra + 3));
        ptra += 4;
        ptrb += 4;
    }
    t = n;
    buff = (Ptr) buffer;
    ptra = (Ptr)a;
    while (t--) {
        _mm_storeu_si128(ptra + 0, _mm_loadu_si128(buff + 0));
        _mm_storeu_si128(ptra + 1, _mm_loadu_si128(buff + 1));
        _mm_storeu_si128(ptra + 2, _mm_loadu_si128(buff + 2));
        _mm_storeu_si128(ptra + 3, _mm_loadu_si128(buff + 3));
        ptra += 4;
        buff += 4;
    }
}
int v[1008 * 1008];
char data[1008][3008];
int vs = 0;

int main() {
#ifdef LOCAL
    FREIN("in.txt");
    FREOUT("out.txt");
#endif
    ios_base::sync_with_stdio(0);
    int n, m, q;
    n = read_int();
    m = read_int();
    q = read_int();
    FI(n) FJ(m) {
        v[vs] = read_int();
        int val = vs++;
        char *ptr = data[i] + j * 3;
        const char* valPtr = (const char*)&val;
        ptr[0] = valPtr[0];
        ptr[1] = valPtr[1];
        ptr[2] = valPtr[2];
    }
    while (q--) {
        int a, b, c, d, w, h;
        a = read_int();
        b = read_int();
        c = read_int();
        d = read_int();
        h = read_int();
        w = read_int();
        --a; --b; --c; --d;
        for (int i = 0; i < h; ++i) {
            swap(data[a + i] + b * 3, data[c + i] + d * 3, w * 3);
        }
    }
    FI(n) {
        FJ(m) {
            int val = 0;
            const char *ptr = data[i] + j * 3;
            char* valPtr = (char*)&val;
            valPtr[0] = ptr[0];
            valPtr[1] = ptr[1];
            valPtr[2] = ptr[2];
            val = v[val];
            write_int(val);
        }
        *outptr++ = '\n';
    }
    cout.write(outbuf, outptr - outbuf);
    CURTIME();
    return 0;
}