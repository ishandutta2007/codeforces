#include <iostream>
#include <utility>
#include <bitset>
#include <map>

using namespace std;

constexpr int mod = 998244353, K = 5, N = 1 << K;

uint32_t pad[K + 1][N], hsh_offset[K + 1];
int k;
uint8_t dpw_[0100213], *dpw[K] = {dpw_ + 0100212, dpw_ + 0100210, dpw_ + 0100200, dpw_ + 0100000, dpw_};
int dph_[0100213], *dph[K] = {dph_ + 0100212, dph_ + 0100210, dph_ + 0100200, dph_ + 0100000, dph_};

int winner(int lbsz, int mask) {
  int msb = mask & 1, offset = msb << lbsz - 1, low = (1 << (1 << lbsz - 1) - 1) - 1;
  return lbsz? dpw[lbsz - 1][mask >> offset + !offset & low] + offset: 0;
}

int smod(uint32_t a) {
  while (a >= mod) {
    a -= mod;
  }
  return a;
}

int smod1(uint32_t a) {
  return a >= mod? a - mod: a;
}

int hsh(int lbsz, int mask) {
  int low = (1 << (1 << lbsz - 1) - 1) - 1;
  return lbsz? smod(pad[k - lbsz][winner(lbsz, mask)] + dph[lbsz - 1][mask >> 1 & low] + dph[lbsz - 1][mask >> (1 << lbsz - 1) & low] + hsh_offset[lbsz]): pad[k][0];
}

void precalc(int a) {
  pad[0][0] = a;
  int64_t pa_ = a;
  for (int i = 1; i <= k; ++i) {
    pad[i][0] = pa_ * a % mod;
    pad[i - 1][0] = (pad[i - 1][0] + mod - pad[i][0]) % mod;
    pa_ = pa_ * pa_ % mod;
  }
  for (int i = 0; i <= k; ++i)
  for (int w = 1; w < (1 << k); ++w) {
    pad[i][w] = (pad[i][0] + pad[i][w - 1]) % mod;
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < i; ++j) {
      hsh_offset[i] = (hsh_offset[i] + (int64_t(pad[k - j][0]) << 2 * i - j - 2)) % mod;
    }
  }
  for (int lbsz = 0; lbsz < k; ++lbsz) {
    for (int mask = 0; mask < 1 << (1 << lbsz) - 1; ++mask) {
      dpw[lbsz][mask] = winner(lbsz, mask);
      dph[lbsz][mask] = hsh(lbsz, mask);
    }
  }
}

string m2p(int lbsz, int mask) {
  int low = (1 << (1 << lbsz - 1) - 1) - 1;
  auto ans = lbsz? m2p(lbsz - 1, mask >> 1 & low) + m2p(lbsz - 1, mask >> (1 << lbsz - 1)): "a";
  ans[winner(lbsz, mask)] = (1 << k - lbsz >> 1) + 1;
  return ans;
}

bitset<1 << 27> used;

map<int, int> all_outcomes() {
  int a;
  cin >> k >> a;
  precalc(a);
  map<int, int> h2ml, h2mr, h2m;
  for (int mask = 0; mask < 1 << (1 << k - 1) - 1; ++mask) {
    h2ml[smod1(dph[k - 1][mask] + hsh_offset[k])] = mask;
    h2mr[smod1(dph[k - 1][mask] + pad[0][dpw[k - 1][mask]])] = mask << 1;
    h2mr[smod1(dph[k - 1][mask] + pad[0][dpw[k - 1][mask] + (1 << k - 1)])] = mask << (1 << k - 1) | 1;
  }
  for (auto& l: h2ml) for (auto& r: h2mr) {
    int ch = smod1(l.first + r.first);
    if (!used[ch & 0777777777]) {
      used[ch & 0777777777] = 1;
      h2m.emplace(ch, r.second | l.second << (r.second & 1? 1: 1 << k - 1));
    }
  }
  return h2m;
}

int main() {
  auto outcomes = all_outcomes();
  int h;
  cin >> h;
  if (outcomes.count(h)) {
    auto places = m2p(k, outcomes[h]);
    for (int p: places) {
      cout << p << ' ';
    }
  } else {
    cout << -1;
  }
}