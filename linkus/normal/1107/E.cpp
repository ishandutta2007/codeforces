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
#define N 101

int n;
string s;
ll gib[N];

/* map<string,ll> dp; */
ll dp[N][N][N];

ll rec(int st, int end, int pre){
    if(dp[st][end][pre]) return dp[st][end][pre];
    if(end-st <= 0) return 0;
    if(end-st == 1) return gib[pre];
    /* whatis(s) */
    /* if(dp.count(s)) return dp[s]; */
    ll cr = 0;
    /* FOR(i,1,nn){ */
    /*     if(s[i] != s[i-1]){ */
    /*         if(!~id1) */
    /*             id1 = i; */
    /*         if(~id1 && s[i] == s[0] && s[i] != s[i-1]) */
    /*             cr = max(cr,rec(string(s.begin(),s.begin()+id1)+string(s.begin()+i,s.end()))+rec(string(s.begin()+id1,s.begin()+i))); */
    /*     } */
    /* } */
    cr = gib[pre]+rec(st+1,end,1);
    FOR(i,st+1,end){
        if(s[i] == s[st]){
            cr = max(cr,rec(st+1,i,1)+rec(i,end,pre+1));
        }
    }////
    return dp[st][end][pre] = cr;
    /* if(~id1) */
    /*     return cr = max(cr,gib[id1]+rec(string(s.begin()+id1,s.end()))); */
    /* else */
    /*     return dp[s] = gib[nn]; */
    /* whatis(s) */
    /* whatis(id2) */
    /* whatis(id1) */
    /* if(~id2) */
    /*     return dp[s] = max(gib[id1]+rec(string(s.begin()+id1,s.end())),gib[id2-id1]+rec(string(s.begin(),s.begin()+id1)+string(s.begin()+id2,s.end()))); */
    /* if(~id1) */
    /*     return dp[s] = gib[id1]+gib[nn-id1]; */
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n);
    getstr(s);
    FOR(i,1,n+1){
        sc(gib[i]);
    }
    FOR(i,1,n+1){
        int xd = 1;
        for(int x = i << 1; x <= n; x += i){
            gib[x] = max(gib[x],gib[i]*++xd);
        }
    }
    cout << rec(0,n,1);
    /* whatis(dp) */
}