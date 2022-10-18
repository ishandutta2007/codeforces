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
    int a[n];
    GET(a);
    /* map<int,set<int>> mp; */
    map<int,vi> vals;
    FOR(i,0,n)
        vals[a[i]].pb(i);
    int it = 0;
    map<int,int> wh;
    FORR(i,vals){
        FORR(x,i.e2){
            wh[it] = x;
            a[x] = it++;
        }
    }
    vector<pi> st;
    /* set<pi> st; */
    /* FOR(i,0,n){ */
    /*     FOR(x,i+1,n){ */
    /*         if(a[i] > a[x]){ */
    /*             st.insert({i,x}); */
    /*         } */
    /*     } */
    /*     /1* mp[a[i]].insert(i); *1/ */
    /*     /1* whatis(a[i]) *1/ */
    /* } */
    /* cout << st.size() << '\n'; */
    // what made this complicated, was repeated values
    // so can just ez convert this into a permutation
    FOR(i,0,n){
        auto it = wh.find(a[i]);
        /* whatis(i) */
        /* whatis(mp) */
        /* if(a[i] && wh[a[i]-1] > i){ */
        if(it != wh.begin()){
            /* int it2 = wh[a[i]-1]; */
            auto it2 = prev(it);
            /* pi wh = {i,*--(it2->e2.end())}; */
            pi whh = {i,it2->e2};
            st.pb(whh);
            /* cout << whh.e1+1 << ' ' << whh.e2+1 << '\n'; */
            /* whatis(whh) */
            /* st.erase(whh); */
            /* it2->e2.erase(--(it2->e2.end())); */
            /* it->e2.erase(i); */
            /* it->e2.insert(wh.e2); */
            /* it2->e2.insert(i); */
            swap(a[i],a[whh.e2]);
            /* wh[it->e1] = whh.e2; */
            /* wh[it2->e1] = i; */
            it->e2 = whh.e2;
            it2->e2 = i;
            // erase to the same ones now
            /* for(auto it = ++it2->e2.find(i); it != it2->e2.end(); ++it){ */
            /*     cout << i+1 << ' ' << *it+1 << '\n'; */
            /*     /1* st.erase({i+1,*it+1}); *1/ */
            /*     st.erase({i,*it}); */
            /* } */
            /* // same thing for orig actually, but in reverse order */
            /* for(auto itt = it->e2.find(wh.e2); itt != it->e2.begin();){ */
            /*     --itt; */
            /*     /1* whatis(*itt) *1/ */
            /*     /1* cout << wh.e2+1 << ' ' << *itt+1 << '\n'; *1/ */
            /*     /1* st.erase({wh.e2,*itt}); *1/ */
            /*     cout << *itt+1 << ' ' << wh.e2+1 << '\n'; */
            /*     st.erase({*itt,wh.e2}); */
            /* } */
            --i;
        }
        else{
            wh.erase(it);
            /* it->e2.erase(i); */
            /* if(it->e2.empty()) */
            /*     mp.erase(it); */
        }
    }
    /* cout.flush(); */
    /* assert(st.empty()); */
    cout << st.size() << '\n';
    FORR(i,st){
        cout << i.e1+1 << ' ' << i.e2+1 << '\n';
    }
}