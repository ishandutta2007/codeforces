#include <bits/stdc++.h>

using namespace std;

template<int MOD>
struct ModInt {
   using Mint = ModInt;
   int val;
   ModInt(int64_t __val = 0) { fix(__val % MOD + MOD); }
   Mint& fix(int __val) { val = __val; if (val >= MOD) val -= MOD; return *this; }
   explicit operator int() { return val; }
   Mint operator + (const Mint &mt) const { return Mint().fix(val + mt.val); }
   Mint operator - (const Mint &mt) const { return Mint().fix(val - mt.val + MOD); }
   Mint operator * (const Mint &mt) const { return Mint().fix(int64_t(val) * mt.val % MOD + MOD); }
   Mint& operator += (const Mint &mt) { return *this = *this + mt; }
   Mint& operator -= (const Mint &mt) { return *this = *this - mt; }
   Mint& operator *= (const Mint &mt) { return *this = *this * mt; }
   Mint pow(int y) const {
      Mint x = *this;
      Mint ans(1);
      for (; y > 0; y >>= 1, x *= x) {
         if (y & 1) ans *= x;
      }
      return ans;
   }
   Mint operator -() const { return Mint().fix(MOD - val); }
   Mint inv() const { return pow(MOD - 2); }
   Mint operator / (const Mint &mt) const { return *this * mt.inv(); }
   Mint& operator /= (const Mint &mt) const { return *this / mt; }
   friend ostream& operator<<(ostream& os, const Mint& mt) { return os << mt.val; }
};

using Mint = ModInt<int(1e9+7)>;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int64_t> A(N); for (auto &a : A) cin >> a;
        array<int, 60> cnts{};
        array<array<int, 60>, 60> cnts2{};
        for (int i = 0; i < N; ++i) {
            vector<int> v0;
            vector<int> v1;
            for (int z = 0; z < 60; ++z) {
                if (A[i] >> z & 1) v1.emplace_back(z);
                else v0.emplace_back(z);
            }
            for (int v : v1) cnts[v] ++;
            for (int v : v1) for (int u : v0) cnts2[v][u] ++;
        }
        Mint ans;
        for (int i = 0; i < 60; ++i) {
            for (int j = 0; j < 60; ++j) {
                ans += Mint(cnts[i]) * cnts2[i][j] * cnts[j] * Mint(2).pow(i+j);
                ans += Mint(cnts[i]) * (cnts[i] - cnts2[i][j]) * N * Mint(2).pow(i+j);
            }
        }
        cout << ans << '\n';
    }
}