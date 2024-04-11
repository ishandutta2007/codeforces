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

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 1000001

ll mx = 1e5+5;

/* const ll is_qu = -(1ll << 63); */

/* struct Line{ */
/*     ll m,b; */
/*     //pamita trzeba mutable i <const Line*()> */
/*     mutable function<const Line*()> succ; //aby w comparatorze mie dostp do nexta Linii */
/*     bool operator < (const Line &rhs) const{ */
/*         if(rhs.b != is_qu){ //hackish - gdy porwnujemy przy insercie liczy si tylko m */
/*             return m < rhs.m; */
/*         } */
/*         //przy lower boundzie - porwnujemy z nextem dla danego iksa */
/*         const Line *nx = succ(); */
/*         if(!nx) return 0; */
/*         ll x = rhs.m; */
/*         return x*m+b < x*nx->m+nx->b; */
/*     } */
/* }; */

/* //inherituje od multisetu, to istotne! */
/* /1* struct hull : public multiset<Line>{ *1/ */

/* struct hull : public multiset<Line>{// */
/*     int intersect(iterator x, iterator y){ */
/*         // int vs double wanie i guess */

/*         /1* ll low = -mx, high = mx, mid, ans = -1; *1/ */
/*         ll low = -mx, high = mx, mid, ans = LONG_LONG_MAX; */
/*         // pierwszy, e 2nd (strictly) better */
/*         while(low <= high){ */
/*             mid = (low+high)/2; */
/*             // < vs <=?? */
/*             // >= -> better */
/*             // xd, no mid used */
/*             /1* if(x->m+x->b >= y->m+y->b){ *1/ */
/*             if(x->m*mid+x->b >= y->m*mid+y->b){ */
/*                 // prev better -> trzeba dalej */
/*                 low = mid + 1; */
/*             } */
/*             else{ */
/*                 high = mid - 1; */
/*                 ans = mid; */
/*             } */
/*         } */
/*         whatis(x->m) */
/*         whatis(x->b) */
/*         whatis(y->m) */
/*         whatis(y->b) */
/*         /1* assert(~ans); *1/ */
/*         /1* assert(ans != LONG_LONG_MAX); *1/ */
/*         // XDDD, legit -1 wynik wyszed na 2nd samplu, ale fart XD */
/*         // -> RTE6 though */
/*         // (but better than wa3 def) */
/*         // */
/*         return ans; */
/*     } */
/*     bool bad(iterator y){ */
/*         auto nx = next(y); */
/*         if(y == begin()){ */
/*             if(nx == end()) return 0; */
/*             /1* return y->m == nx->m && y->b <= nx->b; *1/ */
/*             /1* bool sth1 = pr->m*mx+pr->b >= y->m*mx+y->b && pr->m*-mx+pr->b >= y->m*-mx+y->b; *1/ */
/*             bool sth2 = nx->m*mx+nx->b >= y->m*mx+y->b && nx->m*-mx+nx->b >= y->m*-mx+y->b; */
/*             return sth2; */
/*             // -> te git at least)) */
/*         } */
/*         auto pr = prev(y); */
/*         if(nx == end()){ */
/*             /1* return y->m == pr->m && y->b <= pr->b; *1/ */
/*             bool sth1 = pr->m*mx+pr->b >= y->m*mx+y->b && pr->m*-mx+pr->b >= y->m*-mx+y->b; */
/*             return sth1; */
/*             // -> te git at least)) */
/*         } */
/*         //to cza pamita, zawsze najpierw m i b, w 1. najpierw nx potem pr, */
/*         //potem na odwrt i na odwrt kolejno z y */
/*         //?OVERFLOW? */
/*         /1* return (nx->m-y->m)*(pr->b-y->b) >= (y->m-pr->m)*(y->b-nx->b); *1/ */
/*         // test if that's needed */
/*         /1* return (double)(nx->m-y->m)*(pr->b-y->b) >= (double)(y->m-pr->m)*(y->b-nx->b); *1/ */
/*         // -> wa after rem:v */
/*         /1* return (nx->m-y->m)/(y->b-nx->b) >= (y->m-pr->m)/(pr->b-y->b); *1/ */
/*         // alternative on range?: */
/*         bool sth1 = pr->m*mx+pr->b >= y->m*mx+y->b && pr->m*-mx+pr->b >= y->m*-mx+y->b; */
/*         bool sth2 = nx->m*mx+nx->b >= y->m*mx+y->b && nx->m*-mx+nx->b >= y->m*-mx+y->b; */
/*         if(sth1 || sth2) */
/*             return true; */
/*         /1* return sth1 || sth2; *1/ */
/*         // -> nope */
/*         // can chg into finding intersections between pr and y; y and nx, and */
/*         // checking if latter intersection is b4 this one? */
/*         ll i1 = intersect(pr,y); */
/*         ll i2 = intersect(y,nx); */
/*         return i2 < i1; */
/*         /1* return i1 == LONG_LONG_MAX || i2 < i1; *1/ */
/*         // ^^ pls make sense */
/*         // -> wtf, tle XD */
/*     } */
/*     void insert_line(ll m, ll b){ */
/*         auto y = insert({m,b}); */
/*         // [=] */
/*         y->succ = [=]{return next(y) == end() ? 0 : &*next(y);}; //referencja nie iterator */
/*         if(bad(y)){ */
/*             erase(y); */
/*             return; */
/*         } */
/*         while(y != begin() && bad(prev(y))){ */
/*             erase(prev(y)); */
/*         } */
/*         while(next(y) != end() && bad(next(y))){ */
/*             erase(next(y)); */
/*         } */
/*     } */
/*     ll eval(ll x){ */
/*         auto l = *lower_bound((Line){x,is_qu}); */
/*         return l.m*x+l.b; */
/*     } */
/* }; */

struct Line {
    mutable ll m, b, p;
    bool operator<(const Line &o) const { return m < o.m; }
    bool operator<(const ll &x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> { // upper convex hull.
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) {
            x->p = inf;
            return false;
        }
        if (x->m == y->m)
            x->p = x->b > y->b ? inf : -inf;
        else
            x->p = div(y->b - x->b, x->m - y->m);
        return x->p >= y->p;
    }
    /* void add(ll m, ll b) { */
    void insert_line(ll m, ll b) {
        auto z = insert({m, b, 0}), y = z++, x = y;
        while (isect(y, z))
            z = erase(z);
        if (x != begin() && isect(--x, y))
            isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    /* ll query(ll x) { */
    ll eval(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.m * x + l.b;
    }
};


int a[100000],b[100000];
vi adj[100000];
ll dp[100000];

/* hull st[100000]; */
LineContainer st[100000];
int it;

int d1(int v, int p){
    vi its;
    int wh = -1;
    FORR(i,adj[v]){
        if(i == p) continue;
        its.pb(d1(i,v));
    }
    sort(all(its),[&](int &f, int &s){return st[f].size() > st[s].size();});
    if(its.empty()){
        dp[v] = 0;
        wh = it;
        st[wh].insert_line(b[v],-dp[v]);
        ++it;
        return wh;
    }
    wh = its[0];
    FOR(i,1,its.size()){
        FORR(x,st[its[i]]){
            st[wh].insert_line(x.m,x.b);
        }
        st[its[i]].clear();
    }
    dp[v] = -st[wh].eval(-a[v]);
    st[wh].insert_line(b[v],-dp[v]);
    return wh;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    FOR(i,0,n)
        sc(a[i]);
    FOR(i,0,n)
        sc(b[i]);
    int f,s;
    FOR(i,1,n){
        sc(f,s);
        --f,--s;
        adj[f].pb(s);
        adj[s].pb(f);
    }
    d1(0,-1);
    FOR(i,0,n){
        cout << dp[i] << ' ';
    }
}