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
#define INF 0x7F7F7F7F //2139062143 | 127 in memset -> memset(arr,127,size)
#define SINF 1061109567 //Safe INF, for graphs or 2d arrays 63 in memset(arr,63,size)
#define LL_INF 7234017283807667300 //100 in memset(arr,100,size) !!!must be LL
#define whatis(x) cerr << #x << " is " << x << endl;
#define e1 first
#define e2 second
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
#define umap unordered_map
#define uset unordered_set
using namespace std;
using namespace __gnu_pbds;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
template<typename T> inline void print_128(T num){ if(!num) return; print_128(num / 10); cout.put((num % 10) + '0'); }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<int> adj[100000];
int depth[100000];
int pre[100000][20];
int preV[100000];

void dfs(int cur, int prev){
    depth[cur] = (~prev?depth[prev]+1:0);
    if(cur){
        pre[cur][0] = prev;
        for(int i = 1; i < 20; ++i){
            if(!pre[cur][i-1]) break;
            pre[cur][i] = pre[pre[cur][i-1]][i-1];
        }
        preV[cur] = prev;
    }
    FORR(i,adj[cur]){
        if(i != prev)
            dfs(i,cur);
    }
}

int anc(int cur, int step){
    for(int i = 0; i < 20; ++i){
        if((1 << i) & step){
            cur = pre[cur][i];
            if(!cur) break;
        }
    }
    return cur;
}

int lca(int f, int s){
    int df = depth[f], ds = depth[s];
    if(df > ds) swap(df,ds), swap(f,s);
    /* whatis(f) */
    /* whatis(s) */
    /* whatis(df) */
    /* whatis(ds) */
    int nf = f, ns = anc(s, ds - df);
    while(nf != ns){
        nf = preV[nf];
        ns = preV[ns];
    }
    /* whatis(nf) */
    return nf;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,q,in[3],cur;
    sc(n,q);
    for(int i = 1; i < n; ++i){
        sc(cur);
        --cur;
        /* adj[i].pb(cur); */
        adj[cur].pb(i);
    }
    dfs(0,-1);
    /* whatis(lca(2,3)) */
    /* whatis(anc(2,2)) */
    /* return 0; */
    while(q--){
        sc(in[0],in[1],in[2]);
        --in[0], --in[1], --in[2];
        sort(in,in+3);
        int bs = 1;
        do{
            int f = in[0], s = in[1], t = in[2];
            bool is1 = lca(f,s) ==  f, is2 = lca(f,t) == f;
            if(is1!=is2) continue;
            if(is1)
                bs = max(bs, depth[lca(s,t)] - depth[f]+1);
            else if(lca(f,s) != lca(f,t))
                bs = max(bs, depth[f] - max(depth[lca(f,s)], depth[lca(f,t)]) + 1);
            else
                bs = max(bs, depth[f] + depth[lca(s,t)] - 2 * depth[lca(f,t)] + 1);
        }while(next_permutation(in,in+3));
        cout << bs << '\n';
    }
}