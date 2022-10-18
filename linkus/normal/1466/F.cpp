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

int size[N];
int link[N];
bool jeden[N];
vi wh[N];

inline int find(int a){
    while(a != link[a]) a = link[a];
    return a;
}

inline void unite(int a, int b){ //a and b are after find() //or not, whatever
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(::size[a] < ::size[b]) swap(a,b);
    ::size[a] += ::size[b];
    FORR(i,wh[b])
        wh[a].pb(i);
    jeden[a] |= jeden[b];
    link[b] = a;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i = 0; i < N; ++i){
        link[i] = i;
        ::size[i] = 1;
    }
    int n,m;
    sc(n,m);
    FOR(i,0,n){
        int k;
        sc(k);
        int f,s;
        sc(f);
        --f;
        if(k == 1){
            int ff = find(f);
            /* jeden[ff] |= 1; */
            if(!jeden[ff]){
                jeden[ff] = 1;
                wh[ff].pb(i+1);
            }
        }
        else{
            sc(s);
            --s;
            int ff = find(f);
            int ss = find(s);
            // i nie cae zapenione jedynkami i guess?
            // czyli jak ktores (>= 1) nie ma jeden wsm
            /* if(ff != ss){ */
            if(ff != ss && jeden[ff] + jeden[ss] <= 1){
                wh[ff].pb(i+1);
                unite(ff,ss);
            }
        }
    }
    vi sp;
    /* bool vis[n]; */
    /* memset(vis,0,n); */
    /* FOR(i,0,n){ */
    // nice bug btw, thx 3rd sample
    bool vis[m];
    memset(vis,0,m);
    FOR(i,0,m){
        int fi = find(i);
        if(vis[fi]) continue;
        vis[fi] = 1;
        /* whatis(fi) */
        /* whatis(wh[fi]) */
        /* if(!jeden[fi]) continue; */
        // jeden -> x2 sort of
        // -> wsm wh size ma znaczene
        FORR(x,wh[fi]){
            sp.pb(x);
        }
    }
    ll res1 = 1;
    /* FOR(i,1,sp.size()){ */
    FOR(i,0,sp.size()){
        res1 <<= 1;
        res1 %= 1000000007;
    }
    cout << res1 << ' ' << sp.size() << '\n';
    /* cout << sp.size() << '\n'; */
    sort(all(sp));
    FORR(i,sp)
        cout << i << ' ';
    cout << '\n';
    // -> wa5 xd rip
    // XD, bo output musi by posortowany, wtf xd
}