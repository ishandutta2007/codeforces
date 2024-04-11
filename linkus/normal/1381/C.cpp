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
#define N 100001

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        int n,x,y;
        sc(n,x,y);
        int b[n];
        GET(b);
        int a[n];
        memset(a,-1,n<<2);
        vector<int> wh[n+2];
        priority_queue<pi> pq;
        FOR(i,0,n){
            wh[b[i]].push_back(i);
        }
        int nonexistant = -1;
        FORE(i,1,n+1){
            if(wh[i].size())
                pq.push({wh[i].size(),i});
            else
                nonexistant = i;
        }
        assert(~nonexistant);
        FOR(i,0,x){
            int cr = pq.top().e2;
            pq.pop();
            a[wh[cr].back()] = cr;
            wh[cr].pop_back();
            // here it was also much needed
            if(wh[cr].size())
                pq.push({wh[cr].size(),cr});
        }
        set<pi,greater<pi>> st2; // available to be assigned as
        vector<int> whav[n+2]; // that is needless, just need the size
        FORE(i,1,n+1){
            if(wh[i].size()){
                st2.insert({wh[i].size(),i});
                whav[i] = wh[i];
            }
        }
        bool kk = 1;
        y -= x;
        if(y && 2*pq.top().e1-(n-x) > n-x-y){ // wieksze y -> gorzej
            cout << "NO\n";
            continue;
        }
        vector<pi> rest;
        FOR(i,0,n){
            if(a[i] == -1){
                rest.push_back({b[i],i});
            }
        }
        sort(all(rest));
        int shft = (n-x)/2;
        /* whatis(rest) */
        if(y)
        FOR(i,0,rest.size()){
            if(rest[i].e1 != rest[(i+shft)%(n-x)].e1){
                whatis(i)
                a[rest[i].e2] = b[rest[(i+shft)%(n-x)].e2];
                if(!--y)
                    break;
            }
        }
        FORR(i,a)
            if(i == -1)
                i = nonexistant;
        /* FOR(i,0,y){ */
        /*     // is this needed if the same thing is below? */
        /*     if(pq.empty()){ */
        /*         kk = 0; */
        /*         break; */
        /*     } */
        /*     int cr = pq.top().e2; */
        /*     pq.pop(); */
        /*     int oth; */
        /*     /1* whatis(cr) *1/ */
        /*     // shouldnt ever happen surely */
        /*     if(st2.empty()){ */
        /*         kk = 0; */
        /*         break; */
        /*     } */
        /*     if(st2.begin()->second != cr){ */
        /*         oth = st2.begin()->e2; */
        /*     } */
        /*     else{ */
        /*         // just pop it, its only bad if nothing else remains */
        /*         if(st2.size() < 2){ */
        /*             if(pq.empty()){ */
        /*                 kk = 0; */
        /*                 break; */
        /*             } */
        /*             --i; */
        /*             continue; */
        /*         } */
        /*         oth = (++st2.begin())->e2; */
        /*     } */
        /*     /1* whatis(oth) *1/ */
        /*     /1* a[wh[cr].back()] = whav[oth].back(); *1/ */
        /*     assert(wh[cr].size()); */
        /*     assert(whav[oth].size()); */
        /*     a[wh[cr].back()] = oth; */
        /*     wh[cr].pop_back(); */
        /*     whav[oth].pop_back(); */
        /*     assert(st2.erase({whav[oth].size()+1,oth})); */
        /*     if(whav[oth].size()) */
        /*         st2.insert({whav[oth].size(),oth}); */
        /*     // important */
        /*     if(wh[cr].size()) */
        /*         pq.push({wh[cr].size(),cr}); */
        /* } */
        /* /1* whatis(nonexistant) *1/ */
        /* FORE(i,1,n+1){ */
        /*     FORR(x,wh[i]){ */
        /*         a[x] = nonexistant; */
        /*     } */
        /* } */
        /* if(!kk){ */
        /*     assert(false); */
        /*     cout << "NO\n"; */
        /*     continue; */
        /* } */
        cout << "YES\n";
        FOR(i,0,n){
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}