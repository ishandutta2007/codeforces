/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC optimize("Ofast,unroll-loops") */
/* #pragma GCC target("avx2,popcnt") */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = (arr).rbegin()+(plus); x !=(arr).rend(); ++x)
#define REE(s_) {cout<<s_<<'\n';exit(0);}
#define GET(arr) for(auto &i: (arr)) sc(i)
#define whatis(x) cerr << #x << " is " << (x) << endl;
#define e1 first
#define e2 second
#define INF 0x7f7f7f7f
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
typedef uint64_t ull;
#define umap unordered_map
#define uset unordered_set
using namespace std;
using namespace __gnu_pbds;
 
#ifdef ONLINE_JUDGE
#define whatis(x) ;
#endif
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 1000001

vector<string> ops;
#define int ll
int mul(int a, int b, int base){
    if(b == 1){
        return a;
    }
    if(b&1){
        // razy pow2, wiec ma sens ze tego nie ma wsm.
        int wh = mul(a, b ^ 1, base);
        assert(base == a); // ?? jak.
        // -> wait, no ta, przeciez nie zmieniam a nigdie xd.
        /* ops.push_back(to_string(wh) + " + " + to_string(base)); */
        /* return wh + base; */
        ops.push_back(to_string(wh) + " + " + to_string(a));
        return wh + a;
    }
    int wh = mul(a, b / 2, base);
    ops.push_back(to_string(wh) + " + " + to_string(wh));
    return wh + wh;
}

int gcdExtended(int a, int b, int *x, int *y){
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    /* int e = 0; */
    /* while((1 << (e + 1)) <= n) */
    /*     ++e; */
    int e = 1;
    while((e << 1) <= n)
        e <<= 1;
    int y = n;
    int tgy = e * n;
    /* assert(mul(n, e) == tgy); */
    assert(mul(n, e, n) == tgy);
    ops.push_back(to_string(tgy) + " ^ " + to_string(n));
    /* y = tgy + n; */
    // ??? XD.
    /* y = tgy ^ N; */
    y = tgy ^ n;
    int a,b;
    assert(gcdExtended(n, y, &a, &b) == 1);
    a = abs(a);
    b = abs(b);
    int nx = n * a;
    int ny = y * b;
    /* whatis("1stmul") */
    /* ops.pb("1stmul"); */
    /* whatis(n) */
    /* whatis(nx) */
    assert(mul(n, a, n) == nx);
    /* whatis("2ndmul") */
    /* ops.pb("2ndmul"); */
    /* whatis(y) */
    /* whatis(ny) */
    assert(mul(y, b, y) == ny);
    if(nx > ny)
        swap(nx, ny);
    // ny wieksze tera.
    assert(ny == nx + 1);
    // opposite. smaller has to be even.
    /* if(ny & 1){ */
    /*     ops.push_back(to_string(nx) + " + " + to_string(y)); */
    /*     ops.push_back(to_string(ny) + " + " + to_string(y)); */
    /*     nx += y; */
    /*     ny += y; */
    /*     assert(ny % 2 == 0); */
    /* } */
    if(nx & 1){
        // lol.
        /* ops.push_back(to_string(nx) + " + " + to_string(N)); */
        ops.push_back(to_string(nx) + " + " + to_string(n));
        ops.push_back(to_string(ny) + " + " + to_string(n));
        nx += n;
        ny += n;
        assert(nx % 2 == 0);
    }
    ops.push_back(to_string(nx) + " ^ " + to_string(ny));
    /* whatis(nx) */
    /* whatis(ny) */
    assert((nx ^ ny) == 1);
    /* whatis(nx) */
    /* whatis(ny) */
    /* whatis(n) */
    /* whatis(y) */
    /* whatis(__gcd(n, y)) */
    /* assert(__gcd(n, y) == 1); */
    cout << ops.size() << '\n';
    FORR(i,ops)
        cout << i << '\n';
}