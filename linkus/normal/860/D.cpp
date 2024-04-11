#include <stdio.h>
#include <array>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <climits>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <numeric>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
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
#define N 1000001

vi adj[N];
vi backedge[N];
bool vis[N];
/* int pp[N]; */
int d[N];

void d1(int v, int p){
    /* whatis(v) */
    /* whatis(p) */
    // xd, nc no vis setting.
    vis[v] = 1;
    FORR(i,adj[v]){
        if(i == p)
            continue;
        if(!vis[i]){
            /* pp[i] = v; */
            d[i] = d[v] + 1;
            d1(i, v);
        }
        else{
            // this:
            // w sumie bruh, nvm, przecie jak to jest undirected, to to nie ma
            // znaczenia xd.
            /* if(pp[i] == -1) */
            /*     pp[i] = v; */
            /* backedge[i].push_back(v); // only from lower to higher. */
            // bruh XDDD
            // przecie obie strony prbuj to samo doda.
            // -> not only [i].pb(v), ale tylko jak depth odpowiednio rny
            // jest...
            if(d[v] > d[i])
                backedge[i].push_back(v); // only from lower to higher.
            /* backedge[v].push_back(i); */
        }
    }
}

vector<array<int,3>> resvec;

void d2(int v, int p){
    vis[v] = 1;
    FORR(i,adj[v]){
        if(i == p)
            continue;
        if(!vis[i]){
            d2(i, v);
        }
    }
    whatis(v)
    whatis(p)
    whatis(backedge[v])
    while(backedge[v].size() > 1){
        int v1 = backedge[v].back();
        backedge[v].pop_back();
        int v2 = backedge[v].back();
        backedge[v].pop_back();
        resvec.push_back({v1, v, v2});
        whatis("pb1")
    }
    if(backedge[v].size() == 1){
        int v1 = backedge[v].back();
        if(~p){
            resvec.push_back({p, v, v1});
            whatis("pb2")
        }
    }
    else{
        if(~p){
            backedge[p].push_back(v);
            whatis("pb3")
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    sc(n,m);
    int f,s;
    FOR(i,0,m){
        sc(f,s);
        --f,--s;
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    /* memset(pp,-1,n << 2); */
    FOR(i,0,n){
        if(!vis[i])
            d1(i,-1);
    }
    /* memset(vis,0,n << 2); */
    memset(vis,0,n);
    FOR(i,0,n){
        if(!vis[i])
        /* if(pp[i] == -1) */
            d2(i,-1);
    }
    cout << resvec.size() << '\n';
    FORR(i,resvec){
        FORR(x,i) ++x;
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
    }
}