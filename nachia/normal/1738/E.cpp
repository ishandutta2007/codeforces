#line 1 "Main.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

#line 2 "nachia\\math\\ext-gcd.hpp"

#line 5 "nachia\\math\\ext-gcd.hpp"
#include <cassert>
namespace nachia{

// ax + by = gcd(a,b)
std::pair<long long, long long> ExtGcd(long long a, long long b){
    long long x = 1, y = 0;
    while(b){
        long long u = a / b;
        std::swap(a-=b*u, b);
        std::swap(x-=y*u, y);
    }
    return std::make_pair(x, y);
}

} // namespace nachia
#line 5 "nachia\\math\\static-modint.hpp"

namespace nachia{

template<unsigned int MOD>
struct StaticModint{
private:
    using u64 = unsigned long long;
    unsigned int x;
public:

    using my_type = StaticModint;
    template< class Elem >
    static Elem safe_mod(Elem x){
        if(x < 0){
            if(0 <= x+MOD) return x + MOD;
            return MOD - ((-(x+MOD)-1) % MOD + 1);
        }
        return x % MOD;
    }

    StaticModint() : x(0){}
    StaticModint(const my_type& a) : x(a.x){}
    StaticModint& operator=(const my_type&) = default;
    template< class Elem >
    StaticModint(Elem v) : x(safe_mod(v)){}
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
        while(i){ if(i & 1){ res *= a; } a *= a; i >>= 1; }
        return res;
    }
    my_type inv() const { return my_type(ExtGcd(x, MOD).first); }
    unsigned int val() const { return x; }
    static constexpr unsigned int get_mod() { return MOD; }
    static my_type raw(unsigned int val){ auto res = my_type(); res.x = val; return res; }
    my_type& operator/=(const my_type& r){ return operator*=(r.inv()); }
    my_type operator/(const my_type& r) const { return operator*(r.inv()); }
};

}
#line 2 "nachia\\math\\combination.hpp"

#line 4 "nachia\\math\\combination.hpp"


namespace nachia{

template<class Modint>
class Comb{
private:
    ::std::vector<Modint> F;
    ::std::vector<Modint> iF;
public:
    Comb(int n){
        F.assign(n+1, Modint(1));
        for(int i=1; i<=n; i++) F[i] = F[i-1] * Modint(i);
        iF.assign(n+1, Modint(1));
        iF[n] = F[n].inv();
        for(int i=n; i>=1; i--) iF[i-1] = iF[i] * Modint(i);
    }
    Modint factorial(int n) const { return F[n]; }
    Modint inv_factorial(int n) const { return iF[n]; }
    Modint inv_of(int n) const { return iF[n] * F[n-1]; }
    Modint comb(int n, int r) const {
        if(n < 0 || n < r || r < 0) return Modint(0);
        return F[n] * iF[r] * iF[n-r];
    }
    Modint inv_comb(int n, int r) const {
        if(n < 0 || n < r || r < 0) return Modint(0);
        return iF[n] * F[r] * F[n-r];
    }
    Modint perm(int n, int r) const {
        if(n < 0 || n < r || r < 0) return Modint(0);
        return F[n] * iF[n-r];
    }
    Modint inv_perm(int n, int r) const {
        if(n < 0 || n < r || r < 0) return Modint(0);
        return iF[n] * F[n-r];
    }
    Modint operator()(int n, int r) const { return comb(n,r); }
};

} // namespace nachia
#line 10 "Main.cpp"

using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

const i64 INF = 1001001001001001001;
using Modint = nachia::StaticModint<998244353>;

void testcase(){
    int N; cin >> N;
    nachia::Comb<Modint> comb(N*2);
    vector<i64> A(N); rep(i,N) cin >> A[i];
    A.front()++;
    A.back()++;
    vector<i64> S(N+1, 0);
    rep(i,N) S[i+1] = S[i] + A[i];
    vector<pair<i64, i64>> Q;

    Modint ans = 1;
    for(int i=1; S[i]*2<S[N]; i++){
        if(A[i] == 0) continue;
        int l = upper_bound(S.begin()+1, S.end()-1, S[i]) - lower_bound(S.begin()+1, S.end()-1, S[i]);
        int r = upper_bound(S.begin()+1, S.end()-1, S[N]-S[i]) - lower_bound(S.begin()+1, S.end()-1, S[N]-S[i]);
        Modint q = 0;
        for(int c=0; c<=l && c<=r; c++){
            q += comb(l,c) * comb(r,c);
        }
        ans *= q;
    }
    if(S[N] % 2 == 0){
        int C = upper_bound(S.begin()+1, S.end()-1, S[N]/2) - lower_bound(S.begin()+1, S.end()-1, S[N]/2);
        Modint q = 0;
        for(int c=0; c<=C; c++){
            q += comb(C,c);
        }
        ans *= q;
    }
    cout << ans.val() << '\n';
}

int main(){
    int T; cin >> T;
    rep(t,T) testcase();
    return 0;
}


struct ios_do_not_sync{
    ios_do_not_sync(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
} ios_do_not_sync_instance;