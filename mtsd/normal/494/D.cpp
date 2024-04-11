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

#define MOD 1000000007
using mod = ModInt<MOD>;
#define int long long
int n;

vector<vector<pair<int,mod> > > g;

int depth[100010];
int parent[30][100010];
mod dist[30][100010];

void lca_init(int id,int pre){
    if(pre!=-1){
        depth[id] = depth[pre] + 1;
    }
    for(auto x:g[id]){
        if(x.first==pre)continue;
        parent[0][x.first] = id;
        dist[0][x.first] = x.second;
        lca_init(x.first,id);
    }
}

mod sz[100010];
mod dsm[100010];
mod dp[100010];
mod dp2[100010];
mod dsm2[100010];
void dfs(int id,int pre){
    for(auto x:g[id]){
        if(x.first==pre)continue;
        dfs(x.first,id);
        sz[id] += sz[x.first];
        dsm[id] += dsm[x.first] + sz[x.first] * x.second;
        dp[id] += sz[x.first]*x.second*x.second + dsm[x.first]*x.second*2 + dp[x.first]; 
    }
    sz[id] += 1;
}

void dfs2(int id,int pre,mod w,mod ds,mod v){
    if(pre==-1){
        dsm2[id] += dsm[id];
        dp2[id] += dp[id];
        
    }
    if(pre!=-1){
        mod m = n-sz[id];
        dsm2[id] += dsm[id];
        dsm2[id] += w * (n-sz[id]) + ds;
        dp2[id] += dp[id];
        dp2[id] += m*w*w + ds * w * 2 + v;
    }
    for(auto x:g[id]){
        int nxt = x.first;
        if(nxt==pre)continue;
        mod W = x.second;
        dfs2(nxt,id,W, dsm2[id] - W*sz[nxt] - dsm[nxt], dp2[id] - dp[nxt] - W*W*sz[nxt] - W*dsm[nxt]*2);
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    g.resize(n);
    rep(i,n-1){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        g[a].push_back(MP(b,c));
        g[b].push_back(MP(a,c));
    }
    lca_init(0,-1);
    rep(i,25){
        rep(j,n){
            parent[i+1][j] = parent[i][parent[i][j]];
            dist[i+1][j] = dist[i][j] + dist[i][parent[i][j]];
        }
    }
    dfs(0,-1);
    dfs2(0,-1,0,0,0);
    // rep(i,n){
    //     cerr << i << " " << sz[i] << " " << dsm[i] << " "<<dsm2[i] << " " << dp[i] << " " << dp2[i] << endl;
    // }

    int q;
    cin >> q;
    rep(zz,q){
        int a,b;
        cin >> a >> b;
        a--;b--;
        int ta = a,tb = b;
        if(depth[ta]>depth[tb])swap(ta,tb);
        mod dstab = 0;
        for(int i=24;i>=0;i--){
            if(((depth[tb] - depth[ta])>>i)&1){
                dstab += dist[i][tb];
                tb = parent[i][tb];
            } 
        }
        int lca;
        if(ta!=tb){
            for(int i=24;i>=0;i--){
                if(parent[i][ta]!=parent[i][tb]){
                    dstab += dist[i][ta] + dist[i][tb];
                    ta = parent[i][ta];
                    tb = parent[i][tb];
                }
            }
            dstab += dist[0][ta] + dist[0][tb];
            lca = parent[0][ta];
        }else{
            lca = ta;
        }
        mod res = 0;
        // cerr << a << " "<< b << " " << lca << " " << dstab << endl;
        if(lca==b){
            res += dp2[a];
            
            if(b!=0){
                int x = parent[0][b];
                mod w = dist[0][b];
                mod tmp = 0;
                mod D = 0;
                // cerr << dp2[x] << endl;
                tmp += dp2[x];      
                tmp -= dp[b];  
                tmp -= w*w*sz[b];
                tmp -= w*(dsm[b] )*2;
                // cerr << dp2[x] << " " << dp[b] << " " << w*w*sz[b] << " " << w*(dsm2[x] - dsm[b] - w*sz[b] )*2 << endl;
                // cerr << tmp << endl;
                D = dsm2[x] -dsm[b] - w*sz[b];
                // cerr << tmp + D*(dstab+w)*2 + w*w*(n-sz[b])  << endl;
                res -= (tmp + D*(dstab+w)*2 + (dstab+w)*(dstab+w)*(n-sz[b]) ) * 2;
            }
        }else{
            res -= dp2[a] ;
            res += (dp[b] + dstab*dstab*sz[b] + dstab*dsm[b]*2)*2;
        }
        cout << res << "\n";
    }
    return 0;
}