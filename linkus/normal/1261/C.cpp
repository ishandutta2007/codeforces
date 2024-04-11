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
#define N 1000001
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    sc(n,m);
    /* string a[n]; */
    vector<string> a(n);
    FORR(i,a){
        getstr(i);
        i = "." + i + ".";
    }
    a.push_back(string(m + 2, '.'));
    a.insert(a.begin(), string(m + 2, '.'));
    n += 2;
    m += 2;
    assert(n == a.size());
    assert(m == a[1].size());
    /* int low = 0, high = n, mid, ans; */
    int low = 0, high = min(n,m), mid, ans;
    vector<string> ansvec(n - 2, string(m - 2, 0));
    while(low <= high){
        mid = (low + high) / 2;
        int t = mid;
        /* int xddd[10000000]{}; */
        /* xddd[2] = 3; */
        int pre[3*n][3*m];
        memset(pre,0,sizeof pre);
        /* int xddd2[10000000]{}; */
        int pre2[3*n][3*m];
        memset(pre2,0,sizeof pre);
        const int off1 = n + n / 2;
        const int off2 = m + m / 2;
        FOR(i,0,n){
            FOR(x,0,m){
                if(a[i][x] == '.'){
                    // offset just i guess.
                    /* pre[i-t][x-t] = max(pre[i-t][x-t], 2*t+1); */
                    pre[i-t+off1][x-t+off2] = max(pre[i-t+off1][x-t+off2], 2*t+1);
                }
            }
        }
        int ile = 0;
        FOR(i,-n,n){
            FOR(x,-m,m){
                assert(i+off1 >= 0 && x + off2 >= 0);
                pre[i+off1][x+off2] = max(pre[i+off1][x+off2], pre[i+off1-1][x+off2] - 1);
                pre[i+off1][x+off2] = max(pre[i+off1][x+off2], pre[i+off1][x+off2-1] - 1);
                pre[i+off1][x+off2] = max(pre[i+off1][x+off2], pre[i+off1-1][x+off2-1] - 1);
                if(i >= 0 && x >= 0){
                    if(pre[i+off1][x+off2] > 0){ // '.' reaches -> can't have (init) 'X' there.
                    }
                    else{
                        ++ile;
                        assert(a[i][x] == 'X');
                        pre2[i-t+off1][x-t+off2] = max(pre2[i-t+off1][x-t+off2], 2*t+1);
                    }
                }
            }
        }
        bool git = 1;
        FOR(i,-n,n){
            FOR(x,-m,m){
                pre2[i+off1][x+off2] = max(pre2[i+off1][x+off2], pre2[i+off1-1][x+off2] - 1);
                pre2[i+off1][x+off2] = max(pre2[i+off1][x+off2], pre2[i+off1][x+off2-1] - 1);
                pre2[i+off1][x+off2] = max(pre2[i+off1][x+off2], pre2[i+off1-1][x+off2-1] - 1);
                if(i >= 0 && x >= 0){
                    if(a[i][x] == 'X' && !pre2[i+off1][x+off2]){
                        git = 0;
                    }
                    /* if(pre[i][x] > 0){ // '.' reaches -> can't have 'X' there. */
                    /* } */
                    /* else{ */
                    /*     ++ile; */
                    /*     assert(a[i][x] == 'X'); */
                    /*     pre2[i-t][x-t] = max(pre2[i-t][x-t], 2*t+1); */
                    /* } */
                }
            }
        }
        /* whatis(mid) */
        /* whatis(ile) */
        /* whatis(git) */
        if(ile > 0 && git){
            ans = mid;
            low = mid + 1;
            /* ansvec= */
            FOR(i,1,n-1){
                FOR(x,1,m-1){
                    /* ansvec[i-1][x-1] = a[i][x] == 'X' && pre[i][x] == 0 ? 'X' : '.'; */
                    ansvec[i-1][x-1] = a[i][x] == 'X' && pre[i+off1][x+off2] == 0 ? 'X' : '.';
                }
            }
        }
        else{
            high = mid - 1;
        }
    }
    /* whatis(ans) */
    cout << ans << '\n';
    FORR(i,ansvec)
        cout << i << '\n';
}