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

using Mint = ModInt<1000000007>;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N; cin >> N;
   vector<vector<Mint>> p(6, vector<Mint>(6));
   for (int i = 0; i < 6; ++i) {
      if (i < N) {
         for (int j = 0; j < N; ++j) {
            int _p; cin >> _p;
            p[i][j] = Mint(_p) / Mint(100);
         }
      } else p[i][i] = 1;
   }
   vector<Mint> lval(1 << 20);
   vector<Mint> rval(1 << 20);
   for (int mask = 0; mask < (1 << 18); ++mask) {
      Mint prob = 1;
      for (int z = 0; z < 18; ++z) {
         if (mask & (1 << z)) prob *= p[z/6][z%6];
         else prob *= (Mint(1) - p[z/6][z%6]);
      }
      int idx = 0;
      int state = 0;
      for (int a = 0; a < 6; ++a) {
         for (int b=a+1; b < 6; ++b) {
            for (int c=b+1; c < 6; ++c) {
               bool good = false;
               int arr[3] = {a, b, c};
               do {
                  bool ok = true;
                  for (int z : {arr[0], 6 + arr[1], 12+arr[2]}) {
                     if (!(mask & (1 << z))) ok = false;
                  }
                  if (ok) good = true;
               } while (next_permutation(arr, arr + 3));
               if (good) state |= (1 << idx);
               idx++;
            }
         }
      }
      lval[state] += prob;
   }
   for (int mask = 0; mask < (1 << 18); ++mask) {
      Mint prob = 1;
      for (int z = 0; z < 18; ++z) if (mask & (1 << z)) {
         prob *= p[z/6+3][z%6];
      } else prob *= (Mint(1) - p[z/6 + 3][z%6]);
      int idx = 0;
      int state = 0;
      for (int a = 0; a < 6; ++a) {
         for (int b=a+1; b < 6; ++b) {
            for (int c=b+1; c < 6; ++c) {
               bool good = false;
               int arr[3];
               int sz = 0;
               for (int i = 0; i < 6; ++i) if (i != a && i != b && i != c) arr[sz++] = i;
               do {
                  bool ok = true;
                  for (int z : {arr[0], 6 + arr[1], 12+arr[2]}) {
                     if (!(mask & (1 << z))) ok = false;
                  }
                  if (ok) good = true;
               } while (next_permutation(arr, arr + 3));
               if (good) state |= (1 << idx);
               idx++;
            }
         }
      }
      rval[state] += prob;
   }
   for (int i = 0; i < 20; ++i) {
      for (int j = 0; j < (1<<20); ++j) if (!(j & (1 << i))) rval[j ^ (1 << i)] += rval[j];
   }
   Mint ans = 1;
   for (int i = 0; i < (1 << 20); ++i) ans -= lval[i] * rval[((1 << 20)-1) ^ i];
   cout << ans << '\n';
   return 0;
}