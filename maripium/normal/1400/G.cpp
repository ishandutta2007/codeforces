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

using Mint = ModInt<998244353>;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, M; cin >> N >> M;
   vector<int> L(N), R(N);
   for (int i = 0; i < N; ++i) cin >> L[i] >> R[i];
   vector<Mint> fact(N+1);
   vector<Mint> ifact(N+1);
   fact[0] = 1; for (int i = 1; i <= N; ++i) fact[i]=fact[i-1]*i;
   ifact[N] = fact[N].inv(); for (int i = N; i > 0; --i) ifact[i-1] = ifact[i] *i;
   auto binom = [&](int x, int y) {
      if (x < y || y < 0) return Mint();
      return fact[x] * ifact[y] * ifact[x-y];
   };
   vector<int> deg(N+2);
   for (int i = 0; i < N; ++i) {
      deg[L[i]]++;
      deg[R[i]+1]--;
   }
   for (int i = 1; i <= N; ++i) deg[i] += deg[i-1];
   vector<vector<Mint>> pref(2*M+1, vector<Mint>(N+1));
   for (int sz = 0; sz <= 2*M; ++sz) {
      for (int i = 1; i <= N; ++i) pref[sz][i] = pref[sz][i-1] + binom(deg[i] - sz, i - sz);
   }
   vector<int> A(M), B(M);
   for (int i = 0; i < M; ++i) {
      cin >> A[i] >> B[i];
      --A[i], --B[i];
   }
   Mint ans = 0;
   for (int mask = 0; mask < (1<<M); ++mask) {
      vector<int> vs;
      // cerr << "MASK " << mask << '\n';
      for (int z = 0; z < M; ++z) if (mask& (1<<z)) {
         vs.emplace_back(A[z]);
         vs.emplace_back(B[z]);
      }
      sort(vs.begin(), vs.end());
      vs.resize(unique(vs.begin(), vs.end()) - vs.begin());
      int l = max<int>(1, vs.size());
      int r = N;
      for (int z : vs) {
         l = max(l, L[z]);
         r = min(r, R[z]);
      }
      // cerr << l << ' ' << r << '\n';
      if (l > r) continue;
      Mint cur = (pref[vs.size()][r]-pref[vs.size()][l-1]);
      if (__builtin_popcount(mask) & 1) ans -= cur;
      else ans += cur;
   }
   cout << ans << '\n';
   return 0;
}