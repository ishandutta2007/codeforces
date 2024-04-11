#include <stdio.h>
#include <algorithm>
#include <vector>
#include <array>
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
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    sc(n,m);
    int a[n];
    FOR(i,0,n)
        a[i] = 1 << i;
    while(m--){
        int f,s;
        sc(f,s);
        --f,--s;
        a[f] |= 1 << s;
        a[s] |= 1 << f;
    }
    /* bool vis[n]; */
    /* memset(vis,0,n); */
    /* function<void(int)> xd = [&](int v){ */
    /*     vis[v] = 1; */
    /*     FOR(i,0,n){ */
    /*         if(a[v] & (1 << i)){ */
    /*             /1* if(!vis[v]) *1/ */
    /*             if(!vis[i]) */
    /*                 xd(i); */
    /*         } */
    /*     } */
    /* }; */
    /* xd(0); */
    /* if(accumulate(vis,vis+n,0) == n) */
    /*     REE(0) */
    // wait XD
    // not really, nie ma byc connected, ma byc klik.
    // btw, jakim cudem dopiero wa4, juz first test powinien byl nie przejcs xd.
    // -> !vis[v] != !vis[i]
    // -> forgot to check for is_con anywhere xd.
    if(count(a,a+n,(1<<n) -1) == n)
        REE(0)
    // -> wa6.
    bool is_con[1 << n];
    memset(is_con, 0, sizeof is_con);
    FOR(i,0,n)
        is_con[1 << i] = 1;
    pi res{INF,INF};
    FOR(i,0,1 << n){
        if(!is_con[i])
            continue;
        // -> wa6 still:(
        // -> WOW, pog cf error on details. forgot to memset.
        int m = 0;
        FOR(x,0,n){
            if(i & (1 << x))
                m |= a[x];
        }
        if(m == (1 << n) - 1){
            res = min(res, {__builtin_popcount(i), i});
        }
        FOR(x,0,n){
            if((m & (1 << x)) && !(i & (1 << x)))
                is_con[i | (1 << x)] = 1;
        }
    }
    cout << res.e1 << '\n';
    FOR(i,0,n){
        if(res.e2 & (1 << i))
            cout << i + 1 << ' ';
    }
    cout << '\n';
}