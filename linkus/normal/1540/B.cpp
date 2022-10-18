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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
 
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
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 200

vi adj[N];

vi crvec;
int r;
bool d1(int v, int p){
    /* crvec.pb(v); */
    if(v == r){
        return 1;
    }
    crvec.pb(v);
    FORR(i,adj[v]){
        if(i == p)
            continue;
        if(d1(i,v))
            return 1;
    }
    crvec.pop_back();
    return 0;
}

constexpr ll mod = 1e9 + 7;

ll fastpow(ll a, ll b){
    if(b == 0)
        return 1;
    if(b&1){
        // xd.
        /* return fastpow(a,b^1) * b % mod; */
        return fastpow(a,b^1) * a % mod;
    }
    ll sth = fastpow(a,b>>1);
    return sth * sth % mod;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    int f,s;
    FOR(i,0,n-1){
        sc(f,s);
        --f,--s;
        adj[f].pb(s);
        adj[s].pb(f);
    }
    constexpr ll inv2 = 500000004;
    ll res = 0;
    int dsdp[n][n]; // -> chance for greater.
    memset(dsdp,-1,sizeof dsdp);
    FOR(i,0,n){
        r = i;
        ll cr = 0;
        vi vec[n];
        FOR(x,0,n){
            crvec.clear();
            d1(x, -1);
            vec[x] = crvec;
            reverse(all(vec[x]));
        }
        FOR(x,0,n){
            FOR(j,x+1,n){
                // brrr liniowe lca might just as well.
                /* crvec.clear(); */
                /* d1(x, -1); */
                /* crvec.clear(); */
                /* d1(x); */
                int k = 0;
                // xd
                /* while(k < min(vec[x].size(), vec[j].size()) && vec[x][k] == vec[x][j]) */
                while(k < min(vec[x].size(), vec[j].size()) && vec[x][k] == vec[j][k])
                    ++k;
                int d1 = vec[x].size() - k;
                int d2 = vec[j].size() - k;
                bool gt = 0; // czy ten ktory powoduje inv ma dalszy dist.
                /* whatis(d1) */
                /* whatis(d2) */
                if(d1 < d2)
                    swap(d1,d2), gt ^= 1;
                if(dsdp[d1][d2] == -1){
                    int dp[d1+1][d2+1];
                    memset(dp,0,sizeof dp);
                    dp[0][0] = 1;
                    FOR(i,0,d1){
                        FOR(x,0,d2){
                            dp[i+1][x] += dp[i][x] * inv2 % mod;
                            dp[i+1][x] %= mod;
                            dp[i][x+1] += dp[i][x] * inv2 % mod;
                            dp[i][x+1] %= mod;
                        }
                    }
                    int c1 = 0;
                    FOR(x,0,d2){
                        c1 += dp[d1][x];
                        c1 %= mod;
                    }
                    /* whatis(c1) */
                    int c2 = 0;
                    FOR(x,0,d1){
                        c2 += dp[x][d2];
                        c2 %= mod;
                    }
                    assert((c1 + c2) % mod == 1);
                    dsdp[d1][d2] = c1;
                }
                if(gt){
                    cr += dsdp[d1][d2];
                }
                else{
                    cr += (1 - dsdp[d1][d2]) % mod;
                }
                cr %= mod;
            }
        }
        cr += mod;
        cr %= mod;
        /* whatis(i) */
        /* whatis(cr) */
        res += cr;
        res %= mod;
    }
    cout << res * fastpow(n, mod - 2) % mod << '\n';
}