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
#define whatis(x) cerr << #x << " is " << x << endl;
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
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
template<typename T> inline void print_128(T num){ if(!num) return; print_128(num / 10); cout.put((num % 10) + '0'); }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

inline uint64_t fastpow(uint64_t a, uint64_t b, uint64_t mod){
    if(b == 1)
        return a;
    if(b&1){
        return (a * fastpow(a,b^1,mod)) % mod;
    }
    a = fastpow(a,b >> 1,mod);
    return (a*a)%mod;
}

//Miller-Rabin
inline bool isprime(ull n){
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(n%2 == 0) return 0;
    /* for(ull i = 3; i*i <= n; i += 2){ */
    /*     if(n%i == 0) return 0; */
    /* } */
    /* return 1; */
    ull magic[] = {2,3,5,7}; //enough for <= 1 << 32
    ull d = n;
    --d;
    ull r = 0;
    while(d%2)
        d /= 2, ++r;
    bool pr = 1;
    FORR(k,magic){
        if(k >= n) break;
        ull x = fastpow(k,d,n);
        if(x == 1 || x == n-1) continue;
        bool kk = 1;
        FOR(i,0,r-1){
            x = x*x%n;
            if(x == n-1){
                k = 0;
                break;
            }
        }
        if(kk){
            pr = 0;
            break;
        }
    }
    return pr;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    /* int n; */
    /* sc(n); */
    /* static bool s[1000001]; */
    /* vector<ll> primes = {4}; */
    /* for(ll i = 3; i <= 1000000; i += 2){ */
    /*     if(s[i]) continue; */
    /*     primes.pb(i*i); */
    /*     for(int x = i << 1; x <= 1000000; x += i) */
    /*         s[x] = 1; */
    /* } */
    /* ll cur; */
    /* while(n--){ */
    /*     sc(cur); */
    /*     /1* bool g = 0; *1/ */
    /*     /1* FORR(i,primes){ *1/ */
    /*     /1*     if(cur%i == 0){ *1/ */
    /*     /1*         cur /= i; *1/ */
    /*     /1*         if(cur%i == 0){ *1/ */
    /*     /1*             g = 1; *1/ */
    /*     /1*         } *1/ */
    /*     /1*         break; *1/ */
    /*     /1*     } *1/ */
    /*     /1* } *1/ */
    /*     /1* cout << (g?"YES\n":"NO\n"); *1/ */
    /*     cout << (binary_search(all(primes),cur)?"YES\n":"NO\n"); */
    /* } */
    int t;
    sc(t);
    while(t--){
        ll n;
        sc(n);
        ll sq = sqrtl(n);
        if(sq*sq != n){
            cout << "NO\n";
        }
        else{
            cout << (isprime(sq)?"YES\n":"NO\n");
        }
    }
}