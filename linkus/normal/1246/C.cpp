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
#define N 1000001
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    sc(n,m);
    string in[n];
    FORR(i,in)
        getstr(i);
    if(n == 1 && m == 1){
        REE((in[0][0] == '.'))
    }
    ll mod = 1e9+7;
    ll dp[n][m][2]; //0 -> z gory, musi w prawo
    int dokr[n][m]; //dokad exclusive -> gdzie decrement
    memset(dokr,0,sizeof dokr);
    FOR(i,0,n){
        dokr[i][m-1] = m;
        for(int x = m-2; x >= 0; --x){
            dokr[i][x] = dokr[i][x+1];
            if(in[i][x+1] == 'R'){
                --dokr[i][x];
            }
        }
    }
    int dokc[n][m]; //dokad exclusive -> gdzie decrement
    memset(dokc,0,sizeof dokr);
    FOR(x,0,m){
        dokc[n-1][x] = n;
        for(int i = n-2; i >= 0; --i){
            dokc[i][x] = dokc[i+1][x];
            if(in[i+1][x] == 'R'){
                --dokc[i][x];
            }
        }
    }
    /* whatis(dokr[1][0]) */
    /* whatis(dokc[0][1]) */
    //1 -> z lewa, musi w dol
    memset(dp,0,sizeof dp);
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    ll prec[n+1][m+1], prer[n+1][m+1];
    memset(prec,0,sizeof prec); //kolumnami w dol
    memset(prer,0,sizeof prec); //rowami w prawo
    FOR(i,0,n){
        FOR(x,0,m){
            whatis(i)
            whatis(x)
            {
                if(i){
                    prec[i][x] += prec[i-1][x];
                    prec[i][x] = (prec[i][x]+mod)%mod;
                }
                dp[i][x][0] += prec[i][x];
                dp[i][x][0] %= mod;
                prer[i][x+1] += dp[i][x][0];
                prer[i][x+1] = (prer[i][x+1]+mod)%mod;
                /* whatis(dokr[i][x]) */
                prer[i][dokr[i][x]] -= dp[i][x][0];
                prer[i][dokr[i][x]] = (prer[i][dokr[i][x]]+mod)%mod;
            }
            {
                if(x){
                    prer[i][x] += prer[i][x-1];
                    prer[i][x] = (prer[i][x]+mod)%mod;
                }
                dp[i][x][1] += prer[i][x];
                dp[i][x][1] %= mod;
                prec[i+1][x] += dp[i][x][1];
                prec[i+1][x] %= mod;
                prec[dokc[i][x]][x] -= dp[i][x][1];
                prec[dokc[i][x]][x] = (prec[dokc[i][x]][x]+mod)%mod;
            }
            whatis(dp[i][x][0])
            whatis(dp[i][x][1])
        }
    }
    cout << ((dp[n-1][m-1][0] + dp[n-1][m-1][1])%mod+mod)%mod << '\n';
}