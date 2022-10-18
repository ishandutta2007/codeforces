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
int d[N];
bool vis[N];
vi adj2[N];
map<pi, bool> vl;

pi sth(int f, int s){
    if(f > s)
        swap(f,s);
    return pi{f,s};
}

void d1(int v, int p){
    vis[v] = 1;
    FORR(i,adj[v]){
        if(i == p)
            continue;
        if(vis[i])
            continue;
        d[i] = d[v] + 1;
        d1(i, v);
        adj2[v].push_back(i);
        adj2[i].push_back(v);
    }
}

vector<vi> paths;

bool d2(int v, int p, int tg){
    if(v == tg){
        paths.back().push_back(v);
        return 1;
    }
    FORR(i,adj2[v]){
        if(i == p)
            continue;
        bool rt = d2(i, v, tg);
        if(rt){
            paths.back().push_back(v);
            vl[sth(v, i)] ^= 1;
            return 1;
        }
    }
    return 0;
}

pi dp[N]; // {subres, goesup}
void d3(int v, int p){
    int iletera = 0;
    FORR(i,adj2[v]){
        if(i == p)
            continue;
        d3(i, v);
        dp[v].e1 += dp[i].e1;
        iletera += dp[i].e2;
    }
    /* if(p != -1){ */
    /*     if(vl[sth(v, p)]){ */
    /*         ++iletera; */
    /*     } */
    /* } */
    /* dp[v].e1 += iletera / 2; // aren't those already priced in? */
    // -> na odwrt? xd
    dp[v].e1 -= iletera / 2;
    bool added = 0;
    if(p != -1){
        if(vl[sth(v, p)]){
            /* ++iletera; */
            /* added = 1; */
            if(iletera % 2 == 0){
                ++iletera;
                added = 1;
            }
        }
        // omg, wait, reset do 0 otherwise.
        else{
            iletera = 0;
        }
    }
    iletera &= 1;
    // tylko jak faktycznie dodaem nowy i guess.
    /* dp[v].e1 += iletera; */
    if(added)
        dp[v].e1 += iletera;
    dp[v].e2 = iletera;
    /* whatis(v) */
    /* whatis(dp[v]) */
    /* whatis(added) */
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    sc(n,m);
    FOR(i,0,m){
        int f,s;
        sc(f,s);
        --f,--s;
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    d1(0, -1);
    int q;
    sc(q);
    FOR(_,0,q){
        int f,s;
        sc(f,s);
        --f,--s;
        paths.push_back({});
        /* reverse(all(paths.back())); */
        assert(d2(f, -1, s));
        reverse(all(paths.back()));
    }
    bool kk = 1;
    FORR(i,vl){
        kk &= i.e2 == 0;
    }
    if(kk){
        cout << "YES\n";
        FORR(i,paths){
            cout << i.size() << '\n';
            FORR(x,i)
                cout << x + 1 << ' ';
            cout << '\n';
        }
    }
    else{
        cout << "NO\n";
        d3(0, -1);
        cout << dp[0].e1 << '\n';
    }
}