#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = (arr).rbegin()+(plus); x !=(arr).rend(); ++x)
#define REE(s_) {cout<<s_<<'\n';exit(0);}
#define GETCIN(arr) for(auto &i: (arr)) cin>>i
#define GET(arr) for(auto &i: (arr)) sc(i)
#define GETSTR(arr) for(auto &i: (arr)) getstr(i)
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

vector<int> adj[500];
vector<vector<int>> scc;
int which[500];
int dfs_low[500], dfs_num[500];
stack<int> st;

int it = 0;

void dfs1(int cur){
    st.push(cur);
    dfs_low[cur] = dfs_num[cur] = ++it;
    FORR(i,adj[cur]){
        if(!dfs_num[i]){
            dfs1(i);
        }
        dfs_low[cur] = min(dfs_low[cur], dfs_low[i]);
    }
    if(dfs_low[cur] == dfs_num[cur]){
        if(st.top() != cur){
            scc.push_back({});
            loop:
                int v = st.top(); st.pop();
                scc.back().push_back(v);
                which[v] = scc.size()-1;
                dfs_low[v] = 0x7f7f7f7f; //VERY IMPORTANT
                if(v != cur)
                    goto loop;
        }
        else{
            dfs_low[cur] = 0x7f7f7f7f;
            st.pop();
        }
    }
}
int nvis[500];

int curcnt;

int dfs3(int cur){
    nvis[cur] = 1;
    FORR(i,adj[cur]){
        if(!~i) continue;
        if(nvis[i] == 1) return 1;
        if(!nvis[i]){
            if(dfs3(i) == 1) return 1;
        }
    }
    nvis[cur] = 2;
    return 0;
}

/* void dfs3(int cur){ */
/*     vis[cur] = 1; */
/*     FORR(i,adj2[cur]){ */
/*         if(!~i) continue; */
/*         if(!vis[i]){ */
/*             dfs3(i); */
/*         } */
/*     } */
/*     ++curcnt; */
/* } */


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(which,127,2000);
    int n,m;
    sc(n,m);
    int f,s;
    static bool mat[500][500];
    bool alr = 0;
    pi disc;
    while(m--){
        sc(f,s);
        --f, --s;
        if(mat[s][f]){
            if(alr) REE("NO")
            alr = 1;
            disc = {f,s};
        }
        else{
            adj[f].pb(s);
            mat[f][s] = mat[s][f] = 1;
        }
    }
    FOR(i,0,n){
        if(!dfs_num[i]){
            dfs1(i);
        }
        /* cerr << i << ": dfs_num = " << dfs_num[i] << " dfs_low = " << dfs_low[i] << '\n'; */
    }
    /* whatis(scc) */
    if(scc.size() > 1) REE("NO")
    if(scc.empty()) REE("YES")
    if(alr){
        adj[disc.e2].erase(find(all(adj[disc.e2]),disc.e1));
        adj[disc.e1].pb(disc.e2);
        FOR(i,0,n){
            if(!nvis[i]){
                if(dfs3(i)){
                    REE("NO")
                }
            }
        }
        REE("YES")
    }
    FOR(i,0,n)
        sort(all(adj[i]));
    pi r;
    vi tmp = scc[0];
    vi scc = tmp;
    for(int i = 0; i < (int)scc.size(); ++i){
        for(auto it = adj[scc[i]].begin(); it < adj[scc[i]].end(); ++it){
            if(!which[*it]){
                bool g = 1;
                r = {scc[i], *it};
                int s = *it;
                *it = -1;
                /* auto someit = lower_bound(all(adj2[s]),scc[i]); */
                /* *someit = -1; */
                /* adj[scc[i]].erase(it); */
                /* adj2[s].erase(find(all(adj2[s]),scc[i])); */
                /* sid = n; */
                /* memset(vis,0,500); */
                /* FOR(i,0,n){ */
                /*     if(!vis[i]){ */
                /*         dfs1(i); */
                /*     } */
                /* } */
                memset(nvis,0,2000);
                FORR(i,scc){
                    if(!nvis[i]){
                        if(dfs3(i)){
                            g = 0; break;
                        }
                        /* if(curcnt > 1){ */
                        /*     g = 0; break; */
                        /* } */
                    }
                }
                if(g) REE("YES")
                *it = s;
                /* *someit = scc[i]; */
                /* adj[r.e1].pb(r.e2); */
                /* adj2[r.e2].pb(r.e1); */
            }
        }
    }
    cout << "NO";
}