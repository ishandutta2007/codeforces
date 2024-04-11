/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC optimize("Ofast,unroll-loops") */
/* #pragma GCC target("avx2,popcnt") */
#include <bits/stdc++.h>
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
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 400004
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    string a[n];
    FORR(i,a)
        getstr(i);
    int bal[n];
    static int cntbal[20][N]; // ujemny tylko zliczamy obv.
    int lowbal[n]; // neg.
    FOR(i,0,n){
        int crbal = 0;
        int mnbal = 0;
        FORR(x,a[i]){
            if(x == '('){
                ++crbal;
            }
            else{
                --crbal;
                mnbal = min(mnbal, crbal);
                if(mnbal == crbal){
                    /* ++cntbal[i][crbal]; */
                    ++cntbal[i][-crbal];
                }
            }
        }
        bal[i] = crbal;
        lowbal[i] = mnbal;
        /* whatis(i) */
        /* whatis(bal[i]) */
        /* whatis(lowbal[i]) */
    }
    /* pi dp[1 << n]; // {res, bal (const)}; */
    pi dp[1 << n][2]; // {res, bal (const)} [isdp-INF];
    memset(dp,-1,sizeof dp);
    /* dp[0] = {0, 0}; */
    dp[0][0] = {0, 0};
    FOR(i,0,1<<n){
        /* whatis(i) */
        /* whatis(dp[i]) */
        FOR(j,0,2)
        FOR(x,0,n){
            if(dp[i][j].first == -1)
                continue;
            int newm = i | (1 << x);
            if(newm == i)
                continue;
            int nwbal, nwres;
            if(dp[i][j].e2 == -INF || lowbal[x] < -dp[i][j].e2){
                nwbal = -INF;
            }
            else{
                nwbal = dp[i][j].e2 + bal[x];
            }
            nwres = dp[i][j].e1;
            // niezalenie o nwbal cnie.
            if(dp[i][j].e2 != -INF){
                assert(dp[i][j].e2 >= 0);
                assert(j == 0);
                nwres += cntbal[x][dp[i][j].e2];
            }
            else{
                assert(j == 1);
            }
            int nwdim = nwbal == -INF;
            /* dp[newm] = max(dp[newm], {nwres, nwbal}); */
            if(dp[newm][nwdim].first != -1){
                assert(nwbal == dp[newm][nwdim].second);
            }
            dp[newm][nwdim] = max(dp[newm][nwdim], {nwres, nwbal});
        }
    }
    /* cout << dp[(1 << n) - 1].first << '\n'; */
    cout << max(dp[(1 << n) - 1][0].first,dp[(1 << n) - 1][1].first) << '\n';
}