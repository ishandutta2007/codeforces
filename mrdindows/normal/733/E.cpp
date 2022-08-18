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

template<class T1, class T2, class T3>
struct triple{ T1 a; T2 b; T3 c; triple() : a(T1()), b(T2()), c(T3()) {}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };
template<class T1, class T2, class T3>
bool operator<(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a<t2.a;else if(t1.b!=t2.b)return t1.b<t2.b;else return t1.c<t2.c;}
template<class T1, class T2, class T3>
bool operator>(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a>t2.a;else if(t1.b!=t2.b)return t1.b>t2.b;else return t1.c>t2.c;}
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
//int some_primes[10] = {100271, 500179, 1000003, 2000227, 5000321, 98765431}

#define COMPARE(T) [&](const decltype(T)& a, const decltype(T)& b)
#define COMPARE_BY(T, field) [&](const decltype(T)& a, const decltype(T)& b) { return a.field < b.field; }

#define checkbit(n, b) (((n) >> (b)) & 1)
#define setbit(n, b) ((n) | (static_cast<decltype(n)>(1) << (b)))
#define removebit(n, b) (~setbit(~(n), (b))))
inline int bits_count(int v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int bits_count(ll v){int t=v>>32;int p=(v& ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
inline int sign(int x){ return x > 0; }
inline bool isPowerOfTwo(int x){ return (x != 0 && (x&(x - 1)) == 0); }

//STL output *****************************************************************************************************
template<class T1, class T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p);
template<class T> inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v);
template<class T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v);
template<class T1, class T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v);
template<class T1, class T2, class T3> inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t);
template<class T1, class T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){ return os <<"("<<p.first<<", "<< p.second<<")"; }
template<class T>inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v){ bool first = true; os << "["; for (unsigned int i = 0; i<v.size(); i++){ if (!first)os << ", "; os << v[i]; first = false; }return os << "]"; }
template<class T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v){ bool first = true; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<class T1, class T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v){ bool first = true; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<class T, class T2>void printarray(T  a[], T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }
template<class T1, class T2, class T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }

//STL input *****************************************************************************************************
template<class T1, class T2> inline std::istream& operator >> (std::istream& os, std::pair<T1, T2>& p);
template<class T> inline std::istream& operator >> (std::istream& os, std::vector<T>& v);
template<class T1, class T2, class T3> inline std::istream& operator >> (std::istream& os, triple<T1, T2, T3>& t);
template<class T1, class T2> inline std::istream& operator >> (std::istream& os, std::pair<T1, T2>& p) { return os >> p.first >> p.second; }
template<class T> inline std::istream& operator >> (std::istream& os, std::vector<T>& v) {
    if (v.size()) for (T& t : v) os >> t; else {
        string s; T obj; while (s.empty()) {getline(os, s); if (!os) return os;}
        stringstream ss(s); while (ss >> obj) v.push_back(obj);
    }
    return os;
}
template<class T1, class T2, class T3> inline std::istream& operator >> (std::istream& os, triple<T1, T2, T3>& t) { return os >> t.a >> t.b >> t.c; }

//Pair magic *****************************************************************************************************
#define PT1T2 pair<T1, T2>
template<class T1, class T2> inline PT1T2 operator+(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first + p2.first, p1.second + p2.second); }
template<class T1, class T2> inline PT1T2 operator-(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first - p2.first, p1.second - p2.second); }

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

int solve(string s, int pos) {
    int ans = 0;
    while (pos >= 0 && pos < s.size()) {
        auto &c = s[pos];
        pos += c ? 1 : -1;
        c = !c;
        ++ans;
    }
    return ans;
}
ll res[1020202];
struct Fenwick {
    ll tr[1010101];
    void add(int pos, int val) {
        for (int i = pos; i <= 1000000; i |= (i + 1)) {
            tr[i] += val;
        }
    }
    ll sum(int x) {
        ll res = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            res += tr[i];
        }
        return res;
    }
    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
Fenwick fl, fr;
void solve(string s) {
    int n = (int) s.size();
    deque<int> right;
    deque<int> left;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'D') {
            right.push_back(i);
            fr.add(i, i);
        } else {
            fl.add(i, i);
        }
    }
    left.push_back(-1);
    right.push_back(n);
    for (int i = 0; i < n; ++i) {
        ll res = 0;
        if (s[i] == 'D') {
            right.pop_front();
            ll lcnt, rcnt, plus;
            if (left.size() <= right.size()) {
                lcnt = left.size() - 1;
                rcnt = lcnt;
                plus = i + 1;
            } else {
                rcnt = right.size() - 1;
                lcnt = rcnt + 1;
                plus = n - i;
            }
            res += plus;
            if (lcnt) {
                res += 2 * (i * lcnt - fl.sum(left[left.size() - lcnt], left[left.size() - 1]));
            }
            if (rcnt) {
                res += 2 * (fr.sum(right[0], right[rcnt - 1]) - i * rcnt);
            }
        } else {
            ll lcnt, rcnt, plus;
            if (left.size() >= right.size()) {
                rcnt = right.size() - 1;
                lcnt = rcnt;
                plus = n - i;
            } else {
                lcnt = left.size() - 1;
                rcnt = lcnt + 1;
                plus = i + 1;
            }
//            DBN(lcnt, rcnt, plus);
            res += plus;
            if (lcnt) {
                res += 2 * (i * lcnt - fl.sum(left[left.size() - lcnt], left[left.size() - 1]));
            }
//            DBN(res);
            if (rcnt) {
                res += 2 * (fr.sum(right[0], right[rcnt - 1]) - i * rcnt);
            }
//            DBN(res);
            
            left.push_back(i);
        }
        ::res[i] = res;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s(n, '0');
    cin >> s;
    solve(s);
    FI(n) {
        cout << res[i] << ' ';
    }
    cout << endl;
//    for (char& c : s) {
//        c = (c == 'U');
//    }
//    for (int mask = 0; mask < (1 << n); ++mask) {
////    cin >> s;
//        FI(n) {
//            s[i] = checkbit(mask, i);
//        }
//        FI(n) {
//            res[i] = solve(s, i);
//        }
//        auto idx = min_element(res, res + n) - res;
////        if (idx != 0 && idx != n - 1) {
////            DBN(mask, idx);
//            printarray(res, n);
////        }
//    }
////    FI(n) {
////        DBN(i, solve(s, i));
////    }
    return 0;
}