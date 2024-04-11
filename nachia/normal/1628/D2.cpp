
#include <vector>
#include <utility>

namespace nachia{

template<unsigned int MOD>
struct StaticModint{
private:
    using u64 = unsigned long long;
    unsigned int x;
public:

    using my_type = StaticModint;

    StaticModint() : x(0){}
    StaticModint(unsigned int v) : x(v){}
    unsigned int operator*() const { return x; }
    my_type& operator+=(const my_type& r){ auto t = x + r.x; if(t >= MOD) t -= MOD; x = t; return *this; }
    my_type operator+(const my_type& r) const { my_type res = *this; return res += r; }
    my_type& operator-=(const my_type& r){ auto t = x + MOD - r.x; if(t >= MOD) t -= MOD; x = t; return *this; }
    my_type operator-(const my_type& r) const { my_type res = *this; return res -= r; }
    my_type operator-() const { my_type res = *this; res.x = ((res.x == 0) ? 0 : (MOD - res.x)); return res; }
    my_type& operator*=(const my_type& r){ x = (u64)x * r.x % MOD; return *this; }
    my_type operator*(const my_type& r) const { my_type res = *this; return res *= r; }
    my_type pow(unsigned long long i) const {
        my_type a = *this, res = 1;
        while(i){ if(i & 1) res *= a; a *= a; i >>= 1; }
        return res;
    }
    my_type inv() const { return pow(MOD-2); }
    unsigned int val() const { return x; }
    static unsigned int get_mod() { return MOD; }
    my_type& operator/=(const my_type& r){ return operator*=(r.inv()); }
    my_type operator/(const my_type& r) const { return operator*(r.inv()); }
};

}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using i32 = int;
using u32 = unsigned int;
#define rep(i,n) for(int i=0; i<(n); i++)

using m32 = nachia::StaticModint<1000000007>;


vector<m32> F, iF, ipow2;
void init(){
    int Z = 2000000;
    F.assign(Z+1, m32(1));
    for(int i=1; i<=Z; i++) F[i] = F[i-1] * i;
    iF.assign(Z+1, m32(1));
    iF[Z] = F[Z].inv();
    for(int i=Z; i>=1; i--) iF[i-1] = iF[i] * i;
    ipow2.assign(Z+1, m32(1));
    m32 inv2 = m32(2).inv();
    for(int i=1; i<=Z; i++) ipow2[i] = ipow2[i-1] * inv2;
}
m32 Comb(int n, int r){ return F[n] * iF[r] * iF[n-r]; }


m32 testcase(){
    int m,n,k; cin >> n >> m >> k;
    if(n == m) return m32(n) * m32(k);
    m32 ans = 0;
    for(int sm=1; sm<=m; sm++) ans += m32(sm) * Comb(n-sm-1, m-sm) * ipow2[n-sm];
    return ans * k;
}


int main() {
    int T; cin >> T;
    init();
    rep(i,T) cout << *testcase() << "\n";
    return 0;
}



struct ios_do_not_sync{
    ios_do_not_sync(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
} ios_do_not_sync_instance;