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
    int n;
    sc(n);
    /* int a[n][3]; */
    array<int,3> a[n];
    FORR(i,a)
        GET(i);
    int sth[n];
    /* FOR(i,0,n){ */
    constexpr ll mod = 998244353;
    ll res = a[n-1][0] + 1;
    ll cr = 0;
    /* vector<pi> vec; */
    set<pi> vec;
    for(int i = n-1; i >= 0; --i){
        sth[i] = a[i][2];
        /* while(!vec.empty() && vec.begin()->e1 > a[i][0]){ */
        while(!vec.empty() && -vec.begin()->e1 > a[i][0]){
            cr -= vec.begin()->e2;
            cr += mod;
            cr %= mod;
            vec.erase(vec.begin());
        }
        sth[i] += cr;
        cr += sth[i];
        cr %= mod;
        /* vec.insert({a[i][1],sth[i]}); */
        vec.insert({-a[i][1],sth[i]});
        /* FOR(x,i+1,n){ */
        /*     /1* sth[i] += a[x][1] < a[i][0]; *1/ */
        /*     sth[i] += a[x][1] < a[i][0] ? sth[x] : 0; */
        /*     sth[i] %= mod; */
        /* } */
        /* res += sth[i] * (a[i][0] - a[i][1]); */
        res += (ll)sth[i] * (a[i][0] - a[i][1]);
        res %= mod;
        /* cout << sth[i] << ' '; */
    }
    cout << res << '\n';
    /* cout << '\n'; */
    /* int pos = 0; */
    /* ll res = 0; */
    /* /1* while(pos <= a[n-1][0]){ *1/ */
    /* /1* auto st = [](){ *1/ */
    /* /1* }; *1/ */
    /* vi cnt(n,0); */
    /* for(;;){ */
    /*     /1* auto it = lower_bound(a,a+n,[](auto &f, int sth){return f[0] < sth;}); *1/ */
    /*     /1* auto it = lower_bound(a,a+n,pos,[](int sth, auto &f){return f[0] < sth;}); *1/ */
    /*     /1* auto it = lower_bound(a,a+n,pos,[](auto &f, int sth){return f[0] < sth;}); *1/ */
    /*     /1* auto it = lower_bound(a,a+n,pos+1,[](auto &f, int sth){return f[0] < sth;}); *1/ */
    /*     auto it = lower_bound(a,a+n,pos+1,[](auto &f, int sth){return f[0] < sth;}); */
    /*     if(it == a+n) */
    /*         break; */
    /*     /1* ++cnt[it - a]; *1/ */
    /*     res += (*it)[0] - pos; */
    /*     if(!((*it)[2] ^= 1)){ */
    /*         pos = (*it)[1]; */
    /*         ++cnt[it - a]; */
    /*     } */
    /*     else{ */
    /*         pos = (*it)[0]; */
    /*     } */
    /*     whatis(pos) */
    /*     FOR(i,0,n) */
    /*         cout << a[i][2]; */
    /*     cout << '\n'; */
    /*     /1* if( *1/ */
    /*     /1* if(){ *1/ */
    /*     /1* } *1/ */
    /* } */
    /* whatis(res + 1) */
    /* whatis(cnt) */
}