#include <stdio.h>
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
// wait, przecie 1 << 20 jest wieksze niz 1e6 xd.
/* #define N 2000007 */
/* #define N 3000007 */
/* #define N 4000007 */
#define N 4000007

int n,m;
int h,g;
/* int adj[N][2]; */
/* bool can[N]; */
/* int p[N]; */
/* int root; */
int a[N];
int valind[N];

/* void d1(int v, int h){ */
/*     if(a[adj[v][0]] == 0 && a[adj[v][1]] == 0){ */
/*         a[v] = 0; */
/*     } */
/*     else{ */
/*         if(a[adj[v][0]] > a[adj[v][1]]){ */
/*             d1(adj[v][0], h + 1); */
/*             if(p[v]){ */
/*             } */
/*         } */
/*     } */
/* } */

/* void d1(int v){ */
int itt = 0;
bool d1(int v){
    assert(v <= n); // no rte either.
    assert(v > 0); // -> rte. how. init is positive apparently..
    // overflow neither, bo assert v*2+1 <= n.
	/* assert(++itt < 30); */
    if(a[v*2] == 0 && a[v*2+1] == 0){
        // That's the other taktyk:
        if(v < (1 << g)){
            return false;
        }
        valind[a[v]] = -1; // this one shouldn't matter at all. we --it after all instantly.
        // or if not, above we set it to the new correct val.
        a[v] = 0;
        /* if(v < (1 << g)){ */
        /* if(v / 2 < (1 << g)){ */
        // Inny taktyk jednak.
        /* assert(v >= (1 << g)); */
        /* if(v / 2 < (1 << g) && a[v^1] == 0){ */
        /*     v >>= 1; */
        /*     while(v >= 1){ */
        /*         // could add a stopping if here. */
        /*         if(!can[v]) */
        /*             break; */
        /*         can[v] = 0; */
        /*         v >>= 1; */
        /*     } */
        /* } */
    }
    else{
        assert(v*2+1 <= n); // -> No rte with just this.
        if(a[v*2] > a[v*2+1]){
            int nval = a[v*2];
            if(!d1(v*2))
                return false;
            a[v] = nval;
            valind[nval] = v;
        }
        else{
            int nval = a[v*2+1];
            if(!d1(v*2+1))
                return false;
            a[v] = nval;
            valind[nval] = v;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        sc(h,g);
        n = (1 << h) - 1;
        m = (1 << g) - 1;
        /* iota(a+1,a+n+1,1); */
        /* reverse(a+1,a+n+1); */
        /* shuffle(a+1,a+n+1); */
        FORE(i,1,n)
            sc(a[i]);
        FORE(i,n+1,n*2+7){
            a[i] = 0;
        }
        /* root = a[1]; */
        /* FORE(i,1,n){ */
        /*     /1* FORR(x,vi({i*2,i*2+1})){ *1/ */
        /*     /1*     if(x <= n){ *1/ */
        /*     /1*         adj[i][0] *1/ */
        /*     /1*     } *1/ */
        /*     /1* } *1/ */
        /*     int v = a[i]; */
        /*     if(i*2 <= n){ */
        /*         adj[v][0] = a[i*2]; */
        /*         adj[v][1] = a[i*2+1]; */
        /*         p[a[i*2]] = v; */
        /*         p[a[i*2+1]] = v; */
        /*     } */
        /* } */
        FORE(i,1,n){
            valind[a[i]] = i;
        }
        /* memset(can,1,n+1); */
        int it = n;
        vi resvec;
        ll res = accumulate(a+1,a+n+1,0ll);
        /* FOR(x,0,n - m){ */
        /*     assert(it >= 0); // -> still no rte, hmmm. */
        /*     assert(it > 0); // -> with this alone also rte. -> it eq 0. */
        /*     // wait XD, forgot to check if this node still exists? */
        /*     // -> nie no, must exist here, can only get fully remd by top d1() */
        /*     // call. */
        /*     /1* while(!can[it]) *1/ */
        /*     /1* while(!can[valind[it]]) *1/ */
        /*     /1*     --it; *1/ */
        /*     /1* d1(it, 0); *1/ */
        /*     // height based on ind wsm. */
        /*     /1* d1(valind[it], 0); *1/ */
        /*     /1* int val = valind[it]; *1/ */
        /*     int valindv = valind[it]; */
        /*     /1* assert(valindv != -1); // -> no rte. *1/ */
        /*     /1* assert(valindv >= 0); // -> no rte either. *1/ */
        /*     assert(valindv > 0); // -> tutaj rte, damn. so eq 0. */
        /*     assert(valindv <= n); // no rte. */
        /*     /1* resvec.pb(valind[it]); *1/ */
        /*     itt = 0; */
        /*     if(d1(valind[it])){ // odd e brak wa wsm. guess never pyli leafa? */
        /*     /1* resvec.pb(it); *1/ */
        /*         res -= it; */
        /*         /1* resvec.pb(valind[it]); *1/ */
        /*         resvec.pb(valindv); */
        /*     } */
        /*     else{ */
        /*         /1* resvec.pop_back(), --x; *1/ */
        /*         --x; */
        /*     } */
        /*     --it; */
        /*     /1* assert(it >= 0); *1/ */
        /* } */
        // guess let's try by v...
        FORE(v,1,n){
            while(a[v] != 0){
                int cr = a[v];
                if(d1(v)){
                    res -= cr;
                    resvec.push_back(v);
                }
                else{
                    break;
                }
            }
        }
        cout << res << '\n';
        FORR(i,resvec){
            cout << i << ' ';
        }
        cout << '\n';
        /* whatis(a[1]) */
        /* whatis(a[2]) */
        /* whatis(a[3]) */
    }
}