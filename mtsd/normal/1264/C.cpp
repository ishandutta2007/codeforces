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
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
  constexpr bool operator==(const modint rhs) noexcept{
  return (*this).value()==rhs.value();
  }
  inline constexpr bool operator!=(const modint rhs) noexcept{
  return !(*this==rhs);
  }
};
#define mint modint<998244353>
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    set<int>st;
    st.insert(1);
    st.insert(n+1);
    vector<mint> p(n+2),g(n+2);
    p[0] = 1;
    p[n+1] = 0;
    g[n+1] = 1;
    rep(i,n){
        int k;
        cin >> k;
        p[i+1] = k;
        p[i+1]/=100;
    }
    for(int i=n-1;i>=1;i--){
        p[i] *= p[i+1];
        g[i+1] = p[i+1];
        g[i] = p[i];
    }
    mint s = 1;
    for(int i=1;i<=n;i++){
        p[i] = s/p[i];
    }
    for(int i=n-1;i>=1;i--){
        p[i] += p[i+1];
    }
    // for(int i=1;i<=n;i++){
    //     cerr << p[i].value() << endl;
    // }
    mint res = p[1];
    //cerr << res.value() << endl;
    rep(zz,q){
        int k;
        cin >> k;
        if(st.count(k)==1){
            st.erase(k);
            int a,b;
            auto x = st.lower_bound(k);
            x--;
            a = *x;
            auto y = st.lower_bound(k);
            b = *y;
            mint X = (p[a]-p[b])*g[b];
            res += X;
            mint Y = (p[a]-p[k])*g[k];
            mint Z = (p[k]-p[b])*g[b];
            res -= Y;
            res -= Z;
        }else{
            int a,b;
            auto x = st.lower_bound(k);
            x--;
            a = *x;
            auto y = st.lower_bound(k);
            b = *y;
            //cerr << a << " " << b << endl;
            st.insert(k);
            mint X = (p[a]-p[b])*g[b];
            res -= X;
            mint Y = (p[a]-p[k])*g[k];
            mint Z = (p[k]-p[b])*g[b];
            res += Y;
            res += Z;
        }
        cout << res.value() << "\n";
    }
    return 0;
}