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
    vector<int> primes;
    bool is_composite[N]{};
    int wh_pr_ind[N];
    static int func[N], cnt[N]; // If wanna wyliczy multiplicative function.
    // Mobius function calc by default.
    func[1] = 1;
    FOR(i,2,N){
        // without non-modulo opt:
        /* if(!is_composite[i]) primes.push_back(i); */
        /* for(int j = 0; j <= (int)primes.size() && i * primes[j] < N; ++j){ */
        /*     /1* assert(!is_composite[i * primes[j]]); *1/ */
        /*     is_composite[i * primes[j]] = 1; */
        /*     if(i % primes[j] == 0) break; */
        /* } */
        // without checking divisibility:
        if(!is_composite[i]){
            primes.push_back(i);
            func[i] = -1; cnt[i] = 1; // If wanna wyliczy multiplicative function.
            for(int j = 0; j < (int)primes.size() && i * primes[j] < N; ++j){
                is_composite[i * primes[j]] = 1;
                wh_pr_ind[i * primes[j]] = j;
                // If wanna wyliczy multiplicative function.
                if(j + 1 == (int)primes.size()){
                    /* func[i * primes[j]] = func[i] / cnt[i] * (cnt[i] + 1); */
                    func[i * primes[j]] = 0;
                    cnt[i * primes[j]] = cnt[i] + 1;
                }
                else{
                    func[i * primes[j]] = func[i] * func[primes[j]];
                    cnt[i * primes[j]] = 1;
                }
            }
        }
        else{
            for(int j = 0; j <= wh_pr_ind[i] && i * primes[j] < N; ++j){
                is_composite[i * primes[j]] = 1;
                wh_pr_ind[i * primes[j]] = j;
                // If wanna wyliczy multiplicative function.
                if(j == wh_pr_ind[i]){
                    /* func[i * primes[j]] = func[i] / cnt[i] * (cnt[i] + 1); */
                    func[i * primes[j]] = 0;
                    cnt[i * primes[j]] = cnt[i] + 1;
                }
                else{
                    func[i * primes[j]] = func[i] * func[primes[j]];
                    cnt[i * primes[j]] = 1;
                }
            }
        }
    }
    constexpr ll mod = 998244353;
    int n,m;
    sc(n,m);
    pi a[n];
    FORR(i,a)
        sc(i.e1, i.e2);
    ll res = 0;
    FORE(d,1,m){
        int till = m / d;
        int dp[n+1][till + 1];
        int dppre[n][till + 1];
        memset(dp,0,sizeof dp);
        dp[0][0] = 1;
        FOR(i,0,n){
            dppre[i][0] = dp[i][0];
            FORE(x,1,till){
                dppre[i][x] = dp[i][x] + dppre[i][x-1];
                dppre[i][x] %= mod;
            }
            int ll = (a[i].e1 + d - 1) / d;
            int rr = a[i].e2 / d;
            /* if(ll <= rr) */
            for(int x = 1; x <= till; ++x){
                int prl = x - ll;
                if(prl >= 0)
                    /* dp[i][x] += dppre[i-1][x-ll]; */
                    /* dp[i][x] += dppre[i-1][prl]; */
                    dp[i+1][x] += dppre[i][prl];
                int prr = x - rr - 1;
                if(prr >= 0){
                    /* dp[i][x] -= dppre[i-1][prr]; */
                    dp[i+1][x] -= dppre[i][prr];
                }
                /* dp[i][x] %= mod; */
                dp[i+1][x] %= mod;
            }
            /* for(int x = ; x <= a[i].e2 / d; ++x){ */
            /*     /1* dp[i][x] += dppre[i-1][ *1/ */
            /* } */
        }
        ll cr = 0;
        /* whatis(d) */
        FORE(i,1,till){
            cr += dp[n][i];
            cr %= mod;
        }
        /* whatis(cr) */
        res += func[d] * cr % mod;
        res %= mod;
    }
    res += 2 * mod;
    res %= mod;
    cout << res << '\n';
}