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
#define N 2100001

inline uint64_t mulmod(uint64_t a, uint64_t b, uint64_t mod){
    if(b == 1) return a;
    if(b&1){
        return (a+mulmod(a,b^1,mod))%mod;
    }
    return mulmod(a,b >> 1,mod)*2%mod;
}

constexpr int64_t mod = 1000000007;
inline int64_t fastpow(int64_t a, int64_t b){
    if(b == 0)
        return 1;
    if(b&1){
        return (a * fastpow(a,b^1)) % mod;
    }
    a = fastpow(a,b >> 1);
    return (a*a)%mod;
}

int gcdExtended(int a, int b, int *x, int *y){
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}

//dzielnik i modulo musza byc wzglednie pierwsze
//jesli oba sa PIERWSZE, mozna tez uzyskac invb=fastpow(b,mod-2) % mod
int modInverse(int a, int m) {
    int x, y;
    gcdExtended(a, m, &x, &y);
    return (x%m + m) % m;
}

ll fac[N];
ll facinv[N];

// constexpr btw?
void pre(){
    fac[0] = 1;
    FOR(i,1,N)
        fac[i] = fac[i - 1] * i % mod;
#if N == 1000001
    if constexpr (mod == 1000000007)
        facinv[N - 1] = 397802501;
    else
        facinv[N - 1] = fastpow(fac[N - 1], mod - 2);
#else
    facinv[N - 1] = fastpow(fac[N - 1], mod - 2);
#endif
    for(int i = N - 2; i >= 0; --i)
        facinv[i] = facinv[i + 1] * (i + 1) % mod;
    // Also i^-1 = facinv[i] * fac[i - 1] (i in 1..n)
    // Similary idea can be used to get invs of any n numbers in O(n + logp).
    // -> zamiast *1, *2, *3... do *a[0], *a[1], *a[2]...
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    pre();
    int k,pa,pb;
    sc(k,pa,pb);
    /* int inv2 = facinv[2]; */
    ll dp[k + 1][k];
    memset(dp,0,sizeof dp);
    ll magic = (pa + pb) * facinv[pb] % mod * fac[pb - 1] % mod;
    ll magic2 = facinv[pa + pb] * fac[pa + pb - 1] % mod;
    /* dp[0][0] = 2; */
    // klepasko b4 good idea zawsze na propsie...
    for(int ilea = k; ilea >= 1; --ilea){
        for(int crk = k-1; crk >= 0; --crk){
            if(ilea + crk >= k){
                dp[ilea][crk] = ilea + crk + magic - 1;
                dp[ilea][crk] %= mod;
            }
            else{
                dp[ilea][crk] = (dp[ilea+1][crk] * pa + dp[ilea][crk+ilea] * pb) % mod * magic2 % mod;
            }
        }
    }
    cout << dp[1][0] << '\n';
    // top-down
    /* ll res = 0; */
    /* ll sth[k + 1]; */
    /* ll cr = 1; */
    /* sth[0] = 0; */
    /* // this needed? */
    /* cr *= inv2; */
    /* cr %= mod; */
    /* // this needed? */
    /* FOR(i,1,k+1){ */
    /*     cr *= inv2; */
    /*     cr %= mod; */
    /*     sth[i] = i * cr % mod; */
    /*     sth[i] += sth[i-1]; */
    /*     sth[i] %= mod; */
    /* } */
    /* FOR(ilea,0,k){ */
    /*     FOR(crk,0,k){ */
    /*         whatis(ilea) */
    /*         whatis(crk) */
    /*         ll cradd = dp[ilea][crk]; */
    /*         whatis(cradd) */
    /*         for(int i = 0;; ++i){ */
    /*             cradd *= inv2; */
    /*             cradd %= mod; */
    /*             int nxilea = ilea + i; */
    /*             int nxcrk = crk + ilea + i; */
    /*             if(nxcrk >= k){ */
    /*                 if(crk == 0 && ilea == 0){ */
    /*                     cradd *= 2; */
    /*                     cradd %= mod; */
    /*                 } */
    /*                 /1* res += cradd * 2; *1/ */
    /*                 res += (crk + ilea) * cradd * 2; */
    /*                 /1* res += cradd * (2 - sth[i]); *1/ */
    /*                 whatis(i) */
    /*                 whatis(sth[max(0,i-1)]) */
    /*                 /1* res += 2 * cradd * (2 - sth[max(0,i-1)]); *1/ */
    /*                 res += 2 * cradd * (1 - sth[max(0,i-1)]); */
    /*                 res %= mod; */
    /*                 break; */
    /*             } */
    /*             dp[nxilea][nxcrk] += cradd; */
    /*             dp[nxilea][nxcrk] %= mod; */
    /*         } */
    /*     } */
    /* } */
    /* cout << res << '\n'; */
    /* cout << res * 2 % mod << '\n'; */
}