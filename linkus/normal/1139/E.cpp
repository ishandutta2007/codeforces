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
#define N 6000

vi adj[N*2];
bool vis[N*2];
int assign[N*2];
int assigndig[N*2];

bool aug(int cur){
    if(vis[cur]) return 0;
    vis[cur] = 1;
    FORR(i,adj[cur]){
        /* if(assign[i] == cur) return 1; */
        if(assign[i] == -1 || aug(assign[i])){
            assign[i] = cur;
            assigndig[cur] = i;
            /* assign[i] = cur; */
            return 1;
        }
    }
    /* if(adj[cur].size() && assign[adj[cur][0]] > cur){ */
    /*     assign[adj[cur][0]] = cur; */
    /*     return 1; */
    /* } */
    /* FORR(i,adj[cur]){ */
    /*     if(assign[i] == -1 || aug(assign[i])){ */
    /*         assign[i] = cur; */
    /*         /1* assign[i] = cur; *1/ */
    /*         return 1; */
    /*     } */
    /* } */
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    sc(n,m);
    pair<int,int> st[n];
    int il[m][5000];
    memset(il,0,sizeof il);
    FOR(i,0,n){
        sc(st[i].e1);
    }
    FOR(i,0,n){
        sc(st[i].e2);
        if(++il[--st[i].e2][st[i].e1] == 1){
            /* adj[N+st[i].e2].pb(st[i].e1); */
            adj[st[i].e1].pb(N+st[i].e2);
        }
    }
    FORR(i,adj){
        sort(all(i),greater<int>());
    }
    int d;sc(d);
    int wh;
    int bs = 0;
    memset(assigndig,-1,sizeof assign);
    memset(assign,-1,sizeof assign);
    for(int i = 0; i <= n; ++i){
        memset(vis,0,sizeof vis);
        if(!aug(i)){
            /* whatis(i) */
            bs = i;
            break;
        }
    }
    int itt = bs;
    FOR(xddx,0,d){
        sc(wh);
        --wh;
        if(!--il[st[wh].e2][st[wh].e1]){
            /* adj[st[wh].e2+N].erase(find(all(adj[st[wh].e2+N]),st[wh].e1)); */
            adj[st[wh].e1].erase(find(all(adj[st[wh].e1]),st[wh].e2+N));
            /* whatis(st[wh].e1) */
            if(assign[st[wh].e2+N] == st[wh].e1){
                assigndig[assign[st[wh].e2+N]] = -1;
                assign[st[wh].e2+N] = -1;
                ++itt;
                do{
                    --itt;
                    if(itt <= st[wh].e1) break;
                    if(itt <= 0) break;
                    memset(vis,0,sizeof vis);
                    assign[assigndig[itt]] = -1;
                    assigndig[itt] = -1;
                }while(!aug(st[wh].e1));
                vi xd;
                FOR(i,0,m){
                    if(~assign[N+i])
                        xd.push_back(assign[N+i]);
                }
                sort(all(xd));
                if(xd.empty()){
                    bs = 0;
                }
                else{
                    bs = xd.back()+1;
                    if(xd[0]) bs = 0;
                    else
                    FOR(i,1,xd.size()){
                        if(xd[i]-1 > xd[i-1]){
                            bs = xd[i]-1;
                            break;
                        }
                    }
                }
            }
            /* int xd; */
            /* FOR(i,0,123123){ */
            /*     if( */
            /* } */
            /* for(int i = 0; i < n; ++i){ */
            /*     aug(i); */
            /*     /1* mf += aug(i); *1/ */
            /* } */
        }
        cout << bs << '\n';
    }
}