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
    int t,n,m;
    sc(t);
    while(t--){
        sc(n,m);
        char a[n][m];
        FORR(i,a)
            FORR(x,i)
                getch(x);
        int mx = -1;
        pi last;
        FORR(i,a){
            FORR(x,i){
                x -= 'a';
                mx = max(mx,(int)x);
            }
        }
        int row[26];
        int kol[26];
        memset(row,-1,sizeof row);
        memset(kol,-1,sizeof row);
        int mnr[26],mxr[26],mnc[26],mxc[26];
        memset(mnr,127,sizeof mnr);
        memset(mnc,127,sizeof mnr);
        memset(mxr,0,sizeof mnr);
        memset(mxc,0,sizeof mnr);
        /* whatis(a[0]) */
        FOR(i,0,n){
            FOR(x,0,m){
                if(a[i][x] == -51) continue;
                if(a[i][x] == mx) last = {i,x};
                if(row[a[i][x]] != i){
                    if(~row[a[i][x]])
                        row[a[i][x]] = INF;
                    else
                        row[a[i][x]] = i;
                }
                if(kol[a[i][x]] != x){
                    if(~kol[a[i][x]])
                        kol[a[i][x]] = INF;
                    else
                        kol[a[i][x]] = x;
                }
                mnr[a[i][x]] = min(mnr[a[i][x]],i);
                mnc[a[i][x]] = min(mnc[a[i][x]],x);
                mxr[a[i][x]] = max(mxr[a[i][x]],i);
                mxc[a[i][x]] = max(mxc[a[i][x]],x);
            }
        }
        /* whatis(a[0]) */
        char b[n][m];
        memset(b,-51,sizeof b);
        bool kk = 1;
        array<int,4> ops[mx+1];
        FORE(c,0,mx){
            if(row[c] == -1){
                ops[c] = {{last.e1,last.e2,last.e1,last.e2}};
                continue;
            }
            if(row[c] == INF && kol[c] == INF){
                kk = 0;
                break;
            }
            if(row[c] != INF){
                ops[c] = {{row[c],mnc[c],row[c],mxc[c]}};
                FORE(x,mnc[c],mxc[c])
                    b[row[c]][x] = c;
            }
            else{
                /* whatis(mnr[c]) */
                /* whatis(kol[c]) */
                /* whatis(mxr[c]) */
                ops[c] = {{mnr[c],kol[c],mxr[c],kol[c]}};
                FORE(i,mnr[c],mxr[c])
                    b[i][kol[c]] = c;
            }
        }
        /* whatis(a[0]) */
        FOR(i,0,n){
            FOR(x,0,m){
                /* whatis(i) */
                /* whatis(x) */
                if(b[i][x] != a[i][x]) kk = 0;
            }
        }
        if(kk){
            cout << "YES\n";
            cout << mx+1 << '\n';
            FORR(i,ops){
                FORR(x,i) cout << x+1 << ' ';
                cout << '\n';
            }
        }
        else{
            cout << "NO\n";
        }
        /* whatis(a[0]) */
        /*     whatis(t) */
    }
}