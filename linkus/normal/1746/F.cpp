#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ssize(x) int(x.size())
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define FORR(x,arr) for(auto &x: arr)
#define REE(s_) {cout<<s_<<'\n';exit(0);}
#define GET(arr) for(auto &i: (arr)) sc(i)
#define e1 first
#define e2 second
#define INF 0x7f7f7f7f
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "),...); }(x), cerr << '\n'
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
typedef uint64_t ull;
using namespace std;
using namespace __gnu_pbds;

#ifdef ONLINE_JUDGE
#define debug(...) {}
#endif
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) { return o << '(' << p.first << ", " << p.second << ')'; }
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) { o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}'; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// 1 << 19 if segtree where merges matter.
#define N 300001

#define bits 64

struct st{
    int cnts[bits]{};
};

st baseval;
st t[N*2]; // XXX jeeli wiele testw to sikwadraci z t takim.
template<st op(st, st)>
class seg{
public:
    ll n;

    st query(ll l, ll r){
        st res = baseval;
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
        st xd{};
        REP(i,bits){
            xd.cnts[i] = bool(val & (1ll << i));
        }
        for(t[p += n] = xd; p > 1; p>>=1)
            t[p>>1] = op(t[p] , t[p^1]);
    }

    /* template<typename T> */
    seg(int n) : n(n) {
        /* for(int i = 2*n-1; i >= n; --i) */
        /*     t[i] = a[i - n]; */
        /* for(int i = n - 1; i > 0; --i) */
        /*     t[i] = op(t[i<<1] , t[i<<1|1]); */
    }
};

st fun(st a, st b){
    st ret = a;
    REP(i,bits){
        ret.cnts[i] += b.cnts[i];
    }
    return ret;
    /* return max(a,b); */
    /* return min(a,b); */
    /* return a + b; */
}

/* mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); //mt19937_64 for 64bit */
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); //mt19937_64 for 64bit
inline ll rand(ll l, ll r){
    return uniform_int_distribution<ll>(l,r)(rng);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    /* srand(time(0)^213769420); */
    int n,q;
    sc(n,q);
    map<ll,ll> mp;
    seg<fun> t(n);
    ll a[n];
    GET(a);
    REP(i,n){
        ll v;
        if(mp.count(a[i])){
            v = mp[a[i]];
        }
        else{
            v = mp[a[i]] = rand(0, (1ll << 62) - 1);
        }
        t.modify(i, v);
    }
    while(q--){
        int typ;
        sc(typ);
        if(typ == 1){
            ll p,val;
            sc(p,val);
            ll v;
            if(mp.count(val)){
                v = mp[val];
            }
            else{
                v = mp[val] = rand(0, (1ll << 62) - 1);
            }
            --p;
            t.modify(p, v);
        }
        else{
            int l,r,k;
            sc(l,r,k);
            --l,--r;
            auto res = t.query(l,r+1);
            bool kk = 1;
            REP(i,bits){
                kk &= res.cnts[i] % k == 0;
            }
            cout << (kk ? "YES\n" : "NO\n");
        }
    }
}