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
#define N 1000001

ll n,l,r,z;

inline uint64_t mulmod(uint64_t a, uint64_t b, uint64_t mod){
    if(b == 1) return a;
    if(b&1){
        return (a+mulmod(a,b^1,mod))%mod;
    }
    return mulmod(a,b >> 1,mod)*2%mod;
}

constexpr int64_t mod = 1000000007;
/* constexpr int64_t mod = 998244353; */
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
// -> operation limit that can't be changed by a pragma is too low. (agc051a.cpp tried on pc)
void pre(){
    fac[0] = 1;
    FOR(i,1,N)
        fac[i] = fac[i - 1] * i % mod;
    if constexpr (mod == 1000000007 && N == 1000001)
        facinv[N - 1] = 397802501;
    else if constexpr (mod == 998244353 && N == 1000001)
        facinv[N - 1] = 490058372;
    else
        facinv[N - 1] = fastpow(fac[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; --i)
        facinv[i] = facinv[i + 1] * (i + 1) % mod;
    // Also i^-1 = facinv[i] * fac[i - 1] (i in 1..n)
    // Similary idea can be used to get invs of any n numbers in O(n + logp).
    // -> zamiast *1, *2, *3... do *a[0], *a[1], *a[2]...
}

ll binom(ll n, ll k){
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

ll res;
map<ll,ll> mpp;

void rec(ll rem, int k, ll cr){
    if(k == 60){
        res += cr;
        if(res >= mod)
            res -= mod;
        return;
    }
    for(int ile = (z >> k) & 1; ile <= min(rem, n); ile += 2){
        /* rec((rem - ile) >> 1, k + 1, cr * binom(n, ile) % mod); */
        mpp[(rem - ile) >> 1] += cr * binom(n, ile) % mod;
    }
}

void dorec(ll rem){
    mpp.clear();
    mpp[rem] = 1;
    REP(k,61){
        map<ll,ll> crmpp = mpp;
        mpp.clear();
        FORR(i,crmpp){
            /* rec(i.e1 % mod, k, i.e2); */
            /* rec(i.e1 % mod, k, i.e2 % mod); // bruuuh */
            rec(i.e1, k, i.e2 % mod); // bruuuh
            // eh. feynman couldve saved me.
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    pre();
    sc(n,l,r,z);
    /* rec(r,0,1); */
    dorec(r);
    ll resall = res;
    res = 0;
    /* rec(l-1,0,1); */
    dorec(l-1);
    // XD.
    /* cout << resall - res << '\n'; */
    cout << ((resall - res) % mod + mod) % mod << '\n';
}