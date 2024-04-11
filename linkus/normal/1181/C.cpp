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
#define N 1000

int n,m;
string a[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n,m);
    FOR(i,0,n)
        getstr(a[i]);
    ll ans = 0;
    /* pair<char,int> pre[n][m]; //{col,ilepodrzad (powyej)} */
    /* FOR(x,0,m){ */
    /*     FOR(i,0,n){ */
    /*         pre[i][x] = {a[i][x],1}; */
    /*         if(i && a[i-1][x] == a[i][x]) pre[i][x].e2 = pre[i-1][x].e2+1; */
    /*     } */
    /* } */
    int targ[n][m]; //ile pod rzad ale w dol
    FOR(x,0,m){
        for(int i = n-1; i >= 0; --i){
            targ[i][x] = 1;
            if(i+1 != n && a[i][x] == a[i+1][x]) targ[i][x] = targ[i+1][x] + 1;
        }
    }
    FOR(i,1,n-1){
        int cu = -1,cm = -1,cl = -1;
        int st = 0;
        int wh = -1;
        FOR(x,0,m){ //top of mid
            if(a[i][x] == a[i-1][x]){
                ans += (ll)(st)*(st+1)/2;
                st = 0;
                cu = -1,cm = -1,cl = -1;
                    wh = -1;
                continue;
            };
            int h = targ[i][x];
            /* if(i == 3 && x == 1){ */
            /*     whatis(i) */
            /*     whatis(x) */
            /*     whatis(h) */
            /*     whatis(i+h < n && i-h >= 0 && targ[i+h][x] == h && targ[i-h][x] == h) */
            /* } */
            if(i+h < n && i-h >= 0 && targ[i+h][x] >= h && targ[i-h][x] >= h){
                if(wh == h && a[i][x] == cm && a[i-1][x] == cu && a[i+h][x] == cl){
                    ++st;
                }
                else{
                    ans += (ll)(st)*(st+1)/2;
                    st = 1;
                    cu = a[i-1][x],cm = a[i][x],cl = a[i+h][x];
                    wh = h;
                    continue;
                }
            }
            else{
                ans += (ll)(st)*(st+1)/2;
                st = 0;
                cu = -1,cm = -1,cl = -1;
                    wh = -1;
                continue;
            }
        }
        ans += (ll)(st)*(st+1)/2;
    }
    cout << ans << '\n';
}