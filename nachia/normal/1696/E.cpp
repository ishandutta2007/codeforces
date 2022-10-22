
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>


#include <utility>

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


using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(int)(n); i++)


const i64 INF = 1001001001001001001;

using modint = nachia::StaticModint<1'000'000'007>;

int main(){
	int N; cin >> N; N++;
	vector<int> A(N+1);
	rep(i,N) cin >> A[i];

	auto comb = nachia::Comb<modint>(500000);

	modint ans = 0;

	rep(x,N) ans += comb(x+1 + A[x]-1, A[x]-1);

	cout << *ans << '\n';
    return 0;
}


struct ios_do_not_sync{
    ios_do_not_sync(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
} ios_do_not_sync_instance;