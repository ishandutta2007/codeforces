#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <climits>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <numeric>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
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
#define N 100001

ll fac[N];
ll mod = 998244353;
/* vector<vi> nwm; */
vector<ll> pr;

inline uint64_t fastpow(uint64_t a, uint64_t b, uint64_t mod){
    if(b == 1)
        return a;
    if(b&1){
        return (a * fastpow(a,b^1,mod)) % mod;
    }
    a = fastpow(a,b >> 1,mod);
    return (a*a)%mod;
}

ll tab[N];
ll inv(int a){
    if(tab[a])
        return tab[a];
    return tab[a] = fastpow(fac[a],mod-2,mod);
}

ll ile(ll f, ll s){ //f <= s, s%f == 0
    if(f > s) swap(f,s);
    if(f == s) return 1;
    vector<ll> cnt;
    assert(s % f == 0);
    ll num = s/f;
    whatis(num)
    FORR(i,pr){
        int cr = 0;
        while(num % i == 0){
            num /= i;
            ++cr;
        }
        if(cr){
            cnt.pb(cr);
        }
    }
    assert(num == 1);
    /* if(num != 1){ */
    /*     ll sq = sqrtl(num)+0.5; */
    /*     if(sq*sq == num){ */
    /*         cnt.pb(2); */
    /*     } */
    /*     else if(!isprime(num)){ */
    /*         cnt.pb(1); */
    /*         cnt.pb(1); */
    /*     } */
    /*     else{ */
    /*         cnt.pb(1); */
    /*     } */
    /* } */
    int sum = 0;
    FORR(i,cnt){
        sum += i;
    }
    ll ret = fac[sum];
    FORR(i,cnt){
        ret *= inv(i);
        ret %= mod;
    }
    whatis(cnt)
    return ret;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    fac[0] = 1;
    FOR(i,1,N)
        fac[i] = fac[i-1]*i%mod;
    ll d;
    sc(d);
    for(ll i = 2; i*i <= d; ++i){
        while(d%i == 0){
            if(pr.empty() || pr.back() != i)
                pr.push_back(i);
            d /= i;
        }
    }
    if(d != 1)
        pr.pb(d);
    int q;
    sc(q);
    while(q--){
        ll f,s;
        sc(f,s);
        if(f > s) swap(f,s);
        ll gc = __gcd(f,s);
        /* if(gc != 1){ */
        cout << ile(gc,f) * ile(gc,s) % mod << '\n';
        /* } */
        /* else{ */
        /*     cout << ile(f,s) << '\n'; */
        /* } */
    }
}