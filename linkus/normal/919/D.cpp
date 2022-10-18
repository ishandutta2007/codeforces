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
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
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
template<typename T> inline void print_128(T num){ if(!num) return; print_128(num / 10); cout.put((num % 10) + '0'); }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define MX 300000
int dp[MX][26];
vector<int> adj[MX];
vector<int> adj2[MX];
int val[MX];
int S[MX];
int sid;
bool vis[MX];

void topo1(int cur){
    vis[cur] = 1;
    FORR(i,adj[cur]){
        if(!vis[i])
            topo1(i);
    }
    S[--sid] = cur;
}

int cnt;

void topo2(int cur){
    vis[cur] = 1;
    ++cnt;
    FORR(i,adj2[cur]){
        if(!vis[i])
            topo2(i);
    }
}

inline void dfs(int cur){
    dp[cur][val[cur]] = 1;
    FORR(i,adj[cur]){
        FOR(x,0,26){
            dp[cur][x] = max(dp[cur][x], dp[i][x]+(x==val[cur]));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    sc(n,m);
    FOR(i,0,n){
        val[i] = getchar_unlocked()-'a';
    }
    int f,s;
    while(m--){
        sc(f,s);
        --f,--s;
        if(f == s){
            REE(-1)
        }
        else{
            adj[f].pb(s);
            adj2[s].pb(f);
        }
    }
    sid = n;
    FOR(i,0,n){
        if(!vis[i])
            topo1(i);
    }
    memset(vis,0,n);
    FOR(i,0,n){
        if(!vis[S[i]]){
            cnt = 0;
            topo2(S[i]);
            if(cnt > 1)
                REE(-1)
        }
    }
    int ans = 0;
    for(int i = n; ~--i;){
        dfs(S[i]);
        FOR(x,0,26)
            ans = max(ans,dp[S[i]][x]);
    }
    cout << ans << '\n';
}