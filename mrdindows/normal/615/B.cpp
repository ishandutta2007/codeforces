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
#define DBN1(a)			std::cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)		std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)		std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)	std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)	std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
#define DA(a,n) cout<<#a<<"=["; printarray(a,n); cout<<"]\n"
#define DAR(a,n,s) cout<<#a<<"["<<s<<"-"<<n-1<<"]=["; printarray(a,n,s); cout<<"]\n"

#ifdef _MSC_VER
#define ALIGN(x) __declspec(align(x))
#else
#define ALIGN(x) __attribute__((aligned(x)))
#endif

#define CURTIME() do { std::cout << "Current time = " << clock() * 1.0 / CLOCKS_PER_SEC << std::endl; } while(0)
static double __begin;
#define DTIME(ccc) __begin = clock(); ccc; std::cerr<<"Time of work = "<<(clock()-__begin)/CLOCKS_PER_SEC<<std::endl;

#define mp make_pair
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

template<typename T1,typename T2,typename T3>
struct triple{T1 a;T2 b;T3 c;triple(){};triple(T1 _a,T2 _b, T3 _c):a(_a),b(_b),c(_c){}};
#define tri triple<int,int,int>
#define trll triple<ll,ll,ll>
template<typename T1,typename T2,typename T3>
bool operator<(const triple<T1,T2,T3> &t1,const triple<T1,T2,T3> &t2){if (t1.a!=t2.a) return t1.a<t2.a; else if (t1.b != t2.b) return t1.b<t2.b; else return t1.c < t2.c; }
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }

#define FI(n) for(int i=0;i<n;i++)
#define FJ(n) for(int j=0;j<n;j++)
#define all(a) a.begin(), a.end()
//int some_primes[10] = {100271, 500179, 1000003, 2000227, 5000321}

inline int bits_count(int v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));return((x >> 16) | (x << 16));}
inline int sign(int x){ return x > 0;}
inline bool isPowerOfTwo(int x){return (x!=0 && (x&(x-1))==0);}
#define checkbit(n,b) ( (n >> b) & 1)
#define reunique(v) v.resize(std::unique(v.begin(), v.end()) - v.begin())

//STL output ********************************
template<typename T1,typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){return os << "(" << p.first << ", " << p.second << ")";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::vector<T>& v){bool first=true;os<<"[";for(unsigned int i=0;i<v.size();i++){if(!first)os<<", ";os<<v[i];first=false;}return os<<"]";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::set<T>&v){bool first=true;os << "[";for(typename std::set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v){bool first = true; os << "[";for (typename std::map<T1,T2>::const_iterator ii =v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T,typename T2>void printarray(T  a[],T2 sz,T2 beg=0){for(T2 i=beg;i<sz;i++) cout<<a[i]<<" ";cout<<endl;}

#define FREIN(FILE) freopen(FILE,"rt",stdin)
#define FREOUT(FILE) freopen(FILE,"wt",stdout)

#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(1.0*(x))
#define pow(x,n) pow(1.0*(x),n)
#define cmpBy(T, field) [](const T& x, const T& y){ return x.field < y.field; }

inline ll powmod(ll x,ll n, ll _mod){ll res=1;while(n){if(n&1)res=(res*x)%_mod;x=(x*x)%_mod;n>>=1;}return res;}
inline ll gcd(ll a,ll b){ll t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline int gcd(int a,int b){int t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
inline ll gcd(ll a,ll b,ll c){return gcd(gcd(a,b),c);}
inline int gcd(int a,int b,int c){return gcd(gcd(a,b),c);}

template<class T>
inline void getar(T a, int n, int m){ for (int i = 0; i < n; i++) for (int j=0;j<m;++j) { scanf("%d", &a[i][j]); } }
inline void getar(int *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d", a + ii); } }
inline void getar(pii *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d%d", &a[ii].first, &a[ii].second); } }
inline void getar(ll *a, int n){ for (int ii = 0;ii < n; ii++){ scanf("%I64d", a + ii); } }
template<class T>
inline void cinarr(T &a, int n){ for (int i=0;i<n;++i) cin >> a[i];}
// Useful constants

#define INF			1011111111
#define LLINF       1000111000111000111LL
#define EPS			(double)1e-15
#define mod			1000000007
#define PI			3.14159265358979323
//*******************************************************************************/

vector<int> v[101010];

int tot[101010];
bool used[101010];
int dp[101010];
int main() {
    int n, m;
    cin >> n >> m;
    FI(m){
        int x, y;
        cin >> x >> y;
        --x; --y;
        tot[x]++;
        tot[y]++;
        if (x > y) {
            v[y].push_back(x);
        } else {
            v[x].push_back(y);
        }
    }
    ll ans = 1;
    FI(n) dp[i] = 1;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[i] * 1ll * tot[i]);
        for (int to : v[i]) {
            dp[to] = max(dp[to], dp[i] + 1);
        }
    }
    cout << ans << endl;
    
    return 0;
}


//
//
//struct SA {
//    const int maxn = 30000;
//    map<char, int> to[30000];
//    int link[30000], len[30000];
//    int64_t cnt[30000];
//    int idx[30000];
//    int last, sz = 1;
//    
//    void add_letter(char c, int id)
//    {
//        int p = last;
//        last = sz++;
//        len[last] = len[p] + 1;
//        idx[last] = id;
//        for(; to[p][c] == 0; p = link[p])
//            to[p][c] = last;
//        if(to[p][c] == last)
//            return;
//        int q = to[p][c];
//        if(len[q] == len[p] + 1)
//        {
//            link[last] = q;
//            return;
//        }
//        int cl = sz++;
//        to[cl] = to[q];
//        link[cl] = link[q];
//        len[cl] = len[p] + 1;
//        link[last] = link[q] = cl;
//        for(; to[p][c] == q; p = link[p]) 
//            to[p][c] = cl;
//    }
//    
//};
//SA sa, revsa;
//int main() {
//    
//    string s, t;
//    cin >> s >> t;
//    for (int i = 0; i < s.size(); ++i) {
//        sa.add_letter(s[i], i);
//    }
//    reverse(all(s));
//    for (int i = 0; i < s.size(); ++i) {
//        revsa.add_letter(s[i], s.size() - i);
//    }
//    vector<pii> ans;
//    for (int i = 0; i < t.size();) {
//        
//        
//        int na = 0;
//        int cura = 0;
//        for (int j = i; j < t.size(); ++j) {
//            int to = sa.to[cura][t[j]];
//            if (to == 0) {
//                break;
//            }
//            ++na;
//            cura = to;
//        }
//        
//        
//        int nr = 0;
//        int curr = 0;
//        for (int j = i; j < t.size(); ++j) {
//            int to = revsa.to[curr][t[j]];
//            if (to == 0) {
//                break;
//            }
//            ++nr;
//            curr = to;
//        }
//        
//        if (na == 0 && nr == 0) {
//            cout << -1 << endl;
//            return 0;
//        }
//        if (na >= nr) {
//            ans.push_back({sa.idx[cura] - na + 2, sa.idx[cura] + 1});
//        } else {
//            ans.push_back({revsa.idx[curr] + nr - 1, revsa.idx[curr]});
//        }
//        i += max(na, nr);
//    }
//    cout << ans.size() << endl;
//    for (auto p : ans) {
//        cout << p.first << ' ' << p.second << endl;
//    }
//    
//    
//    return 0;
//}