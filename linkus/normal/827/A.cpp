#pragma GCC optimize("O3")
#include <bits/stdc++.h>
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
#define N 2100000

/* int t[N << 2]; */
/* int n = N-1; */
int ans[N];

/* int query(int v, int l, int r, int tl, int tr){ //all inclusive */
/*     if(v >= n) */
/*         return v-n; */
/*     int tm = (tl+tr) >> 1; */
/*     if((t[v << 1] < t[v << 1|1] && l <= tm) || tm+1 > r) */
/*         return query(v << 1,l,min(r,tm),tl,tm); */
/*     return query(v << 1|1,max(l,tm+1),r,tm+1,tr); */
/* } */
/* void build(ll v, ll tl, ll tr){ */
/*     if(tl == tr){ */
/*         ans[tl] = t[v]; */
/*         return; */
/*     } */
/*     ll tm = (tl+tr)>>1; */
/*     build(v<<1,tl,tm); */
/*     build(v<<1|1,tm+1,tr); */
/*     /1* t[v] = min(t[v<<1] , t[v<<1|1]); *1/ */
/* } */
/* void modify(int v, int tl, int tr, int pos, int val){ */
/*     if(tl == tr){ */
/*         t[v] = val; */
/*         return; */
/*     } */
/*     int tm = (tl+tr)/2; */
/*     if(pos <= tm) */
/*         modify(v*2,tl,tm,pos,val); */
/*     else */
/*         modify(v*2|1,tm+1,tr,pos,val); */
/*     t[v] = min(t[v<<1],t[v<<1|1]); */
/* } */
/* pair<int,int> query(int v, int tl, int tr, int l, int r){ */
/*     /1* whatis(v) *1/ */
/*     /1* whatis(t[v]) *1/ */
/*     /1* whatis(l) *1/ */
/*     /1* whatis(r) *1/ */
/*     if(l > r) return {0x7f7f7f7f,0x7f7f7f7f}; */
/*     /1* if(t[v]){ *1/ */
/*     /1*     return {0x7f7f7f7f,0x7f7f7f7f}; *1/ */
/*     /1* } *1/ */
/*     if(tl == l && tr == r && tr == tl){ */
/*         return {t[v],tl}; */
/*         /1* if(t[v]){ *1/ */
/*         /1*     return {0x7f7f7f7f,1}; *1/ */
/*         /1* } *1/ */
/*         /1* return {t[v],v}; *1/ */
/*     } */
/*     /1* push(v); *1/ */
/*     int tm = (tl+tr)>>1; */
/*     if(tl == l && tr == r){ */
/*         if(t[v<<1] < t[v<<1|1]){ */
/*             return query(v<<1,tl,tm,l,min(tm,r)); */
/*         } */
/*         else{ */
/*             return query(v<<1|1,tm+1,tr,max(l,tm+1),r); */
/*         } */
/*     } */
/*     auto xd = query(v<<1,tl,tm,l,min(tm,r)); */
/*     if(xd.e1 == 0) return xd; */
/*     xd = query(v<<1|1,tm+1,tr,max(l,tm+1),r); */
/*     return xd; */
/* } */

/* void modify(int p, int val){ */
/*     for(t[p += n] = val; p > 1; p>>=1) */
/*         t[p>>1] = min(t[p] , t[p^1]); */
/* } */

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    int mx = 0;
    set<int> st;
    FORE(i,1,2000010){
        st.insert(st.end(),i);
    }
    FOR(i,0,n){
        string s;
        getstr(s);
        int sz = s.size();
        int m;
        sc(m);
        int aa;
        while(m--){
            sc(aa);
            /* pi cr; */
            auto it = st.lower_bound(aa);
            while(*it < aa+sz){
                /* whatis(*it) */
                mx = max(mx,*it);
                ans[*it] = s[*it-aa];
                ++it;
                st.erase(prev(it));
            }
            /* whatis(aa) */
            /* whatis(query(1,0,N-1,aa,aa+sz-1)) */
            /* while(cr = query(1,0,N-1,aa,aa+sz-1), cr.e1 == 0){ */
            /*     /1* whatis(cr) *1/ */
            /*     /1* assert(!t[N+cr]); *1/ */
            /*     /1* t[cr] = s[cr-aa]; *1/ */
            /*     /1* modify(cr.e2,s[cr.e2-aa]); *1/ */
            /*     /1* modify(1,0,N-1,cr.e2,s[cr.e2-aa]); *1/ */
            /*     mx = max(mx,cr.e2); */
            /* } */
        }
    }
    /* build(1,0,N-1); */
    FORE(i,1,mx){
        /* whatis(i) */
        /* whatis(ans[i]) */
        cout.put(ans[i] ? ans[i] : 'a');
    }
    cout << '\n';
}