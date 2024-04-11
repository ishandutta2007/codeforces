#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto &x : b) cin >> x;
    sort(all(b));

    constexpr int INF = 1e9 + 228;
    a.insert(a.begin(), -2);
    a.push_back(INF);
    n += 2;

    vector<int> dp{-INF}, dp_pref(n);
    dp.reserve(n);
    for (int i = 0; i < n; i++) {
        auto add_value = [&](int x, int pos) {
            if (pos == len(dp)) {
                dp.push_back(x);
            } else {
                dp[pos] = x;
            }
        };

        if (a[i] == -1) {
            int pos = len(dp);
            for (int i = m - 1; i >= 0; i--) {
                while (pos > 0 && dp[pos - 1] >= b[i]) pos--;
                add_value(b[i], pos);
            }
        } else {
            int pos = lower_bound(all(dp), a[i]) - dp.begin();
            add_value(a[i], pos);
            dp_pref[i] = pos;
        }
    }

    vector<int> empty_pref(n);
    for (int i = 1; i < n; i++) {
        empty_pref[i] = empty_pref[i - 1] + (a[i] == -1);
    }

    multiset<int> st(all(b));
    b.resize(unique(all(b)) - b.begin());
    auto ans = a;

    for (int i = n - 2, last = n - 1; i >= 0; i--) {
        if (a[i] == -1 || a[i] >= a[last]) continue;
        int cur = dp_pref[i];
        cur += min<int>(empty_pref[last] - empty_pref[i], lower_bound(all(b), a[last]) - upper_bound(all(b), a[i]));
        cur++;
        if (cur == dp_pref[last]) {
            int last_value = a[i];
            for (int j = i + 1; j < last; j++) {
                if (a[j] != -1) continue;
                auto it = st.upper_bound(last_value);
                if (it != st.end()) {
                    ans[j] = last_value = *it;
                    st.erase(it);
                }
            }
            last = i;
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            assert(!st.empty());
            ans[i] = *st.begin();
            st.erase(st.begin());
        }
    }

    for (int i = 1; i < n - 1; i++) {
        cout << ans[i] << " \n"[i == n - 2];
    }
}