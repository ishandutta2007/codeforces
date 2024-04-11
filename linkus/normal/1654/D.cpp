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
#define N 1000001

int t, n;
vector<array<int, 3>> adj[N];

inline uint64_t mulmod(uint64_t a, uint64_t b, uint64_t mod){
    if(b == 1) return a;
    if(b&1){
        return (a+mulmod(a,b^1,mod))%mod;
    }
    return mulmod(a,b >> 1,mod)*2%mod;
}

constexpr int64_t mod = 998244353;
inline int64_t fastpow(int64_t a, int64_t b){
    if(b == 0)
        return 1;
    if(b&1){
        return (a * fastpow(a,b^1)) % mod;
    }
    a = fastpow(a,b >> 1);
    return (a*a)%mod;
}

int gcdExtended(int a, int b, int *x, int *y){
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}

//dzielnik i modulo musza byc wzglednie pierwsze
//jesli oba sa PIERWSZE, mozna tez uzyskac invb=fastpow(b,mod-2) % mod
int modInverse(int a, int m) {
    int x, y;
    gcdExtended(a, m, &x, &y);
    return (x%m + m) % m;
}

ll fac[N];
ll facinv[N];

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

ll res;
ll mxf[N], f[N];

int whdiv[N];

vector<int> getfac(int v){
    vector<int> ret;
    while(v != 1){
        ret.push_back(whdiv[v]);
        v /= whdiv[v];
    }
    return ret;
}

void d1(int v, int p){
    debug(v, f[2], mxf[2]);
    FORR(i,adj[v]){
        if(i[0] == p) continue;
        debug(i[2], getfac(i[2]));
        FORR(x,getfac(i[2]))
            --f[x];
        FORR(x,getfac(i[1]))
            mxf[x] = max(mxf[x], ++f[x]);
        d1(i[0], v);
        FORR(x,getfac(i[2]))
            ++f[x];
        FORR(x,getfac(i[1]))
            --f[x];
    }
}

void d2(int v, int p, ll val){
    res += val;
    res %= mod;
    debug(v, val);
    FORR(i,adj[v]){
        if(i[0] == p) continue;
        ll nwval = val;
        FORR(x,getfac(i[2]))
            nwval *= x, nwval %= mod;
        FORR(x,getfac(i[1]))
            nwval *= facinv[x] * fac[x - 1] % mod, nwval %= mod;
        d2(i[0], v, nwval);
    }
}
 
int main(){
    pre();
    FOR(i,2,200001){
        if(whdiv[i] == 0){
            whdiv[i] = i;
            for(ll x = (ll)i * i; x < 200001; x += i){
                if(whdiv[x] == 0)
                    whdiv[x] = i;
            }
        }
    }
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(t);
    while(t--){
        sc(n);
        FOR(i,0,n)
            adj[i].clear();
        res = 0;
        FOR(i,1,n){
            int f,s,w1,w2;
            sc(f,s,w1,w2);
            --f,--s; // kox forget.
            adj[f].push_back({s,w1,w2});
            adj[s].push_back({f,w2,w1});
        }
        // forgot this.
        memset(mxf,0,(n+1) << 3);
        d1(0,-1);
        ll p = 1;
        FORE(i,0,n){
            FOR(x,0,mxf[i])
                p = p * i % mod;
        }
        debug(p);
        d2(0,-1,p);
        cout << res << '\n';
    }
}