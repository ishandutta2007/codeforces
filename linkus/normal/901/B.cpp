#include <stdio.h>
#include <algorithm>
#include <vector>
#include <array>
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
#define N 1000001

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    vi v1 = {1}, v2 = {0, 1};
    int cr = 1;
    while(cr < n){
        v1.push_back(0);
        v1.push_back(0);
        FORE(i,0,cr){
            v1[i+1] += v2[i];
            v1[i+1] %= 2;
        }
        v1.swap(v2);
        ++cr;
    }
    cout << v2.size() - 1 << '\n';
    FORR(i,v2)
        cout << i << ' ';
    cout << '\n';
    cout << v1.size() - 1 << '\n';
    FORR(i,v1)
        cout << i << ' ';
    cout << '\n';
    /* if(n == 2){ */
/* cout << R"(2 */
/* -1 0 1 */
/* 1 */
/* 0 1)"; */
    /* } */
    /* else{ */
    /*     cout << n << '\n'; */
    /*     int a[n + 1], b[n]; */
    /*     memset(a,0,sizeof a); */
    /*     memset(b,0,sizeof b); */
    /*     a[0] = b[0] = 1; */
    /*     for(int i = 1; i <= n; i += 2){ */
    /*         a[i] = (i-1)%4 == 0 ? -1 : 1; */
    /*     } */
    /*     /1* for(int i = 1; i < n; i += 2){ *1/ */
    /*     for(int i = 2; i < n; i += 2){ */
    /*         b[i] = (i-2)%4 == 0 ? -1 : 1; */
    /*     } */
    /*     for(int i = n; i >= 0; --i) */
    /*         cout << a[i] << ' '; */
    /*     cout << '\n'; */
    /*     cout << n - 1 << '\n'; */
    /*     for(int i = n - 1; i >= 0; --i) */
    /*         cout << b[i] << ' '; */
    /*     cout << '\n'; */
    /* } */
}