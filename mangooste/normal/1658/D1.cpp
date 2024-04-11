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

void solve() {
    int l, r;
    cin >> l >> r;
    vector<int> a(r - l + 1);
    for (auto &x : a) cin >> x;

    struct node {
        array<node*, 2> nxt{nullptr, nullptr};
        bool must0 = false, must1 = false;

        ~node() {
            for (int i : {0, 1}) {
                if (nxt[i]) delete nxt[i];
            }
        }
    };

    node* root = new node();
    for (auto x : a) {
        for (int rot = 0; rot < 2; rot++, x ^= (1 << 17) - 1) {
            int cur = rot == 0 ? r : (l ^ ((1 << 17) - 1));
            auto v = root;
            for (int bit = 16; bit >= 0; bit--) {
                int b1 = cur >> bit & 1;
                int b2 = x >> bit & 1;
                if (b1 == 0) {
                    if (b2 == 1) v->must1 = true;
                    else v->must0 = true;
                }

                int b = b1 ^ b2;
                if (!v->nxt[b]) v->nxt[b] = new node();
                v = v->nxt[b];
            }
        }
    }

    int ans = y_combinator([&](auto dfs, node* v, int level) -> int {
        if (level == -1 || !v) return 0;
        if (v->must0 && v->must1) return -1;
        int ans = -1;
        if (!v->must1) {
            int pans = dfs(v->nxt[0], level - 1);
            if (pans != -1) ans = pans;
        }
        if (!v->must0) {
            int pans = dfs(v->nxt[1], level - 1);
            if (pans != -1) ans = pans ^ (1 << level);
        }
        return ans;
    })(root, 16);

    assert(ans != -1);
    cout << ans << '\n';
    delete root;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}