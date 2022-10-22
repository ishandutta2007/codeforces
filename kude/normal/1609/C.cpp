#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

std::pair<std::vector<int>,std::vector<int>> primes_lpf(const int n) {
    std::pair<std::vector<int>,std::vector<int>> rv;
    std::vector<int>& primes = rv.first;
    std::vector<int>& lpf = rv.second;
    primes.reserve(n / 10);
    lpf.resize(n + 1);
    for(int i = 2; i <= n; i += 2) lpf[i] = 2;
    for(int i = 3; i <= n; i += 6) lpf[i] = 3;
    if (2 <= n) primes.push_back(2);
    if (3 <= n) primes.push_back(3);
    // 5 * x <= n, x <= floor(n / 5)
    const int n5 = n / 5;
    int x = 5;
    bool one_mod6 = false;
    // x_1 <= n5, x_2 = x_1 + 2 <= n5 + 2 <= n
    for(; x <= n5; one_mod6 = !one_mod6, x += (one_mod6 ? 2 : 4)) {
        if (lpf[x] == 0) {
            lpf[x] = x;
            primes.push_back(x);
        }
        int px = lpf[x];
        for(int i = 2;; ++i) {
            int q = primes[i];
            int y = q * x;
            if (y > n) break;
            lpf[y] = q;
            if (q == px) break;
        }
    }
    for(; x <= n; one_mod6 = !one_mod6, x += (one_mod6 ? 2 : 4)) {
        if (lpf[x] == 0) {
            lpf[x] = x;
            primes.push_back(x);
        }
    }
    return rv;
}

auto [primes, lpf] = primes_lpf(1000000);
bool is_prime(int x) {
    return lpf[x] == x;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, c;
    cin >> n >> c;
    VI a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    rep(i, n) if (is_prime(a[i])) {
        int cl = 0, cr = 0;
        for(int j = i - c; j >= 0; j -= c) {
            if (a[j] != 1) break;
            cl++;
        }
        for(int j = i + c; j < n; j += c) {
            if (a[j] != 1) break;
            cr++;
        }
        ans += ll(cl + 1) * (cr + 1) - 1;
    }
    cout << ans << '\n';
  }
}