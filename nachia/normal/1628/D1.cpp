
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


m32 dp[2001][2001];


void init(){
    rep(i,2001) rep(j,2001) dp[i][j] = 0;
    for(int j=1; j<=2000; j++) dp[0][j] = j;
    m32 inv2 = m32(2).inv();
    for(int i=1; i<=2000; i++) for(int j=1; j<=2000; j++) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) * inv2;
}


m32 testcase(){
    int m,n,k; cin >> n >> m >> k;
    return dp[n-m][m] * k;
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