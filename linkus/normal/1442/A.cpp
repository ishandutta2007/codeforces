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

// fuck this shit, let's do b

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    int tt = 0;
    while(t--){
        int n;
        sc(n);
        int a[n];
        GET(a);
        /* if(++tt == 59){ */
        /*     FORR(i,a) */
        /*         cout << i << '_'; */
        /*     cout << '\n'; */
        /*     exit(0); */
        /* } */
        bool kk = 0;
        // 2 1 2 1 good but
        // 3 1 3 1 bad
        // ???
        // that's good actually^^
        FOR(_,0,2){
            int mn = INF;
            int mxl = -INF;
            int mxr[n]; // najmniejsza na prawo inclusive, lub -inf jak zle
            mxr[n-1] = a[n-1];
            // chcemy good / min na sufie
            // bo musi byc <= ten mid
            for(int i = n-2; i >= 0; --i){
                if(a[i] > mxr[i+1]){
                    /* mxr[i] = INF; */
                    mxr[i] = -INF;
                }
                else{
                    /* mxr[i] = max(mxr[i+1], a[i]); */
                    /* mxr[i] = min(mxr[i+1], a[i]); */
                    mxr[i] = a[i];
                }
            }
            // reverse po tym?
            // moze nie opyla si zawsze maxa usuwa na prefie?
            // nope, opaca si, bo chcemy zminimalizowa te elementy
            // ale nie wewntrz!!!
            int mxdec = INF;
            FOR(i,0,n){
                whatis(i)
                whatis(mxr[i+1])
                /* mn = min(mn,a[i]); */
                // bad -> nie chc minimalizowa wewntrz, chce zminimalizowa,
                // ale eby byo >= od poprzednika
                // -> max z poprzednim mxl, zamiast break jak mniejszy...
                /* int nw = a[i] - mn; */
                // X musi byc >= all na lewo
                // musi byc <= all na lewo pod pref wsm to nie.
                // musi byc >= all na lewo pod suf <- to
                // X musi byc <= all na lewo pod suf
                /* if(nw < mxl) */
                /*     break; */
                // that's the cause of wa^^
                /* mxl = nw; */
                // break tylko wtedy, jak a[i] < mxl tutaj, bo ofc nie moemy
                // go zwikszy
                /* if(a[i] < mxl) */
                /*     break; */
                // still wa on test 2 ja jebie (ale 59th token zamiast 14th)
                /* mxl = max(mxl,nw); */
                // nvm, nie mona tak randomowo ustawia tego elementu, bo
                // ilo dekrementw musi by nierosnca na prefie...
                // :
                /* int dec = a[i] - mxl; */
                /* int dec = min(a[i], mxdec); */
                int dec = min({a[i], mxdec, a[i] - mxl});
                // dec <= a[i] - mxl
                mxdec = min(mxdec, dec);
                /* if(a[i] - dec > mxl) */
                // za, same, -> min z jeszcze jednym variablem
                /* if(a[i] - dec < mxl) */
                /*     break; */
                if(dec < 0)
                    break;
                // sole final decision up to the suffix sequence
                // wsm nie, jeli a[i] < mxl no to bad
                mxl = max(mxl,a[i] - dec);
                // -> za, nie musz decowa na pae cnie
                /* if(dec > mxdec) */
                /*     break; */
                mxdec = dec;
                whatis(mxl)
                // <= all na prawo
                /* if(i+1 == n || mxl >= mxr[i+1]){ */
                if(i+1 == n || mxl <= mxr[i+1]){
                    kk = 1;
                    break;
                }
            }
            // gj
            reverse(a,a+n);
            // still hmm
        }
        cout << (kk ? "YES\n" : "NO\n");
    }
}