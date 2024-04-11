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
template<class T> ostream& operator<<(ostream &os, deque<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
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

using T = int;
struct Flow{
    struct E{
        int dest;
        T orig, *lim, *rev;
    };
    int zr,uj,n=0;
    vector<unique_ptr<T>> ts;
    vector<vector<E>> graf;
    vector<int> ptr, odl;
    void vert(int v){
        n = max(n,v+1);
        graf.resize(n);
        ptr.resize(n);
        odl.resize(n);
    }
    bool iszero(T v){
        return !v; //zmien dla doubli
    }
    void bfs(){
        fill(odl.begin(),odl.end(),0);
        vector<int> kol = {zr};
        odl[zr] = 1;
        for(int i = 0; i < (int)kol.size(); ++i){
            for(E &e: graf[kol[i]]){
                if(!odl[e.dest] && !iszero(*e.lim)){
                    odl[e.dest] = odl[kol[i]]+1;
                    kol.push_back(e.dest);
                }
            }
        }
    }
    T dfs(int v, T lim){
        if(v == uj) return lim;
        T ret = 0, wez;
        for(int &i = ptr[v] ; i < (int) graf[v].size(); ++i){
            E& e = graf[v][i];
            if(odl[e.dest] == odl[v]+1 && !iszero(*e.lim) && !iszero(wez = dfs(e.dest,min(*e.lim,lim)))){
                ret += wez;
                *e.lim -= wez;
                *e.rev += wez;
                lim -= wez;
                if(iszero(lim)) break;
            }
        }
        return ret;
    }
    void add_edge(int u, int v, T lim, bool bi = false /* bidirectional?*/){
        vert(max(u,v));
        T *a = new T(lim), *b = new T(lim*bi);
        ts.emplace_back(a);
        ts.emplace_back(b);
        graf[u].push_back({v,lim,a,b});
        graf[v].push_back({u,lim*bi,b,a});
    }
    T dinic(int zr_, int uj_){
        zr = zr_; uj = uj_;
        vert(max(zr,uj));
        T ret = 0;
        while(true){
            bfs();
            fill(ptr.begin(),ptr.end(),0);
            const T sta = dfs(zr,numeric_limits<T>::max());
            if(iszero(sta)) break;
            ret += sta;
        }
        return ret;
    }
    vector<int> cut(){
        vector<int> ret;
        bfs();
        for(int i = 0; i < n; ++i)
            if(odl[i])
                ret.push_back(i);
        return ret;
    }
    map<pair<int,int>,T> get_flowing(){
        map<pair<int,int>,T> ret;
        for(int i = 0; i < n; ++i)
            for(E& e: graf[i])
                if(*e.lim < e.orig)
                    ret[make_pair(i,e.dest)] += e.orig - *e.lim;
        for(auto &i: ret){
            const pair<int,int> rev(i.first.second,i.first.first);
            const T x = min(i.second,ret[rev]);
            i.second -= x;
            ret[rev] -= x;
        }
        return ret;
    }
};

bool ispr(int v){
    for(int i = 2; i*i <= v; ++i)
        if(v%i == 0) return 0;
    return 1;
}

vi adj[N];
bool vis[N];
vector<deque<int>> ans;

void d1(int v){
    vis[v] = 1;
    ans.back().push_back(v);
    FORR(i,adj[v]){
        if(vis[i]) continue;
        d1(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    int a[n];
    GET(a);
    Flow fw;
    fw.vert(n+2);
    int xd = 0;
    FORR(i,a)
        xd += vector<int>{-1,1}[i&1];
    if(xd) REE("Impossible")
    FOR(i,0,n){
        if(a[i]%2 == 0){
            fw.add_edge(i,n+1,2);
            continue;
        }
        fw.add_edge(n,i,2);
        FOR(x,0,n){
            if(a[x]%2 == 1) continue;
            int nw = a[i]+a[x];
            if(ispr(nw)){
                fw.add_edge(i,x,1);
            }
        }
    }
    int ret = fw.dinic(n,n+1);
    if(ret != n) REE("Impossible")
    /* whatis(fw.cut()) */
    auto st = fw.get_flowing();
    /* whatis(st) */
    int where[n];
    memset(where,-1,n<<2);
    FOR(i,0,n){
        if(a[i]%2 == 0){
            continue;
        }
        whatis(i)
        whatis(ans)
        vi wh;
        FOR(x,0,n){
            if(a[x]%2 == 1){
                continue;
            }
            if(st[mp(i,x)])
                wh.push_back(x);
        }
        FORR(x,wh){
            adj[i].pb(x);
            adj[x].pb(i);
        }
    }
    FOR(i,0,n){
        if(!vis[i]){
            ans.pb({});
            d1(i);
        }
    }
    cout << ans.size() << '\n';
    FORR(i,ans){
        cout << i.size();
        FORR(x,i)
            cout << ' ' << x+1;
        cout << '\n';
    }
}