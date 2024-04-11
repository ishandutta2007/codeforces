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
#define whatis(x) cerr << #x << " is " << x << endl;
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
#define N 100001 //SIZE SIZE SIZE SIZE

int n;
ll len[N]; //sum of distances to every other node
pair<int,int> far[N]; //farthest node from node - {dist,targetnode}
vector<int> adj[N];
ll subl[N]; //sum of distances to every node in subtree
int subcnt[N]; //size of subtree
pair<int,int> subfar[N]; //farthest node in subtree

void d1(int v, int p){
    subcnt[v] = 1;
    subfar[v].e2 = v;
    FORR(i,adj[v]){
        if(i == p) continue;
        d1(i,v);
        subl[v] += subl[i];
        subcnt[v] += subcnt[i];
        if(subfar[i].e1+1 > subfar[v].e1){
            subfar[v] = {subfar[i].e1+1,subfar[i].e2};
        }
    }
    subl[v] += subcnt[v]-1;
}

void d2(int v, int p, ll bckl, int bckc, pair<int,int> bckf){
    len[v] = bckl+subl[v];
    if(bckf.e1 == 0) bckf.e2 = v;
    if(bckf.e1 > subfar[v].e1){
        far[v] = bckf;
    }
    else{
        far[v] = subfar[v];
    }
    set<pair<int,int>> mp;
    mp.insert({bckf.e1+1,bckf.e2});
    FORR(i,adj[v]){
        if(i == p) continue;
        mp.insert({subfar[i].e1+2,subfar[i].e2});
    }
    FORR(i,adj[v]){
        if(i == p) continue;
        pair<int,int> nxbckf;
        if(mp.rbegin()->e2 == subfar[i].e2){
            nxbckf = *next(mp.rbegin());
        }
        else{
            nxbckf = *mp.rbegin();
        }
        int newbck = bckc+subcnt[v]-subcnt[i];
        d2(i,v,bckl+newbck+subl[v]-subcnt[i]-subl[i],newbck,nxbckf);
    }
}

int cn = 0;
int wh = -1;
int k;
bool d4(int v, int p, int cd){
    if(adj[v].size() == 1){
        if(cd != k) return 0;
    }
    /* if(v != wh){ */
    /*     if(adj[v].size() == 1) return 1; */
    /*     if(adj[v].size() <= 3) return 0; */
    /* } */
    int c1 = 0, cmr = 0;
    FORR(i,adj[v]){
        if(i == p) continue;
        if(adj[i].size() == 1) ++c1;
        else if(adj[i].size() <= 3) return 0;
        else{
            ++cmr;
        }
        if(!d4(i,v,cd+1)) return 0;
    }
    if(c1 && cmr) return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n);
    sc(k);
    int f,s;
    FOR(i,1,n){
        sc(f,s);
        --f,--s; //THIS ASSUMES 1-INDEXED NODE INPUT, CHANGE IF IT'S NOT
        adj[f].pb(s);
        adj[s].pb(f);
    }
    d1(0,-1);
    d2(0,-1,0,0,{0,0});
    FOR(i,0,n){
        if(far[i].e1 == k){
            ++cn;
            wh = i;
        }
    }
    if(cn != 1) REE("No")
    if(adj[wh].size() < 3) REE("No")
        bool g = d4(wh,-1,0);
    cout << (g?"Yes":"No");
}