#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <cstring>

#include <cstdio>
struct UnsafeInput {
  static constexpr int bufsz = 1 << 15;

  UnsafeInput() {
    read();
  }

  void read() {
    fread(buf + 1, 1, sizeof buf - 1, stdin);
    bufptr = buf;
  }

  template <typename T>
  void operator()(T* b, size_t n) {
    for (size_t i = 0; i < n; ++i) {
      b[i] = {};
    }
    (*this)(b, b + n);
  }

  template <typename ...Ts>
  auto operator()(Ts&... xs) -> std::enable_if_t<(!std::is_pointer_v<std::decay_t<Ts>> && ...)> {
    ((*this)(&(xs = {}), &xs + 1), ...);
  }

  char buf[bufsz], *bufptr = buf;
private:

  template <typename T>
  void operator()(T* b, T* e) {
    bool sign = 0;
    while (b != e) {
      if (++bufptr == buf + bufsz) {
        read();
      } else if (*bufptr == '-') {
        sign = 1;
      } else if (*bufptr < '0') {
        *b++ *= sign? -1: 1, sign = 0;
      } else {
        *b = *b * 10 + *bufptr - '0';
      }
    }
  }
} reader;

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }

constexpr int N = 1e6, L = 64;

int64_t a[N];

int64_t solve(int64_t* first, int64_t* mid, int64_t* last) {
  static int cnt[L];
  auto cur = mid, r = cur - 1, l = r, r2 = r, l2 = r, le = r;
  auto mi = *cur, ma = mi, mil = 1ll << 62, mir = mil;
  bool mim = 0, mam = 0;
  int64_t ans = 0, ans2 = 0;
  while (cur != last) {
    if (minb(mi, *cur)) {
      mim = 0;
    }
    if (maxb(ma, *cur)) {
      mam = 0;
    }
    while (l >= first && *l < ma) {
      mini(mil, *l);
      ++cnt[__builtin_popcountll(mil)];
      --l;
    }
    while (le >= first && *le >= mi && *le <= ma) {
      if (auto nmim = *le == mi || mim, nmam = *le == ma || mam; nmim && nmam) {
        break;
      } else {
        mim = nmim;
        mam = nmam;
      }
      --le;
    }
    l2 = min(l2, le);
    while (l2 >= first && *l2 >= mi && *l2 <= ma) {
      --l2;
    }
    if (__builtin_popcountll(mi) == __builtin_popcountll(ma)) {
      ans2 += (r2 - le) + (r2 - l2);
    }
    while (r > l && *r >= mi) {
      mini(mir, *r);
      --cnt[__builtin_popcountll(mir)];
      --r;
    }
    ans += cnt[__builtin_popcountll(ma)];
    ++cur;
  }
  if (r - l < L / 4) {
    while (r > l) {
      mini(mir, *r);
      --cnt[__builtin_popcountll(mir)];
      --r;
    }
  } else {
    memset(cnt, 0, sizeof cnt);
  }
  return ans * 2 + ans2;
}

auto midl(auto l, auto r) {
  int step = 1 << 31 - __builtin_clz(r - l);
  return min(l + step, r - step / 2);
}

int64_t solve(int64_t* first, int64_t* last, int64_t ans = 0) {
  while (last >= first + 2) {
    auto mid = midl(first, last);
    auto ans2 = solve(first, mid, last);
    reverse(first, last);
    mid = last - mid + first;
    ans2 += solve(first, mid, last);
    ans = solve(mid, last, ans + ans2 / 2);
    last = mid;
  }
  return ans + (last - first) + (last != first + 1 && __builtin_popcountll(*first) == __builtin_popcountll(*next(first)));
}

int main() {
  int n;
  reader(n);
  reader(a, n);
  cout << solve(a, a + n);
}