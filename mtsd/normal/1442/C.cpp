#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<pair<int,int>,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}

template <unsigned int mod>
class ModInt {
private:
    unsigned int v;
    static unsigned int norm(const unsigned int& x){ return x < mod ? x : x - mod; }
    static ModInt make(const unsigned int& x){ ModInt m; return m.v = x, m; }
    static ModInt inv(const ModInt& x){ return make(inverse(x.v, mod)); }
    static unsigned int inverse(int a, int m){
        int u[] = {a, 1, 0}, v[] = {m, 0, 1}, t;
        while(*v){
            t = *u / *v;
            swap(u[0] -= t * v[0], v[0]), swap(u[1] -= t * v[1], v[1]), swap(u[2] -= t * v[2], v[2]);
        }
        return (u[1] % m + m) % m;
    }

public:
    ModInt() : v{0}{}
    ModInt(const long long val) : v{norm(val % mod + mod)} {}
    ModInt(const ModInt<mod>& n) : v{n()} {}
    explicit operator bool() const noexcept { return v != 0; }
    bool operator!() const noexcept { return !static_cast<bool>(*this); }
    ModInt& operator=(const ModInt& n){ return v = n(), (*this); }
    ModInt& operator=(const long long val){ return v = norm(val % mod + mod), (*this); }
    ModInt operator+() const { return *this; }
    ModInt operator-() const { return v == 0 ? make(0) : make(mod - v); }
    ModInt operator+(const ModInt& val) const { return make(norm(v + val())); }
    ModInt operator-(const ModInt& val) const { return make(norm(v + mod - val())); }
    ModInt operator*(const ModInt& val) const { return make((long long)v * val() % mod); }
    ModInt operator/(const ModInt& val) const { return *this * inv(val); }
    ModInt& operator+=(const ModInt& val){ return *this = *this + val; }
    ModInt& operator-=(const ModInt& val){ return *this = *this - val; }
    ModInt& operator*=(const ModInt& val){ return *this = *this * val; }
    ModInt& operator/=(const ModInt& val){ return *this = *this / val; }
    ModInt operator+(const long long val) const { return ModInt{v + val}; }
    ModInt operator-(const long long val) const { return ModInt{v - val}; }
    ModInt operator*(const long long val) const { return ModInt{(long long)v * (val % mod)}; }
    ModInt operator/(const long long val) const { return ModInt{(long long)v * inv(val)}; }
    ModInt& operator+=(const long long val){ return *this = *this + val; }
    ModInt& operator-=(const long long val){ return *this = *this - val; }
    ModInt& operator*=(const long long val){ return *this = *this * val; }
    ModInt& operator/=(const long long val){ return *this = *this / val; }
    bool operator==(const ModInt& val) const { return v == val.v; }
    bool operator!=(const ModInt& val) const { return !(*this == val); }
    bool operator==(const long long val) const { return v == norm(val % mod + mod); }
    bool operator!=(const long long val) const { return !(*this == val); }
    unsigned int operator()() const { return v; }
    friend ModInt operator+(const long long val, const ModInt& n) { return n + val; }
    friend ModInt operator-(const long long val, const ModInt& n) { return ModInt{val - n()}; }
    friend ModInt operator*(const long long val, const ModInt& n) { return n * val; }
    friend ModInt operator/(const long long val, const ModInt& n) { return ModInt{val} / n; }
    friend bool operator==(const long long val, const ModInt& n) { return n == val; }
    friend bool operator!=(const long long val, const ModInt& n) { return !(val == n); }
    friend istream& operator>>(istream& is, ModInt& n){
        unsigned int v;
        return is >> v, n = v, is;
    }
    friend ostream& operator<<(ostream& os, const ModInt& n){ return (os << n()); }
    friend ModInt mod_pow(ModInt x, long long n){
        ModInt ans = 1;
        while(n){
            if(n & 1) ans *= x;
            x *= x, n >>= 1;
        }
        return ans;
    }
};

#define MOD 998244353
using mod = ModInt<MOD>;

#define MAX_N 200000
mod inv[MAX_N],fac[MAX_N],finv[MAX_N];

void make()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i=2;i<MAX_N;i++){
        inv[i] = MOD - inv[MOD % i] * (MOD / i);
        fac[i] = fac[i-1] * i;
        finv[i] = finv[i-1] * inv[i];
    }
}

mod comb(int a, int b)
{
    if(a<b) return 0;
    return fac[a] * finv[b] * finv[a-b];
}


#define int long long

ll res[21][200010];
pair<ll,ll> reach[2][200010];


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    vector<vector<int> > rev(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        rev[b].push_back(a);
    }
    Fill(reach,MP(1LL<<60,1LL<<60));
    Fill(res,1LL<<60);
    res[0][0] = 0;
    reach[0][0] = MP(0,0);
    priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>> >pq;
    pq.push(MP(MP(0,0),0));
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int flip = x.first.first;
        int cost = x.first.second;
        int id = x.second;
        if(flip>=20){
            if(flip%2==0){
                if(reach[0][id] != MP(flip,cost))continue;
                pair<ll,ll> nxt = MP(flip,cost+1);
                for(auto x:g[id]){
                    if(chmin(reach[0][x],nxt)){
                        pq.push(MP(nxt,x));
                    }
                }
            }else{
                if(reach[1][id] != MP(flip,cost))continue;
                pair<ll,ll> nxt = MP(flip,cost+1);
                for(auto x:rev[id]){
                    if(chmin(reach[1][x],nxt)){
                        pq.push(MP(nxt,x));
                    }
                }
            }
        }else{
            if(flip%2==0){
                if(res[flip][id] != cost)continue;
                ll nxt = cost+1;
                for(auto x:g[id]){
                    if(chmin(res[flip][x],nxt)){
                        pq.push(MP(MP(flip,nxt),x));
                    }
                }
            }else{
                if(res[flip][id] != cost)continue;
                ll nxt = cost+1;
                for(auto x:rev[id]){
                    if(chmin(res[flip][x],nxt)){
                        pq.push(MP(MP(flip,nxt),x));
                    }
                }
            }
        }
        //flip
        if(flip<=18){
            if(chmin(res[flip+1][id],cost)){
                pq.push(MP(MP(flip+1,cost),id));
            }
        }else{
            pair<ll,ll> nxt = MP(flip+1,cost);
            if(flip%2==1){
                if(chmin(reach[0][id],nxt)){
                    pq.push(MP(nxt,id));
                }
            }else{
                if(chmin(reach[1][id],nxt)){
                    pq.push(MP(nxt,id));
                }
            }
        }
    }
    bool ok = 0;
    ll mi = (1LL<<60);
    ll tmp = 1;
    rep(i,20){
        if(res[i][n-1]!=(1LL<<60)){
            ok = 1;
            chmin(mi,res[i][n-1] + tmp-1);
        }
        tmp *= 2;
    }
    if(ok){
        cout << mi%998244353 << endl;
    }else{
        auto ans = min(reach[0][n-1],reach[1][n-1]);
        mod sss = mod_pow((mod)(2),ans.first);
        sss += ans.second;
        sss -= 1;
        cout << sss << endl;
    }
    return 0;
}