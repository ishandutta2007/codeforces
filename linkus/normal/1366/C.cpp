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

int n,m;
int a[30][30];
vi adj[1000];

int cr[2];
bool vis[1000];

void d1(int v){
    vis[v] = 1;
    ++cr[a[v/m][v%m]];
    FORR(i,adj[v]){
        if(!vis[i])
            d1(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // for oevery possible palindromic cell combination, they must be the same
    // foreach cell, compute dist. foreach cell with dits from it eq to dist
    // from 0 for itself, add edges.
    // all conn comp need to be same -> ez
    int t;
    sc(t);
    while(t--){
        FORR(i,adj)
            i.clear();
        memset(vis,0,1000);
        sc(n,m);
        FOR(i,0,n)
            FOR(x,0,m)
                sc(a[i][x]);
        FOR(i,0,n){
            FOR(x,0,m){
                FOR(k,0,n){
                    FOR(j,0,m){
                        if(i == k && x == j) continue;
                        if(i <= k && x <= j && i+x == n-1-k+m-1-j){
                            int v1 = i*m+x;
                            int v2 = k*m+j;
                            adj[v1].pb(v2);
                            adj[v2].pb(v1);
                            whatis(i)
                            whatis(x)
                            whatis(k)
                            whatis(j)
                        }
                    }
                }
            }
        }
        int res = 0;
        FOR(i,0,n){
            FOR(x,0,m){
                if(!vis[i*m+x]){
                    cr[0] = 0;
                    cr[1] = 0;
                    d1(i*m+x);
                    res += min(cr[0],cr[1]);
                }
            }
        }
        cout << res << '\n';
    }
}