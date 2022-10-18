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
using namespace __gnu_pbds;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 1000000007

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;
    sc(n);
    ll a[2][n];
    FORR(i,a) GET(i);
    if(n == 1) REE(a[0][1])
    ll pre1[n<<1];
    pre1[0] = a[0][0];
    int pos = 1;
    FOR(i,1,n<<1){
        pre1[i] = pre1[i-1]+a[i/n][pos];
        /* whatis(i) */
        /* whatis(i/n) */
        /* whatis(pos) */
        if(i+1<n) ++pos; else if(i+1>n) --pos;
    }
    ll ans = 0;
    pos = 0;
    ll c1 = 0, c2 = 0;
    ll w1 = 0, w2 = 0;
    FOR(i,0,n<<1){c1 += i*a[i/n][pos]; if(i+1<n) ++pos; else if(i+1>n) --pos;}
    pos = 0;
    FOR(i,0,n<<1){c2 += i*a[(i/n)^1][pos] ;if(i+1<n) ++pos; else if(i+1>n) --pos;};
    ll cur = 0;
    ++w2;
    c2 += pre1[2*n-2]-pre1[0];
    c2 -= a[0][0]*(2*n-1);
    FOR(i,0,n){
        /* whatis(i) */
        if(i&1){
            ans = max(ans,cur+c2);
            /* whatis(cur+c2) */
            /* whatis(cur+c2) */
            /* whatis(c2) */
            if(i+2 < n){
                c2 += 2*(pre1[2*n-i-1-2]-pre1[i+2-1]);
                c2 -= a[1][i]*(i+w2);
                c2 -= a[1][i+1]*(i+w2+1);
                c2 -= a[0][i]*(2*n-1);
                c2 -= a[0][i+1]*(2*n-2);
                /* c2 -= a[i][0]*(i+w2); */
                /* c2 -= a[i][1]*(n-1); */
                /* c2 -= a[i+1][0]*(i+w2+1); */
                /* c2 -= a[i+1][1]*(n-2); */
            }
            w2 += 2;
            cur += a[1][i]*(i*2);
            cur += a[0][i]*(i*2+1);
        }
        else{
            /* whatis(cur+c1) */
            /* whatis(c1) */
            ans = max(ans,cur+c1);
            /* whatis(cur+c1) */
            if(i+2 < n){
                /* whatis(2*(pre1[2*n-i-1-2]-pre1[i+2-1])) */
                /* whatis(pre1[2*n-i-1-2]) */
                /* whatis(pre1[i+2-1]) */
                c1 += 2*(pre1[2*n-i-1-2]-pre1[i+2-1]);
                c1 -= a[0][i]*(i+w1);
                c1 -= a[1][i]*(2*n-1);
                c1 -= a[0][i+1]*(i+w1+1);
                c1 -= a[1][i+1]*(2*n-2);
            }
            w1 += 2;
            cur += a[0][i]*(i*2);
            cur += a[1][i]*(i*2+1);
        }
        /* whatis(cur) */
    }
    ans = max(ans,cur);
    cout << ans << '\n';
}