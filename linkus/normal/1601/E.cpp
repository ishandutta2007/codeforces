/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC optimize("Ofast,unroll-loops") */
/* #pragma GCC target("avx2,popcnt") */
#include <bits/stdc++.h>
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
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, deque<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
#define N 1000001

#define int ll
/* struct fen{ */
/* int t[N]; */

/* //1 INDEXED, increment in function if needed */

/* inline void upd(int pos, int val){ //val is delta */
/*     ++pos; */
/*     for(;pos <= 300003;pos += pos & (-pos)) */
/*             //simply for(;posy <= m;posy += posy & (-posy)) for 2nd dimension */
/*         t[pos] += val; */
/* } */

/* inline int query(int r){ //[0,r] */
/*     ++r; */
/*     int ret = 0; */
/*     for(;r > 0;r -= r & (-r)) */
/*         ret += t[r]; */
/*     return ret; */
/* } */
/* }; */

/* #define maxk 10 */
/* fen sum[maxk]; */
/* fen cnt[maxk]; */

pi t[N*2];
ll n;

pi op(pi a, pi b){
    return min(a,b);
}

pi query(ll l, ll r){
    pi res = {INF, INF};
    for(l+=n, r+=n; l<r; l>>=1, r>>=1){
        if(l&1)
            res = op(res,t[l++]);
            //res += t[l++];
        if(r&1)
            res = op(res,t[--r]);
            //res += t[--r];
    }
    return res;
}

/* template<typename T> */
/* seg(T a, int n) : n(n) { */
/*     for(int i = 2*n-1; i >= n; --i) */
/*         t[i] = a[i - n]; */
/*     for(int i = n - 1; i > 0; --i) */
/*         t[i] = op(t[i<<1] , t[i<<1|1]); */

// sz -1 -> unknown at compile time, dynamically allocated based on constructor.
template<typename T, size_t sz = 1000000, bool push_front_only = true, bool push_back_only = false>
struct fastdeque {
    T _a[sz];
    T *a = _a;
    /* template<std::enable_if_t<sz, int> = -1> */
    /* fastdeque(size_t dyn_sz) { */
    /*     a = new T[dyn_sz]; */
    /* } */
    /* template<std::enable_if_t<sz, int> = -1> */
    /* fastdeque() = delete; */
    int initpos = push_front_only ? sz : push_back_only ? 0 : sz >> 1;
    /* T *l = a + initpos, *r = a + initpos; */
    int l = initpos, r = initpos;
    void resize(size_t dyn_sz) {
        static_assert(sz == 0, "resize on nonzero init size");
        a = new T[dyn_sz];
        l = r = initpos = push_front_only ? dyn_sz : push_back_only ? 0 : dyn_sz >> 1;
    }
    /* template<std::enable_if_t<push_front_only, bool> = false> */
    void push_back(const T& value) {
        static_assert(!push_front_only, "push_back on push_front_only");
        a[r++] = value;
    }
    void pop_back() {
        --r;
    }
    /* template<std::enable_if_t<push_back_only, bool> = false> */
    void push_front(const T& value) {
        static_assert(!push_back_only, "push_front on push_back_only");
        a[--l] = value;
    }
    void pop_front() {
        ++l;
    }
    T &front() {
        return a[l];
    }
    T &back() {
        return a[r - 1];
    }
    T *begin() {
        return &a[l];
    }
    T *end() {
        return &a[r];
    }
    ssize_t size() {
        return r - l;
    }
    bool empty() {
        return l == r;
    }
    void clear() {
        /* r = l = initpos; */
        r = l = (r + l) >> 1;
    }
    T &operator [](size_t pos) {
        return a[l + pos];
    }
};

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    /* int n,q,k; */
    int q,k;
    sc(n, q, k);
    /* int a[3 * n]; */
    /* memset(a,127,sizeof a); */
    int a[n];
    FOR(i,0,n)
        sc(a[i]);
    int res[q];
    vector<pi> qus[n]; // [l] -> {r, ind}
    FOR(t,0,q){
        int l,r;
        sc(l,r);
        --l, --r;
        qus[l].push_back({r, t});
    }
    /* GET(a); */
    /* deque<int> vec[k]; */
    // XD. MLE with deques, ciekawe.
    /* deque<pi> vec[k]; // {ind, iletaken (for ezer fenwick updates)} */
    /* deque<pair<int,ll>> sumsuf[k]; // genialne. */
    /* deque<pair<int,ll>> cntsuf[k]; // genialne. */
    fastdeque<pi, 0> vec[k]; // {ind, iletaken (for ezer fenwick updates)}
    fastdeque<pair<int,ll>, 0> sumsuf[k]; // genialne.
    fastdeque<pair<int,ll>, 0> cntsuf[k]; // genialne.
    /* FOR(i,0,n){ */
    FOR(i,0,k){
        vec[i].resize(n / k + 3);
        sumsuf[i].resize(n / k + 3);
        cntsuf[i].resize(n / k + 3);
        /* vec[i].resize(300); */
        /* sumsuf[i].resize(300); */
        /* cntsuf[i].resize(300); */
    }
    /* whatis("Xd") */
    /* vector<pi> vec[k]; // {ind, iletaken (for ezer fenwick updates)} */
    /* vector<pair<int,ll>> sumsuf[k]; // genialne. */
    /* vector<pair<int,ll>> cntsuf[k]; // genialne. */
    for(int i = 2 * n - 1; i >= n; --i){
        /* t[i] = {a[i - n], i}; */
        t[i] = {a[i - n], i - n};
        /* whatis(i) */
        /* whatis(t[i]) */
    }
    for(int i = n - 1; i > 0; --i){
        t[i] = op(t[i << 1], t[i << 1 | 1]);
        /* whatis(i) */
        /* whatis(t[i]) */
    }
    /* fen sum[k]; */
    /* fen cnt[k]; */
    /* FOR(i,0,k) */
    /*     memset(sum[i].t,0,sizeof sum[i].t); */
    /* FOR(i,0,k) */
    /*     memset(cnt[i].t,0,sizeof sum[i].t); */
    for(int i = n - 1; i >= 0; --i){
        int md = i % k;
        /* int cntremd = 0; */
        int cntremd = 1; // 1 not remd, let's have it as total.
        /* int mnind = i; */
        /* int crmn = a[i]; */
        // leftover from when it was supposed to be sqrt (guess mgbym wsm
        // still mie sqrt, ale niech ju bedzie bez tego xd).
        /* for(int x = i + 1; x < i + k; ++x){ */
        /*     if(a[x] < crmn){ */
        /*         crmn = a[x]; */
        /*         mnind = x; */
        /*     } */
        /* } */
        auto [crmn, mnind] = query(i, i + k);
        /* whatis(i) */
        /* whatis(i + k) */
        /* whatis(crmn) */
        /* whatis(mnind) */
        /* while(vec[md].size() && a[vec[md].back().e1] >= a[i]){ */
        /* while(vec[md].size() && a[vec[md].back().e1] >= crmn){ */
        while(vec[md].size() && a[vec[md].front().e1] >= crmn){
            /* cntremd += vec[md].back().e2; */
            cntremd += vec[md].front().e2;
            /* sum[md].upd(vec[md].back().e1, -a[vec[md].back().e1] * vec[md].back().e2); */
            /* cnt[md].upd(vec[md].back().e1, -vec[md].back().e2); */
            /* sumsuf[md].pop_back(); */
            /* cntsuf[md].pop_back(); */
            /* vec[md].pop_back(); */
            sumsuf[md].pop_front();
            cntsuf[md].pop_front();
            vec[md].pop_front();
        }
        if(mnind != i){
            if(cntremd > 1){
                int ilerest = cntremd - 1;
                /* vec[md].push_back({mnind, ilerest}); */
                vec[md].push_front({mnind, ilerest});
                /* sumsuf[md].push_back({mnind, (sumsuf[md].empty() ? 0 : sumsuf[md][0].e2) + ilerest * crmn}); */
                /* cntsuf[md].push_back({mnind, (cntsuf[md].empty() ? 0 : cntsuf[md][0].e2) + ilerest}); */
                /* sumsuf[md].push_back({mnind, (sumsuf[md].empty() ? 0 : sumsuf[md].back().e2) + ilerest * crmn}); */
                /* cntsuf[md].push_back({mnind, (cntsuf[md].empty() ? 0 : cntsuf[md].back().e2) + ilerest}); */
                sumsuf[md].push_front({mnind, (sumsuf[md].empty() ? 0 : sumsuf[md].front().e2) + ilerest * crmn});
                cntsuf[md].push_front({mnind, (cntsuf[md].empty() ? 0 : cntsuf[md].front().e2) + ilerest});
                /* sum[md].upd(mnind, ilerest * crmn); */
                /* cnt[md].upd(mnind, ilerest); */
                cntremd -= ilerest;
                assert(cntremd == 1);
            }
        }
        /* vec[md].push_back({i, cntremd}); */
        vec[md].push_front({i, cntremd});
        /* sum[md].upd(i, cntremd * crmn); */
        /* sum[md].upd(i, cntremd * a[i]); */
        /* cnt[md].upd(i, cntremd); */
        /* sumsuf[md].push_back({mnind, (sumsuf[md].empty() ? 0 : sumsuf[md][0].e2) + cntremd * a[i]}); */
        /* cntsuf[md].push_back({mnind, (cntsuf[md].empty() ? 0 : cntsuf[md][0].e2) + cntremd}); */
        // bugg
        // bug2, pb vs pf xd.
        /* sumsuf[md].push_back({i, (sumsuf[md].empty() ? 0 : sumsuf[md][0].e2) + cntremd * a[i]}); */
        /* cntsuf[md].push_back({i, (cntsuf[md].empty() ? 0 : cntsuf[md][0].e2) + cntremd}); */
        /* sumsuf[md].push_back({i, (sumsuf[md].empty() ? 0 : sumsuf[md].back().e2) + cntremd * a[i]}); */
        /* cntsuf[md].push_back({i, (cntsuf[md].empty() ? 0 : cntsuf[md].back().e2) + cntremd}); */
        sumsuf[md].push_front({i, (sumsuf[md].empty() ? 0 : sumsuf[md].front().e2) + cntremd * a[i]});
        cntsuf[md].push_front({i, (cntsuf[md].empty() ? 0 : cntsuf[md].front().e2) + cntremd});
        /* whatis(i) */
        /* whatis(vec[md]) */
        /* whatis(i) */
        FORR(x, qus[i]){
            /* auto it = lower_bound(all(vec[md]), pi{x.e1,0}); */
            // wait. chce prev upper bnd wsm.
            auto it = lower_bound(all(vec[md]), pi{x.e1 + 1,0});
            /* whatis(*it) */
            /* auto it = lower_bound(vec[md].rbegin(), vec[md].rend(), pi{x.e1 + 1,0}); */
            // conv to vec -> opposite order.
            // moe just na reverse iteratory starczy?
            /* assert(it != vec[md].begin()); */
            --it;
            /* ll cr = sum[md].query(x.e1); // x.e1 eq it->e1 tutaj surely. */
            /* ll ile = cnt[md].query(x.e1); */
            /* auto sumit = lower_bound(all(sumsuf[md]), pair<int,ll>{it->e1 + 1,0}); */
            // chg deque do vec -> AC xd.
            /* int ind = (int)vec[md].size() - (it - vec[md].rbegin()); */
            // is .end() - sth defined? TODO
            /* int ind = (int)vec[md].size() - (it - vec[md].rbegin()) - 2; */
            int ind = it - vec[md].begin() + 1;
            // ind zamiast 3x binsearch -> 280ms time zamiast 483ms.
            // fastdeque ->
            // -> wow, that's the best chas.
            /* auto sumit = lower_bound(sumsuf[md].rbegin(), sumsuf[md].rend(), pair<int,ll>{it->e1 + 1,0}); */
            /* ll cr = sumsuf[md].back().e2; */
            /* whatis(ind) */
            /* whatis(sumsuf[md][ind]) */
            ll cr = sumsuf[md].front().e2;
            /* whatis(sumsuf[md]) */
            /* if(sumit != sumsuf[md].end()) */
            /* if(sumit != sumsuf[md].rend()) */
            /*     cr -= sumit->second; */
            /* if(ind != -1) */
            // ciekawe e ze zwykym deque nie wywalao.
            if(ind != vec[md].size())
                cr -= sumsuf[md][ind].second;
            /* whatis(cntsuf[md]) */
            /* auto ileit = lower_bound(all(cntsuf[md]), pair<int,ll>{it->e1 + 1,0}); */
            /* auto ileit = lower_bound(cntsuf[md].rbegin(), cntsuf[md].rend(), pair<int,ll>{it->e1 + 1,0}); */
            /* ll ile = cntsuf[md].back().e2; */
            ll ile = cntsuf[md].front().e2;
            /* if(ileit != cntsuf[md].end()) */
            /* if(ileit != cntsuf[md].rend()) */
            /*     ile -= ileit->second; */
            /* if(ind != -1) */
            if(ind != vec[md].size())
                ile -= cntsuf[md][ind].second;
            ll req = (x.e1 - i + 1 + k - 1) / k;
            ll ovkcnt = ile - req;
            /* whatis(cr) */
            /* whatis(ile) */
            /* whatis(req) */
            /* whatis(*it) */
            /* whatis(it - vec[md].begin()) */
            assert(ovkcnt >= 0);
            assert(ovkcnt <= it->second);
            cr -= a[it->first] * ovkcnt;
            res[x.e2] = cr;
        }
    }
    FORR(i,res)
        cout << i << '\n';
}