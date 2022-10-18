#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ssize(x) int(x.size())
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define FORR(x,arr) for(auto &x: arr)
#define REE(s_) {cout<<s_<<'\n';exit(0);}
#define GET(arr) for(auto &i: (arr)) sc(i)
#define e1 first
#define e2 second
#define INF 0x7f7f7f7f
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "),...); }(x), cerr << '\n'
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
typedef uint64_t ull;
using namespace std;
using namespace __gnu_pbds;

#ifdef ONLINE_JUDGE
#define debug(...) {}
#endif
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) { return o << '(' << p.first << ", " << p.second << ')'; }
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) { o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}'; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// 1 << 19 if segtree where merges matter.
#define N 1000001

int v22;
int v11;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        int n,m;
        sc(n,m);
        vector<pi> adj[n];
        bool ass[m];
        memset(ass,0,m);
        pi edg[m];
        FOR(i,0,m-1){
            int f,s;
            sc(f,s);
            --f,--s;
            edg[i] = {f,s};
            adj[f].push_back({s,i});
            adj[s].push_back({f,i});
        }
        bool vis[n];
        memset(vis,0,n);
        function<void(int)> dfs = [&](int v) -> void{
            vis[v] = 1;
            FORR(i,adj[v]){
                if(!vis[i.e1]){
                    dfs(i.e1);
                    ass[i.e2] = 1;
                }
            }
        };
        dfs(0);
        if(m == n + 2){
            set<int> st;
            int cn = 0;
            int wh = -1;
            FOR(i,0,m-1){
                if(!ass[i]){
                    ++cn;
                    st.insert(edg[i].e1);
                    st.insert(edg[i].e2);
                    wh = i;
                }
            }
            /* assert(cn == 3); */
            if(st.size() == 3){
                /* FORR(i,adj[edg[wh].e1]){ */
                /*     if(ass[i.e2]){ */
                        /* debug("swp", i.e2, wh); */
                        /* auto [v1,v2] = edg[i.e2]; */
                        auto [v1,v2] = edg[wh];
                        v22 = v2;
                        v11 = v1;
                        debug("swp", wh, v11, v22);
                        function<bool(int, int)> othdfs = [&](int v, int p) -> bool{
                            if(v == v22)
                                return 1;
                            FORR(i,adj[v]){
                                /* if(!vis[i.e1]){ */
                                if(!ass[i.e2]) continue;
                                if(p != i.e1){
                                    if(othdfs(i.e1, v)){
                                        if(v == v11){
                                            v22 = i.e2;
                                        }
                                        return 1;
                                    }
                                }
                            }
                            return 0;
                        };
                        assert(othdfs(v1, -1));
                        debug("swp", wh, v11, v22);
                        /* assert(v22 != wh); */
                        swap(ass[v22], ass[wh]);
                        /* swap(ass[i.e2], ass[wh]); */
                        /* swap(ass[i.e2], ass[wh]); */
                                set<int> st;
                                int cn = 0;
                                int wh = -1;
                                FOR(i,0,m-1){
                                    if(!ass[i]){
                                        ++cn;
                                        st.insert(edg[i].e1);
                                        st.insert(edg[i].e2);
                                        wh = i;
                                    }
                                }
                                /* assert(cn == 3); */
                                /* assert(st.size() == 4); */
                        /* break; */
                    /* } */
                /* } */
            }
            else{
                /* assert(st.size() == 4); */
            }
        }
        FORR(i,ass)
            cout << i;
        cout << '\n';
    }
}