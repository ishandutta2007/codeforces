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
#define N 1000001

/* struct segtree{ */
#define int int64_t

template<ll op(ll, ll), ll baseval>
class seg{
public:
    ll t[N*2];
    ll n;

    ll query(ll l, ll r){
        ll res = baseval;
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

    void modify(ll p, ll val){
        for(t[p += n] = val; p > 1; p>>=1)
            t[p>>1] = op(t[p] , t[p^1]);
    }

    /* template<typename T> */
    /* seg(T a, int n) : n(n) { */
    /*     for(int i = 2*n-1; i >= n; --i) */
    /*         t[i] = a[i - n]; */
    /*     for(int i = n - 1; i > 0; --i) */
    /*         t[i] = op(t[i<<1] , t[i<<1|1]); */
    /* } */
};

ll fun(ll a, ll b){
    /* return max(a,b); */
    /* return min(a,b); */
    return a + b;
}
 
seg<fun, 0> t;
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    int a[n];
    GET(a);
    int b[n];
    FOR(i,0,n){
        --a[i];
        b[a[i]] = i;
    }
    int inv[n];
    int cr = 0;
    ordered_set<int> st;
    /* int ord[n]; */
    int arr[n];
    memset(arr,0,sizeof arr);
	/* seg<fun, 0> t(vi(arr, arr+n), n); */
    t.n = n;
    FOR(i,0,n){
        /* whatis(b[i]) */
        /* ord[i] = st.order_of_key(b[i]); */
        /* whatis(st.order_of_key(b[i])) */
        /* l.modify(1,0,n-1,0,b[i],1); */
        cr += st.size() - st.order_of_key(b[i]);
        /* whatis(st.order_of_key(b[i])) */
        st.insert(b[i]);
        inv[i] = cr;
        /* ord[i] = st.order_of_key(b[i]); */
        // git jednak xd.
        /* whatis(ord[i]) */
        // wtf.
        /* whatis(inv[i]) */
    }
    int dist[n];
    /* set<int> st2; */
    dist[0] = 0;
    /* int crmid = 0, midind = b[0]; */
    /* auto it = st2.insert(b[0]).first; */
    /* int mid = b[0]; */
    /* int cntl = 0, cntr = 0; */
    /* modify(1,0,n-1,mid,mid,-1); */
    /* cntl += query(1,0,n-1,0,mid); */
    /* cntr += query(1,0,n-1,mid,n-1); */
    cr = 0;
    ordered_set<int> st2;
    st2.insert(b[0]);
    // forgot this.
    t.modify(b[0], b[0]);
    FOR(i,1,n){
        /* cr = */ 
        whatis(i)
        st2.insert(b[i]);
        t.modify(b[i], b[i]);
        whatis(b[i])
        int mid = i / 2;
        int midind = *st2.find_by_order(i / 2);
        cr = 0;
        if(mid)
            cr += mid * (midind - 1 + midind - mid) / 2;
        whatis(cr)
        int k = i + 1;
        whatis(mid)
        whatis(k)
        whatis(midind)
        if(mid + 1 < k)
            cr -= (k - mid - 1) * (midind + 1 + midind + k - mid - 1) / 2;
        whatis(cr)
        cr -= t.query(0, midind);
        cr += t.query(midind + 1, n);
        whatis(t.query(midind + 1, n))
        whatis(cr)
        // nie midind tylko newly inserted lol.
        /* t.modify(midind, midind); */
        /* dist[i] = cr; */
        dist[i] = cr;
    }
    FOR(i,0,n){
        cout << inv[i] + dist[i] << ' ';
    }
    cout << '\n';
}