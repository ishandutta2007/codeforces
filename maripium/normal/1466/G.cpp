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
   bool operator == (const Mint &m) const { return val == m.val; }
};

using Mint = ModInt<int(1e9+7)>;
using Mint2 = ModInt<int(1e9+9)>;

using hsh = pair<Mint, Mint2>;

hsh operator * (const hsh &l, const hsh &r) {
    return {l.first * r.first, l.second * r.second};
}

hsh operator + (const hsh &l, const hsh &r) {
    return {l.first + r.first, l.second + r.second};
}

hsh operator - (const hsh &l, const hsh &r) {
    return {l.first - r.first, l.second - r.second};
}

const hsh BASE = {Mint(239), Mint2(1007)};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, Q; cin >> N >> Q;
    string S0, T; cin >> S0 >> T;
    int N0 = int(S0.size());
    vector<Mint> p2({1});
    while (p2.size() <= N) p2.emplace_back(p2.back() * 2);
    string T2;
    for (int i = 0; i < min(N, 20); ++i) T2 = T2 + T[i] + T2;
    int N2 = T2.size();
    vector<hsh> bpw{{Mint(1), Mint2(1)}};
    while (bpw.size() < 1.1e6) bpw.emplace_back(bpw.back() * BASE);
    vector<hsh> H(N2+1);
    H[0] = hsh();
    for (int i = 0; i < N2; ++i) H[i+1] = H[i] * BASE + hsh(Mint(T2[i] - 'a' + 5), Mint2(T2[i] - 'a' + 7));
    vector<array<Mint, 26>> pref(N+1);
    for (int i = 0; i < N; ++i) {
        pref[i+1] = pref[i];
        pref[i+1][T[i] - 'a'] += p2[i].inv();
    }
    auto cnt = [&](int K, string P) {
        if (P.empty()) return p2[K];
        int NP = P.size();
        vector<hsh> HP(NP+1);
        for (int i = 0; i < NP; ++i) HP[i+1] = HP[i] * BASE + hsh(Mint(P[i] - 'a' + 5), Mint2(P[i] - 'a' + 7));
        Mint ans = 0;
        for (int i = 0; i < NP; ++i) {
            int v = max(i, NP-1-i);
            int l = 0;
            while ((1 << l) <= v) l ++;
            if (l > K) continue;
            assert(v <= T2.size());
            hsh Hpref = H[NP - 1 - i];
            hsh Psuff = HP[NP] - bpw[NP - i - 1] * HP[i+1];
            hsh Hsuff = H[N2] - bpw[i] * H[N2 - i];
            hsh Ppref = HP[i];
            if (Hpref == Psuff && Hsuff == Ppref) {
                // cerr << l << ' ' << '\n';
                ans += p2[K-1] * (pref[K][P[i] - 'a'] - pref[l][P[i] - 'a']);
            }
        }
        return ans;
    };
    // cnt(2, "aa");
    while (Q--) {
        int K; string W; cin >> K >> W;
        int NW = int(W.size());
        Mint ans = 0;
        for (int s = 0; s <= N0; ++s) {
        [&]() {
            int is = s;
            int iw = 0;
            string P{};
            while (iw < NW) {
                while (is < N0 && iw < NW) {
                    if (S0[is] != W[iw]) return;
                    is ++;
                    iw ++;
                }
                if (iw == NW) break;
                is = 0;
                P += W[iw++];
            }
            ans += cnt(K, P);
        }();
        }
        cout << ans << '\n';
    }
}