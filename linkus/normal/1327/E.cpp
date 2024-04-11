#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
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
    string s;
    ll mod = 998244353;
    ll ret[n];
    ll ret3[n];
    ret[0] = 10;
    ll crten = 100;
    FOR(i,1,n){
        ret[i] = crten*(i+1)%mod;
        crten *= 10;
        crten %= mod;
    }
    /* FORR(i,ret) */
    /*     cout << i << ' '; */
    /* cout << '\n'; */
    ll del = ret[0];
    ll del2 = ret[0];
    FOR(i,1,n){
        ret[i] -= del;
        ret[i] += mod;
        ret[i] %= mod;
        del += ret[i];
        del %= mod;
    }
    /* FORR(i,ret) */
    /*     cout << i << ' '; */
    /* cout << '\n'; */
    del = ret[0];
    del2 = ret[0];
    FOR(i,1,n){
        ret[i] -= del;
        ret[i] += mod;
        ret[i] %= mod;
        del += ret[i];
        del %= mod;
    }
    reverse(ret,ret+n);
    FORR(i,ret)
        cout << i << ' ';
    cout << '\n';
    /* FOR(i,1,n){ */
    /*     del2 += ret[i]; */
    /*     /1* ret[i] -= ret[i-1]; *1/ */
    /*     ret[i] -= del; */
    /*     ret[i] %= mod; */
    /*     del = del2; */
    /*     del %= mod; */
    /* } */
    /* FOR(i,0,pow(10,n)){ */
    /*     string now = to_string(i); */
    /*     while(now.size() < n){ */
    /*         now.insert(now.begin(),'0'); */
    /*     } */
    /*     s += now; */
    /*     s += ','; */
    /* } */
    /* int ret2[n]; */
    /* memset(ret2,0,n<<2); */
    /* int it = 0; */
    /* while(it < s.size()){ */
    /*     int cr = 1; */
    /*     while(it+1 < s.size() && s[it+1] == s[it]){ */
    /*         ++cr,++it; */
    /*     } */
    /*     ++ret2[cr-1]; */
    /*     ++it; */
    /* } */
    /* whatis(s) */
    /* ret2[0] -= pow(10,n); */
    /* int pre1[n],pre2[n]; */
    /* FOR(i,0,n){ */
    /*     pre1[n-i-1] = ret2[i]; */
    /* } */
    /* FOR(i,1,n){ */
    /*     pre1[i] += pre1[i-1]; */
    /* } */
    /* memcpy(pre2,pre1,n << 2); */
    /* FOR(i,1,n){ */
    /*     pre2[i] += pre2[i-1]; */
    /* } */
    /* FORR(i,ret) */
    /*     cout << i << ' '; */
    /* cout << '\n'; */
    /* FORR(i,ret2) */
    /*     cout << i << ' '; */
    /* cout << '\n'; */
    /* FORR(i,pre1) */
    /*     cout << i << ' '; */
    /* cout << '\n'; */
    /* FORR(i,pre2) */
    /*     cout << i << ' '; */
    /* cout << '\n'; */
}