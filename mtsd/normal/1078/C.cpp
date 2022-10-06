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
typedef pair<int,int> pii;
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

mod dp[300010][3];

int main(){
    int n;
    cin >> n;
    vector<vector<int> > g(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    auto dfs = [&](auto self,int id,int pre) ->void{
        if(g[id].size()==1&&g[id][0]==pre){
            dp[id][0] = 1;
            return;
        }
        int k = 0;
        vector<int> nxt;
        vector<mod> a[3];
        for(auto x:g[id]){
            if(x==pre)continue;
            self(self,x,id);
            a[0].push_back(dp[x][0]);
            a[1].push_back(dp[x][1]);
            a[2].push_back(dp[x][2]);
            k++;
        }
        
        if(k==1){
            dp[id][1] += a[2][0] + a[0][0];
            dp[id][2] += a[1][0];
            dp[id][0] += a[0][0] + a[1][0];
        }else{
            vector<mod> p(k),q(k);
            vector<mod> pp(k),qq(k);
            rep(i,k){
                p[i] = a[0][i]+2*a[1][i];
                pp[i] = 2*a[1][i];
                if(i!=0){
                    p[i] *= p[i-1];
                    pp[i] *= pp[i-1];
                }
            }
            for(int i=k-1;i>=0;i--){
                q[i] = a[0][i]+2*a[1][i];
                qq[i] = 2*a[1][i];
                if(i!=k-1){
                    q[i] *= q[i+1];
                    qq[i] *= qq[i+1];
                }
            }
            
            rep(i,k){
                if(i==0){
                    dp[id][1] += a[2][i] * q[i+1];
                }else if(i==k-1){
                    dp[id][1] += a[2][i] * p[i-1];
                }else{
                    dp[id][1] += a[2][i] * p[i-1]*q[i+1];
                }
            }
            rep(i,k){
                if(i==0){
                    dp[id][1] += a[0][i] * q[i+1];
                }else if(i==k-1){
                    dp[id][1] += a[0][i] * p[i-1];
                }else{
                    dp[id][1] += a[0][i] * p[i-1]*q[i+1];
                }
            }
            mod tmp  = 1;
            rep(i,k){
                tmp *= a[0][i]+a[1][i];
            }
            dp[id][0] += tmp;
            tmp = 1;
            mod tt = 1;
            rep(i,k){
                tmp *= a[0][i]+a[1][i]*2;
                tt *= a[0][i]+a[1][i];
            }
            dp[id][2] += tmp-tt;
            // rep(i,k){
            //     tmp *= a[1][i]*2 + a[2][i];
            //     tt *= a[1][i]*2;
            // }
            // dp[id][2] += tmp-tt;
        }
        // cerr << id << " " << dp[id][0] << " " << dp[id][1] << " " << dp[id][2] << endl;
    };
    dfs(dfs,0,-1);
    cout << dp[0][0] + dp[0][1] << endl;
    return 0;
}