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

int n;
vector<pi> ops;
int a[N];
vi wr;
void swp(int f, int s){
    assert(f != s);
    if(f > s) swap(f,s);
    /* whatis(f) */
    /* whatis(s) */
    /* whatis(ops) */
    int ds = abs(f-s);
    /* whatis(f*2) */
    /* whatis(n) */
    if(2*ds >= n){
        ops.pb({f,s});
        swap(a[f],a[s]);
        return;
    }
    if(s*2 <= n){ //leftwise both
        ops.pb({f,n});
        ops.pb({s,n});
        ops.pb({f,n});
    }
    else if(f*2 > n){ //rightwise both
        ops.pb({f,1});
        ops.pb({s,1});
        ops.pb({f,1});
    }
    else{ //diff
        ops.pb({f,n});
        ops.pb({s,1});
        ops.pb({1,n});
        ops.pb({f,n});
        ops.pb({s,1});
    }
    swap(a[f],a[s]);
    /* whatis(ops) */
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n);
    FORE(i,1,n){
        sc(a[i]);
        if(i != a[i]) wr.pb(i);
    }
    while(!wr.empty()){
        int cr = wr.back();
        wr.pop_back();
        if(a[cr] == cr) continue;
        swp(a[cr],cr);
        if(a[cr] != cr)
        wr.pb(cr);
    }
    /* FORE(i,1,n){ */
        /* whatis(i) */
        /* whatis(a[i]) */
        /* if(a[i] != i){ */
        /*     swp(i,a[i]); */
        /* } */
        /* whatis(i) */
        /* whatis(a[i]) */
    /* } */
    FORE(i,1,n){
        /* whatis(i) */
        /* whatis(a[i]) */
        assert(a[i] == i);
    }
    assert(ops.size() <= 5*n); ///gooood
    cout << ops.size() << '\n';
    FORR(i,ops){
        assert(abs(i.e1-i.e2)*2 >= n);
        cout << i.e1 << ' ' << i.e2 << '\n';
    }
}