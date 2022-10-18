#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <climits>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <numeric>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
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
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        int n;
        sc(n);
        int a[n],b[n];
        int oa[n],ob[n];
        GET(a);
        GET(b);
        memcpy(oa,a,n<<2);
        memcpy(ob,b,n<<2);
        bool g = 0;
        /* FOR(t,0,2){ */
        /*     memcpy(a,oa,n<<2); */
        /*     memcpy(b,ob,n<<2); */
        /*     if(t == 0){ */
        /*         int ile = min(a[0],b[0]); */
        /*         a[0] -= ile; */
        /*         b[0] -= ile; */
        /*         ile = min(b[0],a[1]); */
        /*         /1* a[1] -= b[0]; // n >= 2 ez *1/ */
        /*         a[1] -= ile; // n >= 2 ez */
        /*     } */
        /*     else{ */
        /*         /1* int ile = a[1]; *1/ */
        /*         int ile = min(a[1],b[0]); */
        /*         a[1] -= ile; */
        /*         b[0] -= ile; */
        /*         ile = min(b[0],a[0]); */
        /*         /1* a[0] -= b[0]; // n >= 2 ez *1/ */
        /*         a[0] -= ile; */
        /*     } */
        /*     bool cg = 1; */
        /*     FOR(i,1,n){ */
        /*         int ile = a[i]; */
        /*         a[i] -= ile; */
        /*         b[i] -= ile; */
        /*         if(b[i] < 0){ */
        /*             cg = 0; */
        /*             break; */
        /*         } */
        /*         ile = min(a[(i+1)%n],b[i]); */
        /*         /1* a[(i+1)%n] -= b[i]; *1/ */
        /*         a[(i+1)%n] -= ile; */
        /*     } */
        /*     FOR(i,0,n){ */
        /*         /1* whatis(a[i]) *1/ */
        /*         if(a[i]) */
        /*             cg = 0; */
        /*     } */
        /*     g |= cg; */
        /* } */
        /* int cr = min(a[1],b[0]); //ile na prawo */
        // na poczatku max, potem wraz z wastem, dec
        /* int high = min(a[1],b[0]); //ile na prawo */
        int high = min(a[0],b[0]); //ile na a[0]
        int low = 0;
        int mid;
        /* for(;;){ */
        while(low <= high){
            mid = (low+high)/2;
            memcpy(a,oa,n<<2);
            memcpy(b,ob,n<<2);
            /* if(t == 0){ */
            /*     int ile = min(a[0],b[0]); */
            /*     a[0] -= ile; */
            /*     b[0] -= ile; */
            /*     ile = min(b[0],a[1]); */
            /*     /1* a[1] -= b[0]; // n >= 2 ez *1/ */
            /*     a[1] -= ile; // n >= 2 ez */
            /* } */
            /* else{ */
                /* int ile = a[1]; */
            /* int ile = min(a[1],b[0]); */
            int ile = mid;
            a[0] -= ile;
            b[0] -= ile;
            ile = min(b[0],a[1]);
            /* a[0] -= b[0]; // n >= 2 ez */
            a[1] -= ile;
            b[0] -= ile;
            /* } */
            bool cg = 1;
            int whf = -1;
            FOR(i,1,n){
                int ile = a[i];
                a[i] -= ile;
                b[i] -= ile;
                if(b[i] < 0){
                    cg = 0;
                    whf = i;
                    break;
                }
                ile = min(a[(i+1)%n],b[i]);
                /* a[(i+1)%n] -= b[i]; */
                a[(i+1)%n] -= ile;
                b[i] -= ile;
            }
            if(whf == -1){
                assert(cg);
                /* FOR(i,0,n-1){ */
                /*     /1* whatis(a[i]) *1/ */
                /*     assert(!a[i]); */
                /*     /1* if(a[i]) *1/ */
                /*     /1*     cg = 0; *1/ */
                /* } */
                if(a[0] == 0){
                    g |= cg;
                    break;
                }
            }
            /* if(whf == n-1){ // does it matter if fail on left/right? */
            if(whf == -1){ // does it matter if fail on left/right?
                // bo moze byc zapelnione right, ale fail total na left hmm
                // right on n-1 -> more on left
                low = mid+1;
            }
            else{ // more on right
                high = mid-1;
            }
        }
        cout << (g ? "YES\n" : "NO\n");
    }
}