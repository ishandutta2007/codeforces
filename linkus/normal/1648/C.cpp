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
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
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
#define debug(x...) ;
#endif
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) { return o << '(' << p.first << ", " << p.second << ')'; }
template<class T, enable_if_t<!is_same<T, string>::value, bool> = true> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) { o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}'; }
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 200001

// suma cntw.
ll t[N];

//1 INDEXED, increment in function if needed

inline void upd(int pos, int val){ //val is delta
    for(;pos < N;pos += pos & (-pos))
            //simply for(;posy <= m;posy += posy & (-posy)) for 2nd dimension
        t[pos] += val;
}

inline int query(int r){ //[0,r]
    int ret = 0;
    for(;r > 0;r -= r & (-r))
        ret += t[r];
    return ret;
}

constexpr int64_t mod = 998244353;
ll fac[N];
ll facinv[N];

inline int64_t fastpow(int64_t a, int64_t b){
    if(b == 0)
        return 1;
    if(b&1){
        return (a * fastpow(a,b^1)) % mod;
    }
    a = fastpow(a,b >> 1);
    return (a*a)%mod;
}

// constexpr btw?
void pre(){
    fac[0] = 1;
    FOR(i,1,N)
        fac[i] = fac[i - 1] * i % mod;
#if N == 1000001
    if constexpr (mod == 1000000007)
        facinv[N - 1] = 397802501;
    else
        facinv[N - 1] = fastpow(fac[N - 1], mod - 2);
#else
    facinv[N - 1] = fastpow(fac[N - 1], mod - 2);
#endif
    for(int i = N - 2; i >= 0; --i)
        facinv[i] = facinv[i + 1] * (i + 1) % mod;
    // Also i^-1 = facinv[i] * fac[i - 1] (i in 1..n)
    // Similary idea can be used to get invs of any n numbers in O(n + logp).
    // -> zamiast *1, *2, *3... do *a[0], *a[1], *a[2]...
}
 
int cnt[N];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    pre();
    int n,m;
    sc(n,m);
    int s[n], t[m];
    GET(s);
    GET(t);
    ll res = 0;
    FORR(i,s){
        ++cnt[i];
    }
    ll crfrac = fac[n];
    FOR(i,1,N){
        upd(i, cnt[i]);
        crfrac *= facinv[cnt[i]];
        crfrac %= mod;
    }
    /* FORE(i,0,min(n-1,m)){ */
    FORE(i,0,min(n,m)){
        // first lt at [i].
        debug("in", i, res);
        /* if(i == m){ */
        /* if(i == n && n < m){ */
        if(i == min(n,m)){
            // TODO nie entire frac czasem?
            // albo wsm nic? (bo priced in z prev)
            // -> ye, nic.
            if(n < m){
                ++res;
                // Oh fuck. rip modulo XDDDDDDDDDDDDDDDDDDDDDDDDD
                // Pls dont there be a case which messes this up.
                res %= mod;
            }
            break;
        }
        ll sum = t[i] > 1 ? query(t[i] - 1) : 0;
        debug(crfrac, crfrac * facinv[n - i] % mod * fac[n - i - 1] % mod, sum);
        /* res += crfrac * sum % mod; */
        // jeszcze wywalenie cr chara.
        // albo nie wait. bo dopiero po tym indeed..
        res += crfrac * facinv[n - i] % mod * fac[n - i - 1] % mod * sum % mod;
        res %= mod;
        /* if(i + 1 < n){ // edg case */
        /* } */
        if(i != n){
            if(!cnt[t[i]])
                break;
            // --fac w liczniku
            crfrac *= facinv[n - i];
            crfrac %= mod;
            crfrac *= fac[n - i - 1];
            crfrac %= mod;
            // mianownik.
            crfrac *= fac[cnt[t[i]]];
            crfrac %= mod;
            --cnt[t[i]];
            crfrac *= facinv[cnt[t[i]]];
            crfrac %= mod;
            upd(t[i], -1);
        }
        debug("out", i, res);
    }
    cout << res << '\n';
}