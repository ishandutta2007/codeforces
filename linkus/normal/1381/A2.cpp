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
        string a,b;
        getstr(a);
        getstr(b);
        vi ops;
        int xr = 0;
        pi lr = {0,n-1};
        int last = n;
        string ca = a;
        for(int i = n-1; i >= 0; --i){ // i == 0 edge case?
            /* int dpos = (xr ? : i); */
            /* whatis(i) */
            /* whatis(lr) */
            int cp = (xr ? lr.e2-i : lr.e1+i);
            /* whatis(ca) */
            /* whatis(cp) */
            int crv = (xr ? a[lr.e2-i] ^ 1: a[lr.e1+i]);
            /* whatis(crv) */
            /* assert(crv == ca[i]); */
            /* if((a[i]) == b[i]) continue; */
            /* if((ca[i]) == b[i]){ */
            if(crv == b[i]){
                if(xr == 0){
                    lr.e2 -= 1;
                }
                else{
                    lr.e1 += 1;
                }
                continue;
            }
            /* if((a[0] ^ 1) != b[i]){ */
            /*     ops.push_back(1); */
            /*     a[0] ^= 1; */
            /* } */
            int crv0 = (xr ? a[lr.e2-0] ^ 1: a[lr.e1+0]);
            /* assert(crv0 == ca[0]); */
            /* if((ca[0] ^ 1) != b[i]){ */
            if((crv0 ^ 1) != b[i]){
                ops.push_back(1);
                /* ca[0] ^= 1; */
                a[xr ? lr.e2-0: lr.e1+0] ^= 1;
            }
            ops.push_back(i+1);
            int dif = last-i;
            if(xr == 0){
                /* lr.e1 += dif; */
                lr.e1 += 1;
            }
            else{
                /* lr.e2 -= dif; */
                lr.e2 -= 1;
            }
            /* whatis(ca) */
            last = i;
            xr ^= 1;
            /* string na = ca; */
            /* for(int x = 0; x <= i; ++x){ */
            /*     /1* na[x] = a[i-x-1] ^ 1; *1/ */
            /*     na[x] = ca[i-x] ^ 1; */
            /* } */
            /* ca = na; */
            /* xr ^= 1; */
        }
        /* int df[n]; */
        /* int cnt = 0; */
        /* FOR(i,0,n){ */
        /*     df[i] = a[i] != b[i]; */
        /*     cnt += df[i]; */
        /* } */
        /* vi beg = {-1,-2,1,n}; */
        /* /1* if(cnt > n/2){ *1/ */
        /* /1* if(cnt == n){ *1/ */
        /* FORR(xd,beg){ */
        /*     int xr = 0; */
        /*     vi ops; */
        /*     if(xd > 0){ */
        /*         ops.push_back(xd); */
        /*         int nwdf[n]; */
        /*         string tmp = a; */
        /*         FOR(i,0,xd){ */
        /*             /1* tmp[i] ^= 1; *1/ */
        /*             tmp[i] = (a[xd-i-1] ^ 1); */
        /*             /1* nwdf[i] = df[n-i-1] ^ 1; *1/ */
        /*             /1* nwdf[i] = (a[n-i-1] ^ 1) != b[i]; *1/ */
        /*             /1* whatis(nwdf[i]) *1/ */
        /*             /1* df[i] ^= 1; *1/ */
        /*         } */
        /*         FOR(i,0,n){ */
        /*             nwdf[i] = tmp[i] != b[i]; */
        /*         } */
        /*         memcpy(df,nwdf, n<<2); */
        /*     } */
        /* /1* } *1/ */
        /*     /1* int prexr = 0; *1/ */
        /*     bool prev = 0; */
        /*     /1* if(xd == -2){ *1/ */
        /*     /1*     xr = 1; *1/ */
        /*     /1*     for(int i = n-1; i >= 0; --i){ *1/ */
        /*     /1*         if(prev){ *1/ */
        /*     /1*             ops.push_back(n); *1/ */
        /*     /1*             xr ^= 1; *1/ */
        /*     /1*             prev = 0; *1/ */
        /*     /1*         } *1/ */
        /*     /1*         if(df[i] ^ prexr ^ 1){ *1/ */
        /*     /1*             ops.push_back(i+1); *1/ */
        /*     /1*             prexr ^= 1; *1/ */
        /*     /1*             prev = 1; *1/ */
        /*     /1*             /2* ops.push_back(n); *2/ *1/ */
        /*     /1*             xr ^= 1; *1/ */
        /*     /1*         } *1/ */
        /*     /1*     } *1/ */
        /*     /1*     if(xr){ *1/ */
        /*     /1*         continue; *1/ */
        /*     /1*     } *1/ */
        /*     /1* } *1/ */
        /*     /1* else{ *1/ */
        /*     /1* for(int i = n-1; i >= 0; --i){ *1/ */
        /*     /1*     if(prev){ *1/ */
        /*     /1*         ops.push_back(n); *1/ */
        /*     /1*         xr ^= 1; *1/ */
        /*     /1*         prev = 0; *1/ */
        /*     /1*     } *1/ */
        /*     /1*     if(df[i] ^ prexr){ *1/ */
        /*     /1*         ops.push_back(i+1); *1/ */
        /*     /1*         prexr ^= 1; *1/ */
        /*     /1*         prev = 1; *1/ */
        /*     /1*         /2* ops.push_back(n); *2/ *1/ */
        /*     /1*         xr ^= 1; *1/ */
        /*     /1*     } *1/ */
        /*     /1* } *1/ */
        /*     for(int i = n-1; i >= 0; --i){ */
        /*         if(prev){ */
        /*             /1* ops.push_back(n); *1/ */
        /*             xr ^= 1; */
        /*             prev = 0; */
        /*         } */
        /*         if(df[i]){ */
        /*             ops.push_back(i+1); */
        /*             prev = 1; */
        /*             ops.push_back(i); */
        /*             xr ^= 1; */
        /*         } */
        /*     } */
        /*     if(xr){ */
        /*         continue; */
        /*     } */
        /*     /1* } *1/ */
        /*     if(ops.size() <= 2*n){ */
        /*     whatis(xd) */
        /*         cout << ops.size() << ' '; */
        /*         FORR(i,ops) */
        /*             cout << i << ' '; */
        /*         cout << '\n'; */
        /*         break; */
        /*     } */
        /* } */
        cout << ops.size() << ' ';
        FORR(i,ops)
            cout << i << ' ';
        cout << '\n';
    }
}