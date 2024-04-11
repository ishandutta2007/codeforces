#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    ll k;
    cin >> n >> k;

    vector<ll> numbers;
    for (int mask = 2; mask < (1 << 19); mask++) {
        numbers.push_back(y_combinator([&](auto get, int mask) -> ll {
            return mask == 1 ? 0 : get(mask >> 1) * 10 + (mask % 2 == 0 ? 4 : 7);
        })(mask));
    }

    vector<ll> l(n), r(n);
    ll min_len = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        min_len = min(min_len, r[i] - l[i]);
    }

    sort(all(l));
    sort(all(r));

    using i128 = __int128_t;
    vector<i128> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + r[i];
    }
    vector<i128> suf(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + l[i];
    }
    
    vector<i128> dp_left(len(numbers));
    for (int i = 0; i < len(numbers); i++) {
        int pos = lower_bound(all(l), numbers[i]) - l.begin();
        dp_left[i] = -i128(numbers[i]) * (n - pos) + suf[pos];
    }
    vector<i128> dp_right(len(numbers));
    for (int i = 0; i < len(numbers); i++) {
        int pos = lower_bound(all(r), numbers[i]) - r.begin();
        dp_right[i] = i128(numbers[i]) * pos - pref[pos];
    }

    int ans = 0;
    for (int i = 0, j = 0; i < len(numbers); i++) {
        while (j <= i && (numbers[i] - numbers[j] > min_len || dp_right[i] + dp_left[j] > k)) {
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans << '\n';
}