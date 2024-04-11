/* #pragma GCC optimize("O3") */
#pragma GCC optimize("Ofast")
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
#define N 2000001

constexpr ll mod = 1e9 + 7;

ll fac[N];
ll facinv[N];

// constexpr btw?
void pre(){
    fac[0] = 1;
    FOR(i,1,N)
        fac[i] = fac[i - 1] * i % mod;
    /* facinv[N - 1] = 397802501; */
    facinv[N - 1] = 407182070;
    for(int i = N - 2; i >= 0; --i)
        facinv[i] = facinv[i + 1] * (i + 1) % mod;
    // Also i^-1 = facinv[i] * fac[i - 1] (i in 1..n)
    // Similary idea can be used to get invs of any n numbers in O(n + logp).
    // -> zamiast *1, *2, *3... do *a[0], *a[1], *a[2]...
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    pre();
    ll n;
    sc(n);
    ll a[n];
    GET(a);
    /* vector<int> g[1 << n]; */
    /* map<int,int> g[1 << n]; */
    /* FOR(i,0,1<<n) */
        // asm instruction obv xd.
        // let's leave as a map for now.
        /* g[i].resize( */
    // w8, i want to calc that just once though.

    /* map<int,int> dp[1 << n]; */
    /* ll sumn[1 << n]; // poza [i][i] */
    /* memset(sumn,0,sizeof sumn); // thx mac */
    /* ll res = 0; */
    /* /1* dp[0][0] = 1; *1/ */
    /* FOR(i,1,1<<n){ */
    /*     whatis(i) */
    /*     int crm = i; */
    /*     // actually, have to go at last. */
    /*     /1* for(;;){ *1/ */
    /*     // -> let's dec implicitely. */
    /*     crm = (crm - 1) & i; */
    /*     // edge case. */
    /*     if(!crm) */
    /*         crm = i; */
    /*     for(;crm;){ */
/* xd: */
    /*         ll cr = 1; */
    /*         whatis(crm) */
    /*         // no comp for now. */
    /*         // got samples -> let's introduce comp. */
    /*         // -> we still good. */
    /*         ll comp[14]; */
    /*         memset(comp, -1, 14 << 3); */
    /*         FOR(x,0,14){ */
    /*             /1* if(i & (1 << crm)){ *1/ */
    /*             if(comp[x] == -1){ */
    /*                 comp[x] = 1; */
    /*                 if(crm & (1 << x)){ */
    /*                     FOR(j,0,14){ */
    /*                         // XD? */
    /*                         if((i & (1 << j)) && (!(crm & (1 << j)))){ */
    /*                             /1* cr *= (ll)a[x] * facinv[a[x] + a[j]] % mod * fac[a[x] + a[j] - 1] % mod; *1/ */
    /*                             /1* cr %= mod; *1/ */
    /*                             comp[x] *= (ll)a[x] * facinv[a[x] + a[j]] % mod * fac[a[x] + a[j] - 1] % mod; */
    /*                             comp[x] %= mod; */
    /*                         } */
    /*                     } */
    /*                 } */
    /*             } */
    /*             cr *= comp[x]; */
    /*             cr %= mod; */
    /*         } */
    /*         // cr eq G(). */
    /*         /1* int subcrm = crm; *1/ */
    /*         ll cr2 = 1; // 1 - suma bdz; */
    /*         cr2 -= sumn[crm]; */
    /*         cr2 %= mod; */
    /*         // -> we good. */
    /*         // -> basically that's 3^n * n. */
    /*         /1* while(subcrm){ *1/ */
    /*         /1*     subcrm = (subcrm - 1) & crm; *1/ */
    /*         /1*     if(!subcrm) *1/ */
    /*         /1*         break; *1/ */
    /*         /1*     cr2 -= dp[crm][subcrm]; *1/ */
    /*         /1*     cr2 %= mod; *1/ */
    /*         /1* } *1/ */
    /*         whatis(cr) */
    /*         whatis(cr2) */
    /*         whatis(cr * cr2 % mod) */
    /*         if(i == (1 << n) - 1) */
    /*             /1* res += __builtin_popcount(crm) % mod * cr * cr2 % mod, res %= mod; *1/ */
    /*             res += __builtin_popcount(crm) * cr % mod * cr2 % mod, res %= mod; */
    /*         /1* dp[i][crm] = cr * cr2 % mod; *1/ */
    /*         /1* if(!crm) *1/ */
    /*         /1*     break; *1/ */
    /*         if(crm == i) */
    /*             break; */
    /*         sumn[i] += cr * cr2 % mod; */
    /*         sumn[i] %= mod; */
    /*         crm = (crm - 1) & i; */
    /*         // don't want crm == 0 either. */
    /*         if(!crm){ */
    /*             /1* if(i == (1 << n) - 1){ // new *1/ */
    /*             if(0 && i == (1 << n) - 1){ // new */
    /*                 crm = i; // giga hacky taktyk. */
    /*                 // -> XD, samples passed. */
    /*                 goto xd; */
    /*             } */
    /*             else{ */
    /*                 break; */
    /*             } */
    /*         } */
    /*     } */
    /* } */
    /* /1* ll res = 0; *1/ */
    /* /1* FOR(i,1,1<<n){ *1/ */
    /* /1*     /2* res += __builtin_popcount(i) * dp[1<<n][i]; *2/ *1/ */
    /* /1*     whatis(i) *1/ */
    /* /1*     whatis(dp[(1<<n) - 1][i]) *1/ */
    /* /1*     res += __builtin_popcount(i) * dp[(1<<n) - 1][i]; *1/ */
    /* /1*     res %= mod; *1/ */
    /* /1* } *1/ */
    /* res += (ll)n * (1 - sumn[(1 << n) - 1]); */
    /* res %= mod; */
    /* // -> still good, hmm. what is the diff between the new and old rozw then? */
    // -> XD. Did not reset comp / declare it per subset. co za bug.
    /* res += mod; */
    /* res %= mod; */
    /* cout << res << '\n'; */

    ll res = 0;
    ll dp[1 << n]; // suma F(sub,winners) gdzie winners = maska POZA sub eq winners.
    // or not, is it full xd? no fkn idea.
    /* dp[0] = 0; */
    /* dp[0] = 1; // what base caee? */
    ll dp2[1 << n]; // per subset precomp for O(3^n) instead of O(3^n * n)
    int bits[32], othbits[32];
    FOR(i,1,1<<n){
        whatis(i)
        int crm = (i-1)&i;
        dp[i] = 0;
        // BRUH XD.
        // Guess that was the diff.
        // kozak...
        /* ll comp[14]; */
        /* memset(comp,-1,14 << 3); */
        // to byby przypaowy bug na cercu.
        /* while(crm){ */
        /* do{ */
        /* vi ord; */
        /* while(crm){ */
        /*     ord.push_back(crm); */
        /*     crm = (crm - 1) & i; */
        /* } */
        /* reverse(all(ord)); */
        /* int ii = i; */
        /* FORR(i,ord){ */
        /*     // instead of popping some bit (can do with some builtin), can just */
        /*     // as well get some previous mask by (i - 1) & i. */
        /*     // -> though idk, not neceserily will just one bit differ then. */
        /*     // but -> in that case, instaed of muling by res of just one num, */
        /*     // can mul by res of the xor dopernienie to the gotten mask. */
        /*     // -> that makes sense, then just manual comp for singulars. */
        /*     if(!(i & (i - 1))){ */
        /*         int x = 31 - __builtin_clz(i); */
        /*         /1* whatis(x) *1/ */
        /*         dp2[i] = 1; */
        /*         FOR(j,0,14){ */
        /*             /1* if((i & (1 << j)) && !(crm & (1 << j))){ *1/ */
        /*             // had some shadowing here. */
        /*             // w8 xd, that also depends on what remains. */
        /*             // -> b4 I had a precomp for nothing btw xd. */
        /*             // -> here I'd also have to keep track of total incoming */
        /*             // muls, and mul by that etc. but that's too advanced for */
        /*             // this anyway. */
        /*             // Actually, had O(3^n * n^2) btw. */
        /*             // Wonder how would changing 14 to n affect runtime also. */
        /*             if((ii & (1 << j)) && !(i & (1 << j))){ */
        /*                 dp2[i] *= (ll)(a[x]) * facinv[a[x] + a[j]] % mod * fac[a[x] + a[j] - 1] % mod; */
        /*                 dp2[i] %= mod; */
        /*             } */
        /*         } */
        /*     } */
        /*     else{ */
        /*         int oth = (i - 1) & i; */
        /*         // elegant af btw. */
        /*         dp2[i] = dp2[oth] * dp2[i ^ oth] % mod; */
        /*     } */
        /* } */
        /* crm = (i-1)&1; */
        crm = (i - 1) & i;
        for(;crm;){
            // upgrade.
            ll comp[14];
            memset(comp,-1,14 << 3);
            /* int cr = 1; */
            ll cr = 1;
            /* if(!g[ */
            FOR(x,0,14){ // unrolling obv
            // -> Lol, z O3 diff z 1.6s do 1s. najs.
            /* vi bits; */
            /* vi othbits; */
            /* FOR(x,0,n){ */
            /*     if(crm & (1 << x)) */
            /*         bits.push_back(x); */
            /*     else if(i & (1 << x)) */
            /*         othbits.push_back(x); */
            /* } */
            // -> 2.4s instead XDDD.
            /* int bitsit = 0; */
            /* int othbitsit = 0; */
            /* FOR(x,0,n){ */
            /*     if(crm & (1 << x)) */
            /*         bits[bitsit++] = x; */
            /*     else if(i & (1 << x)) */
            /*         /1* othbits.push_back(x); *1/ */
            /*         othbits[othbitsit++] = x; */
            /* } */
            // co za scam.
            // co jak no vectors, but just arrs?
            // -> 857ms. quite a diff indeed.
            // moe z clz jeszcze try?
            // clz on crm, clz on i ^ crm.
            /* FOR(x,0,n){ // let's see what the dif would be. */
            /* FORR(x,bits){ // let's see what the dif would be. */
            /* FOR(xx,0,bitsit){ // let's see what the dif would be. */
            /* int tcrm = crm; */
            /* while(tcrm){ */
                // either ffs or clz.
                // -> clz 2 instruction, ffs 4. so clz
                // ctz rep bsf, hmm.
                /* int x = 31 - __builtin_clz(tcrm); */
                // -> 1.6ms. guess not pyli.
                /* tcrm ^= 1 << x; */
                // -> o eps lower actually, hmm.
                // wonder what of itering over those in crm? (can precomp wsm)
                if(crm & (1 << x)){
                /* if(true){ */
                    // edge z cr nodea do all nodow w i \ x.
                    // -> wait, might wanna precomp that, sq otherwise.
                    if(comp[x] == -1){
                        comp[x] = 1;
                        FOR(j,0,14){
                        /* FOR(j,0,n){ */
                        /* FORR(j,othbits){ */
                        /* int tmpoth = crm ^ i; */
                        /* FOR(jj,0,othbitsit){ */
                        /* while(tmpoth){ */
                            /* int j = 31 - __builtin_clz(tmpoth); */
                            /* tmpoth ^= 1 << j; */
                            /* if(i & (1 << j) && !(crm & (1 << j))){ */
                            if((i & (1 << j)) && !(crm & (1 << j))){
                            /* if(true){ */
                                /* comp[x] *= (a[x] + a[j]) * inv(a[x] + a[j]); */
                                // XD.
                                /* comp[x] *= (ll)(a[x] + a[j]) * facinv[a[x] + a[j]] % mod * fac[a[x] + a[j] - 1] % mod; */
                                comp[x] *= (ll)(a[x]) * facinv[a[x] + a[j]] % mod * fac[a[x] + a[j] - 1] % mod;
                                comp[x] %= mod;
                            }
                        }
                    }
                    cr *= comp[x];
                    cr %= mod;
                }
            }
            // updgrade.
            // or not.
            /* ll cr = dp2[crm]; */
            whatis(cr)
            whatis(dp[crm])
            cr *= 1 - dp[crm];
            cr %= mod;
            dp[i] += cr;
            dp[i] %= mod;
            whatis(dp[i])
            // bruh, order.
            /* crm = (crm-1)&i; */
            if(i == ((1 << n) - 1)){
                whatis(crm)
                whatis(cr)
                res += (ll)__builtin_popcount(crm) * cr;
                res %= mod;
            }
            /* if(!crm) */
            /*     break; */
            crm = (crm-1)&i;
        }
    }
    whatis(dp[1])
    whatis(dp[2])
    /* res += 1 - dp[(1 << n) - 1]; */
    whatis(dp[3])
    res += (ll)n * (1 - dp[(1 << n) - 1]);
    res %= mod;
    res += mod;
    res %= mod;
    cout << res << '\n';
    /* cout << dp[(1 << n) - 1]; */
}