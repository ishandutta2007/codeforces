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

bool bloc[N];
vector<int> adj[N];
int child[N];
int ch2[N]; //wzgldem centroid roota
int mn[N]; //min from centroid
vi adj2[N]; //centroid tree
int root = -1; //centroid root
vector<pair<int,int>> upc[N]; //all centroids this+higher {node,distance to it}

//numer of paths with weight equal 0

//holding it like this + sort is WAY fater than maps

void pre(int v, int p){
    child[v] = 1;
    FORR(i,adj[v]){
        if(i == p) continue;
        pre(i,v);
        child[v] += child[i];
    }
}

void decomp(int v, int p){ //to get adj2 -> centroid tree
    int nd2 = child[v]/2;
    int wh = -1;
    FORR(i,adj[v]){
        if(child[i] > nd2){
            wh = i;
            break;
        }
    }
    if(~wh){
        child[wh] = child[v];
        child[v] = 1;
        FORR(i,adj[v]){
            if(i == wh) continue;
            child[v] += child[i];
        }
        decomp(wh,p);
    }
    else{
        if(!~root) root = v;
        else adj2[p].push_back(v);
        child[v] = 0;
        FORR(i,adj[v]){
            if(!child[i]) continue;
            decomp(i,v);
        }
    }
}

void dfs2(int v, int p, int c, int d){
    upc[v].push_back({c,d});
    FORR(i,adj[v]){
        if(i == p || bloc[i]) continue;
        dfs2(i,v,c,d+1);
    }
}

void gocent(int v){
    dfs2(v,-1,v,0);
    bloc[v] = 1;
    FORR(i,adj2[v]){
        gocent(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,q;
    sc(n,q);
    int f,s;
    FOR(i,1,n){
        sc(f,s);
        --f,--s;
        adj[f].pb(s);
        adj[s].pb(f);
    }
    pre(0,-1);
    decomp(0,-1);
    gocent(root);
    memset(mn,127,n << 2);
    FORR(i,upc[0])
        mn[i.e1] = min(mn[i.e1],i.e2);
    int typ,nod;
    FOR(i,0,q){
        /* whatis(i) */
        sc(typ,nod);
        --nod;
        if(typ == 1){
            /* whatis(upc[nod]) */
            FORR(i,upc[nod]){
                /* whatis(i) */
                mn[i.e1] = min(mn[i.e1],i.e2);
            }
        }
        else{
            int ans = INF;
            FORR(i,upc[nod]){
                ans = min(ans,mn[i.e1]+i.e2);
            }
            cout << ans << '\n';
        }
    }
}