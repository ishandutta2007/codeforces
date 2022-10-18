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
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
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
#define debug(x...) ;
#endif
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) { return o << '(' << p.first << ", " << p.second << ')'; }
template<class T, enable_if_t<!is_same<T, string>::value, bool> = true> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) { o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}'; }
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 200001

ll n,k;
constexpr ll mod = 998244353;

ll dp[N][2]; // [ilo -1][0 -> same 1 -> dif]
vi a[2];
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n,k);
    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[1][0] = k - 1;
    dp[1][1] = k - 2;
    FOR(i,2,N){
        dp[i][0] = dp[i-2][0] * dp[1][0] + dp[i-2][1] * dp[1][1] % mod * (k - 1);
        dp[i][1] = dp[i-2][1]*dp[1][1]%mod*(k-2) + dp[i-2][1]*dp[1][0] + dp[i-2][0]*dp[1][1];
        dp[i][0] %= mod;
        dp[i][1] %= mod;
    }
    FOR(i,0,n){
        int cr;
        sc(cr);
        a[i&1].push_back(cr);
    }
    ll res = 1;
    FORR(i,a){
        if(i.empty()) continue;
        ll cr = 1;
        int ile = 0;
        int pr = -1;
        FORR(x,i){
            if(x == -1){
                ++ile;
            }
            else{
                if(pr == -1){
                    if(ile){
                        cr = (k - 1) * dp[ile-1][1] + dp[ile-1][0];
                        cr %= mod;
                    }
                }
                else{
                    cr *= dp[ile][pr != x];
                    cr %= mod;
                }
                ile = 0;
                pr = x;
            }
        }
        if(ile){
            if(pr == -1){
                if(ile == 1){
                    cr = k;
                }
                else{
                    cr = (k - 1) * k % mod * dp[ile-2][1] % mod + k * dp[ile-2][0] % mod;
                    cr %= mod;
                }
            }
            else{
                /* cr = (k - 1) * dp[ile-1][1] + dp[ile-1][0]; */
                // nice bug spot.
                cr *= ((k - 1) * dp[ile-1][1] + dp[ile-1][0]) % mod;
                cr %= mod;
            }
        }
        res *= cr;
        res %= mod;
    }
    cout << res << '\n';
}