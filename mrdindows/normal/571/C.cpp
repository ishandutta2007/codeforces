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
using namespace std;

// Let's define unordered map
# ifdef __GNUC__
# if __cplusplus > 199711L
# include <unordered_map>
# else
# include <tr1/unordered_map>
using namespace std::tr1;
# endif
# else
# include <unordered_map>
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

#define DEB(x) std::cerr<<#x<<"="<<(x)<<"  "

#define DB(x) DEB(x)
#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
#define DA(a,n) cout<<#a<<"=["; printarray(a,n); cout<<"]\n"
#define DAR(a,n,s) cout<<#a<<"["<<s<<"-"<<n-1<<"]=["; printarray(a,n,s); cout<<"]\n"

double __begin;
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
#define trl triple<ll,ll,ll>
template<typename T1,typename T2,typename T3>
bool operator<(const triple<T1,T2,T3> &t1,const triple<T1,T2,T3> &t2){if (t1.a!=t2.a) return t1.a<t2.a; else if (t1.b != t2.b) return t1.b<t2.b; else return t1.c < t2.c; }
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }

#define FI(n) for(int i=0;i<n;i++)
#define FJ(n) for(int j=0;j<n;j++)

//STL containers
#define all(a) a.begin(), a.end()

//int some_primes[10] = {100271, 500179, 1000003, 2000227, 5000321}
//fill char arrays
#define fill(a,v)                    memset(a, v, sizeof (a))

inline int bits_count(int v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));return((x >> 16) | (x << 16));}
inline int sign(int x){ return x > 0;}
inline bool ispow2(int x){return (x!=0 && (x&(x-1))==0);}
#define checkbit(n,b) ( (n >> b) & 1)

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

inline ll powmod(ll x,ll n, ll _mod){ll res=1;while(n){if(n&1)res=(res*x)%_mod;x=(x*x)%_mod;n>>=1;}return res;}
inline ll gcd(ll a,ll b){ll t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline int gcd(int a,int b){int t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline ll lcm(int a,int b){return a/gcd(a,b)*(ll)b;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
inline ll gcd(ll a,ll b,ll c){return gcd(gcd(a,b),c);}
inline int gcd(int a,int b,int c){return gcd(gcd(a,b),c);}
inline ll lcm(ll a,ll b,ll c){return lcm(lcm(a,b),c);}
inline ll lcm(int a,int b,int c){return lcm(lcm(a,b),(ll)c);}

inline ll max(ll a,ll b){return (a>b)?a:b;}
inline int max(int a,int b){return (a>b)?a:b;}
inline double max(double a,double b){return (a>b)?a:b;}
inline ll max(ll a,ll b,ll c){return max(a,max(b,c));}
inline int max(int a,int b,int c){return max(a,max(b,c));}
inline double max(double a,double b,double c){return max(a,max(b,c));}
inline ll min(ll a,ll b){return (a<b)?a:b;}
inline int min(int a,int b){return (a<b)?a:b;}
inline double min(double a,double b){return (a<b)?a:b;}
inline ll min(ll a,ll b,ll c){return min(a,min(b,c));}
inline int min(int a,int b,int c){return min(a,min(b,c));}
inline double min(double a,double b,double c){return min(a,min(b,c));}

template<class T>
inline void getar(T a, int n, int m){ for (int i = 0; i < n; i++) for (int j = 0; j < m;++j) { scanf("%d", &a[i][j]); } }
inline void getar(int *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d", a + ii); } }
inline void getar(pii *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d%d", &a[ii].first, &a[ii].second); } }
inline void getar(ll *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%I64d", a + ii); } }
template<class T>
inline void cinarr(T &a, int n){ for (int i=0;i<n;++i) cin >> a[i];}
// Useful constants

#define INF			1011111111
#define EPS			(double)1e-15
#define mod			1000000007
#define PI			3.14159265358979323
//*******************************************************************************/

vector<int> v[201001];
int val[200100];
bool notused[200100];
bool done[200100];
bool used[200010];
vector<int> g[200020];
int b[200010];
int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    FI(n) {
        int k;
        cin >> k;
        FJ(k) {
            int x;
            cin >> x;
            if (x < 0) {
                v[-x].push_back(-i - 1);
            } else {
                v[x].push_back(i + 1);
            }
            g[i + 1].push_back(abs(x));
        }
    }
    vector<int> q;
    for (int i = 1; i <= m; ++i) {
//        DBN(i, v[i]);
        if (v[i].size() == 1 || (v[i].size() == 2 && sign(v[i][0]) == sign(v[i][1]))) {
            q.push_back(i);
            used[i] = true;
        }
    }
//    DBN(q);
    while (!q.empty()) {
        auto x = q.back();
        q.pop_back();
        if (v[x].size() == 0) continue;
        val[x] = v[x][0] > 0;
        for (int to : v[x]) {
            if (to < 0) to = -to;
            if (!done[to]) {
                done[to] = true;
                for (int p : g[to]) {
                    if (!used[p]) {
                        for (int i = 0; i < v[p].size(); ++i) {
                            if (v[p][i] == to || v[p][i] == -to) {
                                v[p].erase(v[p].begin() + i, v[p].begin() + i + 1);
                            }
                        }
                        if (v[p].size() == 1) {
                            q.push_back(p);
                            used[p] = true;
                        }
                    }
                }
            }
        }
    }
    
//    for (int i = 1; i <= m; ++i) {
//        if (v[i].size() == 0) {
//            val[i] = 1;
//        } else if (v[i].size() == 1) {
//            val[i] = v[i][0] > 0;
//        } else {
//            if (v[i][0] > 0 && v[i][1] > 0) {
//                val[i] = 1;
//            } else if (v[i][0] < 0 && v[i][1] < 0) {
//                val[i] = 0;
//            } else {
//                notused[i] = true;
//            }
//        }
//        if (!notused[i]) {
//            for (int x : v[i]) {
//                done[abs(x)] = true;
//            }
//        }
//    }
    int nd = 0;
    set<pii> s;
    for (int i = 1; i <= m; ++i) {
        if (!used[i]) {
            for (int to : v[i]) {
                b[abs(to)]++;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!done[i]) {
            ++nd;
            s.insert({b[i], i});
        }
    }
//    DBN(nd, s);
    
    while (nd > 0) {
        auto it = s.begin();
        int id = it->second;
        s.erase(it);
        int f = -1;
//        DBN(id, g[id]);
        for (int r : g[id]) {
            if (!used[r]) {
                f = r;
                break;
            }
        }
        if (f == -1) {
            puts("NO");
            return 0;
        }
        for (int to : v[f]) {
            if (to == id) {
                val[f] = 1;
                continue;
            }
            if (to == -id) {
                val[f] = 0;
                continue;
            }
            to = abs(to);
            if (done[to]) continue;
            s.erase({b[to], to});
            b[to]--;
            s.insert({b[to], to});
        }
        used[f] = true;
        done[id] = true;
        --nd;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= m; ++i) {
        cout << char('0' + val[i]);
    }
    cout << endl;
    
    return 0;
}