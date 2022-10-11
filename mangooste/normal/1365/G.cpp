#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    struct interactor {
        int n;

        interactor(int n) : n(n) {}

        ll query(const vector<int> &p) const {
            if (p.empty()) return 0;
            cout << "? " << len(p);
            for (auto &x : p) cout << ' ' << x + 1;
            cout << endl;
            ll tot;
            cin >> tot;
            return tot;
        }

        void answer(const vector<ll> &ans) {
            cout << "! ";
            for (int i = 0; i < n; i++) {
                cout << ans[i] << " \n"[i == n - 1];
            }
        }
    } qq(n);

    constexpr int MAX_Q = 13, MASK = 1 << MAX_Q;
    vector<int> masks;
    for (int i = 0; i < MASK; i++) {
        if (__builtin_popcount(i) == 5) masks.push_back(i);
    }
    assert(len(masks) >= 1000);

    vector<ll> res(MAX_Q);
    for (int bit = 0; bit < MAX_Q; bit++) {
        vector<int> cur;
        for (int i = 0; i < n; i++) {
            if (masks[i] >> bit & 1) cur.push_back(i);
        }
        res[bit] = qq.query(cur);
    }

    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX_Q; j++) {
            if (masks[i] >> j & 1) continue;
            ans[i] |= res[j];
        }
    }
    qq.answer(ans);
}