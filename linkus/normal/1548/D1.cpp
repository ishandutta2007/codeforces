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
    pi a[n];
    FORR(i,a)
        sc(i.e1,i.e2);
    int cnt[2][2]{};
    /* auto f = [](ll n){return n*(n-1)*(n-2)/6;}; */
    FOR(i,0,n){
        /* ++cnt[abs(a[i].e2 - a[i].e1) % 4 == 2]; */
        ++cnt[a[i].e1 % 4 == 2][a[i].e2 % 4 == 2];
    }
    /* whatis(cnt[0]) */
    /* whatis(cnt[1]) */
    ll res = 0;
    FOR(i,0,4){
        FOR(x,i,4){
            FOR(j,x,4){
                vector<pi> vec;
                FORR(xd,(vi{i,x,j})){
                    if(xd == 0)
                        vec.pb({0,0});
                    else if(xd == 1)
                        /* vec.pb({2,0}); */
                        vec.pb({0,2});
                    else if(xd == 2)
                        /* vec.pb({0,2}); */
                        vec.pb({2,0});
                    else if(xd == 3)
                        vec.pb({2,2});
                }
                ll sth = 0;
                FOR(i,0,3){
                    FOR(x,i+1,3){
                        /* sth += __gcd(vec[i].e1 - vec[x].e1, vec[i].e2 - vec[x].e2); */
                        sth += abs(__gcd(abs(vec[i].e1 - vec[x].e1), abs(vec[i].e2 - vec[x].e2)));
                    }
                }
                sth /= 2;
                /* whatis(sth) */
                /* if(abs(sth % 2) == 1){ */
                /* if(abs(sth % 2) == 1){ */
                // XDDD, had it other way around, that's what was bad, nie
                // jakietam absy. not-soft bruh.
                if(abs(sth % 2) != 1){
                    whatis(i)
                    whatis(x)
                    whatis(j)
                    // all dif always
                    // after correction, ofc not xd.
                    /* res += ((int*)cnt)[i] * ((int*)cnt)[x] * ((int*)cnt)[j]; */
                    map<int,int> ovk;
                    ++ovk[i];
                    ++ovk[j];
                    ++ovk[x];
                    ll cr = 1;
                    FORR(i,ovk){
                        ll sth = ((int*)cnt)[i.e1];
                        if(i.e2 == 1)
                            cr *= sth;
                        else if(i.e2 == 2)
                            cr *= sth * (sth-1) / 2;
                        else
                            cr *= sth * (sth-1) * (sth-2) / 6;
                    }
                    res += cr;
                    /* whatis(((int*)cnt)[i]) */
                    /* whatis(((int*)cnt)[x]) */
                    /* whatis(((int*)cnt)[j]) */
                }
            }
        }
    }
    /* res += f(cnt[0]); */
    /* res += f(cnt[1]); */
    /* res += cnt[0] * (cnt[0] - 1) / 2 * cnt[1]; */
    cout << res << '\n';
}