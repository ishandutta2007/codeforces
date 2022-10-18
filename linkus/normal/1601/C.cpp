/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC optimize("Ofast,unroll-loops") */
/* #pragma GCC target("avx2,popcnt") */
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
 
#ifdef ONLINE_JUDGE
#define whatis(x) ;
#endif
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/* #define N 1000004 */
#define N 2000004

#define int ll
struct fen{
    int t[N + 1];
    int n;
    inline void upd(int pos, int val){ //val is delta
        ++pos;
        for(;pos <= n;pos += pos & (-pos))
                //simply for(;posy <= m;posy += posy & (-posy)) for 2nd dimension
            t[pos] += val;
    }

    inline int query(int r){ //[0,r]
        if(r > n)
            return 0;
        ++r;
        int ret = 0;
        for(;r > 0;r -= r & (-r))
            ret += t[r];
        return ret;
    }
};

int t[N << 2];
int lazy[N << 2];

void build(int v, int tl, int tr, int arr[]){
    if(tl == tr){
        t[v] = arr[tl];
        return;
    }
    lazy[v] = 0;
    int tm = (tl+tr)>>1;
    build(v<<1,tl,tm,arr);
    build(v<<1|1,tm+1,tr,arr);
    t[v] = min(t[v<<1] , t[v<<1|1]);
}

void push(int v){
    if(lazy[v]){
        lazy[v<<1] += lazy[v];
        lazy[v<<1|1] += lazy[v];
        t[v<<1] += lazy[v];
        t[v<<1|1] += lazy[v];
        lazy[v] = 0;
    }
}

void modify(int v, int tl, int tr, int l, int r, int inc){
    if(l > r) return;
    if(tl == l && tr == r){
        t[v] += inc;
        lazy[v] += inc;
        return;
    }
    push(v);
    int tm = (tl+tr)>>1;
    modify(v<<1,tl,tm,l,min(tm,r),inc);
    modify(v<<1|1,tm+1,tr,max(l,tm+1),r,inc);
    t[v] = min(t[v<<1],t[v<<1|1]);
}

// guess this doesn't work for init l != tl r != tr 
// -> let's just offset pref o duo instead (poza crpr - 1, bo to jest base
// wtedy).
// or better, 1-ind wsm jakos? so im not forced to take [0]?
pair<int,int> query(int v, int tl, int tr, int l, int r){
    /* whatis(v) */
    /* whatis(tl) */
    /* whatis(tr) */
    /* whatis(l) */
    /* whatis(r) */
    /* whatis(t[v]) */
    /* whatis(t[v<<1]) */
    /* whatis(t[v<<1|1]) */
    if(l > r) return {0x7f7f7f7f,0x7f7f7f7f};
    /* if(t[v]){ */
    /*     return {0x7f7f7f7f,0x7f7f7f7f}; */
    /* } */
    if(tl == l && tr == r && tr == tl){
        return {t[v],tl};
        /* if(t[v]){ */
        /*     return {0x7f7f7f7f,1}; */
        /* } */
        /* return {t[v],v}; */
    }
    push(v);
    int tm = (tl+tr)>>1;
    if(t[v<<1] < t[v<<1|1]){
        return query(v<<1,tl,tm,l,min(tm,r));
    }
    else{
        return query(v<<1|1,tm+1,tr,max(l,tm+1),r);
    }
}

int query2(int v, int tl, int tr, int pos){
    if(tr == tl){
        return t[v];
    }
    push(v);
    int tm = (tl+tr)>>1;
    /* if(t[v<<1] < t[v<<1|1]){ */
    if(pos <= tm){
        return query2(v<<1,tl,tm,pos);
    }
    else{
        return query2(v<<1|1,tm+1,tr,pos);
    }
}

fen pre, suf;
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        int n,m;
        sc(n,m);
        /* pre.n = suf.n = n + 4; */
        pre.n = suf.n = n + m + 4;
        /* memset(pre.t, 0, (pre.n + 1) << 2); */
        /* memset(suf.t, 0, (pre.n + 1) << 2); */
        memset(pre.t, 0, (pre.n + 1) << 3);
        memset(suf.t, 0, (pre.n + 1) << 3);
        int a[n];
        GET(a);
        int b[m];
        GET(b);
        vi vec;
        FORR(i,a){
            vec.pb(i);
        }
        FORR(i,b)
            vec.pb(i);
        sort(all(vec));
        vec.erase(unique(all(vec)),vec.end());
        FORR(i,a){
            /* whatis(i) */
            i = lower_bound(all(vec), i) - vec.begin();
            /* whatis(i) */
            /* whatis("apostvec^^") */
        }
        /* vec.clear(); */
        /* FORR(i,b) */
        /*     vec.pb(i); */
        /* sort(all(vec)); */
        /* vec.erase(unique(all(vec)),vec.end()); */
        FORR(i,b){
            /* whatis(i) */
            i = lower_bound(all(vec), i) - vec.begin();
            /* whatis(i) */
            /* whatis("bpostvec^^") */
        }
        /* FORR(i,a){ */
        ll res = 0;
        FOR(i,0,n){
            /* --a[i]; */
            /* res += suf.query(n - 1) - suf.query(a[i]); */
            res += suf.query(n + m) - suf.query(a[i]);
            suf.upd(a[i], 1);
        }
        int it = 0;
        /* auto cost = [&](int elem, int ind){ */
        /*     // casually ignoring ind. */
        /*     int ret = pre.query(n - 1) - pre.query(elem) + suf.query(elem - 1); */
        /*     return ret; */
        /* }; */
        /* auto cost2 = [&](int elem, int ind){ */
        /*     // hard brutish. */
        /*     suf.upd(a[ind], -1); */
        /*     pre.upd(a[ind], 1); */
        /*     int ret = pre.query(n - 1) - pre.query(elem) + suf.query(elem - 1); */
        /*     suf.upd(a[ind], 1); */
        /*     pre.upd(a[ind], -1); */
        /*     return ret; */
        /* }; */
        // forgot to sort xd.
        /* whatis("b4srt") */
        /* FOR(i,0,m){ */
        /*     whatis(b[i]) */ 
        /* } */
        /* whatis("postsrt") */
        sort(b, b + m);
        /* FOR(i,0,m){ */
        /*     whatis(b[i]) */ 
        /* } */
        // and to dec.
        /* FORR(i,b) */
        /*     --i; */
        /* FOR(i,0,m){ */
        /*     /1* while(it < n && cost(b[i], it) >= cost(b[i], it + 1)){ *1/ */
        /*     /1* while(it < n && cost(b[i], it) >= cost2(b[i], it + 1)){ *1/ */
        /*     whatis(cost(b[i], it)) */
        /*     whatis(cost2(b[i], it)) */
        /*     while(it < n && cost(b[i], it) >= cost2(b[i], it)){ */
        /*         suf.upd(a[it], -1); */
        /*         pre.upd(a[it], 1); */
        /*         ++it; */
        /*     } */
        /*     res += cost(b[i], it); */
        /*     whatis(b[i]) */
        /*     whatis(it) */
        /* } */
        // lazy segtree, surely won't pass
        int init[n+1];
        init[0] = 0;
        /* FOR(i,0,n+1){ */
        FOR(i,0,n){
            /* init[i] = i + 1; */
            init[i+1] = i + 1; // fsanitize<3
        }
        /* build(1,0,n-1,init); */
        build(1,0,n,init);
        /* int crinv = n; */
        int crinv = 0; // na poczatku < all elems tamte przecie.
        int it1 = 0;
        int it2 = 0;
        pair<int,int> avec[n];
        FOR(i,0,n)
            avec[i] = {a[i], i};
        sort(avec, avec + n);
        /* int crp = 0; */ // i shouldn't actually need this.
        FOR(i,0,m){
            /* while(it1 < n && avec[it1].e1 >= b[i]){ */
            /* whatis(b[i]) // 4. wtf? */
            // -> init[i + 1] do n + 1 the reason.
            while(it1 < n && avec[it1].e1 <= b[i]){
                /* whatis(avec[it1]) */
                /* modify(1,0,n-1,avec[it1].e2,n-1,-1); */
                modify(1,0,n,avec[it1].e2+1,n,-1);
                /* whatis("modify(1,0,n,avec[it1].e2+1,n,-1)") */
                ++it1;
                // tutaj wsm te, ale opposite border wanie?
                // -> nah, tutaj staje sie eq. nigdy nic nie staje sie gt, bo
                // default wszystko jest gt.
                /* if(avec[it2].e2 < crp + 1) */
                /*     ++crinv; */
            }
            /* while(it2 < n && avec[it2].e1 > b[i]){ */
            while(it2 < n && avec[it2].e1 < b[i]){
                /* whatis(avec[it2]) */
                modify(1,0,n,avec[it2].e2+1,n,-1);
                /* whatis("modify(1,0,n,avec[it2].e2+1,n,-1);") */
                // forgot to update crinv here.
                // though tylko w wypadku jak > crp??? TODO
                /* if(avec[it2].e2 >= crp) */
                /* /1* if(avec[it2].e2 >= crp + 1) *1/ */
                /*     ++crinv; */
                /* else */
                /*     --crinv; // hmmm */
                // -> < 0 res
                // no crp:
                ++crinv;
                ++it2;
            }
            /* whatis(i) */
            /* whatis(crp) */
            /* whatis(crinv) */
            /* whatis(n) */
            /* FORE(i,crp,n){ */
            /*     whatis(i) */
            /*     /1* whatis(query(1,0,n-1,i,i)) *1/ */
            /*     whatis(query2(1,0,n,i)) */
            /* } */
            /* pi sth = query(1,0,n-1,crp,n-1); */
            /* auto sth = query(1,0,n,crp,n); */
            auto sth = query(1,0,n,0,n);
            /* whatis(sth) */
            /* int sth2 = crp ? query(1,0,n,crp-1,crp-1).e1 : 0; */
            /* int sth2 = query2(1,0,n,crp); */
            int sth2 = query2(1,0,n,0);
            /* whatis(crp-1) */
            /* whatis(sth2) */
            assert(sth2 == 0);
            int df = sth.e1 - sth2;
            assert(df <= 0);
            /* crinv += df; */
            /* res += crinv; */
            res += crinv + df;
            /* modify(1,0,n,crp,sth.second-1,1000000); */
            /* modify(1,0,n,crp,sth.second-1,1000000); */
            /* crp = sth.second; */
        }
        cout << res << '\n';
    }
}