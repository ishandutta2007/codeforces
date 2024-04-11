#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")

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

using namespace std;

// Let's define unordered map
# ifdef __GNUC__
# if __cplusplus > 199711L
# include <unordered_set>
# include <unordered_map>
# else
# include <tr1/unordered_map>
# include <tr1/unordered_set>
using namespace tr1;
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
#define ALIGN(x) __declspec(align(x))
#else
#define ALIGN(x) __attribute__((aligned(x)))
#endif

#ifdef LOCAL
#define CURTIME() cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl
#else
#define CURTIME() ;
#endif
double __begin;
#define DTIME(ccc) __begin = clock(); ccc; cerr<<"Time of work = "<<(clock()-__begin)/CLOCKS_PER_SEC<<endl;

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
#define FOR(i,a,b) for(int i = (a), __e = (int) (b); i < __e; ++i)
#define all(a) std::begin(a), std::end(a)
#define reunique(v) v.resize(unique(v.begin(), v.end()) - v.begin())

#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(1.0 * (x))
#define pow(x, n) pow(1.0 * (x), n)

#define COMPARE(obj) [&](const std::decay<decltype(obj)>::type& a, const std::decay<decltype(obj)>::type& b)
#define COMPARE_BY(obj, field) [&](const std::decay<decltype(obj)>::type& a, const std::decay<decltype(obj)>::type& b) { return a.field < b.field; }

#define checkbit(n, b) (((n) >> (b)) & 1)
#define setbit(n, b) ((n) | (static_cast<decltype(n)>(1) << (b)))
#define removebit(n, b) (~setbit(~(n), (b)))
inline int bits_count(int v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int bits_count(ll v){int t=v>>32;int p=(v& ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
template<class T>
inline int sign(T x){ return x > 0 ? 1 : x < 0 ? -1 : 0; }
inline bool isPowerOfTwo(int x){ return (x != 0 && (x&(x - 1)) == 0); }
unsigned long long rdtsc() {
    unsigned long long ret;
    __asm__ __volatile__("rdtsc" : "=A" (ret) : :);
    return ret;
}

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
TT1T2 ostream& operator << (ostream& os, const pair<T1, T2>& p){ return os <<"("<<p.first<<", "<< p.second<<")"; }
TT1 ostream& operator << (ostream& os, const vector<T>& v){       bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const set<T1, T2>&v){    bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const multiset<T1,T2>&v){bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2T3 ostream& operator << (ostream& os, const map<T1,T2,T3>& v){ bool f = 1; os << "["; for (auto& ii : v) { if (!f)os << ", "; os << "(" << ii.first << " -> " << ii.second << ") "; f = 0; }return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const multimap<T1, T2>& v){ bool f = 1; os << "["; for (auto& ii : v) { if (!f)os << ", "; os << "(" << ii.first << " -> " << ii.second << ") "; f = 0; }return os << "]"; }
TT1T2 ostream& operator << (ostream& os, priority_queue<T1, T2> v) { bool f = 1; os << "["; while (!v.empty()) { auto x = v.top(); v.pop(); if (!f) os << ", "; f = 0; os << x; } return os << "]"; }
TT1T2T3 ostream& operator << (ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }
TT1T2 void printarray(T1 a, T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }

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
TT1T2 inline PT1T2 operator-(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first - p2.first, p1.second - p2.second); }

#undef TT1
#undef TT1T2
#undef TT1T2T3

#define FREIN(FILE) freopen(FILE, "rt", stdin)
#define FREOUT(FILE) freopen(FILE, "wt", stdout)

template<class T> bool isPrime(T x) { if (x < 2) return 0; for (T i = 2; i * i <= x; ++i) if (x % i == 0) return 0; return 1; }
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

//int some_primes[10] = {24443, 100271, 500179, 1000003, 1000333, 2000321, 5000321, 98765431, 1000000123};
#define INF         1011111111
#define LLINF       1000111000111000111LL
#define EPS         (double)1e-10
#define mod         1000000007
#define PI          3.14159265358979323
#define link        asaxlajrewqwe
#define rank        wahayawehasdakw
//*************************************************************************************


char s[101][101];
bool canLR[101][101];
bool canUD[101][101];

int n, m;
bool isCorrect(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
bool isSafe(int x, int y) {
    return !isCorrect(x, y) || s[x][y] != '*';
}
int x = 0, y = 0;
bool knowLR = 0;
bool swapLR = 0;
bool knowUD = 0;
bool swapUD = 0;
void go(char c) {
    if (knowLR && swapLR) {
        if (c == 'L') {
            c = 'R';
        } else if (c == 'R') {
            c = 'L';
        }
    }
    if (knowUD && swapUD) {
        if (c == 'U') {
            c = 'D';
        } else if (c == 'D') {
            c = 'U';
        }
    }
    cout << c << endl;
    int px = x;
    int py = y;
    cin >> x >> y;
    --x; --y;
    if (!knowLR && (c == 'L' || c == 'R')) {
        knowLR = true;
        if (c == 'L' && ((isCorrect(px, py - 1) && y != py - 1) || y == py + 1)) {
            swapLR = true;
        }
        if (c == 'R' && ((isCorrect(px, py + 1) && y != py + 1) || y == py - 1)) {
            swapLR = true;
        }
    }
    if (!knowUD && (c == 'U' || c == 'D')) {
        knowUD = true;
        if (c == 'U' && ((isCorrect(px - 1, py) && x != px - 1) || x == px + 1)) {
            swapUD = true;
        }
        if (c == 'D' && ((isCorrect(px + 1, py) && x != px + 1) || x == px - 1)) {
            swapUD = true;
        }
    }
}
bool used[101][101];
pii pr[101][101];
bool vis[101][101];
pii fxy(0, 0);
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    FI(n) {
        cin >> s[i];
        FJ(m) {
            if (s[i][j] == 'F') {
                fxy = {i, j};
            }
        }
    }
    FI(n) {
        FJ(m) {
            if (isSafe(i - 1, j) && isSafe(i + 1, j)) {
                canUD[i][j] = true;
            }
            if (isSafe(i, j - 1) && isSafe(i, j + 1)) {
                canLR[i][j] = true;
            }
        }
    }
    if (canLR[x][y]) {
        go('L');
        int tox = -1;
        int toy = -1;
        int fox = -1;
        int foy = -1;
        for (int i = y; i < m; ++i) {
            if (s[x][i] == '*') {
                break;
            } else if (s[x][i] == 'F') {
                fox = x;
                foy = i;
            } else if (canUD[x][i]) {
                tox = x;
                toy = i;
            }
        }
        if (fox != -1) {
            for (int i = y; i < foy; ++i) {
                go('R');
            }
            return 0;
        }
        for (int i = y; i >= 0; --i) {
            if (s[x][i] == '*') {
                break;
            } else if (s[x][i] == 'F') {
                fox = x;
                foy = i;
            } else if (canUD[x][i]) {
                tox = x;
                toy = i;
            }
        }
        if (fox != -1) {
            for (int i = y; i > foy; --i) {
                go('L');
            }
            return 0;
        }
        while (toy != y) {
            if (toy < y) {
                go('L');
            } else {
                go('R');
            }
        }
        go('U');
    } else {
        go('U');
        int tox = -1;
        int toy = -1;
        int fox = -1;
        int foy = -1;
        for (int i = x; i < n; ++i) {
            if (s[i][y] == '*') {
                break;
            } else if (s[i][y] == 'F') {
                fox = i;
                foy = y;
            } else if (canLR[i][y]) {
                tox = i;
                toy = y;
            }
        }
        if (fox != -1) {
            for (int i = x; i < fox; ++i) {
                go('D');
            }
            return 0;
        }
        for (int i = x; i >= 0; --i) {
            if (s[i][y] == '*') {
                break;
            } else if (s[i][y] == 'F') {
                fox = i;
                foy = y;
            } else if (canLR[i][y]) {
                tox = i;
                toy = y;
            }
        }
        if (fox != -1) {
            for (int i = x; i > fox; --i) {
                go('U');
            }
            return 0;
        }
        while (tox != x) {
            if (tox < x) {
                go('U');
            } else {
                go('D');
            }
        }
        go('L');
    }
    vector<pii> q;
    q.push_back({x, y});
    int qc = 0;
    while (qc < q.size()) {
        auto cur = q[qc++];
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for (int dir = 0; dir < 4; ++dir) {
            int x = cur.first + dx[dir];
            int y = cur.second + dy[dir];
            if (isCorrect(x, y) && !used[x][y] && isSafe(x, y)) {
                used[x][y] = true;
                q.push_back({x, y});
                pr[x][y] = cur;
            }
        }
    }
    pii cur = fxy;
    vector<pii> v;
    while (cur.first != x || cur.second != y) {
        v.push_back(cur);
        cur = pr[cur.first][cur.second];
    }
    reverse(all(v));
    for (auto p : v) {
        if (p.first > x) {
            go('D');
        } else if (p.first < x) {
            go('U');
        } else if (p.second > y) {
            go('R');
        } else {
            go('L');
        }
    }
    
    
    return 0;
}