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

#define MAX 200000
int t[MAX << 2];
bool mark[MAX << 2];

/* void build(int v, int tl, int tr, int *arr){ */
void build(int v, int tl, int tr, char *arr){
    if(tl == tr){
        t[v] = arr[tl];
        return;
    }
    int tm = (tl+tr)>>1;
    build(v<<1,tl,tm,arr);
    build(v<<1|1,tm+1,tr,arr);
    t[v] = t[v<<1] + t[v<<1|1];
    mark[v] = 0; // needed indeed.
}

void push(int v, int tl, int tr){
    int tm = (tl+tr)>>1;
    int setel = t[v] / (tr-tl+1);
    t[v<<1] = setel * (tm-tl+1);
    t[v<<1|1] = setel * (tr-tm);
    mark[v<<1] = mark[v<<1|1] = 1;
    mark[v] = 0;
}

void modify(int v, int tl, int tr, int l, int r, int val){
    if(l > r) return;
    if(l == tl && r == tr){
        mark[v] = 1;
        t[v] = val*(tr-tl+1);
        return;
    }
    if(mark[v])
        push(v,tl,tr);
    int tm = (tl+tr)>>1;
    modify(v<<1,tl,tm,l,min(tm,r),val);
    modify(v<<1|1,tm+1,tr,max(l,tm+1),r,val);
    t[v] = t[v<<1] + t[v<<1|1];
}

int query(int v, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(l == tl && r == tr){
        return t[v];
    }
    if(mark[v])
        push(v,tl,tr);
    int tm = (tl+tr)>>1;
    return query(v<<1,tl,tm,l,min(tm,r)) + query(v<<1|1,tm+1,tr,max(l,tm+1),r);
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tt;
    sc(tt);
    while(tt--){
        /* memset(t,0,sizeof t); */
        /* memset(mark,0,sizeof mark); */
        int n,q;
        sc(n,q);
        string s,f;
        getstr(s);
        getstr(f);
        FORR(i,s)
            i -= '0';
        FORR(i,f)
            i -= '0';
        // bruh
        /* build(1, 0, n-1, (char *)&s[0]); */
        build(1, 0, n-1, (char *)&f[0]);
        /* bs1 = bitset<200000>(s); */
        /* bs2 = bitset<200000>(f); */
        pi qus[q];
        FOR(x,0,q){
            sc(qus[x].e1, qus[x].e2);
        }
        bool kk = 1;
        for(int i = q-1; i >= 0; --i){
            --qus[i].e1, --qus[i].e2;
            int m = qus[i].e2 - qus[i].e1 + 1;
            int cnt1 = query(1,0,n-1,qus[i].e1,qus[i].e2);
            int cnt0 = m - cnt1;
            /* whatis(cnt1) */
            /* whatis(cnt0) */
            /* whatis(m) */
            if(cnt1 * 2 < m){
                modify(1,0,n-1,qus[i].e1,qus[i].e2,0);
                // chg all to 0.
            }
            else if(cnt0 * 2 < m){
                modify(1,0,n-1,qus[i].e1,qus[i].e2,1);
                // chg all to 1.
            }
            else{
                kk = 0;
                break;
                // bad
            }
        }
        FOR(i,0,n){
            kk &= s[i] == query(1,0,n-1,i,i);
        }
        /* kk &= bs1 == bs2; */
        cout << (kk ? "YES\n" : "NO\n");
    }
}