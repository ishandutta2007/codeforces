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
    int n,k;
    sc(n,k);
    string s,tt;
    getstr(s);
    getstr(tt);
    ll res = 0;
    /* ll dp[n+1][2]; */
    ll dp[n+1][4];
    memset(dp,0,sizeof dp); // classic zapomnienie.
    /* dp[0][0] = 1; */
    dp[0][3] = 1;
    FORR(i,s)
        i -= 'a';
    FORR(i,tt)
        i -= 'a';
    // w8, or [0][1] restricted / not restricted? ma sens.
    // actually, [3]. 0 restricted by s, 2 restricted by t, 1 restricted by none, 3 by none.
    /* FORE(i,0,n){ */
    FOR(i,0,n){
        /* dp[i] = dp[i-1] * (abs(t[i] - s[i]) + 1); */
        /* FOR(t,0,2){ */
        FOR(t,0,4){
            FOR(d,0,2){
                /* int nt = t | (d > s[i]); */
                int nt;
                if(t == 1)
                    nt = 1;
                else if(t == 0){
                    if(d < s[i])
                        continue;
                    nt = d > s[i];
                }
                else if(t == 2){
                    if(d > tt[i])
                        continue;
                    nt = d < tt[i] ? 1 : 2;
                }
                else if(t == 3){
                    if(d < s[i] || d > tt[i])
                        continue;
                    if(d > s[i] && d < tt[i])
                        nt = 1;
                    else if(d > s[i])
                        nt = 2;
                    else if(d < tt[i])
                        nt = 0;
                    else
                        nt = 3;
                }
                else{
                    assert(false);
                }
                dp[i+1][nt] += dp[i][t];
                dp[i+1][nt] = min<ll>(dp[i+1][nt], k);
            }
        }
    }
    // lol
    /* FOR(i,1,n){ */
    FORE(i,1,n){
        ll crres = 0;
        FORR(x,dp[i]){
            crres += x;
            // nope xd.
            /* res = min<int>(res,k); */
        }
        // this.
            res += min<int>(crres,k);
    }
    // -> elegant.
    cout << res << '\n';
}