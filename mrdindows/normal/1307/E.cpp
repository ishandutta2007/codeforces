#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

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
# include <string_view>

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
#else
#define ASSUME(condition) ((condition) ? true : (__builtin_unreachable(), false))
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
auto c = []() { if (__ir == __er) {std::fill(__bur, __bur + __BS, 0); cin.read(__bur, __BS); __ir = __bur; };};
template<class T = int> T readInt() {
    c(); while (*__ir && (*__ir < '0' || *__ir > '9') && *__ir != '-') ++__ir; c();
    bool m = false; if (*__ir == '-') {++__ir; c(); m = true;}
    T r = 0; while (*__ir >= '0' && *__ir <= '9') {r = r * 10 + *__ir - '0', ++__ir; c();}
    ++__ir; return m ? -r : r;
}
string readString() {
    string r; c(); while (*__ir && isspace(*__ir)) {++__ir; c();}
    while (!isspace(*__ir)) {r.push_back(*__ir); ++__ir; c();}
    ++__ir; return r;
}
char readChar() {
    c(); while (*__ir && isspace(*__ir)) {++__ir; c();} return *__ir++;
}
static char __buw[__BS + 20], *__iw = __buw, *__ew = __buw + __BS;
template<class T>
void writeInt(T x, char endc = '\n') {
    if (x < 0) *__iw++ = '-', x = -x; if (x == 0) *__iw++ = '0';
    char* s = __iw;
    while (x) { T t = x / 10; char c = x - 10 * t + '0'; *__iw++ = c; x = t; }
    char* f = __iw - 1; while (s < f) {swap(*s, *f); ++s; --f;}
    if (__iw > __ew) {cout.write(__buw, __iw - __buw); __iw = __buw;}
    if (endc) { *__iw++ = endc; }
}
template<class T>
void writeStr(const T& str) {
    int i = 0; while (str[i]) { *__iw++ = str[i++]; if (__iw > __ew) {cout.write(__buw, __iw - __buw); __iw = __buw; }}
}
struct __FL__ { ~__FL__() { if (__iw != __buw) cout.write(__buw, __iw - __buw); } };
static __FL__ __flushVar__;

//STL output *****************************************************************************************************
//STL input *****************************************************************************************************

//Pair magic *****************************************************************************************************


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
template<class T> inline ll norm(const pair<T, T>& p) {
    return p.first * 1LL * p.first + p.second * 1LL * p.second;
}
inline ll lcm(ll a, ll b){ return a / gcd(a, b) * b; }
template<class T> inline T gcd(T a, T b, T c){ return gcd(gcd(a, b), c); }
ll gcdex(ll a, ll b, ll& x, ll& y) {
    if (!a) { x = 0; y = 1; return b; }
    ll y1; ll d = gcdex(b % a, a, y, y1); x = y1 - (b / a) * y;
    return d;
}

bool isPrime(long long n) {
    if (n <= (1 << 14)) { int x = (int) n; if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
        for (int i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1; }
    long long s = n - 1; int t = 0; while (s % 2 == 0) { s /= 2; ++t; }
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
#define EPS         1e-10
#define PI          3.14159265358979323846264
#define link        hiallisubmitted
#define rank        thatsnoteasytask
//*************************************************************************************


int32_t solve();
int32_t main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef LOCAL
//    FREIN("input.txt");
//    FREOUT("out.txt");
#endif
    return solve();
}
//
//struct AddSet : public set<pii> {
//    int add = 0;
//};
//vector<int> v[202020];
//bool used[202020];
//int p[202020];
//int getp(int x) {
//    if (x != p[x]) {
//        p[x] = getp(p[x]);
//    }
//    return p[x];
//}
//void unite(int x, int y) {
//    x = getp(x);
//    y = getp(y);
//    if (rand() % 2) {
//        p[x] = y;
//    } else {
//        p[y] = x;
//    }
//}
//bool good[202020];
//int n, k, r;
//void merge(AddSet& a, AddSet& b) {
//    if (a.empty() && b.empty()) {
//        return;
//    }
//    if (a.size() < b.size()) {
//        swap(a, b);
//    }
//    for (auto [dist, vert] : b) {
//        a.insert({dist + b.add - a.add, vert});
//    }
//    b.clear();
//}
//AddSet go(int cur) {
//    used[cur] = true;
//    AddSet res;
//    if (good[cur]) {
//        res.insert({0, cur});
//    }
//    for (int to : v[cur]) {
//        if (!used[to]) {
//            auto tores = go(to);
//            tores.add++;
//            merge(res, tores);
//        }
//    }
//    while (res.size() > 1) {
//        auto it1 = res.begin();
//        auto it2 = ++res.begin();
//        if (it1->first + it2->first + res.add * 2 <= k) {
//            unite(it1->second, it2->second);
//            res.erase(it2);
//        }
//    }
//    return res;
//}
//
//int solve() {
//    cin >> n >> k >> r;
//    FI(n - 1) {
//        int x, y;
//        cin >> x >> y;
//        --x; --y;
//        v[x].push_back(y);
//        v[y].push_back(x);
//    }
//    FI(r) {
//        int x;
//        cin >> x;
//        --x;
//        good[x] = true;
//    }
//    go(0);
//    return 0;
//}
//

int a[5050];
//short pos[2][5050][5005];
int cnt[5050];
vector<int> v[5050];
pii fh[5005];
int solve() {
    int n, m;
    cin >> n >> m;
    FI(n) {
        cin >> a[i];
//        a[i] = i + 1;
    }
    FI(n) {
        cnt[a[i]]++;
//        pos[0][a[i]][cnt[a[i]]] = i;
    }
//    memset(cnt, 0, sizeof(cnt));
//    for (int i = n - 1; i >= 0; --i) {
//        cnt[a[i]]++;
//        pos[1][a[i]][cnt[a[i]]] = i;
//    }
    FI(m) {
        int f, h;
        cin >> f >> h;
//        f = i + 1; h = 1;
        v[f].push_back(h);
        fh[i] = {f, h};
    }
    ll ans = 0;
    int cntans = 0;
    FI(m + 1) {
        int f = fh[i].first;
        int h = fh[i].second;
        if (h > cnt[f]) {
            continue;
        }
        int cur = -1;
        int t = h;
        while (t > 0) {
            ++cur;
            t -= a[cur] == f;
        }
        int cntL[5005] = {};
        int cntR[5005] = {};
        for (int i = 0; i < cur; ++i) {
            cntL[a[i]]++;
        }
        for (int i = n - 1; i > cur; --i) {
            cntR[a[i]]++;
        }
        cntL[f] = 0;
        int cntres = 0;
        ll prod = 1;
        for (int j = 1; j <= n; ++j) {
            int left = cntL[j];
            int right = cntR[j];
            int cl = 0;
            int cr = 0;
            for (int x : v[j]) {
                if (j == f && x == h) continue;
                if (x <= left) ++cl;
                if (x <= right) ++cr;
            }
            if (cl == 0 && cr == 0) continue;
            if (cl == cr && cl == 1) {
                prod = prod * 2 % mod;
                ++cntres;
            } else if (cl == 0) {
                prod = prod * cr % mod;
                ++cntres;
            } else if (cr == 0) {
                prod = prod * cl % mod;
                ++cntres;
            } else {
                if (cl > cr) swap(cl, cr);
                prod = prod * cl % mod * (cr - 1) % mod;
                cntres += 2;
            }
//            DBN(f, h, j, cl, cr);
        }
        if (i != m) {
            cntres++;
        }
        if (cntres > cntans) {
            cntans = cntres;
            ans = 0;
        }
        if (cntres == cntans) {
            ans += prod;
        }
//        DBN(i, f, h, prod, cntres);
    }
    cout << cntans << ' ' << ans % mod << endl;
    return 0;
}