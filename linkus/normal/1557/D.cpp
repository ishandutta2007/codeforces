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

pi t[N << 2];
bool mark[N << 2];

void build(int v, int tl, int tr, pi arr[]){
    if(tl == tr){
        t[v] = arr[tl];
        return;
    }
    int tm = (tl+tr)>>1;
    build(v<<1,tl,tm,arr);
    build(v<<1|1,tm+1,tr,arr);
    t[v] = min(t[v<<1], t[v<<1|1]);
}

void push(int v){
    t[v<<1] = t[v<<1|1] = t[v];
    mark[v<<1] = mark[v<<1|1] = 1;
    mark[v] = 0;

}

void modify(int v, int tl, int tr, int l, int r, pi val){
    if(l > r) return;
    if(tl == l && tr == r){
        t[v] = val;
        mark[v] = 1;
        return;
    }
    if(mark[v])
        push(v);
    int tm = (tl+tr)>>1;
    modify(v<<1,tl,tm,l,min(tm,r),val);
    modify(v<<1|1,tm+1,tr,max(l,tm+1),r,val);
    t[v] = min(t[v<<1],t[v<<1|1]);
}

pi query(int v, int tl, int tr, int l, int r){
    if(l > r) return {N,0};
    if(tl == l && tr == r){
        return t[v];
    }
    if(mark[v])
        push(v);
    int tm = (tl+tr)>>1;
    return min(
    query(v<<1,tl,tm,l,min(tm,r)),
    query(v<<1|1,tm+1,tr,max(l,tm+1),r)
    );
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    /* linkustree l(0,1,1); */
    /* l.insert(0,1,2); */
    /* /1* whatis(l.s) *1/ */
    /* whatis(l.s.size()) */
    /* whatis(l.s.begin()->val) */
    /* l.insert(0,1,0); */
    /* whatis(l.s.size()) */
    /* whatis(l.s.begin()->val) */
    // nadpisywasko; that's fine.
    int n,m;
    sc(n,m);
    vi vec;
    int segs[m][3];
    FORR(i,segs){
        GET(i);
        --i[0];
        vec.pb(i[1]);
        vec.pb(i[2]);
    }
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());
    int nn = vec.size();
    /* static Segtree t; */
    pi arr[nn];
    FOR(i,0,nn)
        /* arr[i] = n; */
        arr[i] = {0,-1};
    build(1,0,nn-1,arr);
    vector<pi> rows[n];
    FORR(i,segs){
        i[1] = lower_bound(all(vec), i[1]) - vec.begin();
        i[2] = lower_bound(all(vec), i[2]) - vec.begin();
        rows[i[0]].pb({i[1], i[2]});
    }
    int res = n;
    /* whatis("xd1") */
    /* linkustree l[n+2]; // +1, bo -1 moe byc. */
    // hard bruh.
    /* linkustree l[2*n+2]; // +1, bo -1 moe byc. */
    // +n jednak.
    int pr[n];
    /* whatis("xd2") */
    int resid = -1;
    FOR(i,0,n){
        int cr = n;
        int whpr = -1;
        /* FOR(x,0,nn){ */
        /*     cout << t.query(1,0,nn-1,x,x) << ' '; */
        /* } */
        /* cout << '\n'; */
        FORR(x,rows[i]){
            /* whatis(x) */
            /* whatis(t.query(1,0,nn-1,x.e1,x.e2)) */
            /* cr = min(cr, i + query(1,0,nn-1,x.e1,x.e2)); */
            pi crrec = query(1,0,nn-1,x.e1,x.e2);
            if(i + crrec.e1 < cr){
                cr = i + crrec.e1;
                whpr = crrec.e2;
            }
        }
        /* whatis(sthidpr) */
        /* whatis("beg") */
        /* FORR(x,l[sthidpr].s){ */
        /*     cout << x.l << ' ' << x.r << ' ' << x.val << '\n'; */
        /* } */
        /* whatis("end") */
        pr[i] = whpr;
        /* whatis(i) */
        /* whatis(cr) */
        /* whatis(cr-i) */
        /* whatis(cr-i-1) */
        /* res = min(res, cr + (n - i - 1)); */
        int put = cr + (n - i - 1);
        if(put < res){
            res = put;
            resid = i;
        }
        /* int sthid = cr-i; */
        FORR(x,rows[i]){
            // XD, 0iq overkillowanie typowe.
            /* t.modifymne(1,0,nn-1,x.e1,x.e2,cr-i-1); */
            modify(1,0,nn-1,x.e1,x.e2,{cr-i-1,i});
            /* l[sthid].insert(x.e1,x.e2,i); */
        }
    }
    /* FOR(i,0,n) */
    /*     whatis(pr[i]) */
    /* whatis("xd3") */
    /* whatis(l.s) */
    cout << res << '\n';
    vi resvec;
    while(resid != -1){
        resvec.pb(resid);
        resid = pr[resid];
    }
    /* whatis(resvec) */
    reverse(all(resvec));
    auto it = resvec.begin();
    FOR(i,0,n){
        while(it != resvec.end() && *it < i)
            ++it;
        /* if(*it == i) */
        if(*it != i)
            cout << i + 1 << ' ';
    }
    cout << '\n';
}