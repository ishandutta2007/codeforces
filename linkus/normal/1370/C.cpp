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

vi wh(int n){
    vi ret;
    for(int x = 3; x <= n; x += 2){
        if(n%x == 0){
            ret.pb(x);
        }
    }
    return ret;
}

vi whpr(int n){
    vi ret;
    while(n%2 == 0)
        n /= 2;
    for(int x = 3; x*x <= n; x += 2){
        while(n%x == 0){
            ret.pb(x);
            n /= x;
        }
    }
    if(n != 1)
        ret.pb(n);
    return ret;
}

int mex(vi wh){
    sort(all(wh));
    /* if(wh.empty()) return 0; */
    if(wh[0]) return 0;
    FOR(i,1,wh.size()){
        if(wh[i] != wh[i-1]+1){
            return wh[i-1]+1;
        }
    }
    return wh.back()+1;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        int n;
        sc(n);
        int cos = whpr(n).size();
        int xd = n;
        int l= 0;
        while(xd % 2 == 0){
            xd /= 2;
            ++l;
        }
        if(n == 1){
            cout << "FastestFinger\n";
        }
        else if(l == 1 && cos == 1){
            cout << "FastestFinger\n";
        }
        else if(l > 1 && cos == 0){
            cout << "FastestFinger\n";
        }
        else{
            cout << "Ashishgup\n";
        }
    }
    /* int gr[100] = {}; */
    /* vi zer; */
    /* vi zer2; */
    /* FOR(i,2,100){ */
    /*     vi ret = wh(i); */
    /*     vi cr; */
    /*     FORR(x,ret){ */
    /*         cr.pb(gr[i/x]); */
    /*     } */
    /*     cr.pb(gr[i-1]); */
    /*     gr[i] = mex(cr); */
    /*     whatis(i) */
    /*     whatis(gr[i]) */
    /*     if(!gr[i]) */
    /*         zer.pb(i); */
    /*     int xd = i; */
    /*     int l= 0; */
    /*     while(xd % 2 == 0){ */
    /*         xd /= 2; */
    /*         ++l; */
    /*     } */
    /*     /1* if(!gr[i]){ *1/ */
    /*     /1*     whatis(l) *1/ */
    /*     /1* } *1/ */
    /*     /1* if(l > 0 && i != 2 && (l%2 || xd == 1)){ *1/ */
    /*     /1*     zer2.pb(i); *1/ */
    /*     /1* } *1/ */
    /*     int cos = whpr(i).size(); */
    /*     if(l == 1 && cos == 1){ */
    /*         zer2.pb(i); */
    /*     } */
    /*     if(l > 1 && cos == 0){ */
    /*         zer2.pb(i); */
    /*     } */
    /*     /1* if(l > 0){ *1/ */
    /*     /1*     if((l != 1) ^ (cos&1)) *1/ */
    /*     /1*         zer2.pb(i); *1/ */
    /*     /1*     /2* if(l == 1){ *2/ *1/ */
    /*     /1*     /2*     if(cos&1) *2/ *1/ */
    /*     /1*     /2*         zer2.pb *2/ *1/ */
    /*     /1*     /2* } *2/ *1/ */
    /*     /1*     /2* else{ *2/ *1/ */
    /*     /1*     /2* } *2/ *1/ */
    /*     /1* } *1/ */
    /* } */
    /* whatis(zer) */
    /* whatis(zer2) */
}