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
    int n;
    sc(n);
    int a[n];
    GET(a);
    int pre[n];
    memset(pre, 0, n << 2);
    /* static vector<int> vec[1 << 20]; */
    static vector<int> vec[2][1 << 20];
    int res = 0;
    int crb = 0;
    for(int k = 21; k >= 0; --k){
        int l = INF;
        for(int i = 0; i < 1 << 20; ++i){
            /* vec[i].clear(); */
            vec[0][i].clear();
            vec[1][i].clear();
        }
        /* vec[0].push_back(-1); */
        /* vec[0][0].push_back(-1); */
        vec[1][0].push_back(-1);
        for(int i = 0; i < n; ++i){
            /* vec[pre[i]].push_back(i); */
            vec[i & 1][pre[i]].push_back(i);
        }
        // XDDD, ten kox bug z pb czegos malego po wiekszych valach.
        /* vec[0].push_back(-1); */
        for(int i = 0; i < n; ++i){
            if(a[i] & (1 << k)){
                if(l == INF)
                    l = i;
                else{
                    int r = i;
                    auto it = lower_bound(all(vec[r & 1][pre[r]]), l - 1);
                    if(it != vec[r & 1][pre[r]].end() && *it < r){
                        res = max(res, r - *it);
                    }
                }
            }
            else{
                l = INF;
                // giga bania ze sprawdzaniem tylko raz XD.
                /* int r = i - 1; */
                /* if(r >= l){ */
                /*     /1* auto it = lower_bound(all(vec[pre[r]]), l - 1); *1/ */
                /*     // odd len jeszcze req. */
                /*     /1* if(it != vec[pre[r]].end() && *it < r){ *1/ */
                /*     /1*     res = max(res, r - *it); *1/ */
                /*     /1* } *1/ */
                /*     /1* auto it = lower_bound(all(vec[r ^ 1 & 1][pre[r]]), l - 1); *1/ */
                /*     /1* if(it != vec[r ^ 1 & 1][pre[r]].end() && *it < r){ *1/ */
                /*     auto it = lower_bound(all(vec[r & 1][pre[r]]), l - 1); */
                /*     if(it != vec[r & 1][pre[r]].end() && *it < r){ */
                /*         res = max(res, r - *it); */
                /*     } */
                /*     // case with r - 1 end jeszcze indeed. */
                /*     if(r - 1 >= l){ */
                /*         whatis(r - 1) */
                /*         whatis(r ^ 1 & 1) */
                /*         // kox operand order. */
                /*         /1* it = lower_bound(all(vec[r ^ 1 & 1][pre[r - 1]]), l - 1); *1/ */
                /*         it = lower_bound(all(vec[(r ^ 1) & 1][pre[r - 1]]), l - 1); */
                /*         if(it != vec[(r ^ 1) & 1][pre[r - 1]].end() && *it < r - 1){ */
                /*             res = max(res, r - 1 - *it); */
                /*         } */
                /*     } */
                /* } */
                /* l = INF; */
            }
        }
        /* { */
        /*     int r = n - 1; */
        /*     /1* whatis(k) *1/ */
        /*     /1* whatis(l) *1/ */
        /*     /1* whatis(r) *1/ */
        /*     if(r >= l){ */
        /*         /1* auto it = lower_bound(all(vec[pre[r]]), l - 1); *1/ */
        /*         /1* if(it != vec[pre[r]].end() && *it < r){ *1/ */
        /*         auto it = lower_bound(all(vec[r & 1][pre[r]]), l - 1); */
        /*         if(it != vec[r & 1][pre[r]].end() && *it < r){ */
        /*             /1* whatis(*it) *1/ */
        /*             res = max(res, r - *it); */
        /*         } */
        /*         if(r - 1 >= l){ */
        /*             it = lower_bound(all(vec[(r ^ 1) & 1][pre[r - 1]]), l - 1); */
        /*             if(it != vec[(r ^ 1) & 1][pre[r - 1]].end() && *it < r - 1){ */
        /*                 res = max(res, r - 1 - *it); */
        /*             } */
        /*         } */
        /*     } */
        /*     l = INF; */
        /* } */
        crb ^= 1 << k;
        pre[0] = a[0] & crb;
        for(int i = 1; i < n; ++i){
            pre[i] = (a[i] & crb) ^ pre[i - 1];
        }
    }
    cout << res << '\n';
}