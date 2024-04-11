#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

struct Comp {
    static ll f(int n, int k) {
        assert(k <= n);
        if (!k) return 0;
        int base = n / k;
        int more = n % k;
        return ll(base) * base * (k - more) + ll(base + 1) * (base + 1) * more;
    }

    bool operator () (const pair<int, int> &a, const pair<int, int> &b) const {
        return f(a.first, a.second + 1) - f(a.first, a.second) < f(b.first, b.second + 1) - f(b.first, b.second);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    multiset<pair<int, int>, Comp> st;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += Comp::f(x, 1);
        if (x != 1) st.emplace(x, 1);
    }

    k -= n;
    while (k--) {
        pair<int, int> cur = *st.begin();
        st.erase(st.begin());
        ans -= Comp::f(cur.first, cur.second);
        cur.second++;
        ans += Comp::f(cur.first, cur.second);
        if (cur.second != cur.first) st.insert(cur);
    }
    cout << ans << '\n';
}