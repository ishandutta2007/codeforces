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

// so anyway to byo tyla bugow przez tilta ze szkoda gadac

#define N 500001
/* #define N 1000001 */
// NOW AC XDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
// yes, t2[N] giga iq

/* #define int ll */
// still WA, but different, more realistic output XD
// without that but with t2[N] fixed it does pass, and in a cool 529/2000ms in
// nlog^2n

//Lazy Propagation on Increment Modifications, Sum queries

ll t[N << 2];
ll lazy[N << 2];

void build(int v, int tl, int tr, int arr[]){
    if(tl == tr){
        t[v] = arr[tl];
        return;
    }
    int tm = (tl+tr)>>1;
    build(v<<1,tl,tm,arr);
    build(v<<1|1,tm+1,tr,arr);
    t[v] = t[v<<1] + t[v<<1|1];
}

void push(int v, int tl, int tr){
    if(lazy[v]){
        int tm = (tl+tr)>>1;
        t[v<<1] += (tm-tl+1)*lazy[v];
        t[v<<1|1] += (tr-tm)*lazy[v];
        lazy[v<<1] += lazy[v];
        lazy[v<<1|1] += lazy[v];
        lazy[v] = 0;
    }
}

void modify(int v, int tl, int tr, int l, int r, int val){
    if(l > r) return;
    if(tl == l && tr == r){
        lazy[v] += val;
        // potential overflow, but val here is -1 so whatever
        t[v] += val*(tr-tl+1);
        return;
    }
    push(v,tl,tr);
    int tm = (tl+tr)>>1;
    modify(v << 1,tl,tm,l,min(tm,r),val);
    modify(v << 1 | 1,tm+1,tr,max(l,tm+1),r,val);
    t[v] = t[v<<1] + t[v<<1|1];
}

// this has to return an ll as well btw.
// just arrays being ll does not suffice
ll query(int v, int tl, int tr, int l, int r){
    /* whatis(mp(tl,tr)) */
    /* whatis(t[v]) */
    if(l > r) return 0;
    if(tl == l && tr == r){
        return t[v];
    }
    push(v,tl,tr);
    int tm = (tl+tr)>>1;
    return query(v<<1,tl,tm,l,min(tm,r)) + query(v<<1|1,tm+1,tr,max(l,tm+1),r);
}

/* int t2[N]; */
// OMGGG XDDDDDDDDDDD
/* int t2[N << 1]; */
// N << 2 needed for recursive tree. That's important
int t2[N << 2];
int n;

/* int query(int l, int r){ */
/*     int res = -1; */
/*     for(l+=n, r+=n; l<r; l>>=1, r>>=1){ */
/*         if(l&1) */
/*             res = max(res,t2[l++]); */
/*             //res += t[l++]; */
/*         if(r&1) */
/*             res = max(res,t2[--r]); */
/*             //res += t[--r]; */
/*     } */
/*     return res; */
/* } */

void build2(int v, int tl, int tr, int arr[]){
    if(tl == tr){
        t2[v] = arr[tl];
        return;
    }
    int tm = (tl+tr)>>1;
    build2(v<<1,tl,tm,arr);
    build2(v<<1|1,tm+1,tr,arr);
    t2[v] = max(t2[v<<1], t2[v<<1|1]);
}

int find_f(int v, int lv, int rv, int l, int r, int x) {
    if(lv > r || rv < l) return -1;
    if(l <= lv && rv <= r) {
        if(t2[v] <= x) return -1;
        while(lv != rv) {
            int mid = lv + ((rv-lv) >> 1);
            if(t2[v << 1] > x) {
                v = v<<1;
                rv = mid;
            }else {
                v = v<<1|1;
                lv = mid+1;
            }
        }
        return lv;
    }

    int mid = lv + ((rv-lv)>>1);
    int rs = find_f(v<<1, lv, mid, l, r, x);
    if(rs != -1) return rs;
    return find_f(v<<1|1, mid+1, rv, l ,r, x);
}

/* int main(){ */
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n);
    string s;
    getstr(s);
    int a[n];
    FOR(i,0,n)
        a[i] = s[i] == '1';
    /* int sufbest[n]; */
    int suflen[n];
    int crlen[n];
    crlen[0] = a[0];
    set<pi> st; // {len,begpos} updated all time
    // for each pos or for each 1substrbeg?
    for(int i = 1; i < n; ++i){
        if(a[i])
            crlen[i] = crlen[i-1] + 1;
        else
            crlen[i] = 0;
        /* st.insert({crlen[i], i}); */
    }
    /* st.insert({crlen[0], 0}); */
    suflen[n-1] = a[n-1];
    /* st.insert({suflen[n-1], n-1}); */
    // ???
    /* for(int i = n-2; i >= 0; 00i){ */
    for(int i = n-2; i >= 0; --i){
        if(a[i])
            suflen[i] = suflen[i+1] + 1;
        else{
            /* if(a[i+1]) */
            /*     st.insert({suflen[i+1], i+1}); */
            suflen[i] = 0;
        }
        /* st.insert({crlen[i], i}); */
        /* st.insert({suflen[i], i}); */
    }
    /* if(a[0]) */
    /*     st.insert({suflen[0], 0}); */
    int init[n]; // l == 0
    init[0] = crlen[0];
    FOR(i,1,n){
        init[i] = max(init[i-1], crlen[i]);
    }
    /* FORR(i,init) */
    /*     cout << i << ' '; */
    /* cout << '\n'; */
    /* FORR(i,crlen) */
    /*     cout << i << ' '; */
    /* cout << '\n'; */
    /* FORR(i,suflen) */
    /*     cout << i << ' '; */
    /* cout << '\n'; */
    build(1,0,n-1,init);
    ll res = 0;
    /* whatis(st) */
    /* st.insert({0,n}); */ // ????
    // omgggg
    /* FOR(i,n,2*n) */
    /*     /1* t2[i] = init[i]; *1/ */
    /*     /1* t2[i] = crlen[i]; *1/ */
    /*     // XD */
    /*     t2[i] = crlen[i - n]; */
    /* for(int i = n - 1; i > 0; --i) */
    /*     t2[i] = max(t2[i*2] , t2[i*2|1]); */
    build2(1,0,n-1,crlen);
    /* vi sth = {crlen[0]}; */
    /* FOR(i,1,n){ */
    /*     sth.pb(max(sth.back(), crlen[i])); */
    /* } */
    // retarded
    /* whatis(sth) */
    FOR(i,0,n){
        /* res += query(1,0,n-1,0,n-1); */
        whatis(i)
        whatis(query(1,0,n-1,i,n-1))
        res += query(1,0,n-1,i,n-1);
        /* st.erase({suflen[i], i}); */
        /* st.erase({crlen[i], i}); */
        if(!a[i]) continue; // :?
        // suflen decrementowany -> -- na [i+1;first >= suflen[i])
        // eh, przeciez to nie jest ordered by first....
        // another segtree or sth??
        /* auto it = st.lower_bound({suflen[i],i+1}); */
        /* auto it = st.lower_bound({suflen[i],i+crlen[i]}); */
        /* auto it = st.lower_bound({suflen[i],i+suflen[i]}); */
        /* auto it = lower_bound(sth.begin()+i+suflen[i],sth.end(),suflen[i]); */
        // thats good, po prostu still not ordered by i...
        // a vector of max(crlen[i], this[i-1]) -> lower_bound ?
        /* if(it != st.end()) */
        /*     whatis(*it) */
        /* if(it != st.end() && it->e2 > i+1) */
        /* int r = (it == st.end() ? n - 1 : it -> e2 - 1); */
        /* int r = (it == sth.end() ? n - 1 : it - sth.begin() - 1); */
            /* modify(1,0,n-1,i+1, it->e2 - 1, -1); */
        /* whatis(i + suflen[i]) */
        /* int r = find_f(1,i + suflen[i], n - 1, 0, n - 1, suflen[i]) - 1; */
        /* int r = find_f(1,i + suflen[i], n - 1, 0, n - 1, suflen[i] - 1) - 1; */
        int r = find_f(1,0, n-1, i + suflen[i], n - 1, suflen[i] - 1) - 1;
        if(r == -2)
            r = n - 1;
        // not that much faster. just 529ms -> 390ms
        /* whatis(r) */
        // binsearch brr hopefully works at least
        /* int low = i + suflen[i], high = n - 1, mid, ans = n; */
        /* while(low <= high){ */
        /*     mid = (low+high) / 2; */
        /*     int cr = query(i + suflen[i], mid + 1); */
        /*     if(cr >= suflen[i]){ */
        /*         ans = mid; */
        /*         high = mid - 1; */
        /*     } */
        /*     else{ */
        /*         low = mid + 1; */
        /*     } */
        /* } */
        // i dont ever modify a[i]? co jak init[0] = 1:?
        // wsm dont have to bo poza sume wychodzi i guess
        // XDDDDDDDD
        // does this 2 minute solution instead of a sophisticated structure
        // actually work...... hmmmmmmmm
        // nope. WA7 anyway
        // but that's because of overflow in lazy propagation XD
        /* int r = ans - 1; */
        if(r >= i+1)
            modify(1,0,n-1,i+1, r, -1);
        /* st.erase({crlen[i], i}); */
        /* st.erase({suflen[i], i}); */
    }
    cout << res << '\n';
}