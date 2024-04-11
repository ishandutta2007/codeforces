//#pragma comment(linker, "/stack:20000000")
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
//# include <sstream>
//# include <fstream>
//# include <complex>
//# include <numeric>
//# include <immintrin.h>
//# include <cassert>
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
//using namespace std::tr1;
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
//#define DBN1(a)           std::cerr<<#a<<"="<<(a)<<"\n"
//#define DBN2(a,b)         std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
//#define DBN3(a,b,c)       std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
//#define DBN4(a,b,c,d)     std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
//#define DBN5(a,b,c,d,e)   std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
//#define DBN6(a,b,c,d,e,f) std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
//#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
//#define DA(a,n) std::cerr<<#a<<"=["; printarray(a,n); std::cerr<<"]\n"
//#define DAR(a,n,s) std::cerr<<#a<<"["<<s<<"-"<<n-1<<"]=["; printarray(a,n,s); std::cerr<<"]\n"
//
//#ifdef _MSC_VER
//#define ALIGN(x) __declspec(align(x))
//#else
//#define ALIGN(x) __attribute__((aligned(x)))
//#endif
//
//#define CURTIME() std::cerr << clock() * 1.0 / CLOCKS_PER_SEC << std::endl
//double __begin;
//#define DTIME(ccc) __begin = clock(); ccc; std::cerr<<"Time of work = "<<(clock()-__begin)/CLOCKS_PER_SEC<<std::endl;
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
//template<typename T1, typename T2, typename T3>
//struct triple{ T1 a; T2 b; T3 c; triple() : a(T1()), b(T2()), c(T3()) {}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };
//template<typename T1, typename T2, typename T3>
//bool operator<(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a<t2.a;else if(t1.b!=t2.b)return t1.b<t2.b;else return t1.c<t2.c;}
//template<typename T1, typename T2, typename T3>
//bool operator>(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a>t2.a;else if(t1.b!=t2.b)return t1.b<t2.b;else return t1.c<t2.c;}
//#define tri triple<int,int,int>
//#define trll triple<ll,ll,ll>
//
//#define FI(n) for(int i=0;i<n;++i)
//#define FJ(n) for(int j=0;j<n;++j)
//#define FK(n) for(int k=0;k<n;++k)
//#define FL(n) for(int l=0;l<n;++l)
//#define FQ(n) for(int q=0;q<n;++q)
//#define all(a) a.begin(), a.end()
//#define reunique(v) v.resize(std::unique(v.begin(), v.end()) - v.begin())
//
//#define sqr(x) ((x) * (x))
//#define sqrt(x) sqrt(1.0 * (x))
//#define pow(x, n) pow(1.0 * (x), n)
////int some_primes[10] = {100271, 500179, 1000003, 2000227, 5000321, 98765431}
//
//#define COMPARE(T) [&](const decltype(T)& a, const decltype(T)& b)
//#define COMPARE_BY(T, field) [&](const decltype(T)& a, const decltype(T)& b) { return a.field < b.field; }
//
//#define checkbit(n, b) (((n) >> (b)) & 1)
//inline int bits_count(int v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
//inline int bits_count(ll v){int t=v>>32;int p=(v& ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
//unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
//inline int sign(int x){ return x > 0; }
//inline bool isPowerOfTwo(int x){ return (x != 0 && (x&(x - 1)) == 0); }
//
////STL output ********************************
//template<typename T1, typename T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p);
//template<typename T> inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v);
//template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v);
//template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v);
//template<typename T1, typename T2, typename T3> inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t);
//template<typename T1, typename T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){ return os << "(" << p.first << ", " << p.second << ")"; }
//template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v){ bool first = true; os << "["; for (unsigned int i = 0; i<v.size(); i++){ if (!first)os << ", "; os << v[i]; first = false; }return os << "]"; }
//template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v){ bool first = true; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
//template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v){ bool first = true; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
//template<typename T, typename T2>void printarray(T  a[], T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }
//template<typename T1, typename T2, typename T3>
//inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }
//
////STL input ********************************
//template<typename T1, typename T2> inline std::istream& operator >> (std::istream& os, std::pair<T1, T2>& p);
//template<typename T> inline std::istream& operator >> (std::istream& os, std::vector<T>& v);
//template<typename T1, typename T2, typename T3> inline std::istream& operator >> (std::istream& os, triple<T1, T2, T3>& t);
//
//template<typename T1, typename T2> inline std::istream& operator >> (std::istream& os, std::pair<T1, T2>& p) { return os >> p.first >> p.second; }
//template<typename T> inline std::istream& operator >> (std::istream& os, std::vector<T>& v) {
//    if (v.size()) for (T& t : v) os >> t; else {
//        string s; T obj;
//        while (s.empty()) {getline(os, s); if (!os) return os;}
//        stringstream ss(s);
//        while (ss >> obj) v.push_back(obj);
//    }
//    return os;
//}
//template<typename T1, typename T2, typename T3> inline std::istream& operator >> (std::istream& os, triple<T1, T2, T3>& t) { return os >> t.a >> t.b >> t.c; }
//
////Pair magic
//template<typename T1, typename T2> inline pair<T1, T2> operator+(const pair<T1, T2> &p1 , const pair<T1, T2> &p2) { return pair<T1, T2>(p1.first + p2.first, p1.second + p2.second); }
//template<typename T1, typename T2> inline pair<T1, T2> operator-(const pair<T1, T2> &p1 , const pair<T1, T2> &p2) { return pair<T1, T2>(p1.first - p2.first, p1.second - p2.second); }
//
//#define FREIN(FILE) freopen(FILE, "rt", stdin)
//#define FREOUT(FILE) freopen(FILE, "wt", stdout)
//
//inline void normmod(ll &x, ll m) { x %= m; if (x < 0) x += m; }
//inline ll summodfast(ll x, ll y, ll m) { ll res = x + y; if (res >= m) res -= m; return res; }
//inline int summodfast(int x, int y, int m) { int res = x + y; if (res >= m) res -= m; return res; }
//inline void addmodfast(ll &x, ll y, ll m) { x += y; if (x >= m) x -= m; }
//inline void addmodfast(int &x, int y, int m) { x += y; if (x >= m) x -= m; }
//inline void submodfast(ll &x, ll y, ll m) { x -= y; if (x < 0) x += m; }
//inline void submodfast(int &x, int y, int m) { x -= y; if (x < 0) x += m; }
//inline ll mulmod(ll x, ll n, ll m){ ll res = 0; normmod(x, m); normmod(n, m); while (n){ if (n & 1) res = summodfast(res, x, m); x = summodfast(x, x, m); n >>= 1; } return res; }
//inline ll powmod(ll x, ll n, ll m){ ll res = 1; while (n){ if (n & 1)res = (res*x) % m; x = (x*x) % m; n >>= 1; }return res; }
//inline ll gcd(ll a, ll b){ ll t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
//inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
//inline ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
//inline ll gcd(ll a, ll b, ll c){ return gcd(gcd(a, b), c); }
//inline int gcd(int a, int b, int c){ return gcd(gcd(a, b), c); }
//ll gcdex(ll a, ll b, ll& x, ll& y) {
//    if (!a) { x = 0; y = 1; return b; }
//    ll y1;
//    ll d = gcdex(b % a, a, y, y1);
//    x = y1 - (b / a) * y;
//    return d;
//}
//
//// Useful constants
//
//#define INF         1011111111
//#define LLINF       1000111000111000111LL
//#define EPS         (double)1e-10
//#define mod         1000000007
//#define PI          3.14159265358979323
//#define link        asaxlajrewqwe
//#define rank        wahayawehasdakw
//#define next        fksduqojjuwll
////*************************************************************************************
//
//pii p[202020];
//int s[202020];
//int ans[202020];
//int tot[202020];
//int main() {
//    ios_base::sync_with_stdio(0);
//    int n, m;
//    scanf("%d%d", &n, &m);
//    FI(n) {
//        ans[i] = -1;
//    }
//    FI(n) {
//        scanf("%d", &p[i].first);
//        p[i].second = i;
//    }
//    FI(m) {
//        scanf("%d", s + i);
//    }
//    set<tri, std::greater<tri>> sq;
//    sort(p, p + n, std::greater<pii>());
//    FI(m) {
//        sq.insert({s[i], 0, i});
//    }
//    int res = 0;
//    int f = 0;
//    for (int i = 0; i < n; ++i) {
//        auto id = p[i].second;
//        int x = p[i].first;
//        while (!sq.empty() && sq.begin()->a > x) {
//            auto it = sq.begin();
//            int val = it->a;
//            int id = it->c;
//            int b = it->b;
//            sq.erase(it);
//            sq.insert({(val + 1) / 2, b + 1, id});
//        }
//        if (sq.begin()->a < x) continue;
//        int c = sq.begin()->c;
//        ans[id] = c;
//        ++res;
//        tot[c] = sq.begin()->b;
//        f += tot[c];
//        sq.erase(sq.begin());
//    }
//    printf("%d %d\n", res, f);
//    FI(m) {
//        printf("%d ", tot[i]);
//    }
//    puts("");
//    FI(n) {
//        printf("%d ", ans[i] + 1);
//    }
//    puts("");
//    
//    return 0;
//}



//#pragma comment(linker, "/STACK:16777216")

#include <fstream>
#include <iostream>
#include <bitset>
#include <cstring>
#include <string>
#include <complex>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

using ll = long long;
using pii = pair<int, int>;
template<class T1, class T2, class T3> struct triple {
    T1 x; T2 y; T3 z;
};
using tri = triple<int, int, int>;
using trll = triple<ll, ll, ll>;
template<class T1, class T2, class T3>
bool operator<(const triple<T1, T2, T3>& t1, const triple<T1, T2, T3>& t2) {
    return t1.x < t2.x || (t1.x == t2.x && (t1.y < t2.y || t1.y == t2.y && t1.z < t2.z));
}

#define eps 1e-9
#define bs 1000000007
const int mod = 1000000007;
const int INF = 1000111000;
const ll LLINF = 1000111000111000111LL;
const double PI = acos(-1.0);
#define bsize 256

#define all(v) (v).begin(), (v).end()
#define FI(n) for (int i = 0; i < n; ++i)
#define FJ(n) for (int j = 0; j < n; ++j)
#define FK(n) for (int k = 0; k < n; ++k)
#define FREIN(file) freopen(file, "rt", stdin)
#define FREOUT(file) freopen(file, "wt", stdout)
#define sqr(x) ((x)*(x))

#define DB(n) cerr<<#n<<" = "<<(n)<<" "
#define DBN(n) cerr<<#n<<" = "<<(n)<<"\n"

int gcd(int x, int y) { while (y) { x %= y, swap(x, y); } return x; }
ll gcd(ll x, ll y) { while (y) { x %= y, swap(x, y); } return x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll powmod(ll x, ll n, const int mod) {
    ll res = 1; while (n)
    {
        if (n & 1) res = res * x % mod; n /= 2; x = x * x % mod;
    } return res;
}
#define checkbit(mask, bit) ((mask>>bit)&1)


int ax[10101], ay[10101];
int mx[10101], my[10101];
int dx[7][10101], dy[7][10101];
vector<pair<int, ll>> np[7][1010];
ll dist[7][10101];
bool used[10101];
char dp[1010][1 << 7][7];
int k, n;
bool tryToKill(int cur, int mask, int from) {
    auto& ans = dp[cur][mask][from];
    if (!ans) {
        int res = 0;
        if (np[from][cur].size() == 0) {
            res = true;
        }
        else if (np[from][cur].size() > 7) {
            res = false;
        } else {
            int fow = np[from][cur][0].second;
            for (int w = 0; w < k; ++w) {
                if (checkbit(mask, w)) {
                    int wm = mask ^ (1 << w);
                    for (int sm = wm; ; sm = (sm - 1) & wm) {
                        bool here = tryToKill(fow, sm, w) && tryToKill(fow, wm ^ sm, from);
                        if (here) {
                            res = true;
                            goto stop;
                        }
                        if (sm == 0) break;
                    }
                    if (dx[from][fow] == dx[w][fow] && dy[from][fow] == dy[w][fow]) {
                        if (dist[from][fow] < dist[w][fow]) {
                            bool here = tryToKill(fow, wm, w);
                            if (here) {
                                res = true;
                                goto stop;
                            }
                        }
                    }
                }
            }
        }
    stop:
        ans = res + 1;
    }
    return ans - 1;
}

int toKill[101010];
bool isKilled[101010];
int sp = 0;
int cp = 0;
int ls;
bool killed[1010];
bool go(int cp, int sp) {
    if (sp - cp > ls) return false;
    if (cp == sp) {
        return true;
    }
    ++cp;
    for (int i = 0; i < sp; ++i) {
        if (!killed[i]) {
            int cur = toKill[i];
            killed[i] = true;
            for (int i = 0; i < k; ++i) {
                if (!used[i]) {
                    int bonus = 0;
                    bool bad = false;
                    for (auto p : np[i][cur]) {
                        bool add = true;
                        int x = p.second;
                        for (int i = 0; i < sp; ++i) {
                            if (toKill[i] == x) {
                                add = false;
                                break;
                            }
                        }
                        if (add) {
                            toKill[sp + bonus++] = x;
                        }
                    }
                    if (bad) continue;
                    
                    used[i] = true;
                    isKilled[cur] = true;
                    --ls;
                    bool res = go(cp, sp + bonus);
                    ++ls;
                    isKilled[cur] = false;
                    used[i] = false;
                    if (res) return true;
                }
            }
            killed[i] = false;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    ls = k;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> ax[i] >> ay[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> mx[i] >> my[i];
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            int tx = mx[j] - ax[i];
            int ty = my[j] - ay[i];
            int g = gcd(abs(tx), abs(ty));
            dist[i][j] = tx * (ll)tx + ty * (ll)ty;
            dx[i][j] = tx / g;
            dy[i][j] = ty / g;
        }
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < n; ++l) {
                if (l == j) continue;
                if (dx[i][j] == dx[i][l] && dy[i][j] == dy[i][l] && dist[i][j] > dist[i][l]) {
                    np[i][j].push_back({dist[i][l], l });
                } 
                if (np[i][j].size() > 7) break;
            }
            sort(all(np[i][j]));
            reverse(all(np[i][j]));
        }
    }
    int ans = 0;
    
    for (int i = 0; i < n; ++i) {
        toKill[0] = i;
        memset(killed, 0, 20);
        ans += go(0, 1);
    }
    /*
     int fullMask = (1 << k) - 1;
     for (int j = 0; j < n; ++j) {
     bool ok = false;
     for (int i = 0; i < k; ++i) {
     ok |= tryToKill(j, fullMask ^ (1 << i), i);
     }
     
     ans += ok;
     }
     */
    cout << ans << endl;
    
    return 0;
}
/**/