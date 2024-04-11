#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <array>
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

int main(){
    /* #define int ll */
    /* #undef INF */
    /* #define INF 100000000000000000 */
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    sc(n,m);
    int d[m];
    GET(d);
    int g,r;
    sc(g,r);
    int dist[m][g + 1];
    /* memset(dist,127,sizeof dist); */
    FORR(i,dist)
        FORR(x,i)
            x = INF;
    dist[0][0] = 0;
    // XDDD, they don't have to be ordered. kozak.
    sort(d, d+m);
    m = unique(d, d+m) - d;
    FOR(i,1,m){
        if(d[i] - d[i-1] > g){
            REE("-1")
        }
    }
    /* priority_queue<pi> pq; */
    priority_queue<array<int,3>> pq;
    /* pq.push(array<int,3>({0,0,0})); */
    pq.push(array<int,3>({0,0,0}));
    while(!pq.empty()){
        int v = pq.top()[1], w = -pq.top()[0], md = pq.top()[2]; pq.pop();
        if(v){
            int df = d[v] - d[v - 1];
            int nw = w + df;
            int nmd = (md + df) % g;
            if(nmd == 0 || nmd > md){
                // forgot this:
                if(nmd == 0)
                    nw += r;
                if(nw < dist[v-1][nmd]){
                    dist[v-1][nmd] = nw;
                    pq.push({-nw, v-1, nmd});
                }
            }
        }
        if(v+1<m){
            int df = d[v+1] - d[v];
            int nw = w + df;
            int nmd = (md + df) % g;
            if(nmd == 0 || nmd > md){
                if(nmd == 0)
                    nw += r;
                if(nw < dist[v+1][nmd]){
                    dist[v+1][nmd] = nw;
                    pq.push({-nw, v+1, nmd});
                }
            }
        }
    }
    /* cout << (dist[m-1][0] == INF ? -1 : dist[m-1][0]) << '\n'; */
    /* cout << (dist[m-1][0] == INF ? -1 : dist[m-1][0]) << '\n'; */
    int res = INF;
    FOR(i,0,g){
        /* if(dist[n-1][i] != INF){ */
        if(dist[m-1][i] != INF){
            if(i == 0)
                res = min(res, dist[m-1][i] - r);
            else
                res = min(res, dist[m-1][i]);
        }
    }
    cout << (res == INF ? -1 : res) << '\n';
}