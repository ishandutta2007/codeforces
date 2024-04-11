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
/* #define N 1000001 */
/* #define N 40 */

/* int64_t mod = 1000000007; */
/* inline int64_t fastpow(int64_t a, int64_t b){ */
/*     if(b == 0) */
/*         return 1; */
/*     if(b&1){ */
/*         return (a * fastpow(a,b^1)) % mod; */
/*     } */
/*     a = fastpow(a,b >> 1); */
/*     return (a*a)%mod; */
/* } */

/* int gcdExtended(int a, int b, int *x, int *y){ */
/*     if (a == 0){ */
/*         *x = 0, *y = 1; */
/*         return b; */
/*     } */
/*     int x1, y1; */
/*     int gcd = gcdExtended(b%a, a, &x1, &y1); */
/*     *x = y1 - (b/a) * x1; */
/*     *y = x1; */
/*     return gcd; */
/* } */

/* //dzielnik i modulo musza byc wzglednie pierwsze */
/* //jesli oba sa PIERWSZE, mozna tez uzyskac invb=fastpow(b,mod-2) % mod */
/* int modInverse(int a, int m) { */
/*     int x, y; */
/*     gcdExtended(a, m, &x, &y); */
/*     return (x%m + m) % m; */
/* } */

/* ll fac[N]; */
/* ll facinv[N]; */

/* // constexpr btw? */
/* void pre(){ */
/*     fac[0] = 1; */
/*     FOR(i,1,N) */
/*         fac[i] = fac[i - 1] * i % mod; */
/*     // wait XDDDD */
/*     // "Note that  is not necessary the prime!" */
/*     // kozak. */
/*     facinv[N - 1] = fastpow(fac[N - 1], mod - 2); */
/*     for(int i = N - 2; i >= 0; --i) */
/*         facinv[i] = facinv[i + 1] * (i + 1) % mod; */
/*     // Also i^-1 = facinv[i] * fac[i - 1] (i in 1..n) */
/*     // Similary idea can be used to get invs of any n numbers in O(n + logp). */
/*     // -> zamiast *1, *2, *3... do *a[0], *a[1], *a[2]... */
/* } */


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        int d,m;
        sc(d,m);
        /* mod = m; */
        /* pre(); */
        /* ll ressing[32]{}; */
        /* ressing[0] = 1; */
        /* FOR(i,1,4){ */
        /*     FOR(x,0,i){ */
        /*         /1* ll cr = fac[i] * facinv[x] % m * facinv[i-x] % m; *1/ */
        /*         // > req fix. */
        /*         /1* ll cr = fac[i-1] * facinv[x] % m * facinv[i-x] % m; *1/ */
        /*         /1* ll cr = fac[i-1] * facinv[x] % m * facinv[i-1-x] % m; *1/ */
        /*         /1* whatis(i) *1/ */
        /*         /1* whatis(x) *1/ */
        /*         /1* whatis(cr) *1/ */
        /*         // jednak na pae brr. */
        /*         ll cr = 1; */
        /*         FORE(j,x+1,i-1) */
        /*             cr *= j; */
        /*         FORE(j,1,i-1-x) */
        /*             cr /= j; */
        /*         ressing[i] += ressing[x] * cr; */
        /*         ressing[i] %= m; */
        /*     } */
        /* } */
        /* int ile[32]{}; */
        /* FORE(i,1,d){ */
        /*     // pragma popcnt ez. */
        /*     ++ile[__builtin_popcount(i)]; */
        /* } */
        /* whatis(ressing[0]) */
        /* whatis(ressing[1]) */
        /* whatis(ressing[2]) */
        /* whatis(ressing[3]) */
        /* ll res = 0; */
        /* FOR(i,1,32){ */
        /*     res += ressing[i] * ile[i]; */
        /*     res %= m; */
        /* } */
        /* cout << res << '\n'; */
        // soft bruh^^
        ll iletop[32]{};
        /* ll dp[32][2]{}; // [ind][t] */
        ll dp[32][2][32]{}; // [ind][t][topbit]
        dp[0][0][0] = 1;
        /* string s = bitset<32>(d).to_string(); */
        string s = bitset<31>(d).to_string();
        for(int i = 0; i < 31; ++i){
            // wait, this should be in reverse order przecie xd.
            // wait, ale wtedy jak bez dim[32] dodatkowego ogarn topowy bit?
            // -> guess let's add the dim..
            /* int crd = d & (1 << i); */
            int crd = s[i] - '0';
            for(int t = 0; t < 2; ++t){
                for(int crtp = 0; crtp <= i; ++crtp){
                    for(int d = 0; d < 2; ++d){
                        int nt = t | (d < crd);
                        if(t == 0 && d > crd)
                            break;
                        /* dp[i+1][nt] += dp[i][t]; */
                        if(d == 1){
                            /* iletop[i] += dp[i][t]; */
                            /* dp[i+1][nt][i+1] += dp[i][t][crtp]; */
                            // not like this^^ w kocu largest chcemy.
                            dp[i+1][nt][(crtp ? crtp : i+1)] += dp[i][t][crtp];
                            // -> chyba pog..
                        }
                        else{
                            dp[i+1][nt][crtp] += dp[i][t][crtp];
                        }
                    }
                }
            }
        }
        FOR(i,0,32){
            /* FOR(x,0,32){ */
            /*     iletop[i] += dp[x][0][i]; */
            /*     iletop[i] += dp[x][1][i]; */
            /* } */
            iletop[i] = dp[31][0][i] + dp[31][1][i];
        }
        reverse(iletop, iletop + 32);
        /* whatis(iletop[0]) */ // 1 git jak 1.
        /* whatis(iletop[0]) */
        /* whatis(iletop[1]) */
        /* whatis(iletop[2]) */
        /* whatis(iletop[3]) */
        /* whatis(iletop[31]) */
        ll res = 0;
        ll dp2[32]{};
        dp2[0] = iletop[0];
        res = dp2[0];
        /* FOR(i,1,32){ */
        FOR(i,1,31){
            dp2[i] = res * iletop[i];
            dp2[i] += iletop[i];
            /* whatis(dp2[i]) */
            res += dp2[i];
            res %= m;
        }
		/* --res; */
		res %= m;
        res += m;
        res %= m;
        cout << res << '\n';
    }
}