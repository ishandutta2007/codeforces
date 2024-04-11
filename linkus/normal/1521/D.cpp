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

vi adj[N];
vector<pi> rem;
set<pi> remd;

pi sth(int f, int s){
    if(f > s)
        swap(f,s);
    return {f, s};
}

void d1(int v, int p){
    /* int cnt = 0; */
    int cnt = p != -1;
    FORR(i,adj[v]){
        if(i == p)
            continue;
        /* d1(0, -1); */ // lol?
        d1(i, v);
        /* if(++cnt > 2){ */
        if(!remd.count(sth(i,v)) && ++cnt > 2){
            // the fix:
            /* if(cnt == 3){ */
            if(cnt == 3 && p != -1){
                rem.push_back({v, p});
                remd.insert(sth(v, p));
            }
            else{
                rem.push_back({v, i});
                remd.insert(sth(v, i));
            }
        }
    }
}

vi cr; // deg 1 ones.
// czy ever deg0? mooe. yeah, jak star init.
// -> test that.
bool vis[N];
void d2(int v, int p){
    vis[v] = 1;
    int deg = p != -1;
    FORR(i,adj[v]){
        if(remd.count(sth(v, i)))
            continue;
        if(i == p)
            continue;
        assert(!vis[i]);
        ++deg;
        d2(i, v);
    }
    if(deg <= 1)
        cr.push_back(v);
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        int n;
        sc(n);
        memset(vis, 0, n);
        rem.clear();
        remd.clear();
        FOR(i,0,n)
            adj[i].clear();
        FOR(i,1,n){
            int f,s;
            sc(f,s);
            --f,--s;
            adj[f].pb(s);
            adj[s].pb(f);
        }
        d1(0, -1);
        vector<vi> comps;
        FOR(i,0,n){
            if(!vis[i]){
                cr.clear();
                d2(i, -1);
                assert(cr.size() >= 1 && cr.size() <= 2);
                comps.push_back(cr);
            }
        }
        vector<pi> add;
        FOR(i,1,comps.size()){
            /* add.push_back({comps[i][0], comps[i-1][0]}); */
            add.push_back({comps[i].back(), comps[i-1][0]});
        }
        cout << rem.size() << '\n';
        assert(add.size() == rem.size());
        FOR(i,0,rem.size()){
            cout << rem[i].e1 + 1 << ' ' << rem[i].e2 + 1 << ' ' << add[i].e1 + 1 << ' ' << add[i].e2 + 1 << '\n';
        }
    }
}