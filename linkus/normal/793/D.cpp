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
#define N 1000001

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,k;
    sc(n,k);
    int m;
    sc(m);
    vector<pi> adj[n+2];
    while(m--){
        int f,s,w;
        sc(f,s,w);
        adj[f].pb({s,w});
    }
    int dp[k+1][n+2][n+2][n+2];
    memset(dp,127,sizeof dp);;
    /* priority_queue<array<int,5>> qu; */
    /* queue<array<int,5>> qu; */
    deque<array<int,5>> qu;
    FORE(i,1,n){
        dp[1][0][n+1][i] = 0;
        /* qu.push({{0,1,0,n+1,i}}); */
        qu.push_back({{0,1,0,n+1,i}});
    }
    while(!qu.empty()){
        /* array<int,5> cr = qu.top(); qu.pop(); */
        /* array<int,5> cr = qu.front(); qu.pop(); */
        array<int,5> cr = qu.front(); qu.pop_front();
        int kk = cr[1], l = cr[2], r = cr[3], v = cr[4];
        int w = -cr[0];
        if(w != dp[kk][l][r][v]) continue;
        if(kk == k) continue;
        /* if(kk != 1){ */
        /*     whatis(kk) */
        /*     whatis(l) */
        /*     whatis(r) */
        /*     whatis(zw) */
        /*     whatis(w) */
        /*     cout << endl << '\n'; */
        /* } */
        FORR(i,adj[v]){
            int neww = w+i.e2;
            if(i.e1 < v){
                if(i.e1 > l){
                    if(neww < dp[kk+1][l][v][i.e1]){
                        dp[kk+1][l][v][i.e1] = neww;
                        /* qu.push({-neww,kk+1,l,v,i.e1}); */
                        qu.push_back({-neww,kk+1,l,v,i.e1});
                    }
                }
            }
            else{
                if(i.e1 < r){
                    if(neww < dp[kk+1][v][r][i.e1]){
                        dp[kk+1][v][r][i.e1] = neww;
                        /* qu.push({-neww,kk+1,v,r,i.e1}); */
                        qu.push_back({-neww,kk+1,v,r,i.e1});
                    }
                }
            }
        }
        /* if(zw == 0){ */
        /*     FORR(i,adj[l]){ */
        /*         if(i.e1 < l){ */
        /*             int neww = i.e2+w; */
        /*             if(dp[kk+1][i.e1][l][0] > neww){ */
        /*                 dp[kk+1][i.e1][l][0] = neww; */
        /*                 qu.push({-neww,kk+1,i.e1,l,0}); */
        /*             } */
        /*         } */
        /*         else if(i.e1 < r){ */
        /*             int neww = i.e2+w; */
        /*             if(dp[kk+1][l][i.e1][1] > neww){ */
        /*                 dp[kk+1][l][i.e1][1] = neww; */
        /*                 qu.push({-neww,kk+1,l,i.e1,1}); */
        /*             } */
        /*         } */
        /*     } */
        /* } */
        /* else{ */
        /*     FORR(i,adj[r]){ */
        /*         if(i.e1 > r){ */
        /*             int neww = i.e2+w; */
        /*             if(dp[kk+1][r][i.e1][1] > neww){ */
        /*                 dp[kk+1][r][i.e1][1] = neww; */
        /*                 qu.push({-neww,kk+1,r,i.e1,1}); */
        /*             } */
        /*         } */
        /*         else if(i.e1 > l){ */
        /*             int neww = i.e2+w; */
        /*             if(dp[kk+1][i.e1][r][0] > neww){ */
        /*                 dp[kk+1][i.e1][r][0] = neww; */
        /*                 qu.push({-neww,kk+1,i.e1,r,0}); */
        /*             } */
        /*         } */
        /*     } */
        /* } */
    }
    int ans = INF;
    FORR(i,dp[k])
        FORR(x,i)
            FORR(j,x)
                ans = min(ans,j);
    cout << (ans == INF?-1:ans) << '\n';
}