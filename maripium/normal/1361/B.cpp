#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template<int MOD>
struct ModInt {
   using Mint = ModInt;
   int val;
   ModInt(ll __val = 0) { fix(__val % MOD + MOD); }
   Mint& fix(int __val) { val = __val; if (val >= MOD) val -= MOD; return *this; }
   explicit operator int() { return val; }
   Mint operator + (const Mint &mt) const { return Mint().fix(val + mt.val); }
   Mint operator - (const Mint &mt) const { return Mint().fix(val - mt.val + MOD); }
   Mint operator * (const Mint &mt) const { return Mint().fix(ll(val) * mt.val % MOD + MOD); }
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
   int T;
   cin >> T;
   while (T--) {
      int N, P;
      cin >> N >> P;
      vector<int> A(N);
      for (int i = 0; i < N; ++i) {
         cin >> A[i];
      }
      if (P == 1) {
         cout << (N & 1) << "\n";
         continue;
      }
      sort(A.begin(), A.end());
      map<int, int> mp;
      for (int v : A) ++mp[v];
      const ll INF = 2e12;
      vector<pair<int, int>> cnts(mp.begin(), mp.end());
      auto pw = [&](ll &cur, int z) {
         if (cur == 0) return;
         while (z--) {
            cur *= P;
            if (cur >= INF) {
               cur = INF;
               return;
            }
         }
      };
      int last = 1e9;
      ll cur = 0;
      Mint ans = 0;
      for (int i = cnts.size() - 1; i >= 0; --i) {
         pw(cur, last - cnts[i].first);
         last = cnts[i].first;
         ll take = cnts[i].second;
         // -take -> take
         ll f = cur;
         if ((f + take) % 2) f--;
         f = min(f, ll(take));
         f = max(f, ll(-take));
         cur -= f;
         ans -= Mint(P).pow(last) * Mint(f);
      }
      cout << ans << "\n";
   }
}