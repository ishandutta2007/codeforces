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
    int n,m;
    sc(n,m);
    vi adj[n];
    int f,s;
    while(m--){
        sc(f,s);
        --f,--s;
        adj[f].pb(s);
    }
    int ds[n][n];
    memset(ds,127,sizeof ds);
    queue<int> qu;
    FOR(i,0,n){
        ds[i][i] = 0;
        qu.push(i);
        while(!qu.empty()){
            int v = qu.front();
            qu.pop();
            FORR(x,adj[v]){
                if(ds[i][v]+1 < ds[i][x]){
                    ds[i][x] = ds[i][v]+1;
                    qu.push(x);
                }
            }
        }
    }
    vector<pi> mxin[n];
    vector<pi> mxout[n];
    FOR(i,0,n){
        FOR(x,0,n){
            if(i == x) continue;
            if(ds[x][i] != INF)
                mxin[i].pb({ds[x][i],x});
        }
        sort(all(mxin[i]),greater<pi>());
        if(mxin[i].size() > 3)
            mxin[i].erase(mxin[i].begin()+3,mxin[i].end());
    }
    FOR(i,0,n){
        FOR(x,0,n){
            if(i == x) continue;
            if(ds[i][x] != INF)
                mxout[i].pb({ds[i][x],x});
        }
        sort(all(mxout[i]),greater<pi>());
        if(mxout[i].size() > 3)
            mxout[i].erase(mxout[i].begin()+3,mxout[i].end());
    }
    int bs = 0;
    vi ans;
    FOR(i,0,n){
        FOR(x,0,n){
            if(ds[i][x] == INF) continue;
            if(i == x) continue;
            FORR(j,mxin[i]){
                FORR(k,mxout[x]){
                    if(j.e2 == k.e2 || k.e2 == i || j.e2 == x) continue;
                    int nw = ds[i][x] + j.e1 + k.e1;
                    /* if(i == 0 && x == 7){ */
                    /*     whatis(nw) */
                    /*     whatis(j.e2+1) */
                    /*     whatis(i+1) */
                    /*     whatis(x+1) */
                    /*     whatis(k.e2+1) */
                    /* } */
                    if(nw > bs){
                        bs = nw;
                        ans = {j.e2,i,x,k.e2};
                    }
                }
            }
        }
    }
    whatis(bs)
    /* assert(bs); */
    /* FOR(i,0,4) */
    /*     FOR(x,i+1,4) */
    /*         assert(ans[i] != ans[x]); */
    FORR(i,ans)
        cout << i+1 << ' ';
    /* FOR(i,0,n){ */
    /*     FOR(x,0,n){ */
    /*         cout << ds[i][x] << ' '; */
    /*     } */
    /*     cout << '\n'; */
    /* } */
}