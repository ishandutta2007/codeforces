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
#define N 1000005

int pre[N];
int suf[N];
int n,x;

inline bool g(int f, int s){
    if((f-1 >= 0 && pre[f-1] == -1) || (s+1 <= x && suf[s+1] == -1)) return 0;
    if(f-1 >= 0 && s+1 <= x)
        return pre[f-1] <= suf[s+1];
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(pre,-1,N<<2);
    memset(suf,-1,N<<2);
    sc(n,x);
    int a[n];
    GET(a);
    vi wh[x+1];
    FOR(i,0,n){
        wh[a[i]].pb(i);
    }
    pre[0] = 0;
    {
        FORR(x,wh[0]){
            pre[0] = max(pre[0],x);
        }
    }
    FORE(i,1,x){
        bool kk = 1;
        int ls = -1;
        FORR(x,wh[i]){
            if(x < pre[i-1]){
                kk = 0;
                break;
            }
            ls = max(ls,x);
        }
        if(!kk) break;
        pre[i] = max(ls,pre[i-1]);
        /* whatis(i) */
        /* whatis(pre[i]) */
    }
    suf[x] = INF;
    {
        FORR(j,wh[x]){
            suf[x] = min(suf[x],j);
        }
    }
    for(int i = x-1; i >= 0; --i){
        bool kk = 1;
        int ls = INF;
        FORR(x,wh[i]){
            if(x > suf[i+1]){
                kk = 0;
                break;
            }
            ls = min(ls,x);
        }
        if(!kk) break;
        suf[i] = min(ls,suf[i+1]);
        /* whatis(i) */
        /* whatis(suf[i]) */
    }
    int it = 1;
    ll ans = 0;
    FORE(i,1,x){
        /* whatis(i) */
        if(it < i) it = i;
        while(it <= x && !g(i,it)){
            ++it;
        }
        if(it > x) break;
        /* whatis(it) */
        ans += x-it+1;
    }
    cout << ans << '\n';
}