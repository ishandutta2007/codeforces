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
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int n;
    cin >> n;
    int nx[n], p[n];
    memset(nx,-1,n<<2);
    memset(p,-1,n<<2);
    int apr[n];
    for(int x = 0; x < n; ++x){
        apr[x] = 2;
    }
    for(int i = n - 1; i >= 0; --i){
        /* for(int x = 0; x < i; ++x){ */
        /*     a[x] = 1; */
        /* } */
        apr[i] = 1;
        cout << "? ";
        // can't have 0, gr8.
        FORR(i,apr)
            cout << i << ' ';
            /* cout << i + 1 << ' '; */
        cout << endl;
        int wh;
        cin >> wh;
        --wh;
        /* if(wh != -1){ */
        if(wh != -1 && wh != i){
            p[i] = wh;
            /* apr[i] = n; */
        }
        apr[i] = 2;
    }
    int anx[n];
    for(int x = 0; x < n; ++x){
        /* anx[x] = 0; */
        anx[x] = 1;
    }
    for(int i = n - 1; i >= 0; --i){
        /* for(int x = 0; x < i; ++x){ */
        /*     a[x] = 1; */
        /* } */
        anx[i] = 2;
        cout << "? ";
        FORR(i,anx)
            cout << i << ' ';
            /* cout << i + 1 << ' '; */
        cout << endl;
        int wh;
        cin >> wh;
        --wh;
        /* if(wh != -1){ */
        if(wh != -1 && wh != i){ // wh i -> is n.
            nx[i] = wh;
            /* anx[i] = n; */
        }
        // zawsze zera, unless wsm z 1 jednym querowym?
        /* anx[i] = n; */
        /* if( */
        /* anx[i] = n; */
        anx[i] = 1;
    }
    // bruh. anx vs nx. apr vs p.
    FOR(i,0,n){
        /* if(apr[i] != -1) */
        /*     anx[apr[i]] = i; */
        if(p[i] != -1)
            nx[p[i]] = i;
    }
    FOR(i,0,n){
        /* if(anx[i] != -1) */
        /*     apr[anx[i]] = i; */
        if(nx[i] != -1)
            p[nx[i]] = i;
    }
    int wh = -1;
    FOR(i,0,n){
        /* whatis(i) */
        /* whatis(anx[i]) */
        /* whatis(apr[i]) */
        /* if(anx[i] == -1){ */
        if(nx[i] == -1){
            assert(wh == -1);
            wh = i;
        }
    }
    assert(wh != -1);
    int a[n];
    int it = n - 1;
    FOR(i,0,n){
        assert(wh != -1);
        a[wh] = it--;
        /* wh = apr[wh]; */
        wh = p[wh];
    }
    assert(wh == -1);
    cout << "! ";
    FORR(i,a)
        cout << i + 1 << ' ';
    cout << endl;
}