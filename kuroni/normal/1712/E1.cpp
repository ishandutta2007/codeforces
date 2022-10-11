#include <bits/stdc++.h>

#include <cassert>
#include <vector>


#include <cassert>
#include <numeric>
#include <type_traits>

namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class T> struct fenwick_tree {
    using U = internal::to_unsigned_t<T>;

  public:
    fenwick_tree() : _n(0) {}
    explicit fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

}  // namespace atcoder

using namespace std;
using namespace atcoder;

const int MX = 2E5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    vector<long long> ans(t);
    vector<vector<pair<int, int>>> vec(MX);
    vector<vector<int>> rem(MX);
    vector<int> div(MX);
    for (int i = 0; i < t; i++) {
        int l, r; cin >> l >> r;
        int sz = r - l + 1;
        ans[i] = 1LL * sz * (sz - 1) * (sz - 2) / 6;
        vec[l].push_back({r, i});
    }
    fenwick_tree<long long> fw(MX);
    for (int k = 3; k < MX; k++) {
        if (k % 6 == 0) {
            // add k / 2 -> k
            rem[k / 2].push_back(k);
            fw.add(k, 1);
        }
        if (k % 15 == 0) {
            // add 2k / 5 -> k
            rem[2 * k / 5].push_back(k);
            fw.add(k, 1);
        }
    }
    for (int i = 1; i < MX; i++) {
        for (int j = 2 * i; j < MX; j += i) {
            div[j]++;
        }
        fw.add(i, 1LL * div[i] * (div[i] - 1) / 2);
    }
    for (int i = 1; i < MX; i++) {
        for (auto [r, ind] : vec[i]) {
            ans[ind] -= fw.sum(i, r + 1);
        }
        for (int v : rem[i]) {
            fw.add(v, -1);
        }
        for (int j = 2 * i; j < MX; j += i) {
            long long delta = 1LL * div[j] * (div[j] - 1) / 2;
            div[j]--;
            delta -= 1LL * div[j] * (div[j] - 1) / 2;
            fw.add(j, -delta);
        }
    }
    for (int i = 0; i < t; i++) {
        cout << ans[i] << '\n';
    }
}