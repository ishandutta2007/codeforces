#include <bits/stdc++.h>

using namespace std;

int MOD;

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
//   Mint& operator /= (const Mint &mt) const { return *this / mt; }
   friend ostream& operator<<(ostream& os, const Mint& mt) { return os << mt.val; }
};

using Mint = ModInt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M >> MOD;
    vector<vector<Mint>> C(N+1, vector<Mint>(N+1));
    for (int i = 0; i <= N; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) C[i][j] = C[i-1][j] + C[i-1][j-1];
    }
    vector<array<Mint, 2>> F(M+1);
    F[0][0] = 1;
    for (int s = 1; s <= M; ++s) {
        for (int l = 0; l < s; ++l) {
            int r = s-1-l;
            F[s][0] += C[l+r][l] * F[l][0] * F[r][0] * (l+r+2);
            F[s][1] += C[l+r][l] * (F[l][1] * F[r][0] * (l+r+2) + F[l][0] * F[r][1] * (l+r+2)  + F[l][0] * F[r][0] * Mint(l*(l+1)/2 + r*(r+1)/2));
        }
    }
    vector<vector<array<Mint, 2>>> G(M+1, vector<array<Mint, 2>>(M+1));
   G[0][0][0] = 1;
    for (int i = 0; i < M; ++i) {
       for (int j = 0; j < M; ++j) {
          for (int k = 1; j+k <= M; ++k) {
             G[i+1][j+k][0] += C[M-j][k] * G[i][j][0] * F[k][0];
            G[i+1][j+k][1] += C[M-j][k] * (G[i][j][0] * F[k][1] + G[i][j][1] * F[k][0]);
          }
       }
    }
    Mint ans = 0;
    for (int z = 1; z <= M; ++z) {
       // candy (N-M-(z-1), z+1)
       int v = N - M - (z-1);
       int u = z+1;
       if (v < 0) continue;
       ans += C[v+u-1][u-1] * G[z][M][1];
    }
    cout << ans << '\n';
    return 0;
}