#define NDEBUG
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <vector>

// <lib>
#define repeat(n) for (int _repc = (n); _repc > 0; --_repc)
#define ALL(x) (x).begin(), (x).end()


template <typename T> int lsb(const T x) {
  assert(x > 0);
  return 8 * sizeof(T) <= 32 ? __builtin_ctz(x) : __builtin_ctzll(x);
}


template<typename Int = uint32_t, typename SqrtInt = uint16_t>
class TableFactorizer {
public:
  explicit TableFactorizer(Int maxn)
      : maxn_(maxn), table_(new SqrtInt[maxn/2 + 1]) {
    assert(std::sqrt(maxn) <= std::numeric_limits<SqrtInt>::max());
    std::memset(table_.get(), 0, (maxn/2 + 1) * sizeof(SqrtInt));

    struct PrimeState {
      SqrtInt p;
      Int i;
    };
    std::vector<PrimeState> ps_all;
    for (SqrtInt p = 3; Int(p) * p <= maxn; p += 2) {
      bool prime = true;
      for (const auto& qs : ps_all) {
        if (p % qs.p == 0) {
          prime = false;
          break;
        }
      }
      if (prime) {
        ps_all.push_back(PrimeState{p, Int(p) * p});
      }
    }
    auto ps_last_it = ps_all.begin();
    const Int SEGMENT_SIZE = 2 * 32768 / sizeof(SqrtInt);
    for (Int lo = 3; lo <= maxn; lo += SEGMENT_SIZE) {
      const Int hi = std::min(maxn_ + 1, lo + SEGMENT_SIZE);
      while (ps_last_it < ps_all.end() && ps_last_it->i < hi) {
        ++ps_last_it;
      }
      for (auto ps = ps_all.begin(); ps != ps_last_it; ++ps) {
        Int i = ps->i;
        for (; i < hi; i += 2 * ps->p) {
          if (table_[i / 2] == 0) {
            table_[i / 2] = ps->p;
          }
        }
        ps->i = i;
      }
    }
  }

  template<typename Cb>
  void operator()(Int n, Cb&& cb) const {
    assert(n <= maxn_);
    {
      int q = lsb(n);
      if (q > 0) {
        cb(2, q);
      }
      n >>= q;
    }
    while (table_[n/2] > 0) {
      auto p = table_[n/2];
      int q = 0;
      do {
        n /= p;
        ++q;
      } while (table_[n/2] == p);
      if (n == p) {
        n = 1;
        ++q;
      }
      cb(p, q);
    }
    if (n > 1) {
      cb(n, 1);
    }
  }

private:
  const Int maxn_;
  std::unique_ptr<SqrtInt[]> table_;
};
// </lib>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::map<int, int> f;
  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  for (int i=0; i<n; ++i) {
    std::cin >> arr[i];
  }

  TableFactorizer<> fac(*std::max_element(ALL(arr)));
  for (int x : arr) {
    auto cb = [&](const int p, int q) {
      int pp = 1;
      repeat (q) {
        pp *= p;
        ++f[pp];
      }
    };
    fac(x, cb);
  }
  int ans = n+1;
  for (const auto& e : f) {
    int count = e.second;
    if (count < n) {
      if (ans == n+1 || count > ans) {
        ans = count;
      }
    }
  }
  std::cout << n-ans << '\n';
}