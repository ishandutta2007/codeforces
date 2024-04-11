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
# include <type_traits>
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

#define INFLL       (1000100101LL*1000111000LL)
#define INF			1011111111
#define EPS			(double)1e-15
#define mod			1000000007
#define PI			3.14159265358979323
//*******************************************************************************/


vector<pii> v[100010];
bool used[100010];
bool zero[100010];
int pr[100010];
bool correct[100010];
void go_zero(int cur) {
    zero[cur] = true;
    for (pii p : v[cur]) {
        int to = p.first;
        if (p.second == 0 && !zero[to]) {
            go_zero(to);
            pr[to] = cur;
        }
    }
}
int d[100010];
int dp[100010];
void go(int cur) {
    correct[cur] = true;
    used[cur] = true;
    for (pii p : v[cur]) {
        int to = p.first;
//        DBN(cur, to);
        if (!used[to] && d[to] == d[cur] - 1) {
            go(to);
        }
    }
}
bool nice[100010];
int prt[100001];
int main () {
//    FREIN("in.txt");
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    FI(m) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    int f = n - 1;
    pr[f] = -1;
//    go_zero(f);
    
    
    
    vector<int> q;
    q.push_back(f);
    int qc = 0;
    used[f] = true;
    while (qc < q.size()) {
        int cur = q[qc++];
        zero[cur] = true;
        for (pii p : v[cur]) {
            int to = p.first;
            int l = p.second;
            if (l == 0 && !used[to]) {
                dp[to] = dp[cur] + 1;
                used[to] = true;
                q.push_back(to);
                pr[to] = cur;
            }
        }
    }
    
    FI(n) used[i] = false;
    q.clear();
    for (int i = 0; i < n; ++i) {
        if (zero[i]) {
            q.push_back(i);
            used[i] = true;
        }
    }
    int vc = 0;
    while (vc < q.size()) {
        int cur = q[vc++];
        int curd = d[cur];
        for (pii p : v[cur]) {
            int to = p.first;
            if (!used[to]) {
                used[to] = true;
                d[to] = curd + 1;
                q.push_back(to);
            }
        }
    }
    FI(n) used[i] = false;
    go(0);
    int len = d[0];
    q.clear();
    vector<int> curv;
    for (int i = 0; i < n; ++i) {
        if (zero[i]) {
            curv.push_back(i);
            used[i] = true;
        } else {
            used[i] = false;
        }
    }
//    FI(n) {
//        DBN(i, d[i], correct[i]);
//    }
//    DBN(curv);
    vc = 0;
    vector<int> nextv;
    for (int st = 0; st < len; ++st) {
//        DBN(curv);
        nextv.clear();
        int minl = INF;
        for (int cur : curv) {
            for (pii p : v[cur]) {
                int l = p.second;
                if (!used[p.first] && d[p.first] == d[cur] + 1 && correct[p.first] && l < minl) {
                    minl = l;
//                    DBN(p, d[p.first]);
                }
            }
        }
//        DBN(minl);
        for (int cur : curv) {
            for (pii p : v[cur]) {
                int to = p.first;
                int l = p.second;
                //                DBN(l, to, d[to], used[to]);
//                if (l == minl && d[to] == d[cur] + 1 && !used[to]) {
                if (l == minl && d[to] == d[cur] + 1 && correct[to] && !used[to]) {
                    nextv.push_back(to);
                    pr[to] = cur;
                    used[to] = true;
                }
            }
        }
        nextv.swap(curv);
    }
//    return 0;
    vector<int> way;
    int cur = 0;
    while (cur != -1) {
//        DBN(cur);
        way.push_back(cur);
        if (zero[cur]) break;
        cur = pr[cur];
    }
    
    
//    cout << way << endl;
    string ans;
    for (int i = 0; i < way.size() - 1; ++i) {
        int cur = way[i];
        int to = way[i + 1];
        for (pii p : v[cur]) {
            if (p.first == to) {
                ans += p.second + '0';
            }
        }
    }
//    DBN(ans);
//    return 0;
    q.clear();
    q.push_back(0);
    qc = 0;
    prt[0] = -1;
    nice[0] = true;
    while (qc < q.size()) {
//    for (int i = 0; i < n; ++i) {
        int cur = q[qc++];
        int dcur = d[cur];
        
        for (pii p : v[cur]) {
            int to = p.first;
            int l = p.second;
            int dto = d[to];
            
            if (!nice[to] && nice[cur] && correct[cur] && correct[to] && dto == dcur - 1 &&
                ans[ans.size() - dcur] == l + '0') {
                nice[to] = true;
                q.push_back(to);
                prt[to] = cur;
            }
        }
    }
//    DBN(q);
//    return 0;
    int minv = -1;
    for (int i = 0; i < n; ++i) {
        if (zero[i] && nice[i]) {
            if (minv == -1 || dp[minv] > dp[i]) {
                minv = i;
            }
        }
    }
    cur = minv;
    way.clear();
    while (cur != -1) {
        way.push_back(cur);
        cur = prt[cur];
    }
    reverse(all(way));
    cur = minv;
    way.pop_back();
    while (cur != -1) {
        way.push_back(cur);
        cur = pr[cur];
    }

    
    
    
    while (!ans.empty() && ans.back() == '0') {
        ans.pop_back();
    }
    reverse(all(ans));
    if (ans == "") {
        ans = "0";
    }
    cout << ans << endl;
    cout << way.size() << endl;
    for (int v : way) {
        cout << v << ' ';
    }
    cout << endl;
    return 0;
}