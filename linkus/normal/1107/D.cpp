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
#define N 5201

int pre[N][N];
int a[N][N];

int get(int x1, int y1, int x2, int y2){
    return pre[x2][y2] - (x1?pre[x1-1][y2]:0) - (y1?pre[x2][y1-1]:0) + (x1 && y1?pre[x1-1][y1-1]:0);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    char c1,c2;
    /* whatis(n) */
    FOR(i,0,n){
        /* whatis(i) */
        int cr = 0;
        FOR(x,0,n/4){
            /* whatis(n/4) */
            /* whatis(x) */
            getch(c1);
            int xd = (isdigit(c1)?c1-'0':c1-55);
            FOR(c,0,4){
                cr += (a[i][x*4+c] = bool(xd & (1 << (3-c))));
                pre[i][x*4+c] = (i?pre[i-1][x*4+c]:0)+cr;
            }
        }
    }
    /* FOR(i,0,n){ */
    /*     FOR(x,0,n) */
    /*         cout << pre[i][x] << ' '; */
    /*     cout << '\n'; */
    /* } */
    /* FOR(i,0,n){ */
    /*     FOR(x,0,n) */
    /*         cout << a[i][x]; */
    /*     cout << '\n'; */
    /* } */
    int ans = 1;
    FORE(i,2,n){
        if(n%i) continue;
        int isq = i*i;
        bool k = 1;
        /* whatis(i) */
        for(int x = 0; x+i <= n; x += i){
            for(int j = 0; j+i <= n; j += i){
                /* int ret = get(x+i-1,j+i-1,x,i); */
                int ret = get(x,j,x+i-1,j+i-1);
                /* whatis(ret) */
                if(ret != 0 && ret != isq){
                    k = 0;
                    break;
                }
            }
            if(!k) break;
        }
        if(k) ans = i;
    }
    cout << ans << '\n';
}