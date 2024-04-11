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

int dist(pi a, pi b){
    return abs(a.e1-b.e1)+abs(a.e2-b.e2);
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m,k;
    sc(n,m,k);
    pi st[k],en[k];
    FOR(i,0,k){
        sc(st[i].e1,st[i].e2);
        st[i] = {1,1};
    }
    FOR(i,0,k){
        sc(en[i].e1,en[i].e2);
    }
    vector<pi> dif;
    FOR(i,0,k){
        dif.pb({en[i].e1-st[i].e1,en[i].e2-st[i].e2});
    }
    sort(all(dif));
    int ds = n+m-2;
    string s;
    FOR(i,0,m-1){
        s += 'L';
    }
    FOR(i,0,n-1){
        s += 'U';
    }
    //all 1
    pi cd = {0,0};
    FOR(i,0,k){
        int whd = INF;
        int xd = -1;
        FOR(x,0,dif.size()){
            if(whd > dist(dif[x],cd)){
                whd = dist(dif[x],cd);
                xd = x;
            }
        }
        ds += dist(dif[xd],cd);
        pi dff = {dif[xd].e1-cd.e1,dif[xd].e2-cd.e2};
        while(dff.e1 > 0){
            --dff.e1;
            s += 'D';
        }
        while(dff.e1 < 0){
            ++dff.e1;
            s += 'U';
        }
        while(dff.e2 > 0){
            --dff.e2;
            s += 'R';
        }
        while(dff.e2 < 0){
            ++dff.e2;
            s += 'L';
        }
        cd = dif[xd];
        dif.erase(dif.begin()+xd);
    }
    /* FORR(i,dif){ */
    /*     whatis(i) */
    /*     int cs = abs(cd.e1-i.e1)+abs(cd.e2-i.e2); */
    /*     ds += cs; */
    /*     cd = i; */
    /* } */
    /* whatis(ds); */
    /* if(ds <= 2*n*m){ */
    cout << ds << '\n';
    cout << s << '\n';
    assert(ds <= 2*n*m);
    /* } */
    /* else{ */
    /*     assert(0); */
    /*     cout << "-1\n"; */
    /* } */
}