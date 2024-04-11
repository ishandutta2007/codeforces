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
        vi a(n);
        GET(a);
        vi b(n);
        GET(b);
        /* sort(all(a)); */
        sort(all(a), greater<int>());
        sort(all(b), greater<int>());
        int low = n, high = 4*n+10, mid, ans;
        while(low <= high){
            mid = (low + high) / 2;
            vi aa = a;
            vi bb = b;
            FOR(x,0,mid-n){
                aa.pb(100);
                bb.pb(0);
            }
            sort(all(aa), greater<int>());
            sort(all(bb), greater<int>());
            int s1 = 0, s2 = 0;
            FOR(i,0,mid-mid/4)
                // bruh
                /* s1 += a[i], s2 += b[i]; */
                s1 += aa[i], s2 += bb[i];
            if(s1 >= s2){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
            /* whatis(mid) */
            /* whatis(aa.size()) */
            /* whatis(bb.size()) */
            /* whatis(s1) */
            /* whatis(s2) */
        }
        /* cout << low - n << '\n'; */
        cout << ans - n << '\n';
        /* int cr = 0; */
        /* int it1 = 0, it2 = 0; */
        /* int s1 = 0, s2 = 0; */
        /* int nn = n; */
        /* /1* int add = 0; *1/ */
        /* /1* vi low; *1/ */
        /* /1* int sumlow = 0; *1/ */
        /* /1* int begit = 0; *1/ */
        /* for(;;){ */
        /*     while(it1 < nn - nn / 4){ */
        /*         /1* s1 += a[it1++]; *1/ */
        /*         s1 += a[it1++]; */
        /*     } */
        /*     while(it2 < nn - nn / 4){ */
        /*         s2 += b[it2++]; */
        /*     } */
        /*     if(s1 >= s2) */
        /*     /1* sumlow += a[it1-1]; *1/ */
        /*     /1* if(s1 + add * 100 - sumlow >= s2) *1/ */
        /*         break; */
        /*     ++cr; */
        /*     ++nn; */
        /*     for (int i = it1-1; i >= 0; --i){ */
        /*         if(a[i] != 100){ */
        /*             int p = a[i]; */
        /*             s1 += 100 - a[i]; */
        /*             a[i] = 100; */
        /*             break; */
        /*         } */
        /*     } */
        /*     /1* ++add; *1/ */
        /*     /1* sumlow += it1-1 < n ? a[it1-1] : 0; *1/ */
        /*     /1* a.pb(100); *1/ */
        /*     b.pb(0); */
        /* } */
        /* cout << cr << '\n'; */
    }

}