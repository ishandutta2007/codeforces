#pragma comment(linker, "/stack:20000000")
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

#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 6,5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,_6,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
#define DBN1(a)           std::cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)         std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)       std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)     std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)   std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN6(a,b,c,d,e,f) std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
#define DA(a,n) std::cerr<<#a<<"=["; printarray(a,n); std::cerr<<"]\n"
#define DAR(a,n,s) std::cerr<<#a<<"["<<s<<"-"<<n-1<<"]=["; printarray(a,n,s); std::cerr<<"]\n"

#ifdef _MSC_VER
#define ALIGN(x) __declspec(align(x))
#else
#define ALIGN(x) __attribute__((aligned(x)))
#endif

#define CURTIME() std::cerr << clock() * 1.0 / CLOCKS_PER_SEC << std::endl
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
template<typename T1, typename T2, typename T3>
bool operator<(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a<t2.a;else if(t1.b!=t2.b)return t1.b<t2.b;else return t1.c<t2.c;}
#define tri triple<int,int,int>
#define trll triple<ll,ll,ll>

#define FI(n) for(int i=0;i<n;++i)
#define FJ(n) for(int j=0;j<n;++j)
#define FK(n) for(int k=0;k<n;++k)
#define FL(n) for(int l=0;l<n;++l)
#define FQ(n) for(int q=0;q<n;++q)
#define all(a) a.begin(), a.end()
#define reunique(v) v.resize(std::unique(v.begin(), v.end()) - v.begin())

#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(1.0 * (x))
#define pow(x, n) pow(1.0 * (x), n)
//int some_primes[10] = {100271, 500179, 1000003, 2000227, 5000321}

#define COMPARE(T) [&](const decltype(T)& a, const decltype(T)& b)
#define COMPARE_BY(T, field) [&](const decltype(T)& a, const decltype(T)& b) { return a.field < b.field; }

#define checkbit(n, b) ((n >> b) & 1)
inline int bits_count(int v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int bits_count(ll v){int t=v>>32;int p=(v& ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
inline int sign(int x){ return x > 0; }
inline bool isPowerOfTwo(int x){ return (x != 0 && (x&(x - 1)) == 0); }

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

//STL input ********************************
template<typename T1, typename T2> inline std::istream& operator >> (std::istream& os, std::pair<T1, T2>& p);
template<typename T> inline std::istream& operator >> (std::istream& os, std::vector<T>& v);
template<typename T1, typename T2, typename T3> inline std::istream& operator >> (std::istream& os, triple<T1, T2, T3>& t);

template<typename T1, typename T2> inline std::istream& operator >> (std::istream& os, std::pair<T1, T2>& p) { return os >> p.first >> p.second; }
template<typename T> inline std::istream& operator >> (std::istream& os, std::vector<T>& v) {
    if (v.size()) for (T& t : v) os >> t; else {
        string s; T obj;
        while (s.empty()) {getline(os, s); if (!os) return os;}
        stringstream ss(s);
        while (ss >> obj) v.push_back(obj);
    }
    return os;
}
template<typename T1, typename T2, typename T3> inline std::istream& operator >> (std::istream& os, triple<T1, T2, T3>& t) { return os >> t.a >> t.b >> t.c; }

//Pair magic
template<typename T1, typename T2> inline pair<T1, T2> operator+(const pair<T1, T2> &p1 , const pair<T1, T2> &p2) { return pair<T1, T2>(p1.first + p2.first, p1.second + p2.second); }
template<typename T1, typename T2> inline pair<T1, T2> operator-(const pair<T1, T2> &p1 , const pair<T1, T2> &p2) { return pair<T1, T2>(p1.first - p2.first, p1.second - p2.second); }

#define FREIN(FILE) freopen(FILE, "rt", stdin)
#define FREOUT(FILE) freopen(FILE, "wt", stdout)

inline void normmod(ll &x, ll m) { x %= m; if (x < 0) x += m; }
inline ll summodfast(ll x, ll y, ll m) { ll res = x + y; if (res >= m) res -= m; return res; }
inline int summodfast(int x, int y, int m) { int res = x + y; if (res >= m) res -= m; return res; }
inline void addmodfast(ll &x, ll y, ll m) { x += y; if (x >= m) x -= m; }
inline void addmodfast(int &x, int y, int m) { x += y; if (x >= m) x -= m; }
inline void submodfast(ll &x, ll y, ll m) { x -= y; if (x < 0) x += m; }
inline void submodfast(int &x, int y, int m) { x -= y; if (x < 0) x += m; }
inline ll mulmod(ll x, ll n, ll m){ ll res = 0; normmod(x, m); normmod(n, m); while (n){ if (n & 1) res = summodfast(res, x, m); x = summodfast(x, x, m); n >>= 1; } return res; }
inline ll powmod(ll x, ll n, ll m){ ll res = 1; while (n){ if (n & 1)res = (res*x) % m; x = (x*x) % m; n >>= 1; }return res; }
inline ll gcd(ll a, ll b){ ll t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
inline ll gcd(ll a, ll b, ll c){ return gcd(gcd(a, b), c); }
inline int gcd(int a, int b, int c){ return gcd(gcd(a, b), c); }
ll gcdex(ll a, ll b, ll& x, ll& y) {
    if (!a) { x = 0; y = 1; return b; }
    ll y1;
    ll d = gcdex(b % a, a, y, y1);
    x = y1 - (b / a) * y;
    return d;
}

// Useful constants

#define INF         1011111111
#define LLINF       1000111000111000111LL
#define EPS         (double)1e-10
#define mod         1000000007
#define PI          3.14159265358979323
#define link        asaxlajrewqwe
#define rank        wahayawehasdakw
//*************************************************************************************

//int t[201010];
//pii q[201010];
//ll ans[2020];
//int tot[2020];
//int startTime[2020];
//map<int, int> fr[1020];
//int main() {
//    ios_base::sync_with_stdio(0);
//    int n, m;
//    cin >> n >> m;
//    for (int i = 0; i < n; ++i) {
//        cin >> t[i];
//        tot[t[i]]++;
//    }
//    int f = 1;
//    sort(t, t + n);
//    for (int i = 0; i < m; ++i) {
//        cin >> q[i].first;
//        q[i].second = i;
//    }
//    sort(q, q + m);
//    int curq = 0;
//    q[m] = {INF, m};
//    
//    multiset<pii> ms;
//    ms.insert({t[0], 0});
//    startTime[0] = 0;
//    ll tm = 0;
//    for (int cnt = 1; cnt <= 200000; ++cnt) {
//        auto it = ms.begin();
//        int time = it->first;
//        int idx = it->second;
//        ms.erase(it);
//        ms.insert({time + t[idx], idx});
//        if (f < n) {
//            ms.insert({time + t[f], f});
//            startTime[f] = time;
//            ++f;
//        }
//        while (q[curq].first <= cnt) {
//            ans[q[curq].second] = time;
//            ++curq;
//        }
//        tm = time;
//    }
//    ll dec = 0;
//    for (int i = 0; i < n; ++i) {
//        int d = startTime[i] / t[i];
//        dec -= d;
//        startTime[i] -= d * t[i];
//        fr[t[i]][startTime[i]]++;
//    }
//    for (int i = curq; i < m; ++i) {
//        ll l = tm;
//        ll r = t[0] * 1000000000LL;
//        int k = q[i].first;
//        while (l < r) {
//            ll m = (l + r) / 2;
//            ll tot = dec;
//            for (int t = 1; t <= 1000; ++t) {
//                for (auto p : fr[t]) {
//                    tot += (m - p.first) / t * p.second;
//                    if (tot >= k) break;
//                }
//                if (tot >= k) break;
//            }
//            if (tot >= k) {
//                r = m;
//            } else {
//                l = m + 1;
//            }
//        }
//        ans[q[i].second] = l;
//        tm = l;
//    }
//    
//    
//    for (int i = 0; i < m; ++i) {
//        cout << ans[i] << '\n';
//    }
//    
//    
//    
//    return 0;
//}

struct Mat {
    using T = ll;
    T a[2][2];
    Mat() {
        memset(a, 0, sizeof(a));
    }
    static Mat One() {
        Mat r;
        r[0][0] = r[1][1] = 1;
        return r;
    }
    T* operator[](int idx) {
        return a[idx];
    }
    const T* operator[](int idx) const {
        return a[idx];
    }
    Mat operator+(const Mat& b) {
        Mat r;
        FI(2) FJ(2) {
            r[i][j] = a[i][j] + b[i][j];
            if (r[i][j] >= mod) {
                r[i][j] -= mod;
            }
        }
        return r;
    }
    Mat& operator*=(const Mat& b) {
        return *this = *this * b;
    }
    Mat operator*(const Mat& b) {
        Mat r;
        FI(2) FJ(2) {
            FK(2) {
                r[i][j] += a[i][k] * b[k][j];
            }
            r[i][j] %= mod;
        }
        return r;
    }
    Mat power(int n) {
        if (n == 0) return Mat::One();
        if (n == 1) return *this;
        Mat t = power(n / 2);
        t = t * t;
        if (n % 2) {
            t = t * *this;
        }
        return t;
    }
    void print() {
        FI(2) {
            cout << "[" << a[i][0] << ", " << a[i][1] << "]" << endl;
        }
        cout << endl;
    }
    bool empty() {
        return a[0][0] == 1 && a[0][1] == 0 && a[1][0] == 0 && a[1][1] == 1;
    }
    void clear() {
        *this = Mat::One();
    }
};
Mat tr[401010];
Mat pu[401010];
int a[101010];
Mat fib;
void build(int cur, int l, int r) {
    pu[cur] = Mat::One();
    if (l == r) {
        tr[cur] = fib.power(a[l]);
    } else {
        int m = (l + r) / 2;
        int dcur = cur + cur;
        build(dcur, l, m);
        build(dcur + 1, m + 1, r);
        tr[cur] = tr[dcur] + tr[dcur + 1];
    }
}
void upd(int cur, int l, int r, int x, int y, Mat v) {
//    DBN(cur, l, r, x, y);
    if (l == x && r == y) {
        pu[cur] = pu[cur] * v;
        tr[cur] = tr[cur] * v;
    } else {
        int m = (l + r) / 2;
        int dcur = cur + cur;
        if (y <= m) {
            upd(dcur, l, m, x, y, v);
        } else if (x > m) {
            upd(dcur + 1, m + 1, r, x, y, v);
        } else {
            upd(dcur, l, m, x, m, v);
            upd(dcur + 1, m + 1, r, m + 1, y, v);
        }
        tr[cur] = (tr[dcur] + tr[dcur + 1]) * pu[cur];
    }
}
Mat sum(int cur, int l, int r, int x, int y) {
    if (r < x || l > y) return Mat();
    if (l >= x && r <= y) {
        return tr[cur];
    }
    int m = (l + r) / 2;
    int dcur = cur + cur;
    return (sum(dcur, l, m, x, y) + sum(dcur + 1, m + 1, r, x, y)) * pu[cur];
}
int main() {
//    FREIN("in.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int q;
    cin >> q;
    FI(n) {
        cin >> a[i];
    }
    fib[0][0] = fib[0][1] = fib[1][0] = 1;
//    for (int i = 0; i < 10; ++i) {
//        DBN(i);
//        fib.power(i).print();
//    }
    build(1, 0, n - 1);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            --l; --r;
//            DBN(t, l, r, x);
//            fib.power(x).print();
            upd(1, 0, n - 1, l, r, fib.power(x));
        } else {
            int l, r;
            cin >> l >> r;
            --l; --r;
//            DBN(t, l, r);
            auto res = sum(1, 0, n - 1, l, r);
//            res.print();
            cout << res[0][1] << endl;
        }
    }
    
    
    return 0;
}