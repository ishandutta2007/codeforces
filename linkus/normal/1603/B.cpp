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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        ll x,y;
        sc(x,y);
    /* for(int x = 2; x <= 1000; x += 2){ */
    /* for(int y = 2; y <= 1000; y += 2){ */
        /* ll gc = __gcd(x,y); */
        /* ll n; */
        /* /1* if(gc != 1) *1/ */
        /* /1*     n = gc; *1/ */
        /* /1* else *1/ */
        /* /1*     n = x * 1000000007 + y; *1/ */
        /* n = x * 1000000007 + y; */
        /* /1* assert(x * 1000000007 *1/ */
        /* /1* cout << x * 1000000007 + y << '\n'; *1/ */
        /* /1* if(y > x){ *1/ */
        /* whatis(n) */
        /* whatis(x) */
        /* whatis(y) */
        /* assert(n % x == y % n); */
        if(y < x){
            ll n = x + y;
            assert(n % x == y % n);
            cout << n << '\n';
        }
        else if(y == x){
            ll n = x;
            assert(n % x == y % n);
            cout << n << '\n';
        }
        else if(y % x == 0){
            ll n = y;
            assert(n % x == y % n);
            cout << n << '\n';
        }
        else{
            /* ll n = y; */
            ll n;
            /* vector<ll> cands{y,x,x+y,(x+y)/2,(x+y)/2-y,(x+y)/2+y,(x+y)/2+y/2, (x+y)/2+1, (x+y)/2-1, (x+y)/2-x/2, (x+y)/2-x}; */
            // close.
            /* vector<ll> cands{y,x,x+y,(x+y)/2,(x+y)/2-y,(x+y)/2+y,(x+y)/2+y/2, (x+y)/2+1, (x+y)/2-1, (x+y)/2-x/2, (x+y)/2-x, (x+y)/2-(y%x), (x+y)/2-(y%x)/2, (y%x)/2, y%x, (x+y+y%x)/2, (x+y+y%x*2)/2}; */
            // k, nvm.
            n = y - (y % x) / 2;
            /* if(min(x,y) <= 20 || x == 22 && y == 68) */
            /* FOR(t,1,y){ */
            /* FORR(t,cands){ */
            /*     if(t <= 0) */
            /*         continue; */
            /*     n = t; */
            /*     if(n % x == y % n) */
            /*         break; */
            /* } */
            /* while(n % x != y % n){ */
            /*     n = rand()%y+1; */
            /* } */
            /* else */
            /*     n = (x + y) / 2; */
            /* ll n = y - x; */
            /* ll n = y % x; */
            /* ll n = (y - x) / 2; */
            /* ll n = __gcd(x,y); // 4 6 rip. */
            /* ll n = __gcd(x,y) / 2; */
            /* whatis(n) */
            assert(n % x == y % n);
            cout << n << '\n';
        }
    /* } */
    }
}