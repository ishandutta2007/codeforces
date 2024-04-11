#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
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
# include <tuple>
# include <unordered_map>
# include <unordered_set>

#ifdef LOCAL0000
# include <opencv2/core/core.hpp>
# include <opencv2/highgui/highgui.hpp>
# include <opencv2/imgproc/imgproc.hpp>
#endif

using namespace std;

#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 6,5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,_6,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
#define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
#define DA(a,n) cerr<<#a<<"=["; printarray(a,n); cerr<<"]\n"
#define DAR(a,n,s) cerr<<#a<<"["<<s<<"-"<<n-1<<"]=["; printarray(a,n,s); cerr<<"]\n"

#ifdef _MSC_VER
#define PREFETCH(ptr, rw, level) ((void)0)
#else
#define PREFETCH(ptr, rw, level) __builtin_prefetch(ptr, rw, level)
#endif

#if defined _MSC_VER
#define ASSUME(condition) ((void)0)
#define __restrict
#elif defined __clang__
#define ASSUME(condition)       __builtin_assume(condition)
#elif defined __GNUC__
[[noreturn]] __attribute__((always_inline)) inline void undefinedBehaviour() {}
#define ASSUME(condition)       ((condition) ? true : (undefinedBehaviour(), false))
#endif

#ifdef LOCAL
#define CURTIME() cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl
#else
#define CURTIME()
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef int itn;

template<class T1, class T2, class T3>
struct triple{ T1 a; T2 b; T3 c; triple() : a(T1()), b(T2()), c(T3()) {}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };
template<class T1, class T2, class T3>
bool operator<(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a<t2.a;else if(t1.b!=t2.b)return t1.b<t2.b;else return t1.c<t2.c;}
template<class T1, class T2, class T3>
bool operator>(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a>t2.a;else if(t1.b!=t2.b)return t1.b>t2.b;else return t1.c>t2.c;}
#define tri triple<int,int,int>
#define trll triple<ll,ll,ll>

#define FI(n) for(int i=0;i<(n);++i)
#define FJ(n) for(int j=0;j<(n);++j)
#define FK(n) for(int k=0;k<(n);++k)
#define FL(n) for(int l=0;l<(n);++l)
#define FQ(n) for(int q=0;q<(n);++q)
#define FOR(i,a,b) for(int i = (a), __e = (int) (b); i < __e; ++i)
#define all(a) std::begin(a), std::end(a)
#define reunique(v) v.resize(std::unique(v.begin(), v.end()) - v.begin())

#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(1.0 * (x))
#define pow(x, n) pow(1.0 * (x), n)

#define COMPARE(obj) [&](const std::decay_t<decltype(obj)>& a, const std::decay_t<decltype(obj)>& b)
#define COMPARE_BY(obj, field) [&](const std::decay_t<decltype(obj)>& a, const std::decay_t<decltype(obj)>& b) { return a.field < b.field; }

#define checkbit(n, b) (((n) >> (b)) & 1)
#define setbit(n, b) ((n) | (static_cast<std::decay<decltype(n)>::type>(1) << (b)))
#define removebit(n, b) ((n) & ~(static_cast<std::decay<decltype(n)>::type>(1) << (b)))
#define flipbit(n, b) ((n) ^ (static_cast<std::decay<decltype(n)>::type>(1) << (b)))
inline int countBits(uint v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int countBits(ull v){uint t=v>>32;uint p=(v & ((1ULL << 32) - 1)); return countBits(t) + countBits(p); }
inline int countBits(ll v){return countBits((ull)v); }
inline int countBits(int v){return countBits((uint)v); }
unsigned int reverseBits(uint x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
template<class T> inline int sign(T x){ return x > 0 ? 1 : x < 0 ? -1 : 0; }
inline bool isPowerOfTwo(int x){ return (x != 0 && (x&(x - 1)) == 0); }
constexpr ll power(ll x, int p) { return p == 0 ? 1 : (x * power(x, p - 1)); }
template<class T>
inline bool inRange(const T& val, const T& min, const T& max) { return min <= val && val <= max; }
//template<class T1, class T2, class T3> T1 inline clamp(T1 x, const T2& a, const T3& b) { if (x < a) return a; else if (x > b) return b; else return x; }
unsigned long long rdtsc() { unsigned long long ret = 0;
#ifdef __clang__
    return __builtin_readcyclecounter();
#endif
#ifndef _MSC_VER
    asm volatile("rdtsc" : "=A" (ret) : :);
#endif
    return ret; }
// Fast IO ********************************************************************************************************
const int __BS = 4096;
static char __bur[__BS + 16], *__er = __bur + __BS, *__ir = __er;
template<class T = int> T readInt() {
    auto c = [&]() { if (__ir == __er) std::fill(__bur, __bur + __BS, 0), cin.read(__bur, __BS), __ir = __bur; };
    c(); while (*__ir && (*__ir < '0' || *__ir > '9') && *__ir != '-') ++__ir; c();
    bool m = false; if (*__ir == '-') ++__ir, c(), m = true;
    T r = 0; while (*__ir >= '0' && *__ir <= '9') r = r * 10 + *__ir - '0', ++__ir, c();
    ++__ir; return m ? -r : r;
}
string readString() {
    auto c = [&]() { if (__ir == __er) std::fill(__bur, __bur + __BS, 0), cin.read(__bur, __BS), __ir = __bur; };
    string r; c(); while (*__ir && isspace(*__ir)) ++__ir, c();
    while (!isspace(*__ir)) r.push_back(*__ir), ++__ir, c();
    ++__ir; return r;
}
char readChar() {
    auto c = [&]() { if (__ir == __er) std::fill(__bur, __bur + __BS, 0), cin.read(__bur, __BS), __ir = __bur; };
    c(); while (*__ir && isspace(*__ir)) ++__ir, c(); return *__ir++;
}
static char __buw[__BS + 20], *__iw = __buw, *__ew = __buw + __BS;
template<class T>
void writeInt(T x, char endc = '\n') {
    if (x < 0) *__iw++ = '-', x = -x; if (x == 0) *__iw++ = '0';
    char* s = __iw;
    while (x) { T t = x / 10; char c = x - 10 * t + '0'; *__iw++ = c; x = t; }
    char* f = __iw - 1; while (s < f) swap(*s, *f), ++s, --f;
    if (__iw > __ew) cout.write(__buw, __iw - __buw), __iw = __buw;
    if (endc) { *__iw++ = endc; }
}
template<class T>
void writeStr(const T& str) {
    int i = 0; while (str[i]) { *__iw++ = str[i++]; if (__iw > __ew) cout.write(__buw, __iw - __buw), __iw = __buw; }
}
struct __FL__ { ~__FL__() { if (__iw != __buw) cout.write(__buw, __iw - __buw); } };
static __FL__ __flushVar__;

//STL output *****************************************************************************************************
#define TT1 template<class T>
#define TT1T2 template<class T1, class T2>
#define TT1T2T3 template<class T1, class T2, class T3>
TT1T2 ostream& operator << (ostream& os, const pair<T1, T2>& p);
TT1 ostream& operator << (ostream& os, const vector<T>& v);
TT1T2 ostream& operator << (ostream& os, const set<T1, T2>&v);
TT1T2 ostream& operator << (ostream& os, const multiset<T1, T2>&v);
TT1T2 ostream& operator << (ostream& os, priority_queue<T1, T2> v);
TT1T2T3 ostream& operator << (ostream& os, const map<T1, T2, T3>& v);
TT1T2T3 ostream& operator << (ostream& os, const multimap<T1, T2, T3>& v);
TT1T2T3 ostream& operator << (ostream& os, const triple<T1, T2, T3>& t);
template<class T, size_t N> ostream& operator << (ostream& os, const array<T, N>& v);
TT1T2 ostream& operator << (ostream& os, const pair<T1, T2>& p){ return os <<"("<<p.first<<", "<< p.second<<")"; }
TT1 ostream& operator << (ostream& os, const vector<T>& v){       bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
template<class T, size_t N> ostream& operator << (ostream& os, const array<T, N>& v) {     bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const set<T1, T2>&v){    bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const multiset<T1,T2>&v){bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2T3 ostream& operator << (ostream& os, const map<T1,T2,T3>& v){ bool f = 1; os << "["; for (auto& ii : v) { if (!f)os << ", "; os << "(" << ii.first << " -> " << ii.second << ") "; f = 0; }return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const multimap<T1, T2>& v){ bool f = 1; os << "["; for (auto& ii : v) { if (!f)os << ", "; os << "(" << ii.first << " -> " << ii.second << ") "; f = 0; }return os << "]"; }
TT1T2 ostream& operator << (ostream& os, priority_queue<T1, T2> v) { bool f = 1; os << "["; while (!v.empty()) { auto x = v.top(); v.pop(); if (!f) os << ", "; f = 0; os << x; } return os << "]"; }
TT1T2T3 ostream& operator << (ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }
TT1T2 void printarray(const T1& a, T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }

//STL input *****************************************************************************************************
TT1T2T3 inline istream& operator >> (istream& os, triple<T1, T2, T3>& t);
TT1T2 inline istream& operator >> (istream& os, pair<T1, T2>& p) { return os >> p.first >> p.second; }
TT1 inline istream& operator >> (istream& os, vector<T>& v) {
    if (v.size()) for (T& t : v) os >> t; else {
        string s; T obj; while (s.empty()) {getline(os, s); if (!os) return os;}
        stringstream ss(s); while (ss >> obj) v.push_back(obj);
    }
    return os;
}
TT1T2T3 inline istream& operator >> (istream& os, triple<T1, T2, T3>& t) { return os >> t.a >> t.b >> t.c; }

//Pair magic *****************************************************************************************************
#define PT1T2 pair<T1, T2>
TT1T2 inline PT1T2 operator+(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first + p2.first, p1.second + p2.second); }
TT1T2 inline PT1T2& operator+=(PT1T2 &p1 , const PT1T2 &p2) { p1.first += p2.first, p1.second += p2.second; return p1; }
TT1T2 inline PT1T2 operator-(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first - p2.first, p1.second - p2.second); }
TT1T2 inline PT1T2& operator-=(PT1T2 &p1 , const PT1T2 &p2) { p1.first -= p2.first, p1.second -= p2.second; return p1; }

#undef TT1
#undef TT1T2
#undef TT1T2T3

#define FREIN(FILE) freopen(FILE, "rt", stdin)
#define FREOUT(FILE) freopen(FILE, "wt", stdout)
#ifdef LOCAL
#define BEGIN_PROFILE(idx, name) int profileIdx = idx; profileName[profileIdx] = name; totalTime[profileIdx] -= rdtsc() / 1e3;
#define END_PROFILE totalTime[profileIdx] += rdtsc() / 1e3; totalCount[profileIdx]++;
#else
#define BEGIN_PROFILE(idx, name)
#define END_PROFILE
#endif

const int USUAL_MOD = 1000000007;
template<class T> inline void normmod(T &x, T m = USUAL_MOD) { x %= m; if (x < 0) x += m; }
template<class T1, class T2> inline T2 summodfast(T1 x, T1 y, T2 m = USUAL_MOD) { T2 res = x + y; if (res >= m) res -= m; return res; }
template<class T1, class T2, class T3 = int> inline void addmodfast(T1 &x, T2 y, T3 m = USUAL_MOD) { x += y; if (x >= m) x -= m; }
template<class T1, class T2, class T3 = int> inline void submodfast(T1 &x, T2 y, T3 m = USUAL_MOD) { x -= y; if (x < 0) x += m; }
inline ll mulmod(ll x, ll n, ll m){ x %= m; n %= m; ll r = x * n - ll(ld(x)*ld(n) / ld(m)) * m; while (r < 0) r += m; while (r >= m) r -= m; return r; }
inline ll powmod(ll x, ll n, ll m){ ll r = 1; normmod(x, m); while (n){ if (n & 1) r *= x; x *= x; r %= m; x %= m; n /= 2; }return r; }
inline ll powmulmod(ll x, ll n, ll m) { ll res = 1; normmod(x, m); while (n){ if (n & 1)res = mulmod(res, x, m); x = mulmod(x, x, m); n /= 2; } return res; }
template<class T> inline T gcd(T a, T b) { while (b) { T t = a % b; a = b; b = t; } return a; }
template<class T>
T fast_gcd(T u, T v) {
    int shl = 0; while ( u && v && u != v) { T eu = u & 1; u >>= eu ^ 1; T ev = v & 1; v >>= ev ^ 1;
        shl += (~(eu | ev) & 1); T d = u & v & 1 ? (u + v) >> 1 : 0; T dif = (u - v) >> (sizeof(T) * 8 - 1); u -= d & ~dif; v -= d & dif;
    } return std::max(u, v) << shl;
}

inline ll lcm(ll a, ll b){ return a / gcd(a, b) * b; }
template<class T> inline T gcd(T a, T b, T c){ return gcd(gcd(a, b), c); }
ll gcdex(ll a, ll b, ll& x, ll& y) {
    if (!a) { x = 0; y = 1; return b; }
    ll y1; ll d = gcdex(b % a, a, y, y1); x = y1 - (b / a) * y;
    return d;
}
template<class T> bool isPrime(T x) { if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
    for (T i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1; }
bool millerRabin(long long n) {
    if (n <= 1000) return isPrime(n);
    long long s = n - 1; int t = 0; while (s % 2 == 0) s /= 2, ++t;
    for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) { if (!(a %= n)) return true;
        long long f = powmulmod(a, s, n); if (f == 1 || f == n - 1) continue;
        for (int i = 1; i < t; ++i) if ((f = mulmod(f, f, n)) == n - 1) goto nextp;
        return false; nextp:;
    } return true;
}

// Useful constants

//int some_primes[7] = {24443, 100271, 1000003, 1000333, 5000321, 98765431,
#define T9          1000000000
#define T18         1000000000000000000LL
#define INF         1011111111
#define LLINF       1000111000111000111LL
#define mod         1000000007
#define fftmod      998244353
#define EPS         (double)1e-10
#define PI          3.14159265358979323846264
#define link        asaxlajrewqwe
#define rank        wahayawehasdakw
//*************************************************************************************


int32_t solve();
int solveE();
int32_t main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef LOCAL
    FREIN("input.txt");
    //    FREOUT("out.txt");
#endif
    return solve();
}

//int pr[303030303];
//uint32_t mem[1001] = {0, 2752742100,2906128820,309863116,955414256,1690456532,225517568,1519921908,2456220216,2498528432,1144296124,4021470328,1611039128,2004671332,2501085136,1781507200,2552770680,595301548,4005732980,1122516280,2887812744,233083884,2926292176,1904495600,4216880568,404327644,985949520,1507615644,490908248,1438952756,111038676,688184984,4126378696,2785872224,2125123352,3802719740,4028626528,2286695000,3507162104,151060548,1842575144,1027190492,2753937676,766127324,342955604,1544584376,1363975588,2303857012,1858020328,4099056648,3861012636,426277412,3287611692,3942737508,130534480,113802884,32677856,1778683628,3158135020,79341172,199887356,1911483100,4015908488,1948201860,3568088492,3486072000,3346889428,1438813940,1950569456,2787897264,939511128,3479158248,462101616,343784424,2434532960,3555667820,1461931696,3145234020,1331831564,56284356,64889092,1591981172,4115295196,3087032412,3528040396,1548928816,2811933624,2981757372,3073912688,3531093580,2418522820,1551860436,2178123052,2094519964,2940808292,2963049048,202896,2078934828,3134437084,2141064252,3934775252,1630462116,4204435612,1227202568,121705432,3762582752,3811855096,2831464872,698513060,3328892664,56148584,905585716,3618861976,1479105144,3689252316,1773153944,433676612,290372124,2947259576,1950041788,3743570204,3097773668,3467464484,2790591424,2888570948,1580713120,2758426560,4067783900,1890926264,3501311308,2310687924,3087982052,2642054640,2656461400,2154847148,4264214160,332671208,202257660,1079877184,2372274896,50871892,1416556176,3032336868,906704336,2594602616,904132780,1211035296,1793533556,930578428,1727580944,2876452984,962779356,1254670180,1500790228,3492439828,33871728,4186678584,86277036,1256180740,2588767036,3224055240,258998880,83153112,3597892968,1457584608,271370376,1737681180,2504983404,3247955144,679202972,2983585148,1500161960,4032747944,3092168420,2939883952,2894638736,2946160536,1969346860,3905967264,4241536440,2889397088,4201141836,1511214180,3460703504,1853510488,3903864132,38966968,2782377960,2263405776,2675963256,2223780036,1545002568,1014930364,1257555064,1650740052,688473240,65339076,1352633144,2444279996,226849200,3743731472,1400428956,2927232112,1873221380,1878268308,3897411100,1153706068,3460496072,3460744776,1240854100,3863618440,17776556,1698700536,1441054300,3172282768,2797881804,3577359600,2566025080,3714597144,1106562156,2971234288,2433948116,3449312548,2342167292,1928777068,2915217512,1610199412,3417371196,380875616,3201921728,1599212372,3004430984,3593986472,3935621804,537712332,750806488,3517286524,307537984,1352688664,3491911672,2551029076,2104834760,1921781308,1118683516,2264629440,2272446040,903456736,1665303252,2910330712,3492547776,739020648,768935708,243146696,184660740,2279892604,1182460008,2031946916,662421436,2428287784,1321138180,2648034548,3796590936,4208096704,2137563660,3452868764,1702857140,229228012,1563824556,2398342664,925491608,3433234644,2686921256,3752416316,3544368364,4006577232,4108827744,1712323632,2362533084,3135254060,2271047760,2594509508,2822785520,783666552,949153552,1338149776,2267365276,3315035272,3734800972,2962307020,1370144756,523362384,817593040,1954877320,1024174860,1581738572,1553956424,3796189372,410380156,3321005516,2066092624,2658574884,2056958684,3817094144,908225464,4108126164,2110135040,791940832,2791333588,323248700,346377896,1508478080,3063308836,777210360,4045614216,642699964,2216608196,3813715276,755059712,2551597228,2685686420,1497784240,2654390664,1259142832,300064784,2419301876,2381870300,784380084,2930801204,766245488,1048939488,2380747028,1544182988,420310452,2364189944,2264912312,1816354940,301359940,3057553476,165517744,3717005748,3593687564,2403555112,3108489392,3167648716,2293806536,3048656352,1681390072,1326202296,67650012,3701200176,1257975812,3077119600,357430908,824346424,2078282664,2644691340,3980494740,1926245324,2086769884,786668268,2324701088,3657674244,3523154316,2971835192,1637505940,468936372,3744105080,3082384748,1387260452,3166201644,114076560,3688379204,144051916,1088495576,2801577960,1305949620,3645498124,2574691732,2840898604,301462048,2372924208,3022616856,881333248,2312594592,2136906968,672685168,4256487448,1689323452,1033558380,2809329264,3103705600,2802278688,867254464,207020896,988266912,3880408736,3156294716,2340923528,997173292,3324112980,3804723536,888510016,3836972464,5120260,3413021116,149415508,546862988,2661210548,1478126656,1887238816,448299404,1551970228,1886135688,1127925244,3150498972,3459958336,1718684116,3951947884,407077840,2165856184,1280331672,147003288,1961871628,3942595448,1367136192,3063495060,12011228,258489708,605332804,2819643796,1308339716,655389924,1733796768,1241918488,4217555968,3630016316,2501006508,1281355556,3399155252,1888525316,4081286136,3658247396,3109850948,671408592,1498053276,903679112,2181659148,1043674012,618575684,532670172,2575038340,148959612,310188288,303309184,2449031560,4212799168,402059412,763889776,1715528824,4137934852,2444444772,3196409224,3296656968,1414489100,4221120856,1531770948,373165200,1906005688,4049533600,4041875816,2351146492,753014160,1515315000,1110772288,3339456072,1717341616,1444592608,4139826132,581470132,1352819276,3179522628,34737744,727570704,1742622452,1216448268,3450330168,135915776,1667284368,1723210184,988817900,2559127700,183688632,2483032352,3085879440,4071992184,732993348,1215876720,568860692,2214542728,759809452,123304464,1646239340,2631061208,2426944032,3151843892,3480929140,3455663196,13659840,1392498636,3426703824,2174654096,3768598040,3945161096,4230280768,3551671252,4219455936,2657774096,639935212,3671573176,4123519888,3638148912,660363424,2433772992,2644966824,3982039208,3189163636,1619152796,1233179188,2978523072,434098836,1498561476,3869865756,738021240,614791372,2720117988,585553792,3495075608,3649942580,3069507800,2187181852,1067855920,1760780912,3387292896,1640920824,162409088,1555538068,2284324432,3731874932,832608392,1904987116,3037258196,2001518348,3242186920,2735169484,844025856,1222162416,3673067432,872632636,3764422644,2562625240,4111814580,1760384192,3713384616,3262675072,2932941180,3273316820,2332829268,809735928,2005419172,1514165016,4032016568,2735500616,2113310452,2945470924,3577198796,4140071532,3354469788,1838409792,2816936804,1756759556,429985744,3400897612,1824500952,2343225576,1381495840,249002172,890461212,3189575048,1795820700,3302703264,2191523700,983748992,948497188,3151127948,3526557496,775810904,255945500,3522131960,2958563324,759955544,205113816,880271004,262269636,1727018668,2803464376,2868855748,3094800440,2083480304,2514897540,2045596392,2691075148,3730193908,3561403708,1514664000,3129037168,2976761824,1767841064,2149562292,3636626108,873903696,3449486092,2866382680,982417056,1920265628,3306470588,950797080,3782214072,86852176,3176786392,683367444,657750588,1819471152,1366953876,1200979268,614793364,3110117644,1612387012,1296388060,1972442436,1586119112,4115826216,2458551072,2889744712,140986924,1824716416,1570423580,2393143544,479505824,1669009168,2161667272,890222396,1804992228,3856123972,661163016,3526886860,728379808,2006680916,1100452524,2676362572,2243513516,2056266424,2123169612,2306997344,3227567252,1321656428,3112261484,1056651776,436834412,3135492064,3372209760,3472866124,1695711164,1655509940,1779109052,423432624,2011141468,2084409596,1428580820,224274932,3064792336,2506885264,3756577600,2096539056,3565595248,3224436872,266497856,4104105252,2183360152,2524706864,3248338712,4205202000,3007435108,3188590024,3512662624,543544320,1572299172,3667023352,1379716748,2157916720,3437028548,2341821884,4223264476,2531705204,3265251732,835214740,3986986488,1279033368,3570793416,3678292804,1931691964,3543170444,1562013924,581343316,760595428,3989548316,933916340,1169847924,4103004920,2111074944,1086211204,1151609912,2366103004,4288734732,1589855672,3837063352,1797616236,521072852,1093004268,2535373852,4140706284,1542440448,324596112,3891658488,211297056,647665640,3908707092,152808636,43121228,3016802464,3476458720,4273693548,597864960,79518380,1905711404,2648959564,1799083140,1068670844,2195884388,173895416,598526548,3420510744,4036613040,3610951108,1637315952,2813823024,2559819528,3691155556,2101248412,2328199772,1069162552,3294051048,1955717012,2367581168,3797134768,3694944436,3798296452,319153900,3473655556,3845929224,2278173016,2239726528,610021636,4209306532,828174004,58954984,4189118836,3001351580,886850564,3094204944,3229803956,1620013212,1874329044,2057950268,151042556,387876696,1765111568,570746612,3324995692,529168688,2805361592,808110960,2768595720,1260824596,2924493716,1561833608,1984019984,119801744,926070920,1454074748,4041605968,766971812,1462901000,3401228716,141296992,3051511600,2806235280,1568490744,3722416520,1434201024,1402852872,1501127500,2857722924,4194829728,2542596828,3786098984,937358568,1738833524,4112150116,290456628,913083644,4019990284,4212447256,2561782524,1930687908,1812267444,2434558452,2886340780,3873679656,3057223188,240066784,3932382688,4229369892,524047772,3774684864,2944266048,2838289768,1904337204,4181902328,3609519368,2772244004,3269101096,515359716,3848227052,3364767036,554611916,258925520,849947960,3516542788,163811408,3451302720,345066520,3364887996,685590076,2267522588,4154228184,4287917584,2306448564,874484504,3157537252,798427784,3759735176,2267343208,1429938700,609775744,4206226252,3448726360,1180767256,2178582484,4265285876,325271184,2803094140,1700089648,1502750048,903336020,2070662844,470763348,2665375392,1875950848,1022635692,359616984,3763841868,3053784756,2232630300,2183723516,2802382720,3842474848,1720014420,2522011124,4019529552,2592687400,1701797800,620323112,1343345980,1762734784,1352401520,2995290820,3645229360,314812776,3089009964,2527424876,2489905968,1932596528,3343479320,3974810404,3786302964,2426431820,958880164,4142525048,628773680,417669300,2932775556,3695140396,3021107668,1038084664,1645375908,3009333208,4169322128,1357952836,2721540364,200047816,816283444,58731104,2253428344,2927095524,4055133900,2879480492,895269336,2796620260,1664930104,4093879772,395942968,461255016,4120808596,1952289668,944711372,667846072,3596331576,363898624,749720784,3973645408,127040332,165928900,1268722648,3524236876,756961980,3351235600,915029652,2040157556,1373968660,3278523920,1567573992,4117574164,2970935824,3727908420,1117870276,2225310020,1192611284,2528419172,301138236,2097252276,744197116,854554008,1393579552,1141257236,3706549340,4051433308,1708136536,1443219792,147148948,2544786240,14958316,2405653820,3606165848,2960640388,3851168488,49412028,3487940480,1914001888,3011267376,2247250320,1515454612,1756060556,4199842452,3483726168,54872860,2036995596,700265024,287532672,4084085076,3975513460,2037058956,1979911024,3487985504,1853100408,3739275400,3089207540,3644718496,336321468,2508664488,678633948,2138094352};

const int N = 300000000;
const int K = 30000;
int n, a, b, c, d;
uint foo(uint x) {
    auto r1 = a * x + b;
    auto r2 = c * x + d;
    return r1 * x * x + r2;
}
bool isp[K];
int solve() {
    cin >> n >> a >> b >> c >> d;
    uint32_t ans = 0;
    vector<int> primes;
    for (int i = 2; i <= 20000 && i <= n; ++i) {
        if (!isp[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= 20000; j += i) {
                isp[j] = true;
            }
        }
    }
    for (int from = 2; from <= n; from += K) {
        memset(isp, 0, sizeof(isp));
        for (int p : primes) {
            if (p * p >= from + K) break;
            int ost = from % p;
            int i = 0;
            if (ost != 0) {
                i += p - ost;
            }
            if (i + from == p) i += p;
            for (; i < K; i += p) {
                isp[i] = true;
            }
        }
        int d = min(K, n + 1 - from);
        for (int i = 0; i < d; ++i) {
            if (!isp[i]) {
                uint32_t prime = i + from;
                uint32_t k = n;
                uint32_t t = 0;
                while (k > 0) {
                    k /= prime;
                    t += k;
                }
                ans += foo(prime) * t;
            }
        }
    }
    cout << ans << endl;
    CURTIME();
//    uint32_t sum = mem[d / K];
//    FREOUT("mem.txt");
//    uint32_t sum = 0;
//    vector<int> primes;
//    for (int i = 2; i <= N; ++i) {
//        if (!pr[i]) {
//            primes.push_back(i);
//            pr[i] = i;
//        }
//        for (int p : primes) {
//            if (p > pr[i] || i * p > N) break;
//            pr[p * i] = p;
//        }
//        int t = i;
//        while (t > 1) {
//            sum += foo(pr[t]);
//            t /= pr[t];
//        }
//        if (i % K == 0) {
//            cout << sum << ",";
//            if (i / K % 20 == 0)
//            DBN(i, sum);
//        }
//    }

    return 0;
}