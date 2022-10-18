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
#define N 1000001

constexpr int mod = 998244353;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s,t;
    getstr(s);
    getstr(t);
    int n = s.size(), m = t.size();
    int dp[n+1][m+1], dp2[n+1][m+1];
    memset(dp,0,sizeof dp);
    memset(dp2,0,sizeof dp2);
    dp[0][m] = 1;
    FOR(i,0,m){
        // hard bruh XDDD
        /* if(s[i] == t[i]) */
        if(i == m - 1)
            break;
        // ^^ trick aby to zostawic dla dp[] -- case gdzie i tak tylko przed
        // dodajemy.
        if(s[0] == t[i])
            // -> kwestia do tego chyba, e += 2, no bo przod / tyl
            // equivalentne.
            /* ++dp2[1][i]; */
            dp2[1][i] += 2;
    }
    FOR(i,0,n){
        FOR(x,0,m){
            if(s[i] == t[x]){
                dp2[i+1][x] += dp2[i][x+1];
                dp2[i+1][x] %= mod;
                // todo poza i == 0?
                // also, czy na poczatku nie powinno byc += 2? (przod / tyl)
                // -> let's go for the i != 0.
                // hmmm, idk jak z tym legit.
                // *rip middle*
                /* if(i) */
                    dp[i+1][x] += dp[i][x+1];
                if(i == 0)
                    dp[i+1][x] += dp[i][x+1];
                // i-ception.
                // -> XD, all sample testy tera przechodz. hype.
                dp[i+1][x] %= mod;
                // had it wrong.
                // or git jednak? above sth was wrong?
                if(x-i >= 0){
                    dp2[i+1][x-i] += dp2[i][x-i];
                    dp2[i+1][x-i] %= mod;
                }
                /* if(x+i < m) */
                    /* dp2[i+1][x] += dp2[i][x+i]; */
                    /* dp2[i+1][x+i-1] += dp2[i][x+i]; */
            }
            dp[i+1][x] += dp[i][x];
            dp[i+1][x] %= mod;
        }
        // tutaj, jednak musimy by faktycznie pewni, e dodawajc do przodu
        // nie pasuje nam on do sufiksu.
        dp[i+1][m] += 2 * dp[i][m] % mod;
        dp[i+1][m] %= mod;
        // also, edge case i == 0?
        // -> Nie no xd, wanie tutaj nie obchodzi nas jak to i tak pasuje, bo
        // dla nas to nie jest widoczne.
        /* if(i){ */
        /*     dp[i+1][m] += dp[i][m]; // do tyu, zawsze git */
        /*     if(s[i] != t[m-1]) */
        /*         dp[i+1][m] += dp[i][m]; // do przodu, if neq t[m-1] */
        /* } */
        /* else{ */
        /*     if(s[i] != t[m-1]){ */
        /*         // seems sketchy tbh. */
        /*         dp[i+1][m] += dp[i][m]; */
        /*         dp[i+1][m] += dp[i][m]; */
        /*     } */
        /* } */
        if(i == m){
            dp[i+1][0] += dp2[i][0];
            dp[i+1][0] %= mod;
        }
        // another very keyish (hopefully last missing one):
        // powysze monaby te w tym zawrze w sumie.
        if(i < m){
            dp[i+1][m-i] += dp2[i][m-i];
            dp[i+1][m-i] %= mod;
        }

    }
    FORE(i,0,n){
        whatis(i)
        FORE(x,0,m){
            whatis(x)
            whatis(dp[i][x])
        }
    }
    int res = 0;
    res += dp2[m][0];
    whatis(dp2[m][0])
    FORE(i,0,n){
        res += dp[i][0];
        res %= mod;
        whatis(i)
        whatis(dp[i][0])
    }
    cout << res << '\n';
}